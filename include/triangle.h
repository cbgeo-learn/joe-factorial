#ifndef TRIANGLE_H
#define TRIANGLE
#include"shape.h"

template <const int Tdim>
class Triangle : public Shape<Tdim>
{
public:
	Triangle(const std::string& fname);
	double area() const override;
	double volume() const override;
};
#endif
