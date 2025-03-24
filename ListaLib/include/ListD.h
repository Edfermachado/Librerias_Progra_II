#ifndef LIST_D_H
#define LIST_D_H

#include "Nodo.h"
#include <iostream>
#include "LCP_Exceptions.h"

template <typename T>

class ListD{

private:
	Node<T>* head;
	Node<T>* tail;
	int size;
public:

	//Constructor y destructor
	ListD();
	~ListD();

	// basiquitos
	void insertFront(const T& value); //Listo
	void insertBack(const T& value); //Listo
	void deleteNode(const T& value);
	void insert(const T& value, int pos);
	void clear();
	bool isEmpty() const;
	//void destroy();
	void merge(const ListD<T>& listAux);
	void modify(int pos, const T& e);
	void bubbleSort();
	void show() const;


	//acceso
	T getFront() const;
	T getBack() const;
	T get(int pos) const;
	int search(const T& e) const;

	//utilidades para carrear el taller
	int getSize() const;
	void invert();
	void copy(const ListD<T>& listAux);


};

// Implementación del constructor
template <typename T>
ListD<T>::ListD() : head(NULL), tail(NULL), size(0) {}

// Implementación del destructor
template <typename T>
ListD<T>::~ListD() {
    Node<T>* current = head;
    while (current != NULL) {
        Node<T>* next = current->getNext();
        delete current;
        current = next;
    }
    head = tail = NULL;
    size = 0;
}

// Implementacion de insertFront

template <typename T>
void ListD<T>::insertFront(const T& value){
	Node<T>* newNode = new Node<T>(value);

	if(!head){
		head = tail = newNode;
	}else{
		newNode->setNext(head);
		head->setPrev(newNode);
		head = newNode;
	}
	size++;

}
// Implementacion de insertBack

template <typename T>
void ListD<T>::insertBack(const T& value){
	Node<T>* newNode = new Node<T>(value);

	if(!head){
		head = tail = newNode;
	}else{
		tail->setNext(newNode);
		newNode->setPrev(tail);

		tail = newNode;

	}
	size++;


}

// Implementacion de insert

template <typename T>
void ListD<T>::insert(const T& value, int pos){
	Node<T>* newNode = new Node<T>(value);

	if(pos < 0){
		throw IndexOut();
	}

	if(!head){
		head = tail = newNode;
	}else if(pos == 0){
		insertFront(value);
	}else if(pos>=size){
		insertBack(value);
	}else{
		Node<T>* aux = head;

		for(int i = 0; i<pos - 1 && aux->getNext() != NULL; i++){
			aux = aux->getNext();
		}

		newNode->setNext(aux->getNext());
		newNode->setPrev(aux);

		if(aux->getNext() != NULL){
			aux->getNext()->setPrev(newNode);
		}else{
			tail = newNode;
			}
			aux->setNext(newNode);
		}
	size++;
}

//Implementacion DeleteNode
template <typename T>

void ListD<T>::deleteNode(const T& value){

	//caso Lista vacia
	if(!head){
		throw ListEmptyException();
		return;
	}
	//caso Eliminar head
	if(head->getInfo()==value){
		Node<T>* temp = head;
		head = head->getNext();
		if(head){
			head->setPrev(NULL);
		}else{
			tail = NULL;
		}
		delete temp;
		return;
	}

	//caso Eliminar un nodo en el medio o en la cola
	Node<T>* aux = head;
	while(aux != NULL && aux->getInfo() != value){
		aux = aux->getNext();
	}

	//si no se encontró el nodo, salimos
	if(aux == NULL){
		throw NotFound();
		return;
	}

	//caso el nodo está en el medio o en la cola
	if(aux->getNext()){
		aux->getNext()->setPrev(aux->getPrev());
	}else{
		tail = aux->getPrev();
	}

	if(aux->getPrev()){
		aux->getPrev()->setNext(aux->getNext());
	}
	delete aux;

}



//acceso
template <typename T>
T ListD<T>::getFront() const{
	if(head){
	return head->getInfo();
	}
	throw ListEmptyException();

}

template <typename T>
T ListD<T>::getBack() const{
	if(tail){
	return tail->getInfo();
	}
	throw ListEmptyException();
}

