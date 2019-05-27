#ifndef TRIANGLE_H
#define TRIANGLE
#include"shape.h"

class Triangle : public Shape
{
public:
	Triangle(const std::string& fname);
	virtual double area() const override;
};
#endif
