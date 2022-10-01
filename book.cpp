#include <iostream>
#include <string>
#include <set>
#include "product.h"
#include <algorithm>
#include <vector>
#include "book.h"
#include "util.h"

Book::Book(std::string name, double price, int qty, std::string author, int ISBN):Product("book",name,price,qty){
	ISBN_ = ISBN;
	author_ = author;
}
std::set<std::string> Book:: keywords() const{
	std::set<std::string> keywords = parseStringToWords(getName());
	keywords.insert(std::to_string(ISBN_));
	keywords.insert(std::to_string(author_));
	return keywords;
}
std::string Book:: displayString() const{
	std::string s = getName() + "/nAuthor:" + author_ + " ISBN: "+std::to_string(ISBN_)+"\n"+std::to_string(getPrice())+" "+std::to_string(getQty())+" items left.\n";
	return s;
}
void Book::dump(std::ostream& os) const{
	Product::dump(os);
	os << author_ <<"\n"<<ISBN_;
}


