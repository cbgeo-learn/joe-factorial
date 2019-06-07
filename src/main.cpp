#include <memory>

#include "rectanglefactory.h"
#include "shape.h"
#include "shapefactory.h"
#include "trianglefactory.h"

int main(int argc, char **argv) {
  if (argc != 4)
    std::abort();
  // Get dimension number
  // const int dim = std::atoi(argv[1]);
  const int dim = 2;
  // Get string for shape
  std::string str(argv[2]);
  // Get string for file name with points
  std::string fname(argv[3]);
  // Create a pointer to an instance of a concrete factory
  std::shared_ptr<ShapeFactory<2>> shape_factory =
      ShapeFactory<2>::createFactory(str);
  // Create a pointer to an instance of shape
  auto rec = std::make_shared<RectangleFactory<2>>();
  std::shared_ptr<Shape<2>> shape = shape_factory->getshape(fname);
  // Print the area of the initialized shape
  std::cout << "Area = " << shape->area() << "\n";
  // Print the volume of the initialized shape
  std::cout << "Volume = " << shape->volume() << "\n";
}
