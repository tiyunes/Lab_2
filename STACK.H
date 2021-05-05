#ifndef STACK_H
#define STACK_H
#include "ArraySequence.h"
#include "LinkedListSequence.h"

template<class T>
class Stack
{
public:
    Stack()
    {
        this->elements = (Sequence<T>*) new LinkedListSequence<T>();
        //this->elements = (Sequence<T>*) new ArraySequence<T>();
    }
<<<<<<< HEAD
    
=======

>>>>>>> 9fcefc7 (Added tests)
    Stack(T* items, int size) //0.001 s (List) and 0.019 s (Array) for 1000 elements
    {
        this->elements = (Sequence<T>*) new LinkedListSequence<T>(items, size);
        //this->elements = (Sequence<T>*) new ArraySequence<T>(items, size);
        this->elements->Reverse();
    }
<<<<<<< HEAD
    
    T top() //0.452 s (List) and 0.284 s (Array) for 1M iterations
    {
        return this->elements->GetFirst();
    }
    
    bool empty()
=======

    T Top() //0.452 s (List) and 0.284 s (Array) for 1M iterations
    {
        return this->elements->GetFirst();
    }

    bool Empty()
>>>>>>> 9fcefc7 (Added tests)
    {
        if (this->elements->GetLength() == 0) return true;
        else return false;
    }
<<<<<<< HEAD
    
    int size()
    {
        return this->elements->GetLength();
    }
    
    void push(T item) // 0.002 s (List) and 0.384 s (Array) for 1000 elements
    {
        return this->elements->Prepend(item);
    }
    
    void pop() // 0.167 s (List) for 1M iterations and 0.135 s (Array) for 1000 iterations
    {
        this->elements->Pop();
    }
    
    void concat(Stack<T>* s)
=======

    int Size()
    {
        return this->elements->GetLength();
    }

    void Push(T item) // 0.002 s (List) and 0.384 s (Array) for 1000 elements
    {
        return this->elements->Prepend(item);
    }

    void Pop() // 0.167 s (List) for 1M iterations and 0.135 s (Array) for 1000 iterations
    {
        this->elements->Pop();
    }

    void Concat(Stack<T>* s)
>>>>>>> 9fcefc7 (Added tests)
    {
        for(int i = 0; i < s->elements->GetLength(); i++)
        {
            this->Push(s->elements->Get(i));
        }
    }
<<<<<<< HEAD
    
=======

>>>>>>> 9fcefc7 (Added tests)
    ~Stack()
    {
        delete this->elements;
    }

protected:

private:
    Sequence<T>* elements;
};

#endif // STACK_H
