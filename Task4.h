#pragma once
#include <iostream>
using namespace std;
template<typename T>
struct El
{
public:
	El* prev = nullptr;
	El* next = nullptr;
	T value;
};
template<typename T>
class List
{
	El<T>* head;
public:
	List()
	{
		head = nullptr;
	}
	List(T t)
	{
		push(t);
	}
	class Iterator
	{
		El<T>* ptr;
	public:
		Iterator(El<T>* p)
		{
			ptr = p;
		}
		Iterator operator++(int i)
		{
			ptr = ptr->next;
			return *this;
		}
		Iterator operator--(int i)
		{
			ptr = ptr->prev;
			return *this;
		}
		bool operator!=(const Iterator& i1)
		{
			return i1.ptr != this->ptr;
		}
		bool operator==(const Iterator& i1)
		{
			return i1.ptr == this->ptr;
		}
		Iterator& operator=(const Iterator& i)
		{
			return this->ptr = i.ptr;
			return *this;
		}
		El<T>* operator->()
		{
			return ptr;
		}
		T& operator*()
		{
			return ptr->value;
		}
		El<T>* operator()()
		{
			return ptr;
		}
	};

	Iterator begin()
	{
		return  Iterator(head);
	}
	Iterator end()
	{
		if (head == nullptr)return nullptr;
		El<T>* temp = head;
		while (temp->next != nullptr)
			temp = temp->next;
		return  Iterator(temp);
	}
	void push(T value)
	{
		if (head == nullptr)
		{
			head = new El<T>();
			head->value = value;
			return;
		}
		El<T>* el = new El<T>();
		el->value = value;
		El<T>* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = el;
		el->prev = temp;
	}
	T pop()
	{
		if (head == nullptr)return NULL;
		El<T>* temp = end()();
		T t = temp->value;
		temp = temp->prev;
		temp->next = nullptr;
		return t;
	}
	int length()
	{
		if (head == nullptr)return 0;
		El<T>* temp = head;
		int i = 1;
		while (temp->next != nullptr)
		{
			temp = temp->next;
			i++;
		}
		return i;
	}
	T& operator[](int in)
	{
		if (in<0 || in>length())throw exception("Out of range");
		El<T>* temp = head;
		int i = 0;
		while (temp->next != nullptr && i != in)
		{
			temp = temp->next;
			i++;
		}
		return temp->value;
	}
	void show()
	{
		if (head == nullptr)
			return;
		El<T>* temp = head;
		while (temp != nullptr)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}
	}
}; 