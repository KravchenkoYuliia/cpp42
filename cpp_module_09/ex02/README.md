# Ford-Johnson sorting algorithm
	Merge Insertion sorting algorithm

	./PmergeMe any integers ...

	 Original list : [8 2 1 0 4 3 7 5 14 6]

Using this algorith on:
	- `std::vector` (easier because it has index)
	- `std::list` (more complicated without index)
	comparing the performance

## Step 1
	PAIRS
	- "Split the list into pairs (sublists)" (imaginary)
		[8 2] [1 0] [4 3] [7 5] [14 6]
	- Swap the numbers inside every pair to know every pair's `min` and `max`
		[2 8] [0 1] [3 4] [5 7] [6 14]

## Step 2
	SORT MAX
	- Sort only the `max` values, ignoring the `min` values that still remain in pairs
		[0 1] [3 4] [5 7] [2 8] [6 14]
		
		1 -> 4 -> 7 -> 8 -> 14

	- We know exactly that in every pair a first nb is smaller than a second one and `max` values are already sorted 

## Step 3 
	INSERTING
		Now list is : [0 1] [3 4] [5 7] [2 8] [6 14]
		[min1 max1] [min2 max2] [min3 max3] [min4 max4] [min5 max5]

		we know: max1 < max2 < max3 < max4 < max5
	min1 is the first min so it stays at its place
	min2 will be inserted somewhere on the left (it can't be bigger that his max2):
		Now list is : [0 1 3 4] [5 7] [2 8] [6 14]
	min3 = 5	
		Now list is : [0 1 3 4 5 7] [2 8] [6 14]
	min4 = 2	
		Now list is : [0 1 2 3 4 5 7 8] [6 14]
	min5 = 6	
		Now list is : [0 1 2 3 4 5 6 7 8 14]




### Linear search 
	slower
	step by step from the start till the end, no random access, no operator []
	std::list

### Binary search
	faster
	random access, compare only a part so can access the list, for exemple, in the middle by index
	std::vector
	has operator []


## Parsing errors
	- only digit -> only integers
	- `+12` or `-12` are accepted. `+++-12`/ `+-12` are not accepted
	- from INT_MIN to INT_MAX
	- doubles are possible

