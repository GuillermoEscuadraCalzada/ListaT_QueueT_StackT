#pragma once
#include "NodoT.h"
#include <string>
using std::to_string;
template<class T>
class ListaT
{
public:
	NodoT<T>* first;
	NodoT<T>* last;
	int size;

	ListaT() {
		first = NULL;
		last = NULL;
		size = 0;
	};
	~ListaT() {};

	void push_back(T val);
	void push_front(T val);
	bool search(T val);
	void delete_at(int index);
	NodoT<T>* get_at(int index);

	void print(); 
	void BubbleSort();
	void InsertionSort();

	NodoT<T>* swap(NodoT<T>* first, NodoT<T>* second);
};


/* Meterá el valor que el usuario quiera hasta el final de la lista
	@param un valor que se meterá al final de la lista */
template<class T>
void ListaT<T>::push_back(T val) {
	if (first == NULL) { // la lista está completamente vacía
		first = new NodoT<T>(val);
		last = first; // el primero y el último son el mismo
		first->index = last->index;
		size++;
	}
	else if (first == last) { // sólo hay un elemento en la lista
		last = new NodoT<T>(val); // last ahora es diferente
		first->next = last; // el siguiente de first ahora es el nuevo nodo
		first->next->index++;
		size++;
	} else { // hay 2 o más elementos en la lista

		last->next = new NodoT<T>(val); // last->next era null, ahora es un nodo
		last->next->index = last->index; //El índice del siguiente del último es igual al del último
		last = last->next; // last ahora es el nodo nuevo
		last->index++; //incrementa el índice de cada nuevo nodo
		size++;
		
	}
}


/* Meterá el valor que el usuario quiera hasta el inicio de la lista
	@param un valor que se meterá al inicio de la lista */
