#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

#pragma warning(disable : 4996)
using namespace std;

template <typename T>
void ChangeMinMax(T* a, int s)
{
	if (a == NULL)return;
	int maxIn = 0; //індекс мах елемента
	int minIn = 0;
	T curMax = a[0]; // мах елемент
	T curMin = a[0];
	for (int i = 1; i < s; i++)
	{
		if (a[i] > curMax)
		{
			curMax = a[i];
			maxIn = i;
		}
		if (a[i] < curMin)
		{
			curMin = a[i];
			minIn = i;
		}
	}
	T c = a[minIn]; //додаткова змінна
	a[minIn] = a[maxIn];
	a[maxIn] = c;
}


template<>
void ChangeMinMax(char** a, int s)
{

	if (a == NULL)return;
	int maxIn = 0;
	int minIn = 0;
	char* curMax = a[0];
	char* curMin = a[0];

	for (int i = 1; i < s; i++)
	{
		if (strcmp(curMax, a[i]) == -1)
		{
			curMax = a[i];
			maxIn = i;
		}
		if (strcmp(curMin, a[i]) == 1)
		{
			curMin = a[i];
			minIn = i;
		}
	}

	char* c = new char[30];
	c = a[minIn];
	a[minIn] = curMax;
	a[maxIn] = curMin;
}



