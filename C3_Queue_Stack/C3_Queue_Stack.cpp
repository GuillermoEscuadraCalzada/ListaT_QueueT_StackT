#include "Stack.h"
#include "StackT.h"
#include "Queue.h"
#include "QueueT.h"
#include "ListaT.h"
#include "TreeT.h"
#include <Windows.h>


int main()
{
	ListaT<int> l;

	l.push_back(4);
	l.push_back(3);
	//l.push_back(2);
	/*l.push_back(1);
	l.push_back(3);
	l.push_back(7);*/
	printf("List before Insertion Sort\n");
	l.print();
	printf("\nList after Insertion Sort\n");
	l.InsertionSort();
	l.print();


	/*printf("Arbol\n");
	TreeT<int> tree;

	tree.insert(tree.root, 15);
	tree.insert(tree.root, 10);
	tree.insert(tree.root, 9);
	tree.insert(tree.root, 18);
	tree.insert(tree.root, 11);
	tree.insert(tree.root, 16);
	
	tree.print(tree.root, 0);
	tree.deleteNode(tree.root, 16);

	printf("\n\nDeleted node\n\n");
	tree.print(tree.root, 0);


	int number;
	while(!GetAsyncKeyState(VK_ESCAPE))
	{
		printf("Busca un numero:\n");
	
		std::cin >> number;
	
		if(tree.find(tree.root,number) == true)
			printf("Encontrado\n");
	
		else
			printf("No encontrado\n");
	}*/
	

}
