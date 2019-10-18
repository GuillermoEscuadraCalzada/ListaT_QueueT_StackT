#pragma once
#include "NodoT.h"

template<class Q>
class QueueT
{
public:
	NodoT<Q>* first; //Primer elemento del stack
	NodoT<Q>* last; // Último elemento del stack
	int size; //Tamaño del stack

	QueueT() {
		first = NULL;
		last = NULL;
		size = 0;
	};
	~QueueT() {};

	
	void push_back(Q val);


	bool search(Q val);


	void print();


	void pop_front();
};

/*El contenedor irá ingresando los valores que se le quieran introducir, ingresando el nuevo valir hasta el últimp
	@param Q val, cualquier valor que se desee introducir.*/
template<class Q>
void QueueT<Q>::push_back(Q val)
{
	if (first == NULL) { //Ningún elemento en la lista.
		first = new NodoT<Q>(val); //Se agrega un nuevo elemento en la lista
		last = first;
		size++;
	}
	else if (first == last) { // sólo hay un elemento en la lista
		last = new NodoT<Q>(val); // last ahora es diferente
		first->next = last; // el siguiente de first ahora es el nuevo nodo
		first->next->index++;
		size++;
	}
	else {  // hay 2 o más elementos en la lista
			last->next = new NodoT<Q>(val); // last->next era null, ahora es un nodo
			last->next->index = last->index; //El índice del siguiente del último es igual al del último
			last = last->next; // last ahora es el nodo nuevo
			last->index++; //incrementa el índice de cada nuevo nodo
			size++;
	}
}

/*Se buscará un elemento y nos informará si ese valor se encuentra en la lista o no.
	@param Q val, cualquier valor que se desee ingresar.*/
template<class Q>
bool QueueT<Q>::search(Q val) 
{
	bool found;

	// Devuelve true en la primera aparición del valor en algún nodo
	if (first == NULL) {
		std::cout << "No hay nada en tu lista.\n";
		return false;
	}
	else if (first == last) {
		if (first->value == val) { //si el valor se encuentra, regresa verdadero
			std::cout << "Valor encontrado\n";
			return true;
		}
		else {
			printf("No hay nada en esta lista\n");
		}
	}
	else {
		NodoT<Q>* it = first;
		while (it != NULL) {

			if (it->value == val) { //si el valor se encuentra, regresa verdadero
				std::cout << "Valor encontrado en el indice: " << it->index << "\n";
				return true;
			}
			else {
				found = false;
			}

			it = it->next;
		}
		if (found == false) { //Si el valor no se encontró, tira false 
			printf("Ese valor no existe en tu lista\n");
			return false;
		}

	}
}

/*Se imprimen todos los datos que se encuentren dentro de la lista.*/
template<class Q>
void QueueT<Q>::print() 
{
	NodoT<Q>* iterador = first;

	if (size > 0) { //Si el tamaño del contenedor es mayor a cero, imprimelo
		while (iterador != NULL) {//Se recorren los elementos de la lista
			std::cout << iterador->value << " ---------- " << iterador->index << "\n";
			iterador = iterador->next;
		}
	} else {//Si no es mayor a cero, la lista está vacía.
		printf("Queue is empty\n");
	}
}

/*Se elimina el primer elemento de la lista*/
template<class Q>
void QueueT<Q>::pop_front() 
{
	if (first == NULL) { //Ningún elemento en la lista.
		printf("Stack is empty\n");
		return;
	}
	if (first == last) { //Sólo un elemento en la lista
		printf("Valor eliminado.\n");
		size--;
		delete first;
	}
	else { // Más de un elemento en la lista
		
		NodoT<Q>* temporal = first; //Temporal es el primer elemento
		NodoT<Q>* temp = temporal->next; //Temp es el segundo elemento de la lista
		first = temp; //El segundo elemento se vueleve el primero.

		while (temp != NULL) { //Recorrerá toda la lista hasta encontrar el elemento indicado
			temp->index--;
			temp = temp->next;
		}
		size--;
		printf("Valor eliminado.\n");
		delete temporal; //Elimina Temporal
		
	}

}