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

template <int Tdim>
class ShapeFactory {
 public:
  // Virtual shape;
  virtual std::shared_ptr<Shape<Tdim>> getshape(const std::string& fname) = 0;
  // Create a pointer to the shape factory
  static std::shared_ptr<ShapeFactory<Tdim>> createFactory(
      const std::string& str);
};

#include "shapefactory.tcc"
#endif
