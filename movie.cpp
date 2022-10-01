#include <iostream>
#include <string>
#include <set>
#include "product.h"
#include <algorithm>
#include <vector>
#include "movie.h"
#include "util.h"

Movie::Movie(std::string name, double price, int qty, std::string genre, int rating):Product("movie",name,price,qty){
	genre_ = genre;
	rating_ = rating;
}
std::set<std::string> Movie:: keywords() const{
	std::set<std::string> keywords = parseStringToWords(getName());
	keywords.insert(genre_);
	return keywords;
}
std::string Movie:: displayString() const{
	std::string s = getName() + "/nGenre:" + genre_ + " Rating: "+std::to_string(rating_)+"\n"+std::to_string(getPrice())+" "+std::to_string(getQty())+" items left.\n";
	return s;
}
void Movie::dump(std::ostream& os) const{
	Product::dump(os);
	os << genre_ <<"\n"<<rating_;
}