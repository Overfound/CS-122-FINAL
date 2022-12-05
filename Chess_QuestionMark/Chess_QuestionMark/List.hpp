#pragma once
#include "Node.hpp"
template <class T >
class List {
public:
	List();
	~List();

	Node<T>* getHeadNode();
	void setHeadNode(Node<T>* data);

	void insertFront(T data);


private:
	Node<T>* HeadNode;
};


template <class T >
List<T>::List() {
	HeadNode = nullptr;
}
template <class T >
List<T>::~List() {
	Node<T>* pcur = HeadNode;
	while (pcur != nullptr) {
		delete(pcur);
		pcur->getNextNode();
	}
}
template <class T >
Node<T>* List<T>::getHeadNode() {
	return HeadNode;
}
template <class T >
void List<T>::setHeadNode(Node<T>* data) {
	HeadNode = data;
}
template <class T >
void List<T>::insertFront(T data) {
	if (HeadNode == nullptr) {
		HeadNode = new Node<T>(data);
	}
	else {
		Node<T>* temp = HeadNode;
		HeadNode = new Node<T>(data);
		HeadNode->setNextNode(temp);
	}
}
