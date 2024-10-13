#include <iostream>
#include <string>
#include <cmath>
// You are free to use additional libraries as long as it's not PROHIBITED per instruction.

using namespace std;


struct hash_node {
	int key;
	string data;
	hash_node* next;
	hash_node* prev;
};


class Node{ 

public:
	int hashValue;
	int data;
	string text;
	Node* next;

	Node() { 
	data = 0;
	next = NULL;
	}

	Node(int data) { 
	this->data = data;
	this->next = NULL; 
	}

	Node(string text) { 
	this->next = NULL; 
	this->text = text;
	}

};

class linkedList{ 

Node* head;

public:

	//constructor 
	linkedList() {head = NULL;}
	void addNode(const string); 
	void removeNode(const int);
	void insertNode(int, int);
	void printList();
	void createLinkedList();

};


class hashMap { 

Node* head;

	private:
		int hash;
		int hashTableSize;
		double hashTotal;
		//double mean;
	public:

		int* slotSize;
		//Array of nodes
		Node** testHash;

		//array of nodes
		hash_node **hashTable, **top;

		//create a empty hashTable
		hashMap(const int& hashTableSize) { 
			head = NULL;
			this->hashTableSize = hashTableSize;
			//hashTable = new Node*(hashTableSize);
			slotSize = new int[hashTableSize];

			//option 1 
			testHash = new Node*[hashTableSize];
			for (int i = 0; i < hashTableSize; i++) {
				testHash[i] = NULL;
			}

			//using option 2
			//option 2
			hashTable = new hash_node*[hashTableSize];
			for (int i = 0; i < hashTableSize; i++) {
				hashTable[i] = NULL;
			}
		}

		//Deconstructor
		~hashMap() {
			delete[] testHash;

		}


		//declarations
		int hash_function(const string&);
		void insertItem(const string&);
		void printSlotSize();
		void std();
		void print();



		void addNodeTwo(const string); 
		int insert(string, int);
		void removeNode(const int);
		void insertNode(int, int);
		void printList();
		void createLinkedList();


};




