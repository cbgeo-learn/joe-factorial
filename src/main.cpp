#include "shapefactory.h"
#include "shape.h"

int main(int argc, char **argv)
{
	if (argc!=3)
	    std::abort();
	// Get string to determine shape type triangle or square
	std::string str(argv[1]);
	// Get string for file name with points
	std::string fname(argv[2]);
	// Create a pointer to an instance of a concrete factory
	std::shared_ptr<ShapeFactory> shape_factory=ShapeFactory::createFactory(str);
	// Create a pointer to an instance of shape
	std::shared_ptr<Shape> shape=shape_factory->getshape(fname);
	// Print the area of the initialized shape
	std::cout<<"Area = "<<shape->area()<<"\n";
}
