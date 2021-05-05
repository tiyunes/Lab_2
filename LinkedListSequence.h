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
<<<<<<< HEAD
    
=======

>>>>>>> 9fcefc7 (Added tests)
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
<<<<<<< HEAD
    
=======

>>>>>>> 9fcefc7 (Added tests)
    T GetLast() override
    {
        return this->items->GetLast();
    }
<<<<<<< HEAD
    
=======

>>>>>>> 9fcefc7 (Added tests)
    T Get(int index) override
    {
        return this->items->Get(index);
    }
<<<<<<< HEAD
    
=======

>>>>>>> 9fcefc7 (Added tests)
    int GetLength() override
    {
        return this->items->GetLength();
    }
<<<<<<< HEAD
    
=======

>>>>>>> 9fcefc7 (Added tests)
    void Append(T item) override
    {
        this->items->Append(item);
    }
<<<<<<< HEAD
    
=======

>>>>>>> 9fcefc7 (Added tests)
    void Prepend(T item) override
    {
        this->items->Prepend(item);
    }
<<<<<<< HEAD
    
=======

>>>>>>> 9fcefc7 (Added tests)
    void InsertAt(T item, int index) override
    {
        this->items->InsertAt(item, index);
    }
<<<<<<< HEAD
    
=======

>>>>>>> 9fcefc7 (Added tests)
    void Pop() override
    {
        return this->items->Pop();
    }
<<<<<<< HEAD
    
=======

>>>>>>> 9fcefc7 (Added tests)
    void Reverse() override
    {
        return this->items->Reverse();
    }
<<<<<<< HEAD
    
=======

>>>>>>> 9fcefc7 (Added tests)
    Sequence<T>* GetSubsequence(int startIndex, int endIndex) override
    {
        LinkedListSequence<T>* subList = new LinkedListSequence<T>(*(this->items->GetSubList(startIndex, endIndex)));
        subList->items->Size = endIndex - startIndex + 1;
        return subList;
    }
<<<<<<< HEAD
    
=======

>>>>>>> 9fcefc7 (Added tests)
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
<<<<<<< HEAD
    
=======

>>>>>>> 9fcefc7 (Added tests)
    ~LinkedListSequence()
    {
        delete[] this->items;
    }
protected:

private:
    LinkedList<T>* items;
};

#endif // LINKEDLISTSEQUENCE_H

