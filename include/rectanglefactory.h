#ifndef RECTANGLEFACTORY_H
#define RECTANGLEFACTORY_H
#include "shapefactory.h"
class RectangleFactory : public ShapeFactory
{
public:
	// Virtual destructor
	virtual ~RectangleFactory(){}
	// Return pointer to shape 
	std::shared_ptr<Shape> getshape(const std::string& fname, const std::string& dim){
		return std::make_shared<Rectangle>(fname, dim);
	}
};
#endif
