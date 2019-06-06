#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H
#include "rectangle.h"
#include "triangle.h"
#include "tet.h"

class ShapeFactory
{
public:
	// Virtual destructor
	virtual ~ShapeFactory(){};
	// Virtual shape;
	virtual std::shared_ptr<Shape> getshape(const std::string& fname, const std::string& dim)=0;
	// Create a pointer to the shape factory
	static std::shared_ptr<ShapeFactory> createFactory(const std::string& str);
};
#endif
