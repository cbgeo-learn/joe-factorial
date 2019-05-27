#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(const std::string& fname);
	virtual double area() const override;
};
#endif