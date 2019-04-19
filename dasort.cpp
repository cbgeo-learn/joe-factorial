#include <iostream>

int min(int val1, int val2)
{
	return (val1<=val2) ? val1 : val2;
}

int max(int val1, int val2)
{
	return (val1>val2) ? val1 :val2;
}

int defNext(int cId, int aLength)
{
	if (cId+2>aLength)
	{
		return aLength-1;
	}
	else
	{
		return cId+2;
	}
}


int chkChange(int prevIter, int curIter, int changeFound)
{
	if (changeFound==1)
	{
		return 1;
	}
	else
	{
		return (prevIter==curIter) ? 0 : 1;
	}
} 

int  main()
{
	//Ask for length of array and define variable
	std::cout << "Please enter a postive integer to define the array length: ";
	int aLength=2;
	std::cin >> aLength;	

	//Generate two dynamic arrays of that length, one to keep and one to sort
	int *dArray = new int[aLength];
	int *sArray = new int[aLength];
	
	//Loop through the array and ask for inputs
	for (int id=0; id<aLength; ++id)
	{
		std::cout<< "Please enter the values of "<< id << " member of the array: ";
		std::cin >> dArray[id];
		sArray[id]=dArray[id];
	}

	//Sort the one array using a bubble sort
	int count=1;
	int cval;
	int changeFound;

	//Outer loop for repeated passes
	//for (int count=1; count<5; ++count)
	for (int run=1; run==1; ++count)
	{
		changeFound=0;
		//Inner loop performs single pass
		int prev=sArray[0];
		int next=sArray[1];
		for (int cId=0; cId<aLength-1; ++cId)
		{
			
			//Get current (soon to be previous) value for comparison later
			cval = sArray[cId];			
			//std::cout<<"preval "<<cval<<'\n';
	
			//Determine minimum and assign
			sArray[cId]=min(prev, next);
			//std::cout<<"newval "<<sArray[cId]<<'\n';		
	
			//Set new prev to maximum
			prev = max(prev, next);
			//std::cout<<"prev "<<prev<<'\n';		

			//Set new next value, check to be sure dont go beyond array
			next = sArray[defNext(cId, aLength)];
			//std::cout<<"next "<<next<<'\n';

			//Determine if need to repeat sort
			changeFound = chkChange(cval,sArray[cId],changeFound);
			//std::cout<<"run "<<run<<'\n';
		}	
		//std::cout<<"run "<<run<<'\n';
		run=changeFound;
		sArray[aLength-1] = prev;
	}

	std::cout<<" The unsorted array is: ";
	//Print out unsorted array
	for (int pId=0; pId<aLength; ++pId)
	{
		std::cout << dArray[pId] << " ";
	}		

	std::cout<<'\n'<<" The sorted array is: ";
	//Print out sorted array
	for (int pId=0; pId<aLength; ++pId)
	{
		std::cout << sArray[pId] << " ";
	}
	
	std::cout<<'\n';
}
