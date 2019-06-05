#ifndef TET_H
#define TET_H
#include "shape.h"

class Tetrahedron : public Shape
{
public:
	Tetrahedron(const std::string& fname);
	double area() const override;
	double volume() const override;
};
#endif
