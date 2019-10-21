#include "Stack.h"
#include "StackT.h"
#include "Queue.h"
#include "QueueT.h"
#include "ListaT.h"

int main()
{
	ListaT<int> l;


	//l.push_back(6);
	l.push_back(5);
	l.push_back(4);
	l.push_back(3);
	l.push_back(2);
	
	l.sort();
	l.print();


}
