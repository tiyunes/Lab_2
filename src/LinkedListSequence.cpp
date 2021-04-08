#include "LinkedListSequence.h"

template<class T>
void LinkedListSequence<T>::Append(T item)
{
    return this->items->Append(item);
}

template<class T>
LinkedListSequence<T>::LinkedListSequence()
{
    this->items->first = nullptr;
    this->items->Size = 0;
}

template<class T>
LinkedListSequence<T>::LinkedListSequence(const LinkedList<T>& l)
{
    this->items->Size = l->Size;
    this->items->first = new T;
    this->items->first = l->first;
}

template<class T>
void LinkedListSequence<T>::Prepend(T item)
{
    return this->items->Prepend(item);
}

template<class T>
void LinkedListSequence<T>::InsertAt(T item , int index)
{
    return this->items->InsertAt(item, index);
}

template<class T>
T LinkedListSequence<T>::GetFirst()
{
    return this->items->GetFirst();
}

template<class T>
T LinkedListSequence<T>::GetLast()
{
    return this->items->GetLast();
}

template<class T>
T LinkedListSequence<T>::Get(int index)
{
    return this->items->Get(index);
}

template<class T>
Sequence<T>* LinkedListSequence<T>::GetSubsequence(int startIndex, int endIndex)
{
    return this->items->GetSubList(startIndex, endIndex);
}

template<class T>
int LinkedListSequence<T>::GetLength()
{
    return this->items->GetLength();
}

template<class T>
Sequence<T>* LinkedListSequence<T>::Concat(Sequence<T> *l)
{
    return this->items->Concat(l);
}

template<class T>
LinkedListSequence<T>::~LinkedListSequence()
{
    //dtor
}
