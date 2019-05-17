#include <iostream>
#include "book.h"

int main()
{
	Book example1=Book(	Book::FICTION,
				"123-45-67891-01-1",
				"Hitchhikers Guide",
				"Scott Adams",
				1776,
				true);
	std::cout<<example1<<"\n";

	std::cout<<((example1.ischeckedout()==true) ? "Checked Out" : "Checked In")<<"\n";
	example1.checkin();
	std::cout<<((example1.ischeckedout()==true) ? "Checked Out" : "Checked In")<<"\n";

	Book example2 = Book(	Book::CHILDREN,
				"234-56-78910-00-0",
				"Where the wild things are",
				"Patrick Sendec",
				2000,
				false);
	std::cout<<example2<<"\n";

	std::cout<<"False - 0 "<<(example1==example2) << "\n";

	Book example3 = Book(	Book::BIOGRAPHY,
                                "123-45-67891-01-1",
                                "Rebel Yell",
                                "Unkown",
                                2015,
                                true);
	std::cout<<example3<<"\n";

	std::cout<<"True -1 "<<(example1==example3)<<"\n";
	std::cout<<"True - 1 "<<(example1!=example2)<<"\n";
	std::cout<<"False - 0 "<<(example1!=example3)<<"\n";
}
