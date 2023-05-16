#pragma once
#include<vcruntime.h>
template <typename T = double>
class ParameterizedQueue
{
	T* array;
	int size = 0;
	int maxSize;
public:
	ParameterizedQueue()
	{
		array = new T[1];
		maxSize = 1;
	}
	ParameterizedQueue(int n)
	{
		array = new T[n];
		maxSize = n;
	}
	ParameterizedQueue(int s, T* D, T* I)
	{
		array = new T[s];
		maxSize = s;
		size = s;
		for (int i = 0; i < s; i++)
		{
			array[i] = I[i];
		}
	}
	~ParameterizedQueue()
	{
		if (array)
			delete[]array;
		size = 0;
	}
	int getSize()
	{
		return size;
	}
	void Add(T value)
	{
		if (size == maxSize)
		{
			maxSize *= 2;
			T* a = new T[maxSize];
			for (int i = 0; i < size; i++)
			{
				a[i] = array[i];
			}
			if (array)
				delete[]array;
			array = a;
		}
		array[size] = value;
		size++;
	}
	void Pop()
	{
		if (size > 1)
		{
			for (int i = 0; i < size - 1; i++)
			{
				array[i] = array[i + 1];
			}
		}
		if (size > 0)
			size--;
	}
	T& operator[](int);
};


