# Ford-Johnson sorting algorithm
	Merge Insertion sorting algorithm

	./PmergeMe any integers ...


Using this algorith on:
	- `std::vector` (easier because it has index)
	- `std::list` (more complicated without index)
	comparing the performance

Exemple of the original list : [8 2 1 0 4 3 7 5 14 6 9]

## Step 1
	PAIRS
	- "Split the list into pairs (sublists)" (imaginary)
		[8 2] [1 0] [4 3] [7 5] [14 6] [9]
	- Swap the numbers inside every pair to know every pair's `min` and `max`
		[2 8] [0 1] [3 4] [5 7] [6 14] [9]

## Step 2
	SORT MAX
	- Sort only the `max` values, ignoring the `min` values that still remain in pairs
	- `max` values create `main` chain
	- `min` values create `pend` chain (that are waiting the `main` to be sorted so `pend` can start to insert itself inside `main`)
		current `main` : 8 1 4 7 14
		current `pend` : 2 0 3 5 6
		straggler: 9
	- Recalling Step1 for `main` to be sorted till `main` only has 1 last element and start the Step3
			
	- We know exactly that in every pair a first nb is smaller than a second one and `max` values are already sorted 

## Step 3 
	INSERTING

		we know: max1 < max2 < max3 < max4 < max5
	min1 is the first min so it stays at its place
### Jacobsthal Sequence

	current = previous + 2*( previous of the previous );

	Sequence of the indices: 
	0 1 -> fixed start of the sequence
	-> 1(1+2*0) -> 3(1+2*1) -> 5(3+2*1) -> 11(5+2*3) .......

	It will be used on `pend` chain. The sequence is limited by `pend` size

		The last earmain` is : 1 -> 4 -> 7 -> 8 -> 14
		The `pend` chain is : 0, 3, 5, 2, 6
		The pairs:
		 [0 1] [3 4] [5 7] [2 8] [6 14] [9]
		straggler: 9

		`pend`.size is 5 
		Jacobsthal: 0-1-3-5-11-... 
		we can take : 0, 1, 3 (are < size of `pend`)


	FIRST block of the Jacobsthal sequence is 0
	- first element in `main` is 1. His pair is 0 -> insert it first. It's the smallest number

	START from the left to right by blocks (0,1], (1-3], (3, 5], (5-11] and so on 
	- (0,1] insert index 1
	- (1,3] insert index 3 than 2
	- (3,5] insert index 5 than 4 (in our exemple there is no index 5 so just insert 4)
	












### Linear search 
	slower
	step by step from the start till the end, no random access, no operator []
	std::list

### Binary search
	faster
	random access, compare only a part so can access the list, for exemple, in the middle by index
	std::vector
	has operator []


## std::map Vs std::vector<pair<int,int>>
	
	Maps: automatically sorted keys, quicker key search
	Vectors<pair>: just arrays, sorting and searching are manually done by you


## Parsing errors
	- only digit -> only integers -> only possitive integers
		1. more than 10 elements -> error
		2. can be digit/space or +(but with the conditions: space or nothing before `+`; has a digit after )
		3. 
	- `+12` are accepted. `+++12` is not accepted
	- from 0 to INT_MAX
	- doubles are not possible



std::vector<int>::size_type = size_t -> is unsigned
