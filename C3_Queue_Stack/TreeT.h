#pragma once
#include "NodoT.h"

template<class T>
class TreeT
{
public:
	NodoT<T>* root; //Ra�z del �rbo�
	NodoT<T>* left; //Lado izquierdo del �rbol
	NodoT<T>* right; //Lado derecho del �rbol
	int size; //Tama�o del �rbol

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

/*Se pueden ingresar cualquier tipo de valor al �rbol. Se buscar� si el valor ingresado es igual, mayor o menor a la ra�z. Si es menor, se ir� al lado izquierdo,  
  si no se ir� al lado derecho.
	@param valor que se desea ingresar al �rbol.*/
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

/*Buscar� el valor deseado dentro de la familia del �rbol, del lado izquiero siempre ser�n menor a los del lado derecho. */
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