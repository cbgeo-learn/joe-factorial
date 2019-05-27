#include"triangle.h"

Triangle::Triangle(const std::string& fname) : Shape(fname)
{
	std::cout<<"Constructor for Triangle Sub-class"<<"\n";
}

double Triangle::area() const
{
    double area=0;
    int idn1=0;

    //Loop along coordinates, until the penultimate row
    for (std::vector<Eigen::Vector2d>::const_iterator it=pts_.begin(); it!=pts_.end(); ++it)
    {
	std::cout<<(*it)(0)<<","<<(*it)(1)<<"\n";
	
	//idn1 = (idn==(pts_.end-1)) ? 0 : idn+1;
        // (xn*yn+1 - yn*xn+1)
        //area += (pts_(idn,0) * pts_(idn1,1) - pts_(idn,1) * pts_(idn1,0));
    }
    return 0.5*std::abs(area);
}
