#ifndef TRIANGLE_H
#define TRIANGLE
#include"shape.h"

class Triangle : public Shape
{
public:
	Triangle(const std::string& fname, const std::string& dim);
	double area() const override;
	double volume() const override;
};
#endif
