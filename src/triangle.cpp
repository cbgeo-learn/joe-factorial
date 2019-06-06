#include"triangle.h"

Triangle::Triangle(const std::string& fname, const std::string& dim) : Shape(fname, dim)
{
	std::cout<<"Constructor for Triangle Sub-class"<<"\n";
}

double Triangle::area() const
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

double Triangle::volume() const
{
	std::cout<<"Volume of a Triangle is undefined. Returing 0."<<"\n";
	return 0;
}
