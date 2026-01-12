template <typename T>
void    printTimeCallAlgo( T& container, std::string type ) {


	const std::clock_t beforeTime = std::clock();

	if ( type == "vector" ) {
	
		std::cout << "FORD-JOHNSON ALGORITHM" << std::endl;
		T       result = PmergeMe::FJalgorithm( container );
		const std::clock_t afterTime = std::clock();
		PmergeMe::countTime( "vector", container.size(), beforeTime, afterTime );
		
		std::cout << "After: ";
		PmergeMe::printVector( result );
	}

	else if ( type == "list" ) {

		//algo for list
		const std::clock_t afterTime = std::clock();
		PmergeMe::countTime( "list", container.size(), beforeTime, afterTime );
	}
	
	else if ( type == "vector no Ford-Johnson" ) {

		std::cout << "SIMPLE COMPARISON-BASED SORT (not Ford-Johnson)" << std::endl;
		T       result = PmergeMe::sortWithoutAlgo( container );
		const std::clock_t afterTime = std::clock();
		PmergeMe::countTime( "vector", container.size(), beforeTime, afterTime );
		
		std::cout << "After: ";
		PmergeMe::printVector( result );
		std::cout << std::endl << std::endl;
	}

}

