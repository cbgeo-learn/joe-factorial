#ifndef SHAPE_H
#define SHAPE_H
#include<string>
#include<iostream>
#include<cstdlib>
#include<stdlib.h>
#include<fstream>
#include"Eigen/Dense"

class Shape
{
public:
	Shape(const std::string& fname);

	double area();

private:
	Eigen::MatrixXd pts_;	
};
#endif
