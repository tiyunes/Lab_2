#ifndef QUEUE_H
#define QUEUE_H
#include "ArraySequence.h"
#include "LinkedListSequence.h"

template<class T>
class Queue
{
public:
    Queue()
    {
        elements = (Sequence<T>*) new LinkedListSequence<T>();
        //elements = (Sequence<T>*) new ArraySequence<T>();
    }

    Queue(T* items, int size) //0.005 s (List) for 1000 elements and 0.011 s (Array) for 1M elements
    {
        this->elements = (Sequence<T>*) new LinkedListSequence<T>(items, size);
        //this->elements = (Sequence<T>*) new ArraySequence<T>(items, size);
    }

    T Front() //0.316 s (List) and 0.298 s (Array) for 1M iterations
    {
        return this->elements->GetFirst();
    }

    T Back() //0.318 s (List) and 0.274 s (Array) for 1M iterations
    {
        return this->elements->GetLast();
    }

    bool Empty()
    {
        if (this->elements->GetLength() == 0) return true;
        else return false;
    }

    int Size()
    {
        return this->elements->GetLength();
    }

    void Push(T item) //0.005 s (List) and 0.152 s (Array) for 1000 iterations
    {
        return this->elements->Append(item);
    }

    void Pop() //0.002 s (List) and 0.013 s (Array) for 10000 iterations
    {
        this->elements->Pop();
    }

    void Concat(Queue<T>* q)
    {
        for(int i = 0; i < q->elements->GetLength(); i++)
        {
            this->Push(q->elements->Get(i));
        }
    }

    ~Queue()
    {
        delete this->elements;
    }
protected:

private:
    Sequence<T>* elements;
};

#endif // QUEUE_H

