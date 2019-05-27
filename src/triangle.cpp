#include"triangle.h"

Triangle::Triangle(const std::string& fname) : Shape(fname)
{
	std::cout<<"Constructor for Triangle Sub-class"<<"\n";
}

double Triangle::area() const
{
    double area=0;
    std::vector<Eigen::Vector2d>::const_iterator it1;

    //Loop along coordinates
    for (std::vector<Eigen::Vector2d>::const_iterator it=pts_.begin(); it!=pts_.end(); ++it)
    {
	it1 = (it==pts_.end()) ? pts_.begin() : std::next(it);
        // (xn*yn+1 - yn*xn+1)
	area += ((*it)(0)) * ((*it1)(1)) - ((*it)(1)) * ((*it1)(0));
    }
    return 0.5*std::abs(area);
}
