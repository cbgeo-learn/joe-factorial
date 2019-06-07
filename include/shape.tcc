template <>
Shape<2>::Shape(const std::string& fname) {
  io::CSVReader<2> in(fname);
  in.read_header(io::ignore_extra_column, "x", "y");
  double x;
  double y;

  // Loop through the csv file and save x and y coordinates to matrix
  while (in.read_row(x, y))
    pts_.emplace_back(Eigen::Matrix<double, 2, 1>(x, y));
}

template <>
Shape<3>::Shape(const std::string& fname) {
  io::CSVReader<3> in(fname);
  in.read_header(io::ignore_extra_column, "x", "y", "z");
  double x;
  double y;
  double z;

  // Loop through the csv file and save x and y coordinates to matrix
  while (in.read_row(x, y, z))
    pts_.emplace_back(Eigen::Matrix<double, 3, 1>(x, y, z));
}
