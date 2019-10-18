#ifndef Nodo_h
#define Nodo_h
#include <iostream>

class Nodo
{

public:
	Nodo* next;

	int value;
	int index;

	Nodo(int val) : value(val) {
		next = NULL;
		index = 0;
	};
};

#endif Nodo_h