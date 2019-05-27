#ifndef SHAPE_H
#define SHAPE_H
#include<string>
#include<iostream>
#include<cstdlib>
#include<iterator>
#include"csv.h"
#include"Eigen/Dense"

class Shape
{
public:
	Shape(const std::string& fname);
	std::vector<Eigen::Vector2d> pts() const;
	virtual double area() const;
protected:
	std::vector<Eigen::Vector2d> pts_;	
};
#endif
