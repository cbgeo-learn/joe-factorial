#ifndef TRIANGLEFACTORY_H
#define TRIANGLEFACTORY_H
#include "shapefactory.h"
class TriangleFactory : public ShapeFactory
{
public:
	// Virtual destructor
	virtual ~TriangleFactory(){}
	// Return triangle shape
	std::shared_ptr<Shape> getshape(const std::string& fname, const std::string& dim){
		return std::make_shared<Triangle>(fname, dim);}
};
#endif
