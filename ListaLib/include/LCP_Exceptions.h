#ifndef LCP_EXCEPTIONS_H
#define LCP_EXCEPTIONS_H

#include <exception>

class LCP_Exception : public std::exception{
protected:
	const char* message;

public:
	//constructor
	LCP_Exception(const char* msg) throw() : message(msg){}

	//metodo what() que devuelve el mensanje de error
	virtual const char* what() const throw(){
		return message;
	}
};

//Lista vacia
class ListEmptyException : public LCP_Exception{
public:
	ListEmptyException() : LCP_Exception("ERROR: List Empty"){}
};

//Fuera de rango
class IndexOut : public LCP_Exception{
public:
	IndexOut() : LCP_Exception("ERROR: index out range"){}
};

//Valor no encontrado
class NotFound : public LCP_Exception{
public:
	NotFound() : LCP_Exception("ERROR: Value Not Found"){}

};

#endif
