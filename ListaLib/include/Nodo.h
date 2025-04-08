#ifndef NODO_H
#define NODO_H
#include <iostream>

template <typename T>

class Node{

	private:
		Node<T>* next;
		Node<T>* prev;
		T info;
	public:
		Node(const T& valor) : info(valor), next(NULL), prev(NULL){}

		Node<T>* getNext() const {return next;}
		Node<T>* getPrev() const {return prev;}
		T& getInfo() {return info;}
		void setInfo(const T& e){
			info = e;
				}

		void setNext(Node<T>* nodo) {next = nodo; }
		void setPrev(Node<T>* nodo) {prev = nodo; }

};

#endif
