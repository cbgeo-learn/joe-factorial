#include <iostream>
#include <string>
#include "shape.h"

int main(int argc, char **argv)
{
	// Get string to determine shape type triangle or square
	std::string str(argv[2]);

	// Get string for file name with points
	std::string fname(argv[4]);
	
	if (str == "triangle")
	{
		std::cout<<"Triangle"<<"\n";
		Shape x=Shape(fname);
	}
	else {if (str == "rectangle")
	{	
		std::cout<<"Rectangle"<<"\n";
		Shape x=Shape(fname);
	}
	else
	{
		std::abort();
	}
	}
	//std::cout<<"The shape's area is "<<m.area()<<"\n";
}
