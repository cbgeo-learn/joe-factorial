#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

template <int Tdim>
class Rectangle : public Shape<Tdim> {
 public:
  Rectangle(const std::string& fname);
  double area() const override;
  double volume() const override;
};

#include "rectangle.tcc"
#endif
