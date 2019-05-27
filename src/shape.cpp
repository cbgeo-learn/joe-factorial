#include"shape.h"

Shape::Shape(const std::string& fname)
{
    io::CSVReader<2> in(fname);
    in.read_header(io::ignore_extra_column, "x", "y");
    double x;
    double y; 
    
    //Loop through the csv file and save x and y coordinates to matrix
    while(in.read_row(x,y))
	pts_.emplace_back(Eigen::Vector2d(x,y));	
}
