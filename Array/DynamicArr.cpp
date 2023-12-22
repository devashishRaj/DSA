// Dynamic array of int type
/*
	Your DynamicArray class should support the following operations:

	DynamicArray(int capacity) will initialize an empty array with a capacity of capacity, where
   capacity > 0. int get(int i) will return the element at index i. Assume that index i is valid.
	void set(int i, int n) will set the element at index i to n. Assume that index i is valid.
	void pushback(int n) will push the element n to the end of the array.
	nt popback() will pop and return the element at the end of the array. Assume that the array is
   non-empty. void resize() will double the capacity of the array. int getSize() will return the
   number of elements in the array. int getCapacity() will return the capacity of the array. If we
   call void pushback(int n) but the array is full, we should resize the array first.

*/

#include <iostream>

class DynamicArray {
  private:
	int *arr;
	int capacity;
	int size;

  public:
	DynamicArray(int initialCapacity) {
		capacity = initialCapacity;
		arr = new int[capacity];
		size = 0;
	}

	~DynamicArray() { delete[] arr; }

	int get(int i) {
		if (i < 0 || i >= size) {
			std::cerr << "Index out of bounds\n";
			return -1;
		}
		return arr[i];
	}

	void set(int i, int n) {
		if (i < 0 || i >= size) {
			std::cerr << "Index out of bounds\n";
			return;
		}
		arr[i] = n;
	}

	void pushBack(int n) {
		if (size == capacity) {
			resize();
		}
		arr[size++] = n;
	}

	int popBack() {
		if (size == 0) {
			std::cerr << "Array is empty\n";
			return -1;
		}
		return arr[--size];
	}

	void resize() {
		capacity *= 2;
		int *newArr = new int[capacity];
		for (int i = 0; i < size; ++i) {
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
	}

	int getSize() { return size; }
	int getCapacity() { return capacity; }
};

int main() {
	// Example usage
	DynamicArray myArray(5);

	for (int i = 0; i < 10; ++i) {
		myArray.pushBack(i);
	}

	std::cout << "Array size: " << myArray.getSize() << "\n";
	std::cout << "Element at index 3: " << myArray.get(3) << "\n";
	myArray.set(5, 100);
	std::cout << "Element at index 5 after set: " << myArray.get(5) << "\n";

	while (myArray.getSize() > 0) {
		std::cout << "Popped element: " << myArray.popBack() << "\n";
	}

	return 0;
}
