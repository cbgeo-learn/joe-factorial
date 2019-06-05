#ifndef SHAPE_H
#define SHAPE_H
#include<string>
#include<iostream>
#include<cstdlib>
#include"csv.h"
#include"Eigen/Dense"
#include<memory>
class Shape
{
public:
	Shape(const std::string& fname);
	virtual double area() const =0;
protected:
	std::vector<Eigen::Vector2d> pts_;	
};
#endif
