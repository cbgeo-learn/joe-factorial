#include "rectangle.h"

Rectangle::Rectangle(const std::string &fname) : Shape(fname)
{
        std::cout<<"Constructor for Rectangle Sub-class"<<"\n";
}

double Rectangle::area() const
{
    double area=0;
    int idn1=0;

    //Loop along coordinates, until the penultimate row
    //for (int idn=0; idn<pts_.rows(); ++idn)
    //{
    //    idn1 = (idn==(pts_.rows()-1)) ? 0 : idn+1;
        // (xn*yn+1 - yn*xn+1)
    //    area += (pts_(idn,0) * pts_(idn1,1) - pts_(idn,1) * pts_(idn1,0));
    //}
    return 0.5*std::abs(area);
}                                                
