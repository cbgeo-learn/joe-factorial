#ifndef RECTANGLEFACTORY_H
#define RECTANGLEFACTORY_H
#include "shapefactory.h"
class RectangleFactory : public ShapeFactory
{
public:
	// Virtual destructor
	virtual ~RectangleFactory(){}
	// Return pointer to shape 
	Shape* getshape(const std::string& fname){
		return new Rectangle(fname);
	}
};
#endif
