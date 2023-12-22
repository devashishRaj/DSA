#include <iostream>
#include <vector>

class Node {
  public:
	int data;
	Node *prev;
	Node *next;

	Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyCircularLinkedList {
  private:
	Node *head;

  public:
	DoublyCircularLinkedList() : head(nullptr) {}

	int get(int index) {
		if (head == nullptr) {
			std::cerr << "List is empty\n";
			return -1; // You can choose a different way to handle errors
		}

		Node *current = head;
		int count = 0;

		do {
			if (count == index) {
				return current->data;
			}
			current = current->next;
			count++;
		} while (current != head);

		std::cerr << "Index out of bounds\n";
		return -1; // You can choose a different way to handle errors
	}

	void insertHead(int val) {
		Node *newNode = new Node(val);

		if (head == nullptr) {
			head = newNode;
			head->next = head;
			head->prev = head;
		} else {
			newNode->next = head;
			newNode->prev = head->prev;
			head->prev->next = newNode;
			head->prev = newNode;
			head = newNode;
		}
	}

	void insertTail(int val) {
		Node *newNode = new Node(val);

		if (head == nullptr) {
			head = newNode;
			head->next = head;
			head->prev = head;
		} else {
			newNode->next = head;
			newNode->prev = head->prev;
			head->prev->next = newNode;
			head->prev = newNode;
		}
	}

	void insertAt(int index, int val) {
		if (index == 0) {
			insertHead(val);
			return;
		}

		if (head == nullptr) {
			std::cerr << "List is empty\n";
			return;
		}

		Node *newNode = new Node(val);
		Node *current = head;
		int count = 0;

		do {
			if (count == index - 1) {
				newNode->next = current->next;
				newNode->prev = current;
				current->next->prev = newNode;
				current->next = newNode;
				return;
			}
			current = current->next;
			count++;
		} while (current != head);

		std::cerr << "Index out of bounds\n";
	}

	bool remove(int index) {
		if (head == nullptr) {
			std::cerr << "List is empty\n";
			return false;
		}

		if (index == 0) {
			Node *current = head;
			if (head->next == head) {
				// List has only one element
				delete head;
				head = nullptr;
			} else {
				head->prev->next = head->next;
				head->next->prev = head->prev;
				head = head->next;
				delete current;
			}
			return true;
		}

		Node *current = head;
		int count = 0;

		do {
			if (count == index - 1) {
				Node *temp = current->next;
				current->next = temp->next;
				temp->next->prev = current;
				delete temp;
				return true;
			}
			current = current->next;
			count++;
		} while (current != head);

		std::cerr << "Index out of bounds\n";
		return false;
	}

	std::vector<int> getValues() {
		std::vector<int> values;
		Node *current = head;

		if (current != nullptr) {
			do {
				values.push_back(current->data);
				current = current->next;
			} while (current != head);
		}

		return values;
	}
};

int main() {
	DoublyCircularLinkedList myList;

	// Insert elements at the head
	myList.insertHead(3);
	myList.insertHead(2);
	myList.insertHead(1);

	// Insert elements at the tail
	myList.insertTail(4);
	myList.insertTail(5);

	// Insert element at a specific index
	myList.insertAt(2, 10);

	// Print all values in the list
	std::cout << "List values: ";
	for (int value : myList.getValues()) {
		std::cout << value << " ";
	}
	std::cout << "\n";

	// Get and print values at specific indices
	std::cout << "Value at index 2: " << myList.get(2) << "\n";

	// Remove element at a specific index
	myList.remove(1);

	// Print values after removal
	std::cout << "List values after removal: ";
	for (int value : myList.getValues()) {
		std::cout << value << " ";
	}
	std::cout << "\n";

	return 0;
}
