// Fixed size Single dimimension array ADT :

/*
	Functionality
	1.SET(int index , T element)
	2.GET(int index)
	Operations
	1.Max()
	2.Show()
	3.Min()
	4.Search(T element)
	5.Insert(int index , T element)
	6.DeleteAt(int index)
	7.Delete(T element)


*/

// NOTE:Implement usize var for used size(how many cells are filled) value this provide extra checks
// and optimizations. Current problem to check whether cell of type T is filled or not we need to
// set the whole array at initlization with some null value depending upon the type.

#include <iostream>

template <typename T, int size> class FixedArray {
  private:
	T *array;

  public:
	FixedArray() { array = new T[size]; }
	~FixedArray() { delete[] array; }
	void SET(int index, T element);
	T GET(int index);
	T Max();
	void Show();
	T Min();
	void Search(T element);
	void Insert(int index, T element);
	void DeleteAt(int index);
	void Delete(T element);
};

template <typename T, int size> void FixedArray<T, size>::SET(int index, T element) {
	if (index < 0 || index >= size) {
		std::cout << "Index out of bounds" << '\n';
		return;
	}
	array[index] = element;
}

template <typename T, int size> T FixedArray<T, size>::GET(int index) {
	if (index < 0 || index >= size) {
		std::cout << "Index out of bounds" << '\n';
	}

	return array[index];
}

template <typename T, int size> T FixedArray<T, size>::Max() {
	T temp = array[0];
	for (int i{0}; i < size; i++) {
		if (temp < array[i]) {
			temp = array[i];
		}
	}
	return temp;
}

template <typename T, int size> void FixedArray<T, size>::Show() {
	for (int i{0}; i < size; i++) {
		std::cout << "Index " << i << " Element " << array[i] << '\n';
	}
}

template <typename T, int size> T FixedArray<T, size>::Min() {
	T temp = array[0];
	for (int i{0}; i < size; i++) {
		if (temp > array[i] && array[i] != 0) {
			temp = array[i];
		}
	}
	return temp;
}
template <typename T, int size> void FixedArray<T, size>::Search(T element) {
	for (int i{0}; i < size; i++) {
		if (element == array[i] && array[i] != 0) {
			std::cout << "Element present at index : " << i << '\n';

			break;
		}
	}
}
template <typename T, int size> void FixedArray<T, size>::Insert(int index, T element) {
	if (index < 0 || index > size) {
		std::cout << "Index out of bounds" << '\n';
		return;
	}
	for (int i = size - 1; i > index; --i) {
		array[i] = array[i - 1];
	}
	array[index] = element;
}
template <typename T, int size> void FixedArray<T, size>::Delete(T element) {
	for (int i{0}; i < size; i++) {
		if (element == array[i] && array[i] != 0) {
			for (int j{i}; j < size - 1; j++) {
				array[j] = array[j + 1];
			}
			break;
		}
	}
}

template <typename T, int size> void FixedArray<T, size>::DeleteAt(int index) {
	for (int j{index}; j < size - 1; j++) {
		array[j] = array[j + 1];
	}
}
int main() {
	FixedArray<int, 10> myarr;
	myarr.SET(0, 11);
	myarr.SET(1, 9);
	myarr.SET(2, 13);

	std::cout << myarr.GET(0) << '\n';
	std::cout << myarr.Max() << '\n';
	myarr.Show();
	std::cout << myarr.Min() << '\n';
	myarr.Search(9);
}