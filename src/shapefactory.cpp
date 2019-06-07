#include "shapefactory.h"
#include "trianglefactory.h"
#include "rectanglefactory.h"
#include "tetfactory.h"
#include <map>
template <const int Tdim>
std::shared_ptr< ShapeFactory<Tdim> > ShapeFactory<Tdim>::createFactory(const std::string& str)
{
    //Map
    std::map<std::string, std::shared_ptr< ShapeFactory<Tdim> > > shape_map;
    shape_map.emplace(std::make_pair("triangle", std::make_shared< TriangleFactory<Tdim> >()));
    shape_map.emplace(std::make_pair("rectangle", std::make_shared< RectangleFactory<Tdim> >()));
    shape_map.emplace(std::make_pair("tetrahedron", std::make_shared< TetFactory<Tdim> >()));

    //Try to index, if not throw meaningful error and abort
    try
    {	
    	return shape_map.at(str);
    }
    catch (const std::out_of_range& e)
    {
	std::cerr<<"Entry of shape "<<str<<" not recognized use triangle, rectangle, or tetrahedron.\n";
	std::abort();
    } 
}
