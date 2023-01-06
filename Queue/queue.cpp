#include <iostream>


template <typename T>
struct Node;

template <typename T>
class Queue {
private:
	unsigned int _size;
	Node<T>** _front;
	Node<T>* _rear;

public:
	Queue() {
		_size = 0;
		_front = nullptr;
		_rear = nullptr;
	}

	~Queue() {

	}

	int size() {
		return _size;
	}

	bool isEmpty() {
		if (_size == 0) 
			return true;

		return false;
	}
	
	void push(T& data) {
		if (_front == nullptr) {
			Node<T>* temp = new Node<T>(data);
			_front = &temp;
			_rear = temp;
			_size++;
			return;
		}
		
		Node<T>* temp = new Node<T>(data);
		_rear->_next = temp;
		_rear = temp;
		_front->_next;
		_size++;
	}

	void push(T&& data) {
		if (_front == nullptr) {
			Node<T>* temp = new Node<T>(data);
			_front = &temp;
			_rear = temp;
			_size++;
			return;
		}

		Node<T>* temp = new Node<T>(data);
		_rear->_next = temp;
		_rear = temp;
		_size++;
	}

	T pop() {

	}

	T front() {
		if (isEmpty()) {
			throw "큐가 비어있습니다.";
		}
		if (_front != nullptr) {
			return _rear->_value;
		}
	}

	T back() {

	}

};

template <typename T>
struct Node {
	Node<T>* _next = nullptr;
	T _value;
	Node(T& data) {
		_value = data;
	}
	Node(T&& data) {
		_value = data;
	}
	~Node(){
		if (_next != nullptr) 
			delete _next;
	}
};

int main() {

	Queue<int> q;
	q.push(10);
	std::cout << q.front();

	return 0;
}
