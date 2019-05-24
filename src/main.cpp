#include <iostream>
#include "shape.h"

int main()
{
	std::cout<<"Please enter the desired number of points: ";
	int npts;
	std::cin>>npts;

	Shape m=Shape(npts);
	
	std::cout<<"The shape's area is "<<m.area()<<"\n";
}
