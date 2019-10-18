#include "Nodo.h"

class Stack
{
public:
	Nodo* first; //Primer elemento del stack
	Nodo* last; // �ltimo elemento del stack
	int size; //Tama�o del stack

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

