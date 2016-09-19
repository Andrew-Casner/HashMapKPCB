// Andrew Casner KPCB Engineering Fellows Appliction Fall 2016

#include <stdlib>
#include <iostream>
#include "HashMap.cc"

// Class HashMap
class HashMap {
	public:
		HashMap(int);
		~HashMap();
		bool set(std::string, int*);
		int* get(std::string);
		int* deleteNode(std::string);
		float load();

	private:
		struct mapNode(){
			std::string key;
			int value;
			mapNode *head;
			mapNode *tail;
		}
}
