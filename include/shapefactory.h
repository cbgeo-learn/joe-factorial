#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H
#include "rectangle.h"
#include "triangle.h"

class ShapeFactory
{
public:
	// Virtual destructor
	virtual ~ShapeFactory(){};
	// Virtual shape;
	virtual Shape* getshape(const std::string& fname)=0;
	// Create a pointer to the shape factory
	static ShapeFactory* createFactory(const std::string& str);
};
#endif
