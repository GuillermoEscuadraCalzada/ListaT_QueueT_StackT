#include "Queue.h"

void Queue::print()
{
	Nodo* iterador = first;

	if (size > 0) {
		while (iterador != NULL) {
			printf("Numero %i ---- Indice %i\n", iterador->value, iterador->index);
			iterador = iterador->next;
		}
	}
	else {
		printf("Queue is empty\n");
	}
}

void Queue::pop_front()
{
	if (first == NULL) {
		printf("Stack is empty\n");
		return;
	}
	else {
		if (first == last) {
			size--;
			delete first;
		}
		else {
			Nodo* temporal = first;
			Nodo* temp = temporal->next;
			first = temp;

			while (temp != NULL) {
				temp->index--;
				temp = temp->next;
			}
			size--;
			delete temporal;
		}
	}
}

void Queue::push_back(int val)
{
	if (first == NULL) {
		first = new Nodo(val);
		last = first;
		size++;
	}
	else if (first == last) { // sólo hay un elemento en la lista
		last = new Nodo(val); // last ahora es diferente
		first->next = last; // el siguiente de first ahora es el nuevo nodo
		first->next->index++;
		size++;
	}
	else {
		
		{ // hay 2 o más elementos en la lista

			last->next = new Nodo(val); // last->next era null, ahora es un nodo


			last->next->index = last->index; //El índice del siguiente del último es igual al del último

			last = last->next; // last ahora es el nodo nuevo

			last->index++; //incrementa el índice de cada nuevo nodo
			size++;
		}

	}
}

bool Queue::search(int val) {
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

