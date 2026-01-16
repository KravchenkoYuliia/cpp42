# Ford-Johnson sorting algorithm
	Merge Insertion sorting algorithm

	./PmergeMe any integers ...


Using this algorithm on:
	- `std::vector` ( array - linear )
	- `std::deque` ( array of arrays - blocks )
	comparing the performance

Exemple of the original list of numbers that need to be sorted : [8 2 1 0 4 3 7 5 14 6 9]

## Step 1
	PAIRS
	- Split the list into pairs (sublists)
		[8 2] [1 0] [4 3] [7 5] [14 6] [9]
	- Swap the numbers inside every pair to know every pair's `min` and `max`
		[2 8] [0 1] [3 4] [5 7] [6 14] [9] 
		add bigger number to `main` chain and a smaller one to `pend` chain
		and at the same time adding it to vector::pairs where key is bigger and his value is smaller ( we need it to know a pair of every `pend` number )

## Step 2
	SORT MAX
	- `max` values create `main` chain
	- `min` values create `pend` chain (that are waiting the `main` to be sorted so `pend` can start to insert itself inside `main`)
	- Sort only the `max`(`main`) values ( recursively calling the same function that will spit `main` chain to pairs and so on till `main` chain only has 1 number left), ignoring the `min`(`pend`) values that are waiting Step 3
		
		current `main` : 8 1 4 7 14
		current `pend` : 2 0 3 5 6
		straggler: 9
	- Recalling Step1 for `main` to be sorted till `main` only has 1 last element and start the Step3
				

## Step 3 
	INSERTING

		we know: max1 < max2 < max3 < max4 < max5
		every min is smaller than his pair max

		which index from pend insert ? 
		Instead of doing it one by one from the left to the right - insert indices accordingly to Jacobsthal Sequence: 
### Jacobsthal Sequence

	current = previous + 2*( previous of the previous );

	Sequence of the indices: 
	0 1 -> fixed start of the sequence
	-> 1(1+2*0) -> 3(1+2*1) -> 5(3+2*1) -> 11(5+2*3) .......

	It will be used on `pend` chain. The sequence is limited by `pend` size

		The last remain` is : 1 -> 4 -> 7 -> 8 -> 14
		The `pend` chain is : 0, 3, 5, 2, 6
		The pairs:
		 [0 1] [3 4] [5 7] [2 8] [6 14] [9]
		straggler: 9

		`pend`.size is 5 
		Jacobsthal: 0-1-3-5-11-... 
		we can take : 0, 1, 3 (are < size of `pend`)



	START from the left to right by blocks (0,1], (1-3], (3, 5], (5-11] and so on 
	- 0
	- (0,1] insert index 1
	- (1,3] insert index 3 than 2
	- (3,5] insert index 5 than 4 (in our exemple there is no index 5 so just insert 4)
	- (5, 11] insert 11 than 10 9 8 7 6
	




	

	To insert one `pend` number to `main` we need to know his pair's position in `main` so it will be a limit number to check ( `pend`=`min` can't be bigger than his `main`=`max` pair)
	Exemple: 
		vector::pairs has key[12] and value[10]
		`main`: 2 12 100 200 300 
		number we want to insert: 10
			Step 1: find `10`'s pair in vector::pairs ---->>> found 12
			Step 2: find `12`'s position in `main` with BINARY SEARCH --->>> 1
			Step 3: check where we can insert `10` in the list from index 0 to index 1. Possible position is marked as `x` [ `x` 2 `x` 12] 
			
			Ford-Johnson is optimized because:
			- don't wasting time to check if `10` is bigger than `12`, or bigger than `100` and so on
			- Jacobsthal sequence minimize comparisons
			- Binary search minimize comparisons






### Linear search 
	slower
	step by step from the start till the end

### Binary search
	faster
	possible only on a sorted sequence

	instead of checking all the numbers - check only the half and repeate till it's only 1 number left

	use it in
		::findMainPositionForPairs
		::insertStraggler


	exemple: 
		looking for 5
		 0 1 2 3 4 5
		 
		 min = 0
		 max = 5
		 middle = min + (max-min)/2;
	step 1 
		middle[2] < 5 --->>> min = middle + 1
	step 2
		min = 3
		max = 5
		middle = 3 + (5-3)/2 = 4

		middle < 5 --->>> min = middle + 1
	step 3
		min = 4
		max = 5
		middle = 4 + (5-4)/2 = 4
		middle < 4 --->>> min = 5
	step 4
		middle == 5
		

		


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



std::vector<int>::size_type = size_t --->>> is unsigned ( can't be negative )



### DEQUE
It's a sequence container that allows you to add or remove elements from both the front and the back ( like stack and queue ) and it can be iterated with indices like vector as well 

Blocks that stock the memory of elements. Array of arrays.


### cmd to generate a lot of numbers
./PmergeMe $(shuf -i `min-max` -n `how many numbers`)




	
