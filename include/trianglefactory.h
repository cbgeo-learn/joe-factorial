#ifndef TRIANGLEFACTORY_H
#define TRIANGLEFACTORY_H

#include "shape.h"
#include "shapefactory.h"

template <int Tdim>
class TriangleFactory : public ShapeFactory {
 public:
  // Return triangle shape
  std::shared_ptr<ShapeHead> getshape(const std::string& fname) {
    return std::make_shared<Triangle<Tdim>>(fname);
  }
};
#endif
