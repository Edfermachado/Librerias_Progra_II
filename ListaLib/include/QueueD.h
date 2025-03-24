#ifndef QUEUE_H
#define QUEUE_H

#include "ListD.h"
#include "LCP_Exceptions.h"

template <typename T>
class Queue {
private:
    ListD<T> list;  // Usamos la lista doblemente enlazada para implementar la cola

public:
    // Métodos básicos
    void enqueue(const T& value) {   // Insertar al final (insertBack)
        list.insertBack(value);
    }

    void dequeue() {  // Eliminar desde el frente (deleteNode)
        if (isEmpty()) {
            throw ListEmptyException();
        }
        list.deleteNode(list.getFront());
    }

    void clear() {  // Limpiar la cola
        list.clear();
    }

    bool isEmpty() const {  // Verificar si la cola está vacía
        return list.isEmpty();
    }

    void merge(const Queue<T>& q) {  // Unir dos colas
        list.merge(q.list);
    }

    void modify(int pos, const T& e) {  // Modificar un elemento en una posición
        list.modify(pos, e);
    }

    void bubbleSort() {  // Ordenar la cola
        list.bubbleSort();
    }

    void show() const {  // Mostrar los elementos de la cola
        list.show();
    }

    // Métodos de acceso
    T getFront() const {  // Obtener el primer elemento de la cola
        if (isEmpty()) {
            throw ListEmptyException();
        }
        return list.getFront();
    }

    T getBack() const {  // Obtener el último elemento de la cola
        if (isEmpty()) {
            throw ListEmptyException();
        }
        return list.getBack();
    }

    T get(int pos) const {  // Obtener un elemento en una posición
        return list.get(pos);
    }

    int search(const T& e) const {  // Buscar un elemento en la cola
        return list.search(e);
    }

    // Métodos adicionales para utilidades
    int getSize() const {  // Obtener el tamaño de la cola
        return list.getSize();
    }

    void invert() {  // Invertir la cola
        list.invert();
    }

    void copy(const Queue<T>& q) {  // Copiar una cola
        list.copy(q.list);
    }
};

#endif  // QUEUE_H
