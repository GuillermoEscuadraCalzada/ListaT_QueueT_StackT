#include "Stack.h"

void Stack::push_front(int val) {
	if (first == NULL) { // la lista está completamente vacía
		first = new Nodo(val);
		last = first; // el primero y el último son el mismo

		size++;
	}
	else {
		if (first == last) { //un sólo elemento en la lista
			first = new Nodo(val); //First se convierte en el nuevo valor
			first->next = last; // El valor que le sigue a first, se convierte en el último
			first->next->index++;
			size++;
		}
		else { //hay dos  o más elementos en la lista

			/*Se crea un nodo temporal haciendo que haya dos first al mismo tiempo*/
			Nodo* temporal = first;

			//El first original se convierte en un nuevo valor
			first = new Nodo(val);

			//El nodo siguiente a first se conviert en el nodo temporal
			first->next = temporal;
			temporal->index++; // su indice aumenta

			while (temporal->next != NULL) { // Mientras el nodo que le sigue a first->next no sea nulo, hace este loop
				temporal->next->index++;
				temporal = temporal->next; //Temporal se convierte en este nodo, así que siempre va a aumentar.
			}

			size++;
		}
	}

}


void Stack::print()
{
	Nodo* iterador = first;
	if (size > 0) {
		while (iterador != NULL) {
			printf("Numero %i ---- Indice %i\n", iterador->value, iterador->index);
			iterador = iterador->next;
		}
	}
	else {
		printf("Lista vacia\n");
	}
}

bool Stack::search(int val) {
	bool found;

	// Devuelve true en la primera aparición del valor en algún nodo
	if (first == NULL) {
		std::cout << "No hay nada en tu lista.\n";
		return false;
	}
	else {
		if (first == last) {
			if (first->value == val) { //si el valor se encuentra, regresa verdadero
				std::cout << "Valor encontrado\n";
				return true;
			}
			else {
				printf("No hay nada en esta lista\n");
			}
		}
		else {
			Nodo* it = first;
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
}

void Stack::pop_back()
{

	Nodo* iterador = first;
	Nodo* iterador2 = first->next;
	if (first == NULL) { //Una sola lista
		printf("Stack is empty\n");
		return;
	}
	else if (first == last) { //Un elemento en la lista
		size--;
		delete first;
	}
	else { //Más de un elemento
	
	}


}
