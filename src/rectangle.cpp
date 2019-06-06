#include "rectangle.h"

Rectangle::Rectangle(const std::string &fname, const std::string &dim) : Shape(fname, dim)
{
        std::cout<<"Constructor for Rectangle Sub-class\n";
}

double Rectangle::area() const
{
    double area=0;
    std::vector<Eigen::Vector2d>::const_iterator it1;
    //Loop along coordinates
    for (auto it=pts_.begin(); it!=pts_.end(); ++it)
    {
        it1 = ((*it)==pts_.back()) ? pts_.begin() : std::next(it);
	// (xn*yn+1 - yn*xn+1)
        area += ((*it)(0)) * ((*it1)(1)) - ((*it)(1)) * ((*it1)(0));
    }
    return 0.5*std::abs(area);
}                

double Rectangle::volume() const
{
	std::cout<<"Volume of a rectangle is undefined. Returning 0.\n";
	return 0;
}
