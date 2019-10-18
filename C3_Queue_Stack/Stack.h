#include "Nodo.h"

class Stack
{
public:
	Nodo* first; //Primer elemento del stack
	Nodo* last; // Último elemento del stack
	int size; //Tamaño del stack

	Stack() {
		first = NULL;
		last = NULL;
		size = 0;
	};
	~Stack() {};

	void push_front(int val);

	void print();

	bool search(int val);

	void pop_back();

};

