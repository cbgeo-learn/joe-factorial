#include <iostream>
#include <memory>

#include "factory.h"
#include "shapehead.h"

int main(int argc, char** argv) {
  if (argc != 4) std::abort();
  // Get dimension number
  //const int dim = std::atoi(argv[1]);
  const int dim = 2;
  // Get string for shape
  std::string str(argv[2]);
  // Get string for file name with points
  std::string fname(argv[3]);
  // Create a pointer to an instance of shape
  auto shape = Factory<ShapeHead, const std::string&>::instance()->create(str, fname);
  // Print the area of the initialized shape
  std::cout << "Area = " << shape->area() << "\n";
  // Print the volume of the initialized shape
  std::cout << "Volume = " << shape->volume() << "\n";
}
