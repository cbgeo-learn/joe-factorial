#ifndef TETFACTORY_H
#define TETFACTORY_H

#include "tet.h"
#include "shapefactory.h"

template <int Tdim>
class TetFactory : public ShapeFactory { 
 public:
  // Return pointer to concrete factory
  std::shared_ptr<ShapeHead> getshape(const std::string& fname) {
    return std::make_shared<Tetrahedron<Tdim>>(fname);
  }
};
#endif
