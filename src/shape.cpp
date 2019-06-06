#include"shape.h"

Shape::Shape(const std::string& fname, const std::string& dim)
{
    if (dim=="3D")
	{	
    	io::CSVReader<3> in(fname);
    	in.read_header(io::ignore_extra_column, "x", "y", "z");
    	double x;
    	double y; 
	double z;
    
    	//Loop through the csv file and save x and y coordinates to matrix
    	while(in.read_row(x,y,z))
		pts3_.emplace_back(Eigen::Vector3d(x,y,z));	
	}
    else if(dim=="2D")
	{
	io::CSVReader<2> in(fname);
	in.read_header(io::ignore_extra_column, "x", "y");
	double x;
	double y;
	
    	//Loop through the csv file and save x and y coordinates to matrix
    	while(in.read_row(x,y))
		pts_.emplace_back(Eigen::Vector2d(x,y));	
	}
    else
	{
	std::cerr<<"Dimension type "<<dim<<" not recognized. Try 2D or 3D.\n";
	std::abort();
	}
}
