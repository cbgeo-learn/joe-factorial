#ifndef TRIANGLE_H
#define TRIANGLE
#include<iostream>
#include<string>
#include<cstdlib>
#include<stdlib.h>
#include"Eigen/Dense"
#include"shape.h"

class Triangle : public Shape
{
public:
	Triangle(const std::string& fname);
	double area() const;
};
#endif
