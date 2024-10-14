#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

//const int PRIME_CONST = 81;

int hashMap::hash_function(const string& text) {
    // Implement your own hash function here
    int length = text.length();
    int hash_value = 0;
  
    int r = 0;
    long m = 1;
    for (int i = 0; i < text.length(); i++) {
        m = (i % 2 == 0) ? 1 : m * 256;
        hash_value += text[i] * m;
    }

    hash_value = abs(hash_value);
    hash_value  %= hashTableSize;
    
    return hash_value ;

}

void hashMap::insertItem(const string& key) { 
    int index  = hash_function(key);
    //COUNTER FOR SLOT SIZE
    slotSize[index] ++;

        //Node* entry = testHash[index];
        Node* newNode = new Node();
        newNode->text = key;

     if(testHash[index] == NULL ) {
        testHash[index] = newNode;
        
     }else { 
            Node* temp = testHash[index];
        while(temp->next != NULL) { 
            temp = temp->next;
        }
        temp->next = newNode;
     }
}

void hashMap:: printSlotSize() { 
    for(int i = 0;i < hashTableSize ;i++) { 
        cout << "SLOT " << i+1 << ": " << slotSize[i] << endl; 
    }  
    //cout << "total is " << hashTotal << endl; 
}


void hashMap::std() { 
    double variance = 0;
    double std;
    double sum;

    for(int i = 0; i < hashTableSize;i++) { 
        sum += slotSize[i];
    }
   // cout << "TableSize total is: " << sum << endl;

    //calculate mean
    double mean = sum / hashTableSize;
    //cout << "Mean is: " << mean << endl;

    for(int i = 0; i < hashTableSize;i++) { 
        //Node* entry = testHash[i];
        //while(entry != NULL){ 
            variance += pow(slotSize[i] - mean,2);
           //entry = entry->next;
        //}
    }
    variance /= hashTableSize;

    std = sqrt(variance);
    cout << "standard deviation: " << std << endl;
    cout << endl;
}

void hashMap:: print() { 
   // cout << "The hash table size is: " << hashTableSize << endl;
    for(int i = 0; i < 5 ; i++) { 
        Node* entry = testHash[i];
        cout << "SLOT " << i+1 << ": ";
        if(entry == NULL) { 
            cout << "EMPTY"; 
        } else { 
            while(entry != NULL) { 
                cout << entry->text << " --> ";
                entry = entry->next;
                //<< hash_function(entry->text)
            }
        }
        cout << endl;       
    }
}


void hashMap::addNodeTwo(const string text) { 
    int index  = hash_function(text);
   
    Node* newNode = new Node(text);
    Node* tail = NULL;
    if(head == NULL) { 
        head = newNode;
        newNode->next = NULL;  
    }else{ 
        Node* current = head; 
        while(current -> next != NULL){ 
        current = current->next;
    }
    current->next = newNode;
     
    }
}
void linkedList::removeNode(const int index) { 

        Node* current = head;
        Node* tail = NULL;

    if (index  == 0 ){ 
        head = head->next;
    }else { 

        for(int i = 0 ; i < index && current != NULL; i++) { 
            tail = current;
            current = current->next;

        }
        if(current != NULL) { 
            tail->next = current->next;

        }   
    }
}
void linkedList::insertNode(int position, int data) { 

Node* current = head;
Node* tail =    NULL;
Node* newNode = new Node(data);
    //case1
    if(position == 0){ 
        newNode->next = head;
        head = newNode;
    }else { 
    //case two
        for(int i = 0; i < position - 1 && current != NULL; i++) { 
            //tail = current;
            current = current->next;

        }
        if (current != NULL) { 
            newNode->next = current->next;
            current->next = newNode;
        }

        //tail->next = newNode;
        //newNode->next = current;
    }
}
void linkedList::createLinkedList() {

        Node* node1 = new Node(11);
        head = node1;

        Node* node2 = new Node(18);
        node1->next = node2;

        Node* node3 = new Node(24);
        node2->next = node3;
}
void hashMap::printList() { 
    Node* current = head;
    while(current != NULL){ 
        cout << current->text << "-->";
        current = current->next;
    }
    cout << "\n";
} 


