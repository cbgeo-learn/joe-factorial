#ifndef TET_H
#define TET_H
#include "shape.h"

template <int Tdim>
class Tetrahedron : public Shape<Tdim>
{
public:
	Tetrahedron(const std::string& fname);
	double area() const override;
	double volume() const override;
};
#endif
