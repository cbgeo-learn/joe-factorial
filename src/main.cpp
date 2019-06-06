#include "shapefactory.h"
#include "shape.h"

int main(int argc, char **argv)
{
	if (argc!=4)
	    std::abort();
	// Get dimension number
	std::string dim(argv[1]);
	// Get string for shape
	std::string str(argv[2]);
	// Get string for file name with points
	std::string fname(argv[3]);
	// Create a pointer to an instance of a concrete factory
	std::shared_ptr<ShapeFactory> shape_factory=ShapeFactory::createFactory(str);
	// Create a pointer to an instance of shape
	std::shared_ptr<Shape> shape=shape_factory->getshape(fname, dim);
	// Print the area of the initialized shape
	std::cout<<"Area = "<<shape->area()<<"\n";
	// Print the volume of the initialized shape
	std::cout<<"Volume = "<<shape->volume()<<"\n";
}
