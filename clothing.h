#include <iostream>
#include <string>
#include <set>
#include "product.h"
#include <algorithm>
#include <vector>

class Clothing : public Product{
	public:
		Clothing(std::string name, double price, int qty, std::string size, std::string brand);
		~Clothing();
		std::set<std::string> keywords() const;
		std::string displayString() const;
		void dump(std::ostream& os) const;


	private:
		std::string size_;
		std::string brand_;

};