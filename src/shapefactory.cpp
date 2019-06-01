#include "shapefactory.h"
#include "trianglefactory.h"
#include "rectanglefactory.h"

ShapeFactory* ShapeFactory::createFactory(const std::string& str)
{
    if (str == "triangle")
    {
        std::cout<<"Triangle"<<"\n";
        return new TriangleFactory;
    }
    else if (str == "rectangle")
    {
        std::cout<<"Rectangle"<<"\n";
        return new RectangleFactory;
    }
    else
    {
	std::cerr<<"Entry "<<str<<" not recognized use triangle or rectangle"<<"\n";
        std::abort();
    }
}
