#include "datastore.h"
#include "product.h"
#include "user.h"
#include <map>
#include <vector>
#include <string>
#include <set>
#include <vector>

class MyDataStore : public DataStore{
	public:
		MyDataStore();
		~MyDataStore();

		void addProduct(Product* p);
    void addUser(User* u);
    std::vector<Product*> search(std::vector<std::string>& terms, int type);
		void dump(std::ostream& ofile);
		void viewCart(std::string username);
		void addCart(std::string username,Product* br);
		void buyCart(std::string username);

	private:
		std::set<Product*> products_;
		std::map<std::string,User*> users_;
		std::map<std::string,std::vector<Product*>> cart_;
		


};