#ifndef SHAPE_H
#define SHAPE_H
#include "Eigen/Dense"
#include "csv.h"
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>

template <int Tdim>
class Shape {
 public:
  Shape(const std::string& fname);
  virtual double area() const = 0;
  virtual double volume() const = 0;

 protected:
  std::vector<Eigen::Matrix<double, Tdim, 1>> pts_;
};
#include "shape.tcc"
#endif
