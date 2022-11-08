#include <iostream>
#include <string>
#include <set>
#include "product.h"
#include <algorithm>
#include <vector>
#include "book.h"
#include "util.h"

Book::Book(std::string name, double price, int qty, std::string author, std::string ISBN):Product("book",name,price,qty){
	ISBN_ = ISBN;
	author_ = author;
}
Book::~Book(){
	
}
std::set<std::string> Book:: keywords() const{
	std::set<std::string> keywords = parseStringToWords(convToLower(getName()+" "+author_));
	keywords.insert(ISBN_);
	return keywords;
	
}
std::string Book:: displayString() const{
	std::string s = getName() +  "\nAuthor: " + author_ + " ISBN: "+ISBN_+"\n"+std::to_string(getPrice()).substr(0,5)+" "+std::to_string(getQty())+" items left.\n";
	return s;
}
void Book::dump(std::ostream& os) const{
	Product::dump(os);
	os << ISBN_ <<"\n"<<author_;
}


