#include "factory.h"
#include "rectangle.h"
#include "shape.h"
#include "tet.h"
#include "triangle.h"

// Triangle
static Register<Shape<2>, Triangle<2>, const std::string&> triangle(
    "Triangle");

// Rectangle
static Register<Shape<2>, Rectangle<2>, const std::string&> rectangle(
    "Rectangle");

// Tet
static Register<Shape<3>, Tetrahedron<3>, const std::string&> tet(
    "Tetrahedron");
