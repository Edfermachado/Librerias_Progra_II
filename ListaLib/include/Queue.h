#include "ListD.h"
#include "LCP_Exceptions.h"

template <typename T>
class Queue : public ListD<T> {
public:
    // Constructor por defecto
    Queue() : ListD<T>() {}

    // Encolar un elemento (al final)
    void enqueue(const T& value) {
        this->insertBack(value);
    }

    // Desencolar un elemento (del frente)
    void dequeue() {
        if (this->isEmpty()) {
            throw ListEmptyException();
        }
        this->deleteNode(0);
    }

    // Obtener el elemento del frente
    T front() const {
        if (this->isEmpty()) {
            throw ListEmptyException();
        }
        return this->getFront();
    }

    T back() const{
	if(this->isEmpty()){
		throw ListEmptyException();
		}
	return this->getBack();
	}

    // Mostrar la cola usando el método heredado
    void showQueue() const {
        this->show();
    }

    // Obtener el tamaño de la cola
    int getSize() const {
        return this->ListD<T>::getSize();
    }

    // Invertir la cola
    void invertQueue() {
        this->invert();
    }

    // Copiar una cola
    void copyQueue(const Queue<T>& other) {
        this->copy(other);
    }

	//Unir dos colas
    void mergeQueue(const Queue<T>& q){
	this->merge(q);
    }

    //limpiar cola
   void clearQueue(){
	this->clear();
	}

  bool contains(const T& e){
	return this->search(e) != -1;
	}

};
