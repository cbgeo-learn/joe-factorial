#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include <map>
#include <string>

#include "rectangle.h"
#include "tet.h"
#include "triangle.h"

template <int Tdim>
class RectangleFactory;

template <int Tdim>
class TriangleFactory;

template <int Tdim>
class TetFactory;

class ShapeFactory {
 public:
  // Create a pointer to the shape factory
  static std::shared_ptr<ShapeFactory> create_factory(const std::string& str, const int dim);
  // Virtual shape;
  virtual std::shared_ptr<ShapeHead> getshape(const std::string& fname) = 0;
};

#include "shapefactory.tcc"
#endif
