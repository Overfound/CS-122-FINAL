#pragma once
#include "Cordinate.hpp"
template <class T >
class Node {
public:
	Node(T datas);
	Node(Node<T>& rhs);
	~Node();

	Node<T>* getNextNode();
	void setNextNode(Node<T>* data);

	T* getData();

private:
	T *data;
	Node<T>* nextNode;
};

template <class T >
Node<T>::Node(T datas) {
	data = new T(datas);
}
template <class T >
Node<T>::~Node() {
	delete(data);
}
template <class T >
Node<T>* Node<T>::getNextNode() {
	return nextNode;
}
template <class T >
void Node<T>::setNextNode(Node<T>* data) {
	nextNode = data;
}
template <class T>
T* Node<T>::getData() {
	return data;
}
template <class T>
Node<T>::Node(Node<T>& rhs) {
	this->data = rhs.data;
	this->nextNode = rhs.nextNode;
}