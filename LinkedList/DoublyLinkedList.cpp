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
	DoublyLinkedList(int size);

	void Add();
	
};

template <typename T>
struct Node {
public:
	T data;

	Node<T>* next;
	Node<T>* prev;
};


template <typename T>
void DoublyLinkedList<T>::Add() {

}



int main() {

	DoublyLinkedList<int> linked_list{};
	linked_list.Add();

	return 0;
}
