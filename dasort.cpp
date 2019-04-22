#include <iostream>
#include <algorithm>
#include <vector>

int defnext(int cid, int alength)
{
	if (cid+2>alength)
		return alength-1;
	else
		return cid+2;
}

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
		std::cout << array[pid] << " ";
	std::cout<<"\n";
} 


int  main()
{
	//Ask for length of array and define variable
	std::cout << "Please enter a postive integer to define the array length: ";
	int arraylength;
	std::cin >> arraylength;	

	//Generate two dynamic arrays of that length, one to keep and one to sort
	//int *rawarray = new int[arraylength];
	//int *sortarray = new int[arraylength];
	
	// Generate two standard vector types
	std::vector<int> rawarray;
	std::vector<int> sortarray;

	// Resize these standard vectors to be right size, without this segmentation fault
	rawarray.resize(arraylength);
	sortarray.resize(arraylength);	
	
	//Loop through the array and ask for inputs
	for (int id=0; id<arraylength; ++id)
	{
		std::cout<< "Please enter the values of "<< id << " member of the array: ";
		std::cin >> rawarray[id];
		sortarray[id]=rawarray[id];
	}

	//Sort the one array using a bubble sort
	int cval;
	bool changefound=true;

	//Outer loop for repeated passes
	while (changefound)
	{
		//Set null hypothesis
		changefound=false;

		//Inner loop performs single pass
		int prev=sortarray[0];
		int next=sortarray[1];
		for (int cid=0; cid<arraylength-1; ++cid)
		{
			//Get current (soon to be previous) value for comparison later
			cval = sortarray[cid];			
	
			//Determine minimum and assign
			sortarray[cid]=std::min(prev, next);
	
			//Set new prev to maximum
			prev = std::max(prev, next);

			//Set new next value, check to be sure dont go beyond array
			next = sortarray[defnext(cid, arraylength)];

			//Determine if need to repeat sort
			changefound = chkchange(cval,sortarray[cid],changefound);
		}	
		sortarray[arraylength-1] = prev;
	}

	// Print sorted unsorted array:
	std::cout<<" The unsorted array is: ";
	printarray(arraylength, rawarray);
	
	// Print sorted array:
	std::cout<<"The sorted array is: ";
	printarray(arraylength, sortarray);
	
	// Delete array off heap:
	//delete[] rawarray;
	//delete[] sortarray;
}
