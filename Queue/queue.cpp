#include <iostream>

template <typename T>
class Queue {
private:
	int _front;
	int _size;
	int _rear;
	unsigned int _capacity;
	T* _values;

public:
	Queue() {
		_capacity = 4;
		_front = 0;
		_size = 0;
		_rear = 0;
		_values = new T[_capacity];
	}

	~Queue() {
		delete[] _values;
	}
	
	int size() const{
		return _size;
	}

	bool isEmpty() const{
		if (_size == 0) return true;
		return false;
	}

	T front() {
		if (_front == _rear) {
			throw "큐가 비어있습니다.";
		}
		return _values[_front + 1];
	}

	void push(T data) {
		if (_size < _capacity) {
			_values[++_rear] = data;
			_size++;
		}
		else {
			_capacity *= 2;
			T* temp = new T[_capacity];
			for (int i = 1; i < _size; i++) {
				temp[i] = _values[i];
			}
			delete[] _values;
			_values = temp;

			_values[++_rear] = data;
			_size++;
		}
	}

	T pop() {
		if (!isEmpty()) {
			return _values[++front];
		}
		else {
			throw "큐가 비어있습니다.";
		}
	}

};

int main() {

	Queue<int> q;
	q.push(5);
	q.push(10);
	std::cout << q.front();

	return 0;
}
