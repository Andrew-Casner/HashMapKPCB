// Andrew Casner HashMap.cc class file

#include "HashMap.h" 
#define SIZE 128

HashMap::HashMap(){
	//set all spots to NULL
	for(int i = 0; i < SIZE; i++){
		hmap[i] = NULL; 
	}
}

HashMap::~HashMap(){
	//Destructor goes here
}

bool HashMap::set(std::string keyIN, int * valueIN){
	// Helper variables
	mapNode *temp;
	// Create Hash Element
	mapNode * newNode = new mapNode(keyIN, valueIN);
	int index = hashSum(newNode->key, SIZE);
	// Insert into table
	if(hmap[index] == NULL){
		hmap[index] = newNode;
		std::cout << "Here" << std::endl;
		return true;
	}
	else {
		temp = hmap[index];
		while(temp->tail != NULL){
			temp = temp->tail;
		}	
		temp->tail = newNode;
		temp->tail->head = temp;
		std::cout << "Here 2" << std::endl;
		return true;
	}
	// Failed to creatd newNode
	return false;
}

int* HashMap::get(std::string keyIN){
// IM DUMB AND DIDINT OPTIMIZE IT NEED TO GO BACK AND DO THAT
	// Helper variables
	bool found = !true;
	int *value;
	mapNode *temp;
	// Get Element
	for(int i = 0; i < SIZE;i++){
		if(hmap[i] != NULL){
			if(hmap[i]->key == keyIN){
				value = hmap[i]->value;
				found = true;
				break;
			}
			else{
				temp = hmap[i];
				while(temp->tail != NULL){
					temp = temp->tail;
					if(temp->key == keyIN){
						value = hmap[i]->value;
						found = true;
						break;
					}
				}
			}
		}
	}
	if(found){
		return value;
	}
	else{
		return NULL;
	}
}

int* HashMap::deleteNode(std::string keyIN){
	int* re;
	return re;
}

float HashMap::load(){
	float re;
	return re;
}

int HashMap::hashSum(std::string keyIN, int tableSize){
	return 1;
}
