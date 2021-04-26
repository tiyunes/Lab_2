/*
#include <stdexcept>
#include "DynamicArray.h"

template<class T>
DynamicArray<T>::DynamicArray(int size)
{
    this->values = new T[size];
    for (int i = 0; i < size; i++)
    {
        this->values[i] = 0;
    }
    this->size = size;
}

template<class T>
DynamicArray<T>::DynamicArray(T* items, int c)
{
    DynamicArray<T> temp(c);
    this->values = new T[c];
    for (int i = 0; i < c; i++)
    {
        temp.Set(i, items[i]);
    }
    this->values = temp.values;
    this->size = c;
}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& dynamicArray)
{
    this->size = dynamicArray.size;
    this->values = new T[dynamicArray.size];
    for (int i = 0; i < dynamicArray.size; i++)
    {
        this->values[i] = dynamicArray.values[i];
    }
}

template<class T>
T DynamicArray<T>::Get(int index)
{
    if (index < 0 || index >= this->GetSize())
    {
        throw std::out_of_range("Invalid index");
    }
    return this->values[index];
}

template<class T>
int DynamicArray<T>::GetSize()
{
    return this->size;
}

template<class T>
T& DynamicArray<T>::operator[](int index)
{
    return this->values[index];
}

template<class T>
void DynamicArray<T>::Set(int index, T value)
{
    if (index < 0 || index >= this->GetSize())
    {
        throw std::out_of_range("Invalid index");
    }
    this->values[index] = value;
}

template<class T>
void DynamicArray<T>::Resize(int newSize)
{
    int i;
    int *newValues = new T[newSize];
    for (i = 0; i < newSize; i++)
    {
        newValues[i] = this->values[i];
    }
    if (newSize > this->size)
    {
        for (int j = newSize; j < this->size; j++)
        {
            newValues[j] = 0;
        }
    }
    delete[]this->values;
    this->values = newValues;
    this->size = newSize;
}
*/
