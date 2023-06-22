#include <iostream>

using namespace std;

template <typename T>
struct Node;


template <typename T>
class DoublyLinkedList {
private:
	Node<T>* head;
	Node<T>* tail;

public:
	DoublyLinkedList() = default;
	DoublyLinkedList(int size) {

	}

public:
	void assign();
	
	T front();
	T back();

	void push_back();


	

private:
	void create_node();
};

template <typename T>
struct Node {
public:
	T data;

	Node<T>* next;
	Node<T>* prev;
};


template <typename T>
void DoublyLinkedList<T>::push_back() {

}



int main() {

	DoublyLinkedList<int> linked_list{};
	linked_list.push_back();

	return 0;
}
