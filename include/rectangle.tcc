template <const int Tdim>
Rectangle<Tdim>::Rectangle(const std::string& fname) : Shape<Tdim>(fname) {
  std::cout << "Constructor for Rectangle Sub-class\n";
}

template <const int Tdim>
double Rectangle<Tdim>::area() const {
  double area = 0;
  std::vector<Eigen::Matrix<double, 2, 1> >::const_iterator it1;
  // Loop along coordinates
  for (auto it = (this->pts_).begin(); it != (this->pts_).end(); ++it) {
    it1 = ((*it) == (this->pts_).back()) ? (this->pts_).begin() : std::next(it);
    // (xn*yn+1 - yn*xn+1)
    area += ((*it)(0)) * ((*it1)(1)) - ((*it)(1)) * ((*it1)(0));
  }
  return 0.5 * std::abs(area);
}

template <const int Tdim>
double Rectangle<Tdim>::volume() const {
  std::cout << "Volume of a rectangle is undefined. Returning 0.\n";
  return 0;
}
