template <typename T>
void    printTimeCallAlgo( T& container, std::string type ) {


	const std::clock_t beforeTime = std::clock();

	if ( type == "vector" ) {
	

		std::cout << "FORD-JOHNSON ALGORITHM" << std::endl;
		T       result = ::FJalgorithm<T>( container );
		const std::clock_t afterTime = std::clock();
		PmergeMe::countTime( "vector", container.size(), beforeTime, afterTime );
		
		std::cout << "After: ";
		//::printContainer( result, type );
	}

	else if ( type == "deque" ) {

		T       result = ::FJalgorithm<T>( container );
		const std::clock_t afterTime = std::clock();
		PmergeMe::countTime( "deque", container.size(), beforeTime, afterTime );
		
		std::cout << "After: ";
		//::printContainer( result, type );
	}
	
	else if ( type == "vector no Ford-Johnson" ) {

		std::cout << "SIMPLE COMPARISON-BASED SORT (not Ford-Johnson)" << std::endl;
		T       result = ::sortWithoutAlgo( container );
		const std::clock_t afterTime = std::clock();
		PmergeMe::countTime( "vector", container.size(), beforeTime, afterTime );
		
		std::cout << "After: ";
		//::printContainer( result, type );
		std::cout << std::endl << std::endl;
	}

}



template <typename T>
T	FJalgorithm( T container ) {
	
	if ( container.size() <= 1 ) {  return container;  }

	int						straggler = -1;
	T			main;
	T			pend;
	std::vector< std::pair<int, int> >	pairs;
	//
	//Step 1 : get main, pend and straggler
	//
	
	if ( container.size() % 2 != 0 ) {  straggler =container[container.size()-1];  }
	else {  straggler = NOSTRAGGLER;  }
	
	typename T::size_type  i = 0;
	while ( i+1 < container.size() ) {

		int	bigger = 0;
		int	smaller = 0;

		if (container[i] > container[i+1] ) {
			bigger = i;
			smaller = i + 1;
		}
		else {
			bigger = i + 1;
			smaller = i;
		}

		main.push_back( container[bigger] );
		pairs.push_back(  std::make_pair(container[bigger], container[smaller] )  );
		pend.push_back( container[smaller] );

		if ( i+2 < container.size() ) {  i += 2;  }
		else {  break;  }
	}
	//
	//Step 2 : sort main
	//
	main = ::FJalgorithm( main );
	//
	//Step3 : inserting pend to main
	//
	//insert index 0 of pend
	

	main = ::insertNumber<T>( pend[0], main, pairs );
	if ( pend.size() == 1 && straggler == NOSTRAGGLER ) {  return main;  }
	

	int	index = 1;
	int	previousIndex = 1;
	int	previousOfThePreviousIndex = 1;

	int	pendSize = pend.size();


	if ( pend.size() > 1 ) {
		main = ::insertNumber<T>( pend[index], main, pairs );
		PmergeMe::getNextIndexWithJacobsthalSequence( index, previousIndex, previousOfThePreviousIndex );

	}
	while ( index < pendSize ) {

		for ( int i = index; i > previousOfThePreviousIndex; i -= 1 ) {

			main = ::insertNumber( pend[i], main, pairs );
		}
		PmergeMe::getNextIndexWithJacobsthalSequence( index, previousIndex, previousOfThePreviousIndex );
	}


	for ( int i = pendSize-1; i > previousOfThePreviousIndex; i -= 1 ) {

		main = ::insertNumber<T>( pend[i], main, pairs );
	}

	if ( straggler != NOSTRAGGLER ) {
			main = ::insertStraggler( straggler, main );
	}
	
	return main;
}


template <typename T>
T	insertNumber( int insertIt, T here, std::vector< std::pair<int, int> > pairs) {

	int	pairOfPend = PmergeMe::findPair( insertIt, pairs );
	if ( pairOfPend == -1) {  std::cerr << "Error: can't find pair for " << insertIt << std::endl; throw std::runtime_error("Error: no number you're looking for");  }


	int	maxPositionInMain = ::findMainPositionForPair( pairOfPend, here );
	if ( maxPositionInMain == -1) {  throw std::runtime_error("Error: no position you're looking for");  }

	if ( maxPositionInMain == 0 ) {
		
		here.insert( here.begin(), insertIt );
		return here;
	}
	for ( int i = maxPositionInMain-1; i >= 0; i--) {
		if ( insertIt > here[i]) {
		
			here.insert( here.begin() + i + 1, insertIt );
			break ;
		}
		else if ( i == 0 ) {
			here.insert( here.begin(), insertIt );
			break ;
		}
	}

	return here;
}

template <typename T>
void	printContainer( T& container, std::string type ) {
	
	if ( container.empty() ) {  std::cout << "empty" << std::endl;  }

	if ( type == "vector" )
		std::cout << VECTORCOLOR;
	else if ( type == "deque" )
		std::cout << DEQUECOLOR;
	else
		std::cout << BASECOLOR;
	for (std::vector<int>::size_type i = 0; i < container.size(); i++) {

		std::cout << " " << container[i];
	}
	std::cout << RESET << std::endl;
}


template <typename T>
T	sortWithoutAlgo( T container ) {


	T sorted = container;
	while ( !::vectorIsSorted( sorted ) ) {
	
		for ( typename T::size_type i = 0; i < sorted.size(); i++ ) {
			if ( i+1 < sorted.size() && sorted[i] > sorted[i+1] ) {  std::swap( sorted[i], sorted[i+1] );  }
		}
	}
	
	return sorted;
}

template <typename T>
T	insertStraggler( int straggler, T main ) {

	int mainSize = main.size();

	if ( straggler > main[ mainSize/2 ]) {
		for ( int i = mainSize/2 ; i < mainSize; i++) {
			
			if ( straggler < main[i]) {

				main.insert( main.begin() + i, straggler);
				return main;
			}
			else if ( i+1 == mainSize ) {

				main.insert( main.begin() + i+1, straggler);
				return main;
			}
		}
	}
	else {
		for ( int i = mainSize/2 ; i >= 0; i--) {

			if ( straggler > main[i]) {

				main.insert( main.begin() + i + 1, straggler);
				return main;
			}
			if ( i == 0 && straggler < main[i] ) {

				main.insert( main.begin(), straggler);
				return main;
			}

		}
	}

	return main;
}

template <typename T>
int	findMainPositionForPair( int findIt, T&  inHere ) {

	int	min = 0;
	int	max = inHere.size() - 1;
	int	middle;// = min + (max - min)/2;


	while ( max >= min ) {

		middle = min + (max - min)/2;
		if ( inHere[middle] == findIt ) {

			return middle;
		}
		
		if ( inHere[middle] < findIt ) {

			min = middle + 1;
		}
		else if ( inHere[middle] > findIt ) {

			max = middle - 1;
		}

	
	}
/*
	int count = 0;
	for ( typename T::size_type i = 0; i < inHere.size(); i++ ) {
		if ( inHere[i] == findIt ) {  return count;  }
		count += 1;
	}
*/
	return -1;
}

template <typename T>
bool	vectorIsSorted( T v ) {

	for ( typename T::size_type i = 0; i < v.size(); i++ ) {

		if ( i+1 < v.size() && v[i] > v[i+1] ) {  return false;  }
	}
	
	return true;
}
