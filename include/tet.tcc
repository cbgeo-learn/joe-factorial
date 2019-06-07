template <const int Tdim>
Tetrahedron<Tdim>::Tetrahedron(const std::string& fname) : Shape<Tdim>(fname) {
  std::cout << "Constuctor for Tetrahedron sub-class."
            << "\n";
}

template <const int Tdim>
double Tetrahedron<Tdim>::area() const {
  std::cout << "Area of a Tetrahedron is undefined, returning 0."
            << "\n";
  return 0;
}

template <const int Tdim>
double Tetrahedron<Tdim>::volume() const {
  // Place-holder
  std::cout << "Volume calculation occurs ..."
            << "\n";
  return 1.0;
}
