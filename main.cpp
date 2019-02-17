#pragma once
#include <conio.h>
#include "menu.h"

int main(void)
{
	char command;
	base_queue *copyQueue  = 0;
	base_queue *tmp;
	cout << "Hello, enter command(0-9):" << endl;
	for(;;)
	{ 
		try
		{
			switch((command = _getch())-'0')
			{
			case 0:
				help();
				break;
			case 1:
				cout << "Selected, push element" << endl;
				push();
				break;
			case 2:
				cout << "Selected, pop element" << endl;
				pop();
				break;
			case 3:
				cout << "Selected, show original queue" << endl;
				show();
				break;
			case 4:
				cout << "Selected, calcul" << endl;
				calcul();
				break;
			case 5:
				cout << "Selected, create copy" << endl;
				tmp = copy();
				delete copyQueue;
				copyQueue = tmp;
				cout << "Copy create" << endl;
				break;
			case 6:
				cout << "Selected, merge with copy" << endl;
				merge(copyQueue);
				cout << "Queues merge competed" << endl;
				show();
				break;
			case 7:
				cout << "Goodbye"<< endl;
				system("pause");
				delete copyQueue;
				return 0;
			case 8 :
				cout << "Selected, show copy!" << endl;
				cout << "Copy queue:" << endl;
				cout << copyQueue;
				break;
			case 9:
				cout << "Select access modifier (public - 0, protected - 1, private - 2)" << endl;
				setAccess();
				cout << "Change access queue completed" << endl;
				break;
			default:
				cout << "Error, this command: '" << command << "' not found!" << endl;
				cout << "command 0 - help" << endl;
			}
			system("pause");
			system("cls");
			cout << "Please enter comand" << endl;
		}
		catch(myException a)
		{
			cout << a;
		}
	}
}