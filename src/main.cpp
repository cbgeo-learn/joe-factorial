#include <iostream>
#include <string>
#include "shape.h"
#include "triangle.h"
#include "rectangle.h"


int main(int argc, char **argv)
{
	
	if (argc!=3)
	    std::abort();

	// Get string to determine shape type triangle or square
	std::string str(argv[1]);
	
	// Get string for file name with points
	std::string fname(argv[2]);
	
	if (str == "triangle")
	{
		std::cout<<"Triangle"<<"\n";
		Triangle tri = Triangle(fname);
		std::cout<<tri.pts()<<"\n";
		std::cout<<tri.area()<<"\n";

	}
	else {if (str == "rectangle")
	{	
		std::cout<<"Rectangle"<<"\n";
		Rectangle rec = Rectangle(fname);
		std::cout<<rec.pts()<<"\n";
		std::cout<<rec.area()<<"\n";
	}
	else
		std::abort();
	}
}
