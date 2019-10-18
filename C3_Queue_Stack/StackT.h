#pragma once
#include "NodoT.h"
template<class S>
class StackT
{
public:
	NodoT<S>* first; //Primer elemento del stack
	NodoT<S>* last; // �ltimo elemento del stack
	int size; //Tama�o del stack

	StackT() {
		first = NULL;
		last = NULL;
		size = 0;
	};
	~StackT() {};

	
	void push_front(S val);

	
	void print();

	
	bool search(S val);

	
	void pop_back();
};

/*Cualquier elemento que se quiera ingresar, se introducir� en el contenedor, uno detr�s de otro. El nuevo quedar� encima de los anteriores.
		@param S val, cualquier elemento que se desee introducir.*/
template<class S>
void StackT<S>::push_front(S val)
{
	if (first == NULL) { // la lista est� completamente vac�a
		first = new NodoT<S>(val);
		last = first; // el primero y el �ltimo son el mismo
		last->index = first->index;
		size++;
	}
	else if (first == last) { //un s�lo elemento en la lista
		first = new NodoT<S>(val); //First se convierte en el nuevo valor
		first->next = last; // El valor que le sigue a first, se convierte en el �ltimo
		first->next->index++;
		size++;
	} 
	else { //hay dos  o m�s elementos en la lista	  

		/*Se crea un nodo temporal haciendo que haya dos first al mismo tiempo*/
		NodoT<S>* temporal = first;

		//El first original se convierte en un nuevo valor
		first = new NodoT<S>(val);

		//El nodo siguiente a first se conviert en el nodo temporal
		first->next = temporal;
		temporal->index++; // su indice aumenta

		while (temporal->next != NULL) { // Mientras el nodo que le sigue a first->next no sea nulo, hace este loop
			temporal->next->index++;
			temporal = temporal->next; //Temporal se convierte en este nodo, as� que siempre va a aumentar.
		}
		size++;
	}
}

/*Se imprimir� cualquier valor que se encuentre dentro del contenedor.*/
template<class S>
void StackT<S>::print()
{
	NodoT<S>* iterador = first;
	if (size > 0) {
		while (iterador != NULL) {
			std::cout << iterador->value << "----------------" << iterador->index << "\n";
			iterador = iterador->next;
		}
	}
	else {
		printf("Lista vacia\n");
	}
}

/*Se buscar� si el elemento introducido se encuentra dentro del contenedor
		@param S val, cualquier elemento que se desee introducir*/
template<class S>
bool StackT<S>::search(S val)
{
	// Devuelve true en la primera aparici�n del valor en alg�n nodo
	if (first == NULL) {
		std::cout << "No hay nada en tu lista.\n";
		return false;
	}
	else if (first == last) {
		if (first->value == val) { //si el valor se encuentra, regresa verdadero
			std::cout << "Elemento encontrado\n";
			return true;
		}
		else {
			printf("No hay nada en esta lista\n");
		}
	}
	else {
			bool found;
			NodoT<S>* it = first;
			while (it != NULL) {

				if (it->value == val) { //si el valor se encuentra, regresa verdadero
					std::cout << "Elemento encontrado en el indice: " << it->index << "\n";
					return true;
				}
				else {
					found = false;
				}

				it = it->next;
			}
			if (found == false) { //Si el valor no se encontr�, tira false 
				printf("Ese elemento no existe en tu lista\n");
				return false;
			}
		
	}
}

/*Se eliminar� el �ltimo elemento del contenedor*/
template<class S>
void StackT<S>::pop_back()
{
	NodoT<S>* iterador = first;
	NodoT<S>* iterador2 = first->next;

	if (first == NULL) { //Ningun elemento en la lista
		printf("Stack is empty\n");
		return;
	}
	else if (first == last) { //S�lo un elemento en la lista
		size--;
		delete first;
	} else { //M�s de un elemento en la lista

		while (iterador != NULL) //
		{

			if (iterador2 == last || iterador2->next == NULL) {
				iterador->next = NULL;
				delete iterador2;
				size--;
			}
			iterador = iterador->next;
			iterador2 = iterador2->next;
		}
		
	}
}
