#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template<typename T>

class SimpleVector {
private:
	vector<T> data; //타입에 의존하지 않고 데이터를 받을수 있는 배열을 멤버변수로 갖습니다.
	int Vsize;
public:
	SimpleVector() : Vsize(10) {
		data.reserve(10);
	} //기본 생성자는 크기가 10인 배열을 만듭니다.
	SimpleVector(int vsize) : Vsize(vsize) {
		data.reserve(vsize);
	} //숫자를 하나 받는 생성자는 해당 숫자에 해당되는 크기의 배열을 만듭니다.

	void push_back(T value) { //push_back 인자로 받은 원소를 맨 뒤에 추가 합니다.
		if (data.size() < Vsize) { //배열의 크기가 꽉 찼는데 원소가 더 들어올경우 아무 동작도 하지 않습니다.
			data.push_back(value);
		}
		else { //push_back에서 배열의 크기가 꽉 찼는데 원소가 더 들어올경우, 기존 배열보다 크기를 5만큼 더 늘리고 새로운 원소까지 추가됩니다.(기존에 있던 값도 유지되야 합니다.)
			Vsize += 5;
			data.reserve(Vsize);
			data.push_back(value);
		}
	}

	void pop_back() { // pop_back은 벡터의 마지막 원소를 제거 합니다.만약 제거할 원소가 없다면 아무 동작도 하지 않으며, 인자 및 반환값은 없습니다.
		if (!data.empty())
			data.pop_back();
	}

	int size() {  //size는 인자가 없고 현재 원소의 개수를 반환합니다.
		return data.size();
	}

	int capacity() { //capacity 현재 내부 배열의 크기를 반환합니다.
		return data.capacity();
	}

	void resize(int x) {
		if (x > data.capacity()) {
			Vsize = x;
			data.reserve(x);
		}
	}

	void sortData() {
		sort(data.begin(), data.end());
	}

	void seeout() {
		for (T a : data) {
			cout << a;
		}
		cout << endl;
	}
};

int main() {
	SimpleVector<int> vec;
	vec.push_back(30);
	vec.push_back(10);
	vec.push_back(50);
	vec.push_back(20);
	vec.push_back(40);
	vec.sortData();
	vec.seeout();

	SimpleVector<string> vec2;
	vec2.push_back("안");
	vec2.push_back("녕");
	vec2.push_back("하");
	vec2.push_back("세");
	vec2.push_back("요");
	vec2.sortData();
	vec2.seeout();

	return 0;
}



