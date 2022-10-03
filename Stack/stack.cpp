#include <iostream>

using namespace std;

class Stack {
private:
	int top_;
	int max_size_;
	char* stack_;
	
public:
	Stack(int size) {
		top_ = -1;
		max_size_ = size;
		stack_ = new char[max_size_];
	}

	bool isFull();
	bool isEmpty();
	
	char pop();
	void push(char element);

	void print();
};

bool Stack::isEmpty() {
	if (top_ == -1) { return 1; }
	else { return 0; }
}

bool Stack::isFull() {
	if (top_ == max_size_ - 1) { return 1; } 
	else { return 0; }
}

char Stack::pop() {
	if (isEmpty()) { cout << "isEmpty!!" << endl; return 0; }
	else return stack_[top_--];
}

void Stack::push(char element) {
	if (isFull()) cout << "Full\n";
	else stack_[++top_] = element;
}

void Stack::print() {
	if (isEmpty()) cout << "is Empty!!" << endl;
	else {
		for (int i = 0; i < top_ + 1; i++) {
			cout << stack_[i] << endl;
		}
	}
}
