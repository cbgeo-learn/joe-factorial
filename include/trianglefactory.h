#ifndef TRIANGLEFACTORY_H
#define TRIANGLEFACTORY_H
#include "shape.h"
#include "shapefactory.h"
template <int Tdim>
class TriangleFactory : public ShapeFactory<Tdim> {
 public:
  // Return triangle shape
  std::shared_ptr<Shape<Tdim>> getshape(const std::string& fname) {
    return std::make_shared<Triangle<Tdim>>(fname);
  }
};
#endif
