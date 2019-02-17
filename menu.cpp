#include "menu.h";
#include <conio.h>

A cor_access = PUBLIC;
private_queue   q_private;
public_queue    q_public;
protected_queue q_protected;
private_queue   *qptr_private = &q_private;
public_queue    *qptr_public = &q_public;
protected_queue *qptr_protected = &q_protected;

void help(void)
{
	cout << "0 - help" << endl;
	cout << "1 - Push a element to queue" << endl;
	cout << "2 - Pop a element from queue" << endl;
	cout << "3 - Show Queue" << endl;
	cout << "4 - Calcul task" << endl;
	cout << "5 - Create copy queue" << endl;
	cout << "6 - Merge Original queue with copy and show result" << endl;
	cout << "7 - Exit" << endl;
	cout << "8 - Show copy Queue" << endl;
	cout << "9 - Change queue" << endl;
}

void push(void)
{
	int myValue;
	cout << "Enter value" << endl; 
	cin >> ws >> myValue;		
	switch(cor_access)
	{
	case PUBLIC:
		(*qptr_public) + (new elem(myValue));
		break;
	case PROTECTED:
		(*qptr_protected) + (new elem(myValue));
		break;
	case PRIVATE:
		(*qptr_private) + (new elem(myValue));
		break;
	}
}

void pop(void)
{
	switch(cor_access)
	{
	case PUBLIC:
		cout << qptr_public->pop();
		break;
	case PROTECTED:
		cout << qptr_protected->pop();
		break;
	case PRIVATE:
		cout << qptr_private->pop();
		break;
	}
	cout << endl;
}

void show(void)
{
	switch(cor_access)
	{
	case PUBLIC:
		cout << "Accesse public" << endl;		
		cout << qptr_public;
		break;
	case PROTECTED:
		cout << "Accesse protected" << endl;		
		cout << qptr_protected;
		break;
	case PRIVATE:
		cout << "Accesse private" << endl;		
		cout << qptr_private;
		break;
	}
}

void calcul(void)
{
	int tmp;
	switch(cor_access)
	{
	case PUBLIC:
		tmp = qptr_public->calcul();
		break;
	case PROTECTED:
		tmp = qptr_protected->calcul();
		break;
	case PRIVATE:
		tmp = qptr_private->calcul();
		break;
	}
	cout << "Calcul value = " << tmp << endl;
}

base_queue *copy(void)
{
	base_queue *tmp;
	switch(cor_access)
	{
	case PUBLIC:
		tmp = qptr_public->copy();
		break;
	case PROTECTED:
		tmp = qptr_protected->copy();
		break;
	case PRIVATE:
		tmp = qptr_private->copy();
		break;
	}
	return tmp;
}

void merge(base_queue *secondQ)
{
	switch(cor_access)
	{
	case PUBLIC:
		*qptr_public + secondQ;
		break;
	case PROTECTED:
		*qptr_protected + secondQ;
		break;
	case PRIVATE:
		*qptr_private + secondQ;	
		break;
	}
}

void setAccess(void)
{ 
	for(;;)
	{
		switch(_getch()-'0')
		{
		case 0:
			cor_access = PUBLIC;
			cout << "Selected public" << endl;
			return;
		case 1:
			cor_access = PROTECTED;
			cout << "Selected protected" << endl;
			return;
		case 2:
			cor_access = PRIVATE;
			cout << "Selected private" << endl;
			return;
		default:
			cout << "Invalid access modifier!!!" << endl;
		}
		cout << "Repeat enter access modifier" << endl;
	}
}