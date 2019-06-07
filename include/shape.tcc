template<const int Tdim>
Shape<Tdim>::Shape(const std::string& fname)
{
    io::CSVReader<Tdim> in(fname);
    if (Tdim==3)
    {
	in.read_header(io::ignore_extra_column, "x", "y", "z");
    	double x;
    	double y; 
	double z;
    
    	//Loop through the csv file and save x and y coordinates to matrix
    	while(in.read_row(x,y,z))
		pts_.emplace_back(Eigen::Matrix<double, Tdim, 1>(x,y,z));	
    }
    else if(Tdim==2)
    {
	in.read_header(io::ignore_extra_column, "x", "y");
	double x;
	double y;
	
    	//Loop through the csv file and save x and y coordinates to matrix
    	while(in.read_row(x,y))
		pts_.emplace_back(Eigen::Matrix<double, Tdim, 1>(x,y));	
    }
    else
    {
	std::cerr<<"Dimension type "<<Tdim<<" not recognized. Try 2 or 3.\n";
	std::abort();
    }
}
