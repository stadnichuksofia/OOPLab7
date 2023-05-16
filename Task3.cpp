#pragma once
#include <vcruntime_exception.h>
#include<vcruntime.h>
#include "Task3.h"
template<typename T>
T& ParameterizedQueue<T>::operator[](int index) {
	if (index >= 0 && index < size)
		return array[index];
	else throw std::exception("out of range");
}