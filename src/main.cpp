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

	Shape *shp;	
	if (str == "triangle")
	{
		std::cout<<"Triangle"<<"\n";
		shp = new Triangle(fname);
	}
	else {if (str == "rectangle")
	{	
		std::cout<<"Rectangle"<<"\n";
		shp = new Rectangle(fname);
	}
	else
		std::abort();
	}
	//std::cout<<shp->pts()<<"\n";
	std::cout<<shp->area()<<"\n";
	delete shp;
}
