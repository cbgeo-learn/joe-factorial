#ifndef SHAPE_H
#define SHAPE_H
#include<string>
#include<iostream>
#include<cstdlib>

#include "Eigen/Dense"

class Shape
{
public:
	Shape(const int npts);

	double area();
	
private:
	Eigen::MatrixXd pts_;	
};
#endif
