#ifndef RECTANGLEFACTORY_H
#define RECTANGLEFACTORY_H

#include "rectangle.h"
#include "shapefactory.h"

template <int Tdim>
class RectangleFactory : public ShapeFactory {
 public:
  // Return pointer to shape
  std::shared_ptr<ShapeHead> getshape(const std::string& fname) {
    return std::make_shared<Rectangle<Tdim>>(fname);
  }
};
#endif
