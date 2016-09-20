// Andrew Casner KPCB Engineering Fellows Application Fall 2016 Main Class

#include <iostream>
#include "HashMap.cc"

int main(int argc,char *argv[]){
	HashMap *hMap = new HashMap();
	int a = 10;
	int b = 11;
	hMap->set("hi", &a);
	hMap->set("here", &b);
	std::cout << hMap->get("here") << std::endl;
}

