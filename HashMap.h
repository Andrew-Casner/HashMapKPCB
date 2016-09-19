// Andrew Casner KPCB Engineering Fellows Appliction Fall 2016
#ifndef HASHMAP_H
#define HASHMAP_H
#include <string>
#include <iostream>

// Class HashMap
class HashMap{
	public:
		HashMap();
		~HashMap();
		bool set(std::string, int*);
		int* get(std::string);
		int* deleteNode(std::string);
		float load();

	private:
		struct mapNode{
			std::string key;
			int value;
			mapNode *head;
			mapNode *tail;
		};
};
#endif 
