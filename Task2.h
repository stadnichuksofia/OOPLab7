#pragma once
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

template <typename T>
void SortArray(T* a, int s)
{
	for (int i = 1; i < s; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
		}
	}
}

template <>
void SortArray(char** a, int s)
{
	for (int i = 1; i < s; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (strcmp(a[j], a[j - 1]) == -1)
			{
				char* c = new char[30];
				strcpy(c, a[j]);
				strcpy(a[j], a[j - 1]);
				strcpy(a[j - 1], c);
			}
		}
	}
}

template <typename T>
int BinarySearch(T* a, int firstIndex, int secondIndex, T userValue)
{
	if (secondIndex >= firstIndex) {
		int mid = firstIndex + (secondIndex - 1)/2;
		cout << "mid: " << mid;

		if (a[mid] == userValue) {
			return mid;
		}
		if (a[mid] > userValue) {
			return BinarySearch(a, firstIndex, mid - 1, userValue);
		}
		return BinarySearch(a, mid + 1, secondIndex, userValue);
	}
	return -1;
}

template <>
int BinarySearch(char** a, int firstIndex, int secondIndex, char* userValue)
{
	if (secondIndex >= firstIndex) {
		int mid = firstIndex + (secondIndex - 1) / 2;

		if (strcmp(a[mid], userValue) == 0) {
			return mid;
		}
		if (strcmp(a[mid], userValue) == 1) {
			return BinarySearch(a, firstIndex, mid - 1, userValue);
		}
		return BinarySearch(a, mid + 1, secondIndex, userValue);
	}
	return -1;
}