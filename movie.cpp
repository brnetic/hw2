#include <iostream>
#include <string>
#include <set>
#include "product.h"
#include <algorithm>
#include <vector>
#include "movie.h"
#include "util.h"

Movie::Movie(std::string name, double price, int qty, std::string genre, std::string rating):Product("movie",name,price,qty){
	genre_ = genre;
	rating_ = rating;
}
Movie::~Movie(){

}
std::set<std::string> Movie:: keywords() const{
	std::set<std::string> keywords = parseStringToWords(convToLower(getName()));
	keywords.insert(convToLower(genre_));
	return keywords;
}
std::string Movie:: displayString() const{
	std::string s = getName() + "\nGenre:" + genre_ + " Rating: "+rating_+"\n"+std::to_string(getPrice()).substr(0,5)+" "+std::to_string(getQty())+" items left.\n";
	return s;
}
void Movie::dump(std::ostream& os) const{
	Product::dump(os);
	os << genre_ <<"\n"<<rating_;
}