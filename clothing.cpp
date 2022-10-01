#include <iostream>
#include <string>
#include <set>
#include "product.h"
#include <algorithm>
#include <vector>
#include "clothing.h"
#include "util.h"

Clothing::Clothing(std::string name, double price, int qty, std::string size, std::string brand):Product("clothing",name,price,qty){
	size_ = size;
	brand_ = brand;
}
std::set<std::string> Clothing:: keywords() const{
	std::set<std::string> keywords = parseStringToWords(getName());
	keywords.insert(brand_);
	return keywords;
}
std::string Clothing:: displayString() const{
	std::string s = getName() + "/nSize:" + size_ + " brand: "+brand_+"\n"+std::to_string(getPrice())+" "+std::to_string(getQty())+" items left.\n";
	return s;
}
void Clothing::dump(std::ostream& os) const{
	Product::dump(os);
	os << size_ <<"\n"<<brand_;
}