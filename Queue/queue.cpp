#include <iostream>
#include <stdexcept>

template <typename T>
struct Node;

template <typename T>
class Queue {
private:
	unsigned int m_size;
	Node<T>* m_front;
	Node<T>* m_rear;

public:
	Queue() : m_size(0), m_front(nullptr), m_rear(nullptr) {}

	~Queue() { }

	int size() {
		return m_size;
	}

	bool isEmpty() {
		return m_size == 0;
	}
	
	void push(const T& data) {
		if (m_front == nullptr) {
			Node<T>* temp = new Node<T>(data);
			m_front = temp;        // ??
			m_rear = temp;
			m_size++;
			return;
		}
		
		Node<T>* temp = new Node<T>(data);
		m_front->m_next = temp;
		m_rear = temp;
		m_size++;
	}

	void push(T&& data) {
		if (m_front == nullptr) {
			Node<T>* temp = new Node<T>(std::move(data));
			m_front = temp;  // ?? 
			m_rear = temp;
			m_size++;
			return;
		}
		Node<T>* temp = new Node<T>(std::move(data));
		m_front->m_next = temp;
		m_rear = temp;
		m_size++;
	}

	// 가장 먼저 들어온 요소를 삭제한다. delete front
	void pop() {

	}

	// 가장 먼저 들어온 요소를 반환한다. return front
	T front() {
		if (isEmpty()) {
			throw std::runtime_error("Queue is empty");
		}
		
		return m_front->m_value;
	}

	// 가장 나중에 들어온 요소를 반환한다. return rear
	T back() {

	}

};

template <typename T>
struct Node {
	Node<T>* m_next = nullptr;
	T m_value;

	Node(T& data) {
		m_value = data;
	}
	Node(T&& data) {
		m_value = data;
	}
	~Node(){
		delete m_next;
	}
};

int main() {

	Queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);

	std::cout << q.front() << "\n";
	q.pop();
	q.pop();
	std::cout << q.front() << "\n";

	return 0;
}
