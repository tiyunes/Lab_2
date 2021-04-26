#include "ArraySequence.h"

template<class T>
ArraySequence<T>::ArraySequence(int size)
{
    this->items = new DynamicArray<T>(size);
}

template<class T>
ArraySequence<T>::ArraySequence(T* items, int c)
{
    this->items = new DynamicArray<T>(items, c);
}

template<class T>
ArraySequence<T>::ArraySequence(const DynamicArray<T>& dynamicArray)
{
    this->items = new DynamicArray<T>(dynamicArray);
}

template<class T>
T ArraySequence<T>::GetFirst()
{
    return this->items->Get(0);
}

template<class T>
T ArraySequence<T>::GetLast()
{
    return this->items->Get(this->items->size - 1);
}

template<class T>
T ArraySequence<T>::Get(int index)
{
    return this->items->Get(index);
}

template<class T>
int ArraySequence<T>::GetLength()
{
    return this->items->GetSize();
}

template<class T>
void ArraySequence<T>::Append(T item)
{
    this->items->Resize(this->items->size + 1);
    this->items->Set(this->items->size - 1, item);
}

template<class T>
void ArraySequence<T>::Prepend(T item)
{
    this->items->Resize(this->items->size + 1);
    this->items->Set(0, item);
}

template<class T>
void ArraySequence<T>::InsertAt(T item, int index)
{
    this->items->Resize(this->items->size + 1);
    this->items->Set(index, item);
}

template<class T>
Sequence<T>* ArraySequence<T>::GetSubsequence(int startIndex, int endIndex)
{
    ArraySequence<T>* subArray = new ArraySequence<T>(endIndex - startIndex + 1);
    for (int i = 0; i < endIndex - startIndex + 1; i++)
    {
        subArray->items->Set(i, this->items->Get(i + startIndex));
    }
    return subArray;
}

template<class T>
Sequence<T>* ArraySequence<T>::Concat(Sequence <T> *l)
{
    ArraySequence<T>* concatArray = new ArraySequence<T>(*l);
    concatArray->items->Resize(l->size + this->items->size);
    for (int i = 0; i < this->items->size; i++)
    {
        concatArray->items->Set(i + l->size, this->items->Get(i));
    }
    return concatArray;
}
