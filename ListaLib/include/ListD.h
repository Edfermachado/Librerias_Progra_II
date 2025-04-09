#ifndef LIST_D_H
#define LIST_D_H

#include "Nodo.h"
#include <iostream>
#include "LCP_Exceptions.h"
#include <string>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <cstring>


using namespace std;

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


	//Me quiero cortar un brazo
	ListD(const ListD<T>& other);

	// basiquitos
	void insertFront(const T& value); //Listo
	void insertBack(const T& value); //Listo
	void deleteElem(const T& value);
	void insert(const T& value, int pos);
	void clear();
	bool isEmpty() const;
	void deleteNode(int pos);
	//void destroy();
	void merge(const ListD<T>& listAux);
	void modify(int pos, const T& e);
	void bubbleSort();
	void show() const;
	T min() const;
	T max() const;


	//
	//acceso
	T getFront() const;
	T getBack() const;
	T get(int pos) const;
	T& getReference(int pos);
	int search(const T& e) const;

	//utilidades para carrear el taller
	int getSize() const;
	void invert();
	void copy(const ListD<T>& listAux);
	int distanceDuplicates(const T& value) const;
	void readLL();
	void showLL() const;
	void readRow();
	void readLLRow();
	void readLineToList(const string& unwantedSymbols);
	void readSep(char sep);
	void copyInterval(const T& start, const T& end, ListD<T>& result) const;
	void copyIntervalExclusive(const T& start, const T& end, ListD<T>& result) const;


	//Mejora esteticas

	//para modificar
	T& operator[](int pos);

	//para consultar
	const T& operator[](int pos) const;

	//Mejora de utilidad
	ListD<T>& operator=(const ListD<T>& other);



//Si no implemento esto aquí se petatea todo );, por cuestiones de plantillas e instancias y todo eso xd
	int stringToInt(const string& str){
		istringstream iss(str);
		int num;
		if(iss>>num){
		return num;
		}else{
		throw InvalidArgument(("string no convertible a int: " + str).c_str());
		}
	}

	float stringToFloat(const string& str){
		istringstream iss(str);
		float num;
		if(iss>>num){
		return num;
		}else{
			throw InvalidArgument(("string no convertible a float: "+str).c_str());
		}
	}


string cleanString(const string& dirtyString, const string& unwantedSymbol){

	string cleanedString;

	for(size_t i = 0; i < dirtyString.size(); i++){
		bool isUnWanted = false;

		for(size_t j = 0; j < unwantedSymbol.size(); j++){
			if(dirtyString[i] == unwantedSymbol[j]){
				isUnWanted = true;
				break;
			}
		}

		if(!isUnWanted){
			cleanedString += dirtyString[i];
			}
	}
		return cleanedString;
}

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

template <typename T>
ListD<T>::ListD(const ListD<T>& other) : head(NULL), tail(NULL), size(0) {
    if (other.head == NULL) {
        // Si la lista original está vacía, simplemente salimos
        return;
    }

    // Creamos un puntero auxiliar para recorrer la lista original
    Node<T>* current = other.head;

    // Recorremos la lista original y creamos los nuevos nodos
    while (current != NULL) {
        insertBack(current->getInfo());  // Insertamos al final de la nueva lista
        current = current->getNext();   // Avanzamos al siguiente nodo
    }
}


//readLL especializada para int
template<>
void ListD<ListD<int> >::readLL(){
	int n;
	string line;

	cin >> n;
	cin.ignore();

	for(int i = 0; i<n; i++){
		ListD<int> aux;
		this->insertBack(aux);
		}

	while(getline(cin, line)){
		istringstream ss(line);
		string word;
		int col = 0;

		while(ss>>word){
			int value = stringToInt(word);
			(*this)[col].insertBack(value);
			col++;
		}
	}
}

//readLL especializada para float
template <>
void ListD<ListD<float> >::readLL(){
	int n;
	string line;

	cin >> n;
	cin.ignore();

	for(int i = 0; i<n; i++){
		ListD<float> aux;
		this->insertBack(aux);
	}

	while(getline(cin, line)){
		istringstream ss(line);
		string word;
		int col = 0;

		while(ss >> word){
			float value = stringToFloat(word);
			(*this)[col].insertBack(value);
			col++;
		}
	}
}

//para carrear el taller

//encontrar intervalo
template <typename T>
void ListD<T>::copyInterval(const T& start, const T& end, ListD<T>& result) const{

	bool inRange = false;
	Node<T>* current = head;

	while(current != NULL){
		T value = current->getInfo();

		if(value == start){
			inRange = true;
		}

		if(inRange){
			result.insertBack(value);
		}

		if(value == end && inRange){
			break;
			}

		current = current->getNext();
	}
}

