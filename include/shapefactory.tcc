template <>
std::shared_ptr<ShapeFactory<2> > ShapeFactory<2>::createFactory(
    const std::string& str) {

  // Map
  std::map<std::string, std::shared_ptr<ShapeFactory<2> > > shape_map;
  shape_map.emplace(std::make_pair(std::string("triangle"),
                                   std::make_shared<TriangleFactory<2> >()));
  shape_map.emplace(std::make_pair(std::string("rectangle"),
                                   std::make_shared<RectangleFactory<2> >()));

  // Try to index, if not throw meaningful error and abort
  try {
    return shape_map.at(str);
  } catch (const std::out_of_range& e) {
    std::cerr << "Entry of shape " << str
              << " not recognized use triangle, rectangle, or tetrahedron.\n";
    std::abort();
  }
}
