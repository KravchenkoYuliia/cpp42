template <typename T>
void    printTimeCallAlgo( T container, std::string type ) {


	const std::clock_t beforeTime = std::clock();

	if ( type == "vector" ) {
	
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

		T       result = PmergeMe::sortWithoutAlgo( container );
		const std::clock_t afterTime = std::clock();
		std::cout << "Sorting without Ford-Johnson algorithm to compare the used time" << std::endl;
		PmergeMe::countTime( "vector", container.size(), beforeTime, afterTime );
		
		std::cout << "After: ";
		PmergeMe::printVector( result );
	}

}

