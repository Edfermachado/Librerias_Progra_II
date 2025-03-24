#ifndef STACK_H
#define STACK_H

#include "ListD.h"
#include "LCP_Exceptions.h"

template <typename T>
class Stack {
private:
    ListD<T> list;  // Usamos la lista doblemente enlazada para implementar la pila

public:
    // Métodos básicos
    void push(const T& value) {   // Insertar en el frente (insertFront)
        list.insertFront(value);
    }

    void pop() {  // Eliminar desde el frente (deleteNode)
        if (isEmpty()) {
            throw ListEmptyException();
        }
        list.deleteNode(list.getFront());
    }

    void clear() {  // Limpiar la pila
        list.clear();
    }

    bool isEmpty() const {  // Verificar si la pila está vacía
        return list.isEmpty();
    }

    void merge(const Stack<T>& s) {  // Unir dos pilas
        list.merge(s.list);
    }

    void modify(int pos, const T& e) {  // Modificar un elemento en una posición
        list.modify(pos, e);
    }

    void bubbleSort() {  // Ordenar la pila
        list.bubbleSort();
    }

    void show() const {  // Mostrar los elementos de la pila
        list.show();
    }

    // Métodos de acceso
    T getTop() const {  // Obtener el primer elemento de la pila (top)
        if (isEmpty()) {
            throw ListEmptyException();
        }
        return list.getFront();
    }

    T get(int pos) const {  // Obtener un elemento en una posición
        return list.get(pos);
    }

    int search(const T& e) const {  // Buscar un elemento en la pila
        return list.search(e);
    }

    // Métodos adicionales para utilidades
    int getSize() const {  // Obtener el tamaño de la pila
        return list.getSize();
    }

    void invert() {  // Invertir la pila
        list.invert();
    }

    void copy(const Stack<T>& s) {  // Copiar una pila
        list.copy(s.list);
    }
};

#endif  // STACK_H
