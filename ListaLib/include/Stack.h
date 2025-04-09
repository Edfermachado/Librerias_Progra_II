#ifndef STACK_H
#define STACK_H

#include "ListD.h"
#include "LCP_Exceptions.h"

template <typename T>
class Stack : public ListD<T> {
public:
    // Inserta un nuevo elemento al tope de la pila
    void push(const T& value) {
        this->insertBack(value);
    }

    // Elimina el elemento del tope de la pila
    void pop() {
        if (this->isEmpty()) {
            throw ListEmptyException();
        }
        this->deleteNode(this->getSize() - 1);
    }

    // Retorna el elemento del tope sin eliminarlo
    T& top() {
        if (this->isEmpty()) {
            throw ListEmptyException();
        }
        return this->getReference(this->getSize() - 1);
    }

    const T& top() const {
        if (this->isEmpty()) {
            throw ListEmptyException();
        }
        return this->get(this->getSize() - 1);
    }

    // Verifica si está vacía (heredado de ListD, pero puedes hacer override si gustas)
    bool empty() const {
        return this->isEmpty();
    }

    // Vacía completamente la pila
    void clearStack() {
        this->clear();
    }

    void showStack()const{
	this->show();
	}

    int getSize(){
	return getSize();
	}

    void invertStack(){
	this->invert();
	}

    void copyStack(const Stack<T>& other){
	this->copy(other);
	}

    void SortStack(){
	this->bubbleSort();
	}

    void mergeStack(const Stack<T>& s){
	this->merge(s);
	}

};

#endif
