#ifndef SHAPE_H
#define SHAPE_H

#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>

#include "csv.h"
#include "Eigen/Dense"
#include "shapehead.h"

template <int Tdim>
class Shape : public ShapeHead
{
 public:
  Shape(const std::string& fname);
  virtual double area() const = 0;
  virtual double volume() const = 0;

 protected:
  std::vector<Eigen::Matrix<double, Tdim, 1>> pts_;
};
#include "shape.tcc"
#endif