//intervalo sin extremos
template <typename T>
void ListD<T>::copyIntervalExclusive(const T& start, const T& end, ListD<T>& result)const{

	bool inRange = false;
	Node<T>* current = head;

	while(current != NULL){

		T value = current -> getInfo();

		if(value == start){
			inRange = true;
			current = current->getNext();
			continue;
			}

		if(value == end && inRange){
			break;
		}

		if(inRange){
			result.insertBack(value);
		}

		current = current->getNext();
	}
}

//encontrar minimo

template <typename T>
T ListD<T>::min() const{

	if(size == 0){
		throw ListEmptyException();
		}

	Node<T>* aux = head;
	T minValue = aux->getInfo();

	aux = aux->getNext();

	while(aux != NULL){
		if(aux->getInfo()<minValue){
			minValue = aux->getInfo();
			}
		aux = aux->getNext();
		}
	return minValue;
}

//encontrar maximo
template <typename T>
T ListD<T>::max() const{
	if(size == 0){
		throw ListEmptyException();
		}

	Node<T>* aux = head;
	T maxValue = aux -> getInfo();

	aux = aux->getNext();

	while(aux != NULL){
		if(aux->getInfo()>maxValue){
			maxValue = aux->getInfo();
		}
		aux = aux->getNext();
	}
	return maxValue;
}


//leer lista con caracteres no deseados
template <typename T>
void ListD<T>::readLineToList(const string& unwantedSymbols){
	string linea;

	if(getline(cin, linea)){
		if(!linea.empty()){
			string cleanedLine = cleanString(linea, unwantedSymbols);

			istringstream ss(cleanedLine);
			string item;

			while(ss>>item){
				this->insertBack(item);
				}
			}
		}
}


//leer lista de lista
template <>
void ListD<ListD<string> >::readLL() {
    int n;  // Cantidad de columnas
    string line;

    // Leer la primera línea que indica la cantidad de columnas
    cin >> n;
    cin.ignore();  // Para ignorar el salto de línea que sigue al número

    // Inicializar la lista de listas
    for (int i = 0; i < n; i++) {
        ListD<string> aux;
        this->insertBack(aux);  // Crear una lista vacía para cada columna
    }

    // Leer el resto de las líneas (filas de datos)
    while (getline(cin, line)) {
        istringstream ss(line);  // Usar un stringstream para dividir la línea por espacios
        string word;
        int col = 0;  // Contador de columnas

        // Procesar cada palabra en la línea
        while (ss >> word) {
            // Insertar la palabra en la columna correspondiente
            (*this)[col].insertBack(word);  // Insertar al final de la sublista
            col++;  // Avanzar a la siguiente columna
        }
    }
}

//Quiero llorar
template <typename T>
void ListD<T>::readLLRow(){
	int n;
	cin >> n;
	cin.ignore();

	for(int i = 0; i<n; i++){
		//crear una lista para cada linea.
		ListD<string> rowList;

		// Usar el metodo readRow para llenar la fila
		rowList.readRow();

		// Insertar la lista de la fila en la lista principal
		this->insertBack(rowList);
		}
}

//version para int
template<>
void ListD<ListD<int> >::readLLRow() {
    string linea;

    // Leer hasta que no haya más líneas
    while (getline(cin, linea)) {
        if (!linea.empty()) {
            istringstream ss(linea);  // Usamos un stringstream para dividir la línea
            string item;
            ListD<int> rowList;  // Esta lista almacenará los enteros de una fila.

            // Procesamos cada palabra en la línea
            while (ss >> item) {
                    int value = stringToInt(item);  // Convertimos la palabra a int
                    rowList.insertBack(value);  // Insertamos el int en la fila
            }

            // Una vez procesada la fila, la insertamos en la lista principal
            this->insertBack(rowList);
        }
    }
}

template<>
void ListD<ListD<float> >::readLLRow(){
	string linea;

	while(getline(cin, linea)){
		if(!linea.empty()){
		istringstream ss(linea);
		string item;
		ListD<float> rowList;

		while(ss>>item){
			float value = stringToFloat(item);
			rowList.insertBack(value);
			}
			this->insertBack(rowList);
			}
		}
}



//Tambien carrear el taller
template <typename T>
void ListD<T>::showLL() const {
	for(int i = 0; i<this->getSize(); i++){
		cout<< "Columna " << i << ": ";
		for(int j = 0; j < (*this)[i].getSize(); j++){
			cout << (*this)[i][j] << " ";
			}
			cout << endl;
		}
}


