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
    
    //Number of coordiantes string
    char ncoord_s[maxline];
    file_stream.getline(ncoord_s, maxline);

    //Number of coordiantes integer
    int ncoord_i;
    ncoord_i = atoi(ncoord_s);
    
    //Loop through the csv file and save x and y coordinates to matrix
    char coord[maxline];
    pts_.resize(ncoord_i, 2);
    double value;
    for(int row=0; row<ncoord_i; ++row)
    {
	for (int col=0; col<2; ++col)
	{
            file_stream.getline(coord, maxline,',');
	    pts_(row,col) = atof(coord);
	}
    }

    //Close file stream object
    file_stream.close();
}

Eigen::MatrixXd Shape::pts() const {return pts_;}		
