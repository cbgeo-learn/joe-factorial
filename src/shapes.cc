#include "factory.h"
#include "rectangle.h"
#include "shapehead.h"
#include "tet.h"
#include "triangle.h"

// Triangle
static Register<ShapeHead, Triangle<2>, const std::string&> triangle(
    "triangle.txt");

// Rectangle
static Register<ShapeHead, Rectangle<2>, const std::string&> rectangle(
    "rectangle.txt");

// Tet
static Register<ShapeHead, Tetrahedron<3>, const std::string&> tet(
    "tetrahedron.txt");
