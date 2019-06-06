#ifndef TETFACTORY_H
#define TETFACTORY_H
#include "shapefactory.h"
class TetFactory : public ShapeFactory
{
public:
	// Virtual destructor
	virtual ~TetFactory(){}
	// Return pointer to concrete factory
	std::shared_ptr<Shape> getshape(const std::string& fname, const std::string& dim){
		return std::make_shared<Tetrahedron>(fname, dim);}
};
#endif
