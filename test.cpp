#include <iostream>
#include <iostream>
#include <sstream>
#include <cctype>
#include <set>
#include <algorithm>
#include "util.h"

using namespace std;




int main(){
	set<int> L;
	set<int> B;
	set<int> A;
	L.insert(1);
	L.insert(2);
	L.insert(3);
	B.insert(2);
	B.insert(3);
	B.insert(4);
	A = setUnion(L,B);
	set <int>::iterator i;
	for(i = A.begin(); i != A.end();++i){
		cout<<*i<<endl;
	}


	return 0;
}