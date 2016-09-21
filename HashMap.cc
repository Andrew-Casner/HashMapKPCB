// Andrew Casner HashMap.cc class file

#include "HashMap.h" 
#define SIZE 128

HashMap::HashMap(){
	// Default Size
	hmap = new mapNode[SIZE]; 
}

HashMap::HashMap(int sizeIN){
	size = sizeIN;
	hmap = new mapNode[size]; 
}

HashMap::~HashMap(){
	//Destructor goes here
}

bool HashMap::set(std::string keyIN, int * valueIN){
	// Helper variables
	mapNode *temp;
	// Create Hash Element
	mapNode * newNode = new mapNode(keyIN, valueIN);
	int index = hashSum(newNode->key, size);
	// Insert into table
	if(hmap[index].value == NULL){
		hmap[index] = *newNode;
		std::cout << "Here" << std::endl;
		elements++;
		return true;
	}
	else {
		temp = &hmap[index];
		while(temp->tail != NULL){
			temp = temp->tail;
		}	
		temp->tail = newNode;
		temp->tail->head = temp;
		std::cout << "Here 2" << std::endl;
		elements++;
		return true;
	}
	// Failed to creatd newNode
	return false;
}

int* HashMap::get(std::string keyIN){
	// Helper variables
	bool found = !true;
	int *value;
	mapNode *temp;
	// Get Element
	int i = hashSum(keyIN, size);
	if(hmap[i].value != NULL){
		if(hmap[i].key == keyIN){
			value = hmap[i].value;
			found = true;
		}
		else{
			temp = &hmap[i];
			while(temp->tail != NULL){
				temp = temp->tail;
				if(temp->key == keyIN){
					value = temp->value;
					found = true;
					break;
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
	// Helper variables
	bool found = !true;
	int *value;
	mapNode *temp;
	// Get Element
	int i = hashSum(keyIN, size);
	if(hmap[i].value != NULL){
		if(hmap[i].key == keyIN){
			value = hmap[i].value;
			found = true;
		}
		else{
			temp = &hmap[i];
			while(temp->tail != NULL){
				temp = temp->tail;
				if(temp->key == keyIN){
					value = temp->value;
					found = true;
					// Delete node
					temp->head->tail = temp->tail;
					delete temp;
					break;
				}
			}
		}
	}
	if(found){
		elements--;
		return value;
	}
	else{
		return NULL;
	}
}

float HashMap::load(){
	float load = elements/size;
	return load;
}

int HashMap::hashSum(std::string keyIN, int tableSize){
	// Basic Hash function that sums up all of the ASCII values
	// of the chars in the string and then mods them by the 
	// length of the hash map
	tableSize--;
	int sum = 0;
	for(int i = 0; i < keyIN.length(); i++){
		sum = sum + keyIN.at(i);
	}
	sum = sum % tableSize;
	return sum;
}
