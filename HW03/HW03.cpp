#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template<typename T>

class SimpleVector {
private:
	T* arr;
	int currentSize = 0;
	int currentCapacity = 0;

	void resize(int newCapacity) {
		if (newCapacity > currentCapacity) {
			T* newarr = new T[newCapacity];
			for (int a = 0; a < currentSize; a++) {
				newarr[a] = arr[a];
			}
			delete[] arr;
			arr = newarr;
			currentCapacity = newCapacity;
		}
	}

public:
	SimpleVector() : currentCapacity(10) {
		arr = new T[currentCapacity];
	}
	SimpleVector(int num) : currentCapacity(num) {
		arr = new T[currentCapacity];
	}
	SimpleVector(const SimpleVector& other) {
		currentSize = other.currentSize;
		currentCapacity = other.currentCapacity;

		arr = new T[currentCapacity];

		for (int a = 0; a < currentSize; a++) {
			arr[a] = other.arr[a];
		}
	}
	~SimpleVector() {
		delete[] arr;
	}
	void show() {
		for (int a = 0; a < currentSize; a++) {
			cout << arr[a] << endl;
		}
	}
	void sortData() {
		sort(arr, arr + currentSize);
	}

	void push_back(const T& value) {
		if (currentSize == currentCapacity) {
			resize(currentCapacity += 5);
		}
		arr[currentSize] = value;
		currentSize++;
	}
	void pop_back() {
		if (currentSize > 0) {
			currentSize--;
		}
	}
	int size() const {
		return currentSize;
	}
	int capacity() const {
		return currentCapacity;
	}

};

int main() {
	SimpleVector<int> vec(20);
	vec.push_back(40);
	vec.push_back(30);
	vec.push_back(20);
	vec.push_back(50);
	vec.push_back(10);
	vec.show();
	vec.sortData();
	vec.show();
	SimpleVector<string> vec2(20);
	vec2.push_back("안");
	vec2.push_back("녕");
	vec2.push_back("하");
	vec2.push_back("세");
	vec2.push_back("요");
	vec2.show();
	vec2.sortData();
	vec2.show();
	SimpleVector<int> vec3(vec);
	vec3.show();

	vec.pop_back();
	vec.pop_back();
	vec.pop_back();

	vec3.show();
	return 0;
}