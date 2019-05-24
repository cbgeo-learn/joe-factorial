#include"shape.h"

Shape::Shape(int npts)
{
    //Store x and y coordiantes in a nptsx2 matrix of doubles
    Eigen::MatrixXd pts_(npts,2);

    //Assign coordinates
    for (int row=0; row<npts; ++row)
    {
        for (int col=0; col<2; ++col)
	{
		std::cout<<"Please enter the ";
		std::cout<<(col==0 ? "x" : "y");
		std::cout<<" coordiante of the "<<row<<" point: ";
		std::cin>>pts_(row,col);
        }
    }
    std::cout<<pts_; //Prints the matrix as it should
}		

double Shape::area()
{
    double area=0;
    int idn1=0;

    std::cout<<pts_; //Compiles but doesnt print anything
    std::cout<<pts_.rows(); //Says there are 0 Rows
    std::cout<<pts_.cols(); //Says there are 0 Cols

    //Loop along coordinates, until the penultimate row
    for (int idn=0; idn<pts_.rows(); ++idn)
    {   
	idn1 = (idn==(pts_.rows()-1)) ? 0 : idn+1;
	// (xn*yn+1 - yn*xn+1)
        area += (pts_(idn,0) * pts_(idn1,1) - pts_(idn,1) * pts_(idn1,0));
	std::cout<<area<<"\n";
    }
    return 0.5*std::abs(area);
}	
