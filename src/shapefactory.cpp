#include "shapefactory.h"
#include "trianglefactory.h"
#include "rectanglefactory.h"

std::shared_ptr<ShapeFactory> ShapeFactory::createFactory(const std::string& str)
{
    if (str == "triangle")
    {
        std::cout<<"Triangle"<<"\n";
        return std::make_shared<TriangleFactory>();
    }
    else if (str == "rectangle")
    {
        std::cout<<"Rectangle"<<"\n";
        return std::make_shared<RectangleFactory>();
    }
    else
    {
	std::cerr<<"Entry "<<str<<" not recognized use triangle or rectangle"<<"\n";
        std::abort();
    }
}