template<class T>
void ListaT<T>::push_front(T val) {
	
	if (first == NULL) { // la lista está completamente vacía
		first = new NodoT<T>(val);
		last = first; // el primero y el último son el mismo
		last->index = first->index;
		size++;
	}
	else if (first == last) { //un sólo elemento en la lista
		first = new NodoT<T>(val); //First se convierte en el nuevo valor
		first->next = last; // El valor que le sigue a first, se convierte en el último
		first->next->index++;
		size++;
	} else {	//hay dos  o más elementos en la lista
			/*Se crea un nodo temporal haciendo que haya dos first al mismo tiempo*/
			NodoT<T>* temporal = first;

			//El first original se convierte en un nuevo valor
			first = new NodoT<T>(val);

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


/* Se buscará el valor que el usuario quiera en la lista
		@param un valor que se deberá de buscar en toda la lista*/
template<class T>
bool ListaT<T>::search(T val)
{
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
			NodoT<T>* it = first;
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

/*
Se elimina un elemento en el indice indicado
	@param se ingresa el indice donde se quiere eliminar un elemento	
*/
template<class T>
void ListaT<T>::delete_at(int index)
{
	/* Hay 3 casos posibles:
	1.- la lista está vacía
	2.- la lista tiene sólo un elemento
	3.- la lista tiene 2 o más elementos, en cuyo caso hay 3 posibilidades
	a.- el elemento es el inicio de la lista
	b.- el elemento es el final de la lista
	c.- ninguno de los anteriores
	*/

	NodoT<T>* temporal = first;
	NodoT<T>* temp = first->next;

	if (temporal == NULL) { //La lista está vacía
		std::cout << "Lista vacia\n";
	}
	else if (temporal->index == index) { //El indice es el primer elemento de la lista
		printf("Elemento borrado\n");
		first = temp;

		while (temp != NULL) {
			temp->index--;
			temp = temp->next;
		}
		size--;
		delete temporal; //El nodo se elimina
	}
	else {

		 { //El indice del nodo no es igual al que se pidió

			if (index > last->index || index < 0) { //Si el índice es menor a cero y mayor al último índice, no existe en el contenedor
				printf("Indice fuera de la lista\n");
			}
			else {

				while (temp->index != index) {// Si el nodo no tiene el índice que se busca, ambos nodos avanzan en la lista.

					temp = temp->next;
					temporal = temporal->next;
				}
				if (temp->next == NULL || temp == last) { //Si el elemento que sigue al nodo es Nulo, significia que es el ULTIMO elemento de la lista
					temporal->next = NULL;
					printf("Elemento eliminado.\n");

					delete temp; //Se elimina el nodo
					size--;
				}
				else { //El nodo de la lista está entre el inicio y el final.
					printf("Elemento eliminado\n");

					temporal->next = temp->next;

					NodoT<T>* iterador = temporal->next;

					//Los iteradores que le sigan al iterador eliminado, reducirá su numero en 1
					while (iterador != NULL) {
						iterador->index--;
						iterador = iterador->next;
					}
					size--;
					delete temp; //Se elimina el nódo
				}
			}



		}


	}
}

/*Se busca algo en el indice que se introduce
	@param se introduce un indice que se quiere obtener
	@return te regresa el valor que se encuentra en ese índice*/
template<class T>
NodoT<T>* ListaT<T>::get_at(int index) {
	bool found = true;

	// Devuelve true en la primera aparición del valor en algún nodo


	if (first == NULL) { //La lista es nula, por lo que no hay nada que buscar.
		std::cout << "No hay nada en tu lista.\n";
		return NULL;
	}
	if (first == last) { //Un sólo elemento en la lista
		if (first->index == index) { //El óndice del nodo es igual al índice que se pide
			std::cout << "Nodo encontrado\n" << first->value;

			return first;

		}
		else {
			printf("No hay ningun nodo con ese indice en esta lista\n");
			return NULL;
		}
	}
	else { //Más de un elemento en la lista

			NodoT<T>* it = first;

			while (it != NULL) { //Mientras el iterador no encuentre el índice, recorre la lista

				if (it->index == index) { //Algún elemento de la lista contendrá el índice
					std::cout << "El Nodo con el valor " << it->value << " fue encontrado en el indice " << it->index << "\n";
					return it; //Regresa el iterador con el índice
				}
				else { //No se encontró el elemento en el contenedor
					found = false; //entra en este bool
				}

				it = it->next;
			}

			if (found == false) { //Si bool es negativo, haz esto.
				printf("No hay ningun nodo con ese indice en esta lista\n");
				return NULL;
			}
	}
	
}

/*
	Se imprime todos los valores de la lista
*/
template<class T>
void ListaT<T>::print() {
	NodoT<T>* it = first; // se crea un "iterador"

	if (size > 0) {
		while (it != NULL) { // si el iterador no es nulo...
			std::cout << "Numero: " << it->value << " Indice: " << it->index << std::endl; // imprime el valor del iterador
			it = it->next; // se actualiza el iterador por el siguiente nodo en la lista
			// si it->next es null, entonces it será null, y se detendrá el While.
		}

	}
	else {
		printf("Lista vacia\n");
	}
	printf("Tamano: %i %s", size, "\n");
}


template<class T>
/*Acomoda el numero de menor a mayor*/
void ListaT<T>::BubbleSort() {

	//NodoT<T>* iterador = first;
	//if (iterador == NULL) { //Ningún elemento de la lista
	//	printf("No se puede acomodar una lista vacia\n");
	//}
	//else {
	//	while (iterador != NULL) //Buscar en todo el contenedor.
	//	{		
	//		if (iterador->value > iterador->next->value)
	//		{
	//			if(iterador == first)
	//			{
	//				first = iterador->next;
	//				NodoT<T>* temporal = iterador->next->next; //temporal es el apuntador del siguiente al iterador
	//				iterador->next->next = iterador; //el apuntador del iterador es igual al elemento siguiente de iterador->next
	//				iterador->next = temporal; //El siguiente del iterador es el iteador
	//			}
	//			if(iterador == last)
	//			{
	//				
	//				NodoT<T>* temp = iterador->next->next;
	//				iterador->next->next = iterador; //el apuntador del iterador es igual al elemento siguiente de iterador->next
	//				iterador->next = temp; //El siguiente del iterador es el iteador
	//			}
	//			else
	//			{
	//				/*temporal = iterador->next->next;
	//				iterador->next = iterador;
	//				iterador->next = temporal;*/
	//			}
	//			
	//			
	//			iterador = iterador->next;
	//		} else
	//			iterador = iterador->next; 
	//		
	//	}
	//	/*NodoT<T>* i, * j;
	//	for (i = first; i->next != NULL; i = i->next) {
	//		for (j = i->next; j != NULL; j = j->next) {
	//			if (i->value > j->value) {
	//				NodoT<T>* temp = i->next;
	//				i->next = j->next;
	//				j->next = temp;
	//			}
	//		}
	//	}*/
	//	/*NodoT<T>* iterador;
	//	NodoT<T>* iterador2;
	//	NodoT<T>* temp;
	//	for (iterador = first; iterador->next != NULL; iterador = iterador->next) {
	//		for (iterador2 = iterador->next; iterador2 != NULL; iterador2 = iterador2->next) {
	//			
	//			if (iterador->value > iterador2->value) 
	//			{
	//				if (iterador->next = iterador2) {
	//					iterador->next = iterador2->next;
	//					iterador2->next = iterador;				
	//				}
	//				else
	//				{
	//					temp = iterador->next;
	//					iterador->next = iterador2->next;
	//					iterador2->next = temp;
	//					Before(iterador2)->next = iterador;						
	//				}
	//				if(Before(iterador) == NULL)
	//				{
	//					first = iterador2;
	//				} else
	//				{
	//					Before(iterador)->next = iterador2;
	//				}
	//			}
	//			
	//			temp = iterador;
	//			iterador = iterador2;
	//			iterador2 = temp;
	//		}
	//	}*/
	//}

	if(size > 0)
	{
		NodoT<T>* behind = nullptr, * ahead, * it;
		bool swap = true; //saber si se realizó un cambio

		while(swap)
		{
			it = first;
			swap = false;
			while(it->next != NULL)
			{
				if(it == first)  // El iterador se encuentra en el primer lugar
				{
					if(it->value > it->next->value)
					{
						first = it->next; //El segundo se vuelve el primero en la lista

						ahead = it->next->next; //Ahead toma la posición del siguiente a it
						it->next->next = it; //El siguiente del segundo se vuelve el primero
						it->next = ahead; //el siguiente del primero, se vuelve el valor donde estaba el segundo, es decir ahead
						it = first; //El primero ahora es el segundo
						swap = true;
					}
					behind = it;
					it = it->next;
				}
				else if(it->value > it->next->value)
				{
					behind->next = it->next;
					ahead = it->next->next;
					it->next->next = it;
					it->next = ahead;
					behind = behind->next;
					swap = true;
				}
				else
				{
					behind = it;
					it = it->next;
				}

			}
		}

	}
}

/**/
template<class T>
void ListaT<T>::InsertionSort()
{

	NodoT<T> *ahead, *behind = nullptr; 
	NodoT<T>* it1 = first;
	NodoT<T>* it2;
	bool swap = true;
	
	if(first == NULL)
		printf("Can't insert sort this list.\n");
	while(swap)
	{
		
		swap = false;
		it2 = it1->next;
		while(it1 != NULL)
		{
			if(it1 == first)
			{
				if(it1->value > it2->value)
				{
					first = it2;
					ahead = it2->next;
					it2->next = it1;
					it1->next = ahead;
					//it1 = first;
					swap = true;
				}
				behind = it1;
				it1 = it1->next;
			}
			else if(it1->value > it2->value)
			{
				ahead = it2->next;
				it2->next = it1;
				it1->next = ahead;
			}
			else
			{
				
				it1 = it1->next;
				it2 = it2->next;
			}
		}
	}


}

template<class T>
NodoT<T>* ListaT<T>::swap(NodoT<T>* ptr1, NodoT<T>* ptr2)
{
	ptr1->next = ptr2->next;
	ptr2->next = ptr1;

	return ptr2;
}

