#include <iostream>
#include "ListD.h"


using namespace std;

int main(){


        // Intento de obtener un elemento fuera de rango
        ListD<int> gato;
	ListD<char> perro, dog;
	gato.insertFront(1);
	gato.insertFront(-2);
	gato.insertFront(-53);
	//gato.insert(8,5);
	//gato.insert(9,1);

	perro.insertFront('a');
	perro.insertFront('b');
	perro.insertFront('c');
	perro.show();
	//gato.merge(perro);
	perro.bubbleSort();
	perro.show();
	perro.invert();
	perro.show();
	dog.copy(perro);
	dog.bubbleSort();
	dog.show();


return 0;
}

