#include "book.h"

// Constructor for book class
Book::Book(
	Genre genre,	
	const std::string& isbn,
	const std::string& title,
	const std::string& author,
	int copyrightdate,
	bool checkedout) : title_{title}, author_{author}
{
	// Check isbn before assignment
	bool pass=true;
	if (isbn.length()!=17)
		std::cout<<"ISBN must be of length 17 not "<<isbn.length()<<".\n";
	else
	{	
		for (int index=0; index<isbn.length(); index++)
		{
			if (index==3 | index==6 | index==12 | index==15) //Hypen locations
				pass = (isbn.at(index)=='-') ? pass : false;
			else
				pass = (isdigit(isbn.at(index))) ? pass : false;
		}
	}

	if (pass)
		isbn_ = isbn;
	else
	{
		isbn_ = "000-00-00000-00-0";
		std::cout<<"ISBN is not valid, reverting to default "<<isbn_<<".\n";
	}

	copyrightdate_=copyrightdate;
	checkedout_=checkedout;

	//Add map
	std::map<Genre, std::string> genre_map;
	genre_map.emplace(std::make_pair(FICTION, "Fiction"));
	genre_map.emplace(std::make_pair(NONFICTION, "Nonfiction"));
	genre_map.emplace(std::make_pair(PERIODICAL, "Periodical"));
	genre_map.emplace(std::make_pair(BIOGRAPHY, "Biography"));
	genre_map.emplace(std::make_pair(CHILDREN, "Children"));	
	
	//Assigne value to genre_
	genre_=genre_map.at(genre);
}

// Return genre
std::string Book::getgenre() const {return genre_;}

// Return isbn
std::string Book::getisbn() const {return isbn_;}

// Return title
std::string Book::gettitle() const {return title_;}

// Return author
std::string Book::getauthor() const {return author_;}

// Return copyright date
int Book::getcopyright() const {return copyrightdate_;}

// Return checked in status
bool Book::ischeckedout() const {return checkedout_;} 

// Book checkin
void Book::checkin() {checkedout_=false;}

// Book checkout
void Book::checkout() {checkedout_=true;}

// Overload == to compare isbn
bool Book::operator == (const Book& Compare)
{
	if (isbn_.compare(Compare.getisbn()) == 0)
		return true;
	else
		return false;
}

// Overload != to compare isbn
bool Book::operator != (const Book& Compare)
{
	if (isbn_.compare(Compare.getisbn())==0)
		return false;
	else
		return true;
}

// Overlaod << to print out book information
std::ostream& operator<<(std::ostream& os, const Book& Book)
{
	os
	<<"Genre:  \t"<<Book.getgenre()<<"\n"
	<<"Title:  \t"<<Book.gettitle()<<"\n"
	<<"Author: \t"<<Book.getauthor()<<"\n"
	<<"ISBN:   \t"<<Book.getisbn()<<"\n"
	<<"CRDate: \t"<<Book.getcopyright()<<"\n"
	<<"Chkdout:\t"<<Book.ischeckedout()<<"\n";
	return os;
}
