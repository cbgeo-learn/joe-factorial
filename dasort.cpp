#include <iostream>
#include <vector>

bool chkchange(int previter, int curiter, int changefound)
{
	if (changefound==true)
		return true;
	else
		return (previter==curiter) ? false : true;
} 

void printarray( int alength, std::vector<int> array)
{
	for (int pid=0; pid<alength; ++pid)
		std::cout << array.at(pid) << " ";
	std::cout<<"\n";
} 

std::vector<int> swap( std::vector<int> array, int cid)
{
	if (array.at(cid)>array.at(cid+1))
	{
		int temp = array.at(cid);		
		array.at(cid) = array.at(cid+1);
		array.at(cid+1) = temp;
	}
	return array;
}

int  main()
{
	//Ask for length of array and define variable
	std::cout << "Please enter a postive integer to define the array length: ";
	int arraylength;
	std::cin >> arraylength;	

	//Generate two standard vectors of that length, one to keep and one to sort
	std::vector<int> rawarray;
	std::vector<int> sortarray;

	// Reserve these standard vectors to be right size
	rawarray.reserve(arraylength);
	sortarray.reserve(arraylength);	
	
	//Loop through the array and ask for inputs
	int myval;
	for (int id=0; id<arraylength; ++id)
	{
		std::cout<< "Please enter the values of "<< id << " member of the array: ";
		
		std::cin >> myval;
		rawarray.push_back(myval);
		sortarray.push_back(myval);
	}

	//Sort the one array using a bubble sort
	int cval;
	bool changefound;

	//Outer loop for repeated passes, at most N-1 required swaps
	for (int trial=1; trial<arraylength; ++trial)
	{
		//Set null hypothesis
		changefound=false;

		//Inner loop performs single pass, at most arraylength - trial swaps
		for (int cid=0; cid<arraylength-trial; ++cid)
		{
			//Get current (soon to be previous) value for comparison later
			cval = sortarray.at(cid);			
	
			// Use swap
			sortarray = swap(sortarray,cid);
	
			//Determine if need to repeat sort
			changefound = chkchange(cval,sortarray.at(cid),changefound);
		}	
		// Allow to break early if no swaps were made (i.e. changefound = FALSE)
		if (!changefound)
			break;
	}
	
	// Print sorted unsorted array:
	std::cout<<"The unsorted array is: ";
	printarray(arraylength, rawarray);
	
	// Print sorted array:
	std::cout<<"The sorted array is: ";
	printarray(arraylength, sortarray);
}
