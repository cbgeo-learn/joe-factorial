#ifndef TRIANGLE_H
#define TRIANGLE

#include "shape.h"

template <int Tdim>
class Triangle : public Shape<Tdim> {
 public:
  Triangle(const std::string& fname);
  double area() const override;
  double volume() const override;
};

#include "triangle.tcc"
#endif
