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
	~Stack() { delete[] stack_; }

	bool isFull();
	bool isEmpty();
	char pop();
	void push(char element);

	void print();
	char peak();
	int size();
};

/* 
	스택이 비어있는지 확인하는 함수
	비어있으면 1 요소가 하나라도 있으면 0을 반환
*/
bool Stack::isEmpty() {
	if (top_ == -1) { return 1; }
	else { return 0; }
}


// 스택이 가득찼는지 확인하는 함수
bool Stack::isFull() {
	if (top_ == max_size_ - 1) { return 1; } 
	else { return 0; }
}

/*
	스택의 현재 가장 최근에 들어온 요소(top이 가르키는 인덱스)를 반환하고 top의 인덱스를 -1함
	스택이 비어있다면 반환할 요소가 없기떄문에 0을 반환하고 함수 종료
*/
char Stack::pop() {
	if (isEmpty()) { cout << "isEmpty!!" << endl; return 0; }
	
	// stack크기를 1줄이고 가장 최근에 들어온 요소를 반환함
	return stack_[top_--];
}

//	스택에 요소 추가 스택이 가득 차있으면 실행하지않음 
void Stack::push(char element) {
	if (isFull()) cout << "Full\n";
	else stack_[++top_] = element;
}

// 스택에 있는 모든 요소를 출력
void Stack::print() {
	if (isEmpty()) cout << "isEmpty" << endl;
	else {
		for (int i = 0; i < top_ + 1; i++) {
			cout << stack_[i] << endl;
		}
	}
}

// 현재 스택의 크기 반환
int Stack::size(){
	return top_ + 1;
}

//스택을 수정하지않고 현재 가장 최근에 들어온 요소를 반환
char Stack::peak() {
	return stack_[top_];
}
