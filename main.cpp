#pragma once
#include <conio.h>

#include "base_queue.h"

using namespace std;

int main(void)
{
	char command;
	base_queue *copyQueue = 0;
	base_queue *queue = new public_queue;
	base_queue *tmp;
	cout << "Hello, enter command(0-9):" << endl;
	for(;;)
	{ 
		try
		{
			switch((command = _getch())-'0')
			{
			case 0:
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
				break;
			case 1:
				cout << "Selected, push element" << endl;
				int myValue;
				cout << "Enter value" << endl; 
				cin >> ws >> myValue;	
				*queue + new elem(myValue);
				break;
			case 2:
				cout << "Selected, pop element" << endl;
				queue->pop();
				break;
			case 3:
				cout << "Selected, show original queue" << endl;
				cout << queue;
				break;
			case 4:
				cout << "Selected, calcul" << endl;
				cout << "Calcul value = " << queue->calcul() << endl;
				break;
			case 5:
				cout << "Selected, create copy" << endl;
				tmp = queue->copy();
				delete copyQueue;
				copyQueue = tmp;
				cout << "Copy create" << endl;
				break;
			case 6:
				cout << "Selected, merge with copy" << endl;
				*queue + copyQueue;
				cout << "Queues merge competed" << endl;
				break;
			case 7:
				cout << "Goodbye"<< endl;
				system("pause");
				delete queue;
				delete copyQueue;
				return 0;
			case 8 :
				cout << "Selected, show copy!" << endl;
				cout << "Copy queue:" << endl;
				cout << copyQueue;
				break;
			case 9:
				cout << "Select access modifier (public - 0, protected - 1, private - 2)" << endl;
				delete queue;
				queue = 0;
				for(;;)
				{
					switch(_getch())
					{
					case '0':
						queue = new public_queue;
						cout << "Selected public" << endl;
						break;
					case '1':
						queue = protected_queue::get_ptr();
						cout << "Selected protected" << endl;
						break;
					case '2':
						queue = private_queue::get_ptr();
						cout << "Selected private" << endl;
						break;
					default:
						cout << "Invalid access modifier!!!" << endl;
						cout << "Repeat enter access modifier" << endl;
					}
					if(queue != NULL)
						break;
				}
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