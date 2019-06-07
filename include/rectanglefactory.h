#ifndef RECTANGLEFACTORY_H
#define RECTANGLEFACTORY_H
#include "shapefactory.h"
template <const int Tdim>
class RectangleFactory : public ShapeFactory<Tdim>
{
public:
	// Return pointer to shape 
	std::shared_ptr< Shape<Tdim> > getshape(const std::string& fname)
	{
		return std::make_shared< Rectangle<Tdim> >(fname);
	}
};
#endif
