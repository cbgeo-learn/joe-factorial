#include"shape.h"

Shape::Shape(const std::string& fname)
{
    //Open file (fname) to file stream object
    std::ifstream file_stream;
    file_stream.open(fname);
    
    //Check to be sure file was opened
    if (!file_stream)
    {
	std::cerr<<"Unable to open file "<<fname<<".\n";
	std::abort();
    }

    const int maxline=256;
    char ncoord_s[maxline];

    // int ncoord;
    file_stream.getline(ncoord_s, maxline);
    //std::cout<<ncoord_s<<"\n";

    int ncoord_i;
    ncoord_i = atoi(ncoord_s);
    //std::cout<<ncoord_i<<"\n";
    
    char coord[maxline];
    pts_.resize(ncoord_i, 2);
    double value;
    for(int row=0; row<ncoord_i; ++row)
    {
	for (int col=0; col<2; ++col)
	{
            file_stream.getline(coord, maxline);
	    pts_(row,col) = atof(coord);
	}
    }

    //Close file stream object
    file_stream.close();
    
    //Print pts_	
    std::cout<<pts_<<"\n";
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
