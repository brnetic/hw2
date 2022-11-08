#include "datastore.h"
#include "product.h"
#include "user.h"
#include <map>
#include <vector>
#include <string>
#include <set>
#include <vector>
#include "mydatastore.h"
#include "util.h"

MyDataStore :: MyDataStore(){

}
MyDataStore :: ~MyDataStore(){
	std::set<Product*>::iterator it = products_.begin();
	for(it;it != products_.end();++it){
		delete *it;
		
	}
	products_.clear();
	std::map<std::string,User*>::iterator it1 = users_.begin();
	for(it1;it1 != users_.end();++it1){
		delete (*it1).second;
		
	}
}
void MyDataStore :: addProduct(Product* p){
	products_.insert(p);
}
void MyDataStore :: addUser(User* u){
	users_.insert(std::pair<std::string,User*>(convToLower(u->getName()),u));

	std::vector<Product*> br;
	cart_.insert(std::pair<User*,std::vector<Product*>>(u,br));
}

std::vector<Product*> MyDataStore :: search(std::vector<std::string>& terms, int type){
	std::set<std::string> in;
	std::vector<Product*> out;
	for(std::vector<std::string> :: iterator it = terms.begin();it != terms.end();++it){
		in.insert(*it);
	}
	if(type == 1){
		for(std::set<Product*>:: iterator it = products_.begin();it != products_.end();++it){
			std::set<std::string> prod = (*it)->keywords();
			std::set<std::string> both = setIntersection(in,prod);
			if(both.size()> 0){
				out.push_back(*it);
			}

		}
	}
	else if(type == 0){
		for(std::set<Product*>:: iterator it = products_.begin();it != products_.end();++it){
			std::set<std::string> prod = (*it)->keywords();
			std::set<std::string> both = setIntersection(in,prod);
			if(both.size() == in.size()){
				out.push_back(*it);
			}

		}
	}
	else{
		std::cout<<"Invalid type"<<std::endl;
	}
	return out;
}

void MyDataStore :: dump(std::ostream& ofile){
	ofile<<"<products>"<<std::endl;
	for(std::set<Product*> :: iterator it = products_.begin();it != products_.end();++it){
		(*it)->dump(ofile);
		ofile<<std::endl;
	}
	ofile<<"</products>"<<std::endl<<"<users>"<<std::endl;
	for(std::map<std::string,User*> :: iterator it = users_.begin();it != users_.end();++it){
		(*it).second->dump(ofile);
		//ofile<<std::endl;
	}
	ofile<<"</users>";
}

void MyDataStore :: viewCart(std::string username){
	if(users_.find(username) != users_.end()){
		
		std::vector<Product*> :: iterator it = cart_.find(users_[username])->second.begin();
		for(it;it != cart_.find(users_[username])->second.end();++it){
			std::cout<<(*it)->displayString()<<" ";

		}
		std::cout<<std::endl;
	}
}

void MyDataStore :: addCart(std::string username,Product* br){
	if(users_.find(username) != users_.end() && products_.find(br) != products_.end()){
		cart_.find(users_[username])->second.push_back(br);
	}
	else{
		std::cout<<"This username doesn't exist"<<std::endl;
	}
}
void MyDataStore :: buyCart(std::string username){
	if(users_.find(username) != users_.end()){
		User* u = users_[username];
		std::vector<Product*> :: iterator it = cart_.find(users_[username])->second.begin();
		for(it;it != cart_.find(users_[username])->second.end();++it){
			if((*it)->getQty()> 0 && u->getBalance() - (*it)->getPrice() > 0){
				u->deductAmount((*it)->getPrice());
				(*it)->subtractQty(1);
			}
			else{
				std::cout<<"The product: " + (*it)->getName() + "is sold out or you don't have enough money to purchase it"<<std::endl;
				
			}
			

		}
		
		for(int i = 0;i < cart_[users_[username]].size();i++){
			(cart_[users_[username]]).pop_back();
		}
	}
	else{
		std::cout<<"You entered an invalid username"<<std::endl;
	}
}

