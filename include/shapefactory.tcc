std::shared_ptr<ShapeFactory> ShapeFactory::create_factory(
    const std::string& str, const int dim) {

  //Map
  std::map<std::string, std::shared_ptr<ShapeFactory>> shape_map;
  if (dim==2){
  shape_map.emplace(std::make_pair(std::string("triangle"),
                                   std::make_shared<TriangleFactory<2> >()));
  shape_map.emplace(std::make_pair(std::string("rectangle"),
                                   std::make_shared<RectangleFactory<2> >()));
  } else if (dim==3){
  shape_map.emplace(std::make_pair(std::string("tetrahedron"),
			           std::make_shared<TetFactory<3> >()));
  }

  // Try to index, if not throw meaningful error and abort
  try {
    return shape_map.at(str);
  } catch (const std::out_of_range& e) {
    std::cerr << "Entry of shape " << str << " not recognized ";
    if (dim==2)
	std::cerr << "use triangle or rectangle. Or use different dimension.\n";
    else if (dim==3)
	std::cerr << "use tetrahedron. Or use different dimension.\n";
    std::abort();
  }
}
