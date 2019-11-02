#pragma once
#include "NodoT.h"

/*MyCodeSchool, 2019, Tree Data Structure. Ayuda obtenida de:
	https://www.youtube.com/channel/UClEEsT7DkdVO_fkrBw0OTrA 
*/

template<class T>
class TreeT
{
public:
	NodoT<T>* root; //Raíz del árbol

	int size; //Tamaño del árbol

	TreeT()
	{
		//root = NULL;	//Estos valores son nulos
		root = new NodoT<T>(NULL);
		size = 0;
	}
	~TreeT(){}

	NodoT<T>* insert(NodoT<T>*root, T val);
	NodoT<T>* deleteNode(NodoT<T>* root, T val);
	NodoT<T>* FindMint(NodoT<T>* root);

	bool find(NodoT<T>* root, T val);
	void print(NodoT<T>* root, int n);
};



/*Se pueden ingresar cualquier tipo de valor al árbol. Se buscará si el valor ingresado es igual, mayor o menor a la raíz. Si es menor, se irá al lado izquierdo,  
  si no se irá al lado derecho.
	@param valor que se desea ingresar al árbol.*/
template<class T>
NodoT<T>* TreeT<T>::insert(NodoT<T>* root, T val)
{
	if(root == NULL)
	{
		root = new NodoT<T>(val); //Si esta raíz es nula, crea un Nodo con este valor
		size++;
	}
	else if(val <= root->value) //Si el valor de esta raíz es mayor al de VAL...
	{	
		root->left = insert(root->left, val);  //...avanza a la raíz de la izquierda y repite la acción.
		size++;
	}
	else //En caso de que el valor de la raíz sea menor a VAL...
	{
		root->right = insert(root->right, val); //... avanza a la raíz de la derecha y repite la acción.
		size++;
	}

	return root;
}

template<class T>
inline NodoT<T>* TreeT<T>::deleteNode(NodoT<T>* treeRoot, T val)
{
	if(treeRoot == NULL)
		return treeRoot;

	else if(val < treeRoot->value) //Si el valor es menor al de la raíz..-
		treeRoot->left = deleteNode(treeRoot->left, val); //... Avanza a la izquierda y repite la pregunta
	
	else if(val > treeRoot->value) //Si el valor es mayor al de la raíz ...
		treeRoot->right = deleteNode(treeRoot->right, val); //...Avanza a la derecha

	else //Si el valor es igual al de la raíz, pregunta lo siguiente
	{
		/*Si left y right son nulos, borra este valor y conviertelo en nulo*/
		if(treeRoot->right == NULL && treeRoot->left == NULL)
		{
			delete treeRoot;
			treeRoot = NULL;
			size--;
		}
		/*Si la raíz no tiene ningún valor del lado izquierdo, avanza a la derecha y luego borra ese valor*/
		else if(treeRoot->left == NULL)
		{
			NodoT<T>* temp = treeRoot; //Valor temporal
			treeRoot = treeRoot->right; //la raíz avanza al de la derecha
			delete temp; //Borra el valor de temp
			size--;
		}
		/*Si la derecha no existe, avanza a la izquierda y luego borra ese valor.*/
		else if(treeRoot->right == NULL)
		{
			NodoT<T>* temp = treeRoot; //Guarda el valor de la raíz 
			treeRoot = treeRoot->left; //La raíz avanza a la izquierda
			delete temp; //Borra el temporal
			size--;
		}
		//Si encuentras el valor en alguna raíz, regresa este elemento.
		else
		{
			NodoT<T>* temp = FindMint(treeRoot->right); //Si s encuentra el valor, busca si hay algún valor a la izquierda, si no, guardalo
			treeRoot->value = temp->value; //El valor de la raíz se obtiene al del temporal
			treeRoot->right = deleteNode(treeRoot->right, temp->value); //Busca borrar el de la derecha
			size--;
		}
	}
	return treeRoot;
}

/*Busca si hay alguien a la izquierda en esta raíz.
	@param raíz actual.*/
template<class T>
inline NodoT<T>* TreeT<T>::FindMint(NodoT<T>* root)
{

	if(root == NULL)
	{		printf("Arbol vacio.\n");
		return root;
	}
	else if(root->left != NULL) //Si el izquierdo de esta raíz es diferente de nulo
	{
		return FindMint(root->left); //Regresa el izquierdo
	}

	return root;
}

/*Buscará el valor deseado dentro de la familia del árbol, del lado izquiero siempre serán menor a los del lado derecho.
	@param raíz de donde se comienza cada rama, valor que se va a ingresar*/
template<class T>
inline bool TreeT<T>::find(NodoT<T>* root, T val)
{
	if(root == NULL) //Si la raíz es nula no existe VAL
		return false;
	else if(root->value == val)  //Si la raíz contiene el valor, regresa verdadero
		return true;
	else if(root->value >= val)
		return find(root->left, val); //Si VAL es menor al valor de la raíz avanza a la raíz de la izquierda
	else if(root->value <= val)
		return find(root->right, val); //Si VAL es mayor al valor de la raíz avanza a la raíz de la derecha
	
}

/*Se imprimen los valores del arbos, los de la derecha aparecen en la partida de la raíz del árbol y los de la izquierda en la parte inferior.
	@param Raíz de cada rama del árbol, número de espacio original.*/
template<class T>
void TreeT<T>::print(NodoT<T>* arbol, int n) 
{
	if(arbol == NULL)
		return;

	print(arbol->right, n + 1); //Imprime la partee de la derecha del árbol

	std::cout << "\n"; //Hace un salto antes de entrar a la siguiente función.

	for(int i = 0; i < n; i++) //Hace separaciones entre los valores del árbol
		std::cout << "   ";

	std::cout << arbol->value << "\n"; //Imprime el valor y hace un salto de línea.

	print(arbol->left, n + 1); //Imprime la parte de la izquierda del árbol
}