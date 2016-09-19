// Andrew Casner HashMap.cc class file

#include "HashMap.h" 
#define SIZE 128

HashMap::HashMap(){
	for(int i = 0; i < SIZE; i++){
		hmap[i] = NULL;
	}
}

HashMap::~HashMap(){
	// Go through each key value and delete the linked list recursively
	// This is done so there are no memory leaks while removing the Hash Map
	for( int i = 0; i < SIZE; i++){
		// Set the current node to the first node in the linked list
		mapNode *myNode = hmap[i];
		while(myNode!=NULL){
			if(myNode->tail!=NULL){
				myNode = myNode->tail;
				delete myNode->head;
			}
			else{
				myNode = NULL;
			}
			
		}

	}	
	// after all of the values in the map have been removed, remove the Hash Map
	delete hmap;
}

bool HashMap::set(std::string keyIN, int * valueIN){
	return false;
}

int* HashMap::get(std::string keyIN){
	int* re;
	return re;
}

int* HashMap::deleteNode(std::string keyIN){
	int* re;
	return re;
}

float HashMap::load(){
	float re;
	return re;
}
