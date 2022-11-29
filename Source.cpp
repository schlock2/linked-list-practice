//Program written 26/11/22
//An example implementation of a linked list.
#include <iostream>

using namespace std;

class linkedList {
private:
	struct node {
		int value;
		struct node* next;
	};
	struct node* head = NULL;
public:
	//Insertion operations
	void push(int newValue) {
		//pushes a new node to the top of the list
		//new node
		node* newNode = new node;
		//assing that value
		newNode->value = newValue;
		//point to the head
		newNode->next = head;
		//set head to be the new node
		head = newNode;
	}
	void insertEnd(int newValue) {
		node* temp = head;
		node* newNode = new node;
		newNode->value = newValue;
		if (head == NULL) {
			this->push(newValue);
			return;
		}
		while (temp != NULL) {
			if (temp == NULL) {
				return;
			}
			else if (temp->next == NULL) {
				break;
			}
			else {
				temp = temp->next;
			}
		}
		newNode->next = temp->next;
		temp->next = newNode;
		return;
	}
	void insertAfterValue(int afterValue, int newValue) {
		//adds a new node after the first instance of a node with a given value within the list
		node* found = head;
		node* newNode = new node;
		newNode->value = newValue;
		while (found->value != afterValue) {
			found = found->next;
			if (found == NULL) {
				cout << "Cannot insert. There is no value of " << afterValue << " in this list." << endl;
				return;
			}
		}
		newNode->next = found->next;
		found->next = newNode;
		return;
	}
	void insertAfterNode(node* previous, int newValue) {
		node* newNode = new node;
		newNode->value = newValue;
		newNode->next = previous->next;
		previous->next = newNode;
		return;
	}

	//Deletion operations
	void deleteTop() {
		node* temp = head;
		if (head == NULL) {
			cout<<"There are no values in the list to destroy."<<endl;
			return;
		}
		head = head->next;
		delete temp;
	}
	void deleteValue(int targetValue) {
		node* temp = head;
		node* copy = new node;
		if (head == NULL) {
			cout << "Therea re no value in the list to destroy." << endl;
			return;
		}
		if (head->value == targetValue) {
			this->deleteTop();
			return;
		}
		while (temp != NULL) {
			if (temp->next == NULL) {
				cout << "Your value was not found in the list. :(" << endl;
				return;
			}
			else if (temp->next->value == targetValue) {
				break;
			}
			else {
				temp = temp->next;
			}
		}
		copy = temp->next;
		temp->next = copy->next;
		delete copy;
	
	}
	void deleteNode(node* targetNode) {
		node* temp = head;
		if (head == NULL) {
			cout << "That node does not exist inside this list." << endl;
			return;
		}
		while (temp != NULL) {
			if (temp->next == NULL) {
				cout << "That node does not exist inside this list." << endl;
				return;
			}
			else if (temp->next == targetNode) {
				break;
			}
			else {
				temp = temp->next;
			}
		}
		temp->next = targetNode->next;
		delete targetNode;
	}
	void deleteTail() {
		node* temp = head;
		node* copy = new node;
		if (head == NULL) {
			cout << "Nothing to delete ese" << endl;
			return;
		}
		while (temp != NULL) {
			if (temp->next->next == NULL) {
				break;
			}
			else {
				temp = temp->next;
			}
		}
		copy = temp->next;
		temp->next = copy->next;
		delete copy;
	}

	//print functions
	void printList() {
		node* currentNode = head;
		while (currentNode != NULL) {
			cout << currentNode->value<<"-->";
			currentNode = currentNode->next;
		}
		if (currentNode == NULL) {
			cout << "null" << endl;
		}
		return;
	}
	void printHead() {
		if (head == NULL) {
			cout << "null" << endl;
			return;
		}
		cout <<"head:" << head->value << endl;
	}
};

int main() {
	linkedList list;
	list.push(20);
	list.push(40);
	list.push(60);
	list.printList();
	list.insertEnd(10);
	list.printList();
	return 0;
}