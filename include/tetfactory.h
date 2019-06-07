#ifndef TETFACTORY_H
#define TETFACTORY_H
#include "shapefactory.h"
template <const int Tdim>
class TetFactory : public ShapeFactory<Tdim>
{
public:
	// Return pointer to concrete factory
	std::shared_ptr< Shape<Tdim> > getshape(const std::string& fname)
	{
		return std::make_shared< Tetrahedron<Tdim> >(fname);
	}
};
#endif