template <typename T>
T ListD<T>::get(int pos) const{

    if (!head) {
        throw ListEmptyException();
    }
    if (pos < 0 || pos >= size) {
        throw IndexOut();
    }


    Node<T>* aux = head;

    for (int i = 0; i < pos; i++) {
        aux = aux->getNext();
    }

    return aux->getInfo();
}

//Implementacion mostrar lista
template <typename T>
void ListD<T>::show() const{
	if(!head){
		std::cout<<"List Empty"<<std::endl;
		return;
	}
	Node<T>* aux = head;
	while(aux){
		std::cout <<aux->getInfo()<<"->";
		aux = aux->getNext();
	}
	std::cout << "NULL"<<std::endl;
}

//Implementacion limpiar lista

template <typename T>
void ListD<T>::clear() {
    Node<T>* aux = head;

    // Recorremos la lista y eliminamos cada nodo.
    while (aux != NULL) {
        Node<T>* temp = aux;
        aux = aux->getNext();
        delete temp; // Eliminamos el nodo actual.
    }

    // Después de eliminar todos los nodos, reiniciamos las referencias a cabeza y cola.
    head = NULL;
    tail = NULL;
    size = 0; // También reiniciamos el tamaño de la lista.
}

//Implementacion mergeList

template <typename T>
void ListD<T>::merge(const ListD<T>& listAux) {
    // Verificamos si listAux está vacía
    if (listAux.head == NULL) {
        return;  // No hay nada que fusionar
    }

    // Puntero auxiliar para recorrer listAux sin modificarla
    Node<T>* aux = listAux.head;

    // Recorremos listAux y copiamos cada elemento en la lista actual
    while (aux != NULL) {
        insertBack(aux->getInfo()); // Insertamos cada elemento al final de la lista
        aux = aux->getNext();
    }
}

//Implementacion de modify

template <typename T>
void ListD<T>::modify(int pos, const T& e){

	//Validamos si la lista está vacia
	if(head == NULL){
		throw ListEmptyException();
	}
	// Validamos que la posicion esté dentro del rango
	if(pos<0 || pos>=size){
		throw IndexOut();
	}

	//Recorremos la lista hasta la posicion indicada
	Node<T>* aux = head;
	for(int i = 0; i < pos; i++){
		aux = aux->getNext();
	}
	//Modificamos el nodo en la posicion indicada
	aux->setInfo(e);

}

//Implementacion de BubbleSort

template <typename T>
void ListD<T>::bubbleSort() {
    if (!head || !head->getNext()) {
        return; // Si la lista está vacía o tiene un solo elemento, ya está ordenada.
    }

    bool swapped;
    Node<T>* ptr;
    Node<T>* last = NULL;

    do {
        swapped = false;
        ptr = head;

        while (ptr->getNext() != last) {
            if (ptr->getInfo() > ptr->getNext()->getInfo()) {
                // Intercambiar valores
                T temp = ptr->getInfo();
                ptr->setInfo(ptr->getNext()->getInfo());
                ptr->getNext()->setInfo(temp);

                swapped = true;
            }
            ptr = ptr->getNext();
        }
        last = ptr; // Se optimiza, ya que el último nodo ya está en su posición correcta
    } while (swapped);
}

//Implementacion search

template<typename T>
int ListD<T>::search(const T& e)const{
	Node<T>* aux = head;
	int pos = 0;

	while(aux != NULL){
		if(aux->getInfo()==e){
			return pos;
		}
		aux = aux->getNext();
		pos++;
	}
	return -1; //en caso de que no encuentre el elemento

}

//implementacion getSize
template<typename T>
int ListD<T>::getSize() const{
		return size;
	}

//implementacion invert
template<typename T>
void ListD<T>::invert(){
	   Node<T>* current = head;
    Node<T>* temp = NULL;

    // Intercambia los punteros next y prev en cada nodo
    while (current != NULL) {
        temp = current->getPrev();
        current->setPrev(current->getNext());
        current->setNext(temp);
        current = current->getPrev(); // Se mueve al siguiente (que antes era el previo)
    }

    // Intercambia head y tail
    if (temp != NULL) {
        head = temp->getPrev();
    }
}

//Implementacion de copy

template <typename T>

void ListD<T>::copy(const ListD<T>& listAux){
	clear();
	if(listAux.head == NULL){
		return;
	}
	Node<T>* aux = listAux.head;

	while(aux != NULL){
		insertBack(aux->getInfo());
		aux = aux->getNext();
	}
}




#endif
