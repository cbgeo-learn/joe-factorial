#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(const std::string& fname, const std::string& dim);
	double area() const override;
	double volume() const override;
};
#endif
