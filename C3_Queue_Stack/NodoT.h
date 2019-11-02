#pragma once
#include <iostream>

template<class T>
class NodoT
{
public:
	T value;
	NodoT* next;
	NodoT* prev;
	NodoT* left; //Lado izquierdo del �rbol
	NodoT* right; //Lado derecho del �rbol

	int index;
	NodoT(T v) : value(v) {
		next = right = left = prev = NULL;
		index = 0;
	}; ~NodoT() {};

};

