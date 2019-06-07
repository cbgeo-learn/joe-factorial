#ifndef RECTANGLEFACTORY_H
#define RECTANGLEFACTORY_H

#include "rectangle.h"
#include "shapefactory.h"

template <int Tdim>
class RectangleFactory : public ShapeFactory<Tdim> {
 public:
  RectangleFactory() = default;
  // Return pointer to shape
  std::shared_ptr<Shape<Tdim>> getshape(const std::string& fname) {
    return std::make_shared<Rectangle<Tdim>>(fname);
  }
};
#endif
