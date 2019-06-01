#ifndef TRIANGLEFACTORY_H
#define TRIANGLEFACTORY_H
#include "shapefactory.h"
class TriangleFactory : public ShapeFactory
{
public:
	// Virtual destructor
	virtual ~TriangleFactory(){}
	// Return triangle shape
	Shape* getshape(const std::string& fname){
		return new Triangle(fname);
	}
};
#endif
