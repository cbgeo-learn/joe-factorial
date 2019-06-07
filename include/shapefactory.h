#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H
#include "rectangle.h"
#include "triangle.h"
#include "tet.h"

template<const int Tdim>
class ShapeFactory
{
public:
	// Virtual shape;
	virtual std::shared_ptr< Shape<Tdim> > getshape(const std::string& fname)=0;
	// Create a pointer to the shape factory
	static std::shared_ptr< ShapeFactory<Tdim> > createFactory(const std::string& str);
};
#endif