//aaaaaaaaaaaaaaaa
template <typename T>
bool ListD<T>::isEmpty() const {
	return head == NULL;
	}

//Implementacion de eliminar por posicion

template <typename T>
void ListD<T>::deleteNode(int pos){

	if(!head){
		throw ListEmptyException();
		}
	if(pos < 0 || pos >= size){
		throw IndexOut();
	}

	Node<T>* aux = head;

	if(pos == 0){
		head = aux->getNext();
		if(head){
			head->setPrev(NULL);
		}else{
			tail = NULL;
		}
	delete aux;
	size --;
	return;
	}

	for(int i = 0; i<pos; i++){
		aux = aux->getNext();
		}

	if(aux->getNext()){
		aux->getNext()->setPrev(aux->getPrev());
		} else {
		tail = aux->getPrev();
	}

	if(aux->getPrev()){
		aux->getPrev()->setNext(aux->getNext());
	}

	delete aux;
	size--;

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

void ListD<T>::deleteElem(const T& value){

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

template <typename T>
T& ListD<T>::getReference(int pos) {

    if (!head) {
        throw ListEmptyException();
    }

    if (pos < 0 || pos >= size) {  // Cambié "pos > 0 size" a "pos >= size"
        throw IndexOut();
    }

    Node<T>* aux = head;

    for (int i = 0; i < pos; i++) {
        aux = aux->getNext();
    }

    return aux->getInfo();  // Devuelves una referencia al valor almacenado en el nodo
}


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

//Sacado del taller del 2021 xd

template <typename T>

int ListD<T>::distanceDuplicates(const T& value) const{

	if(head == NULL){
		throw ListEmptyException();
	}


	Node<T>* aux = head;
	int firstPos = -1;
	int lastPos = -1;
	int pos = 0;

	while(aux != NULL){
		if(aux->getInfo() == value){
			if(firstPos == -1){
				firstPos = pos;
			}
		lastPos = pos;
		}
		aux = aux->getNext();
		pos++;
	}

	if(firstPos != -1 && lastPos != -1 && firstPos != lastPos){
		return lastPos - firstPos - 1;
	}

	return -1;

}



//implementacion de readRow
template <typename T>
void ListD<T>::readRow(){

	clear();

	string linea;

	if(getline(cin, linea)){
		if(!linea.empty()){
			istringstream ss(linea);
			string item;
		while(ss>>item){
			insertBack(item);
				}
				}
		}

}

template <>
void ListD<int>::readRow(){

	string linea;

	if(getline(cin, linea) && !linea.empty()){
		istringstream ss(linea);
		string item;

		while(ss>>item){
			int value = stringToInt(item);
			insertBack(value);
			}
		}
	}

template <>
void ListD<float>::readRow(){
	string linea;

	if(getline(cin, linea) && !linea.empty()){
		istringstream ss(linea);
		string item;

		while(ss>>item){
			float value = stringToFloat(item);
			insertBack(value);
			}
		}
}

//Utilidades

//Leer con separador
template <>
void ListD<string>::readSep(char sep){

	string linea;
	if(getline(cin, linea) && !linea.empty()){
		string item;
		istringstream ss(linea);

		while(getline(ss, item, sep)){
			if(!item.empty()){
				this->insertBack(item);
				}
			}
	}
}

//Leer con separador para int
template <>
void ListD<int>::readSep(char sep){

	string linea;
	if(getline(cin, linea) && !linea.empty()){
		string item;
		istringstream ss(linea);

		while(getline(ss,item,sep)){
			if(!item.empty()){
				int value = stringToInt(item);
				this->insertBack(value);
				}
			}
	}
}

//Leer con separador para float
template <>
void ListD<float>::readSep(char sep){

	string linea;
	if(getline(cin, linea) && !linea.empty()){
		string item;
		istringstream ss(linea);

		while(getline(ss, item, sep)){
			if(!item.empty()){
				float value = stringToFloat(item);
				this->insertBack(value);
				}
			}
		}
}


//Mejoras esteticas

template <typename T>
T& ListD<T>::operator[](int pos){
	return this->getReference(pos);
}

template <typename T>
ListD<T>& ListD<T>::operator=(const ListD<T>& other){
	if(this != &other){
		clear();
		copy(other);
	}
	return *this;
}

template <typename T>
const T& ListD<T>::operator[](int pos) const{

	if(pos < 0 || pos >= size){
		throw IndexOut();
		}

	Node<T>* aux = head;
	for(int i = 0; i<pos; i++){
		aux = aux->getNext();
		}
	return aux->getInfo();
}



#endif
