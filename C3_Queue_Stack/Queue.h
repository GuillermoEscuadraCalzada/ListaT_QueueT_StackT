#include "Nodo.h"

class Queue
{
public:
	Nodo* first; //Primer elemento del stack
	Nodo* last; // Último elemento del stack
	int size; //Tamaño del stack

	Queue() {
		first = NULL;
		last = NULL;
		size = 0;
	};

	~Queue() {};

	void push_back(int val);
	
	bool search(int val);

	void print();

	void pop_front();
};

