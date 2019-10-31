#pragma once
#include "NodoT.h"

template<class T>
class TreeT
{
public:
	NodoT<T>* root; //Raíz del árboñ
	NodoT<T>* left; //Lado izquierdo del árbol
	NodoT<T>* right; //Lado derecho del árbol
	int size; //Tamaño del árbol

	TreeT(){
		root = NULL;	//Estos valores son nulos
		right = NULL;	//Estos valores son nulos
		left = NULL;	//Estos valores son nulos
	}
	~TreeT(){}

	NodoT<T>* insert(T val);
	void deleteValue(T val);
	bool find(T val);
	void print();
};

/*Se pueden ingresar cualquier tipo de valor al árbol. Se buscará si el valor ingresado es igual, mayor o menor a la raíz. Si es menor, se irá al lado izquierdo,  
  si no se irá al lado derecho.
	@param valor que se desea ingresar al árbol.*/
template<class T>
inline NodoT<T>* TreeT<T>::insert(T val)
{
	
	if(root == NULL)
	{
		root = new NodoT<T>(val);
		//std::cout << root->value<<"\n";
		size++;
	}
	else if(val <= root->value)
	{
		left = new NodoT<T>(val);
		//std::cout << left->value << "\n";

		size++;
	}
	else
	{
		right = new NodoT<T>(val);
		//std::cout << right->value << "\n";

		size++;
	}

	return root;
}

template<class T>
inline void TreeT<T>::deleteValue(T val)
{

}

/*Buscará el valor deseado dentro de la familia del árbol, del lado izquiero siempre serán menor a los del lado derecho. */
template<class T>
inline bool TreeT<T>::find(T val)
{
	
	if(root == NULL)
		return false;

	else if(root->value == val)
		return true;

	else if(val <= root->value)
	{

	}
	else if(val >= root->value)
	{
			
	}
	else
	{
		return false;
	}
	
}


template<class T>
inline void TreeT<T>::print() 
{
}