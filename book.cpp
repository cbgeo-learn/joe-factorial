#include "book.h"
#include <string>
#include <iostream>

// Constructor for book class
Book::Book(
	Genre genre,	
	std::string isbn,
	std::string title,
	std::string author,
	int copyrightdate,
	bool checkedout)
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

	genre_ = genre;
	title_ = title;
	author_ = author;
	copyrightdate_ = copyrightdate;
	checkedout_ = checkedout;
}

// Return genre
std::string Book::getgenre() const 
{
	switch (genre_)
	{
		case Book::FICTION:
			return "Fiction";
			break;
		case Book::NONFICTION:
			return "Nonfiction";
			break;
		case Book::PERIODICAL:
			return "Periodical";
			break;
		case Book::BIOGRAPHY:
			return "Biography";
			break;
		case Book::CHILDREN:
			return "Children";
			break;
	}
}

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
bool Book::operator == (const Book &Compare)
{
	if (isbn_.compare(Compare.getisbn()) == 0)
		return true;
	else
		return false;
}

// Overload != to compare isbn
bool Book::operator != (const Book &Compare)
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
