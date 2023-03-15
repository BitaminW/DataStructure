#include <iostream>


template <typename T>
struct Node;

template <typename T>
class Queue {
private:
	unsigned int msize;
	Node<T>* mfront;
	Node<T>* mrear;

public:
	Queue() : msize(0), mfront(nullptr), mrear(nullptr) {}

	~Queue() { }

	int size() {
		return msize;
	}

	bool isEmpty() {
		return msize == 0;
	}
	
	void push(T& data) {
		if (mfront == nullptr) {
			Node<T>* temp = new Node<T>(data);
			mfront = temp;        // ??
			mrear = temp;
			msize++;
			return;
		}
		
		Node<T>* temp = new Node<T>(data);
		mrear->mnext = temp;
		mrear = temp;
		mfront->mnext;
		msize++;
	}

	void push(T&& data) {
		if (mfront == nullptr) {
			Node<T>* temp = new Node<T>(data);
			mfront = temp;  // ?? 
			mrear = temp;
			msize++;
			return;
		}

		Node<T>* temp = new Node<T>(data);
		mrear->mnext = temp;
		mrear = temp;
		msize++;
	}

	T pop() {

	}

	T front() {
		if (isEmpty()) {
			throw "큐가 비어있습니다.";
		}
		if (mfront != nullptr) {
			return mrear->mvalue;
		}
	}

	T back() {

	}

};

template <typename T>
struct Node {
	Node<T>* mnext = nullptr;
	T mvalue;

	Node(T& data) {
		mvalue = data;
	}
	Node(T&& data) {
		mvalue = data;
	}
	~Node(){
		delete mnext;
	}
};

int main() {

	Queue<int> q;
	q.push(10);
	std::cout << q.front();

	return 0;
}
