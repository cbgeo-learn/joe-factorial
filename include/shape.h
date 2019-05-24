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
	Eigen::MatrixXd pts() const;
	Eigen::MatrixXd pts_;	
};
#endif
