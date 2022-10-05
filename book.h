#include <iostream>
#include <string>
#include <set>
#include "product.h"
#include <algorithm>
#include <vector>

class Book : public Product{
	public:
		Book(std::string name, double price, int qty, std::string author, std::string ISBN);
		~Book();
		std::set<std::string> keywords() const;
		std::string displayString() const;
		void dump(std::ostream& os) const;


	private:
		std::string ISBN_;
		std::string author_;

};