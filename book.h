#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>
#include <map>


class Book
{
public:
	
        // Enumeration for Genre
        enum Genre
        {
		FICTION,
		NONFICTION,
		PERIODICAL,
		BIOGRAPHY,
		CHILDREN
	};
	
	//Constructor
	Book(	Genre genre,
		const std::string& isbn,
		const std::string& title,
		const std::string& author,
		int copyrightdate,
		bool checkedout);

	//Get genre
	std::string getgenre() const;
	
	//Get isbn
	std::string getisbn() const;

	//Get title
	std::string gettitle() const;

	//Get author
	std::string getauthor() const;

	//Get copyright year (YYYY)
	int getcopyright() const;

	//Is checkedout
	bool ischeckedout() const;

	// Checkin
	void checkout();

	// Checkout
	void checkin();
	
	// Overload == to compare isbn
	bool operator == (const Book& Book_To_Compare);

	// Overload != to compare isbn
	bool operator != (const Book& Book_To_Compare);

	// Overlaod << to print book info
	friend std::ostream& operator<<(std::ostream& os, const Book& Book_To_Print);

private:
	std::string isbn_;
	std::string title_;
	std::string author_;
	std::string genre_;
	int copyrightdate_;
	bool checkedout_;
};
#endif
