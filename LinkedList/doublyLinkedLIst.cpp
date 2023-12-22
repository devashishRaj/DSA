#include <iostream>
#include <vector>

class Node {
  public:
	int data;
	Node *prev;
	Node *next;

	Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
  private:
	Node *head;
	Node *tail;

  public:
	DoublyLinkedList() : head(nullptr), tail(nullptr) {}

	int get(int index) {
		Node *current;
		int count;

		if (index < 0 || index >= size()) {
			std::cerr << "Index out of bounds\n";
			return -1; // You can choose a different way to handle errors
		}

		if (index <= size() / 2) {
			current = head;
			count = 0;
			while (count < index) {
				current = current->next;
				count++;
			}
		} else {
			current = tail;
			count = size() - 1;
			while (count > index) {
				current = current->prev;
				count--;
			}
		}

		return current->data;
	}

	void insertHead(int val) {
		Node *newNode = new Node(val);

		if (head == nullptr) {
			head = tail = newNode;
		} else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}

	void insertTail(int val) {
		Node *newNode = new Node(val);

		if (tail == nullptr) {
			head = tail = newNode;
		} else {
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
	}

	void insertAt(int index, int val) {
		if (index == 0) {
			insertHead(val);
			return;
		}

		if (index == size()) {
			insertTail(val);
			return;
		}

		Node *newNode = new Node(val);
		Node *current;
		int count;

		if (index <= size() / 2) {
			current = head;
			count = 0;
			while (count < index - 1) {
				current = current->next;
				count++;
			}
		} else {
			current = tail;
			count = size() - 1;
			while (count > index - 1) {
				current = current->prev;
				count--;
			}
		}

		newNode->next = current->next;
		newNode->prev = current;
		current->next->prev = newNode;
		current->next = newNode;
	}

	bool remove(int index) {
		if (index < 0 || index >= size()) {
			std::cerr << "Index out of bounds\n";
			return false;
		}

		Node *current;
		int count;

		if (index == 0) {
			current = head;
			head = head->next;
			if (head != nullptr) {
				head->prev = nullptr;
			} else {
				tail = nullptr; // List becomes empty
			}
			delete current;
		} else if (index == size() - 1) {
			current = tail;
			tail = tail->prev;
			tail->next = nullptr;
			delete current;
		} else {
			if (index <= size() / 2) {
				current = head;
				count = 0;
				while (count < index - 1) {
					current = current->next;
					count++;
				}
			} else {
				current = tail;
				count = size() - 1;
				while (count > index - 1) {
					current = current->prev;
					count--;
				}
			}

			Node *temp = current->next;
			current->next = temp->next;
			temp->next->prev = current;
			delete temp;
		}

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

	int size() {
		int count = 0;
		Node *current = head;

		while (current != nullptr) {
			count++;
			current = current->next;
		}

		return count;
	}
};

int main() {
	DoublyLinkedList myList;

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
