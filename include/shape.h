#ifndef SHAPE_H
#define SHAPE_H
#include<Eigen/Dense>
#include<string>
#include<iostream>
#include<cstdlib>

class Shape
{
public:
	Shape(const int npts);

	double area();
	
private:
	Eigen::MatrixXd pts_;	
};
#endif
