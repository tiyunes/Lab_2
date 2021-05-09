#include "SEQUENCE.H"
#include "LinkedList.h"
#ifndef LINKEDLISTSEQUENCE_H
#define LINKEDLISTSEQUENCE_H

template <class T>
class LinkedListSequence: public Sequence<T>
{
public:
    friend class LinkedList<T>;

    LinkedListSequence()
    {
        this->items = new LinkedList<T>();
    }

    LinkedListSequence(T* items, int c)
    {
        this->items = new LinkedList<T>(items, c);
    }

    LinkedListSequence(const LinkedList<T>& l)
    {
        this->items = new LinkedList<T>(l);
    }

    LinkedListSequence(const LinkedListSequence<T>& l)
    {
        this->items = new LinkedList<T>(l.items);
    }

    T GetFirst() override
    {
        return this->items->GetFirst();
    }

    T GetLast() override
    {
        return this->items->GetLast();
    }

    T Get(int index) override
    {
        return this->items->Get(index);
    }

    int GetLength() override
    {
        return this->items->GetLength();
    }

    void Append(T item) override
    {
        this->items->Append(item);
    }

    void Prepend(T item) override
    {
        this->items->Prepend(item);
    }

    void InsertAt(T item, int index) override
    {
        this->items->InsertAt(item, index);
    }

    void Pop() override
    {
        return this->items->Pop();
    }

    void Reverse() override
    {
        return this->items->Reverse();
    }

    Sequence<T>* GetSubsequence(int startIndex, int endIndex) override
    {
        LinkedListSequence<T>* subList = new LinkedListSequence<T>(*(this->items->GetSubList(startIndex, endIndex)));
        subList->items->Size = endIndex - startIndex + 1;
        return subList;
    }

    Sequence<T>* Concat(Sequence <T> *l) override
    {
        Sequence<T>* concatSequence = (Sequence<T>*)new LinkedListSequence<T>();
        for (int i = 0; i < this->GetLength(); i++)
        {
            concatSequence->Append(this->Get(i));
        }
        for (int i = 0; i < l->GetLength(); i++)
        {
            concatSequence->Append(l->Get(i));
        }
        return concatSequence;
    }

    ~LinkedListSequence()
    {
        delete[] this->items;
    }
protected:

private:
    LinkedList<T>* items;
};

#endif // LINKEDLISTSEQUENCE_H

