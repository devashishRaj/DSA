#include <iostream>
#include <vector>

class Node {
  public:
	int data;
	Node *next;

	Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
  private:
	Node *head;

  public:
	LinkedList() : head(nullptr) {}

	int get(int index) {
		Node *current = head;
		int count = 0;

		while (current != nullptr) {
			if (count == index) {
				return current->data;
			}
			current = current->next;
			count++;
		}

		std::cerr << "Index out of bounds\n";
		return -1; // You can choose a different way to handle errors
	}

	void insertHead(int val) {
		Node *newNode = new Node(val);
		newNode->next = head;
		head = newNode;
	}

	void insertTail(int val) {
		Node *newNode = new Node(val);

		if (head == nullptr) {
			head = newNode;
			return;
		}

		Node *current = head;
		while (current->next != nullptr) {
			current = current->next;
		}

		current->next = newNode;
	}

	void insertAt(int index, int val) {
		if (index == 0) {
			insertHead(val);
			return;
		}

		Node *newNode = new Node(val);
		Node *current = head;
		int count = 0;

		while (current != nullptr && count < index - 1) {
			current = current->next;
			count++;
		}

		if (current == nullptr) {
			std::cerr << "Index out of bounds\n";
			return;
		}

		newNode->next = current->next;
		current->next = newNode;
	}

	bool remove(int index) {
		if (head == nullptr) {
			std::cerr << "List is empty\n";
			return false;
		}

		if (index == 0) {
			Node *temp = head;
			head = head->next;
			delete temp;
			return true;
		}

		Node *current = head;
		int count = 0;

		while (current != nullptr && count < index - 1) {
			current = current->next;
			count++;
		}

		if (current == nullptr || current->next == nullptr) {
			std::cerr << "Index out of bounds\n";
			return false;
		}

		Node *temp = current->next;
		current->next = current->next->next;
		delete temp;

		return true;
	}

	std::vector<int> getValues() {
		std::vector<int> values;
		Node *current = head;

		while (current != nullptr) {
			values.push_back(current->data);
			current = current->next;
		}

		return values;
	}
};
int main() {
	LinkedList myList;

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