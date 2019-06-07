#ifndef SHAPE_H
#define SHAPE_H
#include<string>
#include<iostream>
#include<cstdlib>
#include"csv.h"
#include"Eigen/Dense"
#include<memory>

template <const int Tdim>
class Shape
{
public:
	Shape(const std::string& fname);
	virtual double area() const =0;
	virtual double volume() const =0;
protected:	
	std::vector< Eigen::Matrix<double, Tdim, 1> > pts_;
};
#endif
