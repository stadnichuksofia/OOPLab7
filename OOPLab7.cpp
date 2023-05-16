#include <iostream>
#include <stdio.h>
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include "Task3.cpp"
#include "Task4.h"
using namespace std;


void Task1AllType()
{
	int s;
	cout << "Enter the number of array elements (size):" << endl;
	cin >> s;
	s = max(abs(s), 1);
	cout << "Enter " << s << " ellements : " << endl;
	double* arr = new double[s];
	for (int i = 0; i < s; i++)
	{
		cin >> arr[i];
	}
	cout << "Initial array:" << endl;
	for (int i = 0; i < s; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	ChangeMinMax(arr, s);
	cout << "Result array:" << endl;
	for (int i = 0; i < s; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Task1Char()
{
	int s;
	cout << "Enter the number of strings (char elements):" << endl;
	cin >> s;
	cout << "Enter " << s << " strings: " << endl;
	char** str = new char* [30];

	cin.get();
	for (int i = 0; i < s; i++)
	{
		str[i] = new char[30];
		cin.getline(str[i], 30);
	}
	cout << "\nInitial char elements: ";
	for (int i = 0; i < s; i++)
	{
		cout << str[i] << " ";
	}
	cout << "\n" << endl;
	ChangeMinMax(str, s);
	cout << "Result char elements: ";
	for (int i = 0; i < s; i++)
	{
		cout << str[i] << " ";
	}
	cout << "\n" << endl;
}

void Task2AllType()
{
	int s;
	cout << "Enter the number of array elements (size):" << endl;
	cin >> s;
	s = max(abs(s), 1);
	cout << "Enter " << s << " ellements : " << endl;
	int* mas = new int[s];
	for (int i = 0; i < s; i++)
	{
		cin >> mas[i];
	}
	cout << "\nInitial array: ";
	for (int i = 0; i < s; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
	SortArray(mas, s);
	cout << "\nOrdered array: ";
	for (int i = 0; i < s; i++)
	{
		cout << mas[i] << " ";
	}

	int userValue;
	cout << "\n\nEnter some number: ";
	cin >> userValue;
	int index = BinarySearch(mas, 0, s - 1, userValue);
	(index == -1)
		? cout << "\nElement " << userValue << " is not present in array\n"
		: cout << "\nElement is present at index " << index << "\n" << endl;

}

void Task2Char()
{
	int s;
	cout << "Enter the number of strings (char elements):" << endl;
	cin >> s;
	cout << "Enter " << s << " strings: " << endl;
	char** str = new char* [30];
	cin.get();
	for (int i = 0; i < s; i++)
	{
		str[i] = new char[30];
		cin.getline(str[i], 30);
	}
	cout << "\nInitial char elements: ";
	for (int i = 0; i < s; i++)
	{
		cout << str[i] << " ";
	}
	SortArray(str, s);
	cout << "\nOrdered array: ";
	for (int i = 0; i < s; i++)
	{
		cout << str[i] << " ";
	}
	char* userValue = new char[30];
	cout << "\n\nEnter a string(letter): ";
	cin >> userValue;

	int index = BinarySearch(str, 0, s - 1, userValue);
	(index == -1)
		? cout << "\nElement " << userValue << " is not present in array\n"
		: cout << "\nElement is present at index " << index << "\n" << endl;

}

void Task3()
{
	ParameterizedQueue<> q = ParameterizedQueue<>();
	cout << "Enter the number of elements: " << endl;
	int s;
	cin >> s;
	double d;
	cout << "Enter " << s << " ellements: " << endl;
	for (int i = 0; i < s; i++)
	{
		cin >> d;
		q.Add(d);
	}
	cout << "All ellements: " << endl;
	for (int i = 0; i < q.getSize(); i++)
	{
		cout << q[i] << " ";
	}
	cout << endl;
	cout << endl << "Removed first 3 elements: " << endl;
	q.Pop();
	q.Pop();
	q.Pop();
	for (int i = 0; i < q.getSize(); i++)
	{
		cout << q[i] << " ";
	}
	cout << endl << endl;

}

void Task4()
{
	List<double> l = List<double>();
	cout << "Enter the number of elements: " << endl;
	int s;
	double d;
	cin >> s;
	cout << "Enter " << s << " ellements: " << endl;
	for (int i = 0; i < s; i++)
	{
		cin >> d;
		l.push(d);
	}
	cout << "All ellements: " << endl;
	for (int i = 0; i < l.length(); i++)
	{
		cout << l[i] << " ";
	}
	cout << endl;
	l.pop();
	cout << "The element standing in the current position (a * i ->):" << endl;
	for (List<double>::Iterator i = l.begin(); i != nullptr; i++)
	{
		cout << *i << " " << i->value << endl;
		//cout << *i++ << " " << i->value << endl;
	}
}

void MainMenuTask1()
{
	int select = 0;
	do
	{
		cout << "\nSelect options:\n" << endl;
		cout << "1. Another type " << endl;
		cout << "2. Char " << endl;
		cout << "0. Exit\n" << endl;
		cin >> select;
		system("cls");

		switch (select)
		{
		case 1:
			system("cls");
			Task1AllType();
			break;
		case 2:
			system("cls");
			Task1Char();
			break;
		default:
			system("cls");
			break;
		}
	} while (select != 0);
}

void MainMenuTask2()
{
	int select = 0;
	do
	{
		cout << "\nSelect options:\n" << endl;
		cout << "1. Another type " << endl;
		cout << "2. Char " << endl;
		cout << "0. Exit\n" << endl;
		cin >> select;
		system("cls");

		switch (select)
		{
		case 1:
			system("cls");
			Task2AllType();
			break;
		case 2:
			system("cls");
			Task2Char();
			break;
		default:
			system("cls");
			break;
		}
	} while (select != 0);
}

int main()
{
	setlocale(LC_ALL, "ukr");
	int f = 1;
	while (f >= 1 && f <= 4)
	{
		system("cls");
		cout << "Lab 7: " << endl;
		cout << "1 - Task 1" << endl;
		cout << "2 - Task 2: " << endl;
		cout << "3 - Task 3: " << endl;
		cout << "4 - Task 4: " << endl;
		cout << " - Exit" << endl;
		cin >> f;
		switch (f)
		{
		case 1:MainMenuTask1(); break;
		case 2:MainMenuTask2(); break;
		case 3:Task3(); break;
		case 4:Task4(); break;
		default:
			break;
		}
		system("pause");
	}
	return 0;
}