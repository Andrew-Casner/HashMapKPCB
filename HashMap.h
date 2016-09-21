// Andrew Casner KPCB Engineering Fellows Appliction Fall 201
#ifndef HASHMAP_H
#define HASHMAP_H
#include <string>
#include <iostream>

// Struct mapNode
struct mapNode{
	std::string key;
	int *value;
	mapNode *head;
	mapNode *tail;
	mapNode(){};
	mapNode(std::string keyIN, int *valueIN){
		key = keyIN;
		value = valueIN;
		head =NULL;
		tail =NULL;
	};
};

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
		int size;
		mapNode * hmap;
		int hashSum(std::string,int);
};
#endif 
