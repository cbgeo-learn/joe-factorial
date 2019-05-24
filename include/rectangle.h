#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "Eigen/Dense"
#include "shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(const std::string& fname);
	double area() const;
};
#endif
