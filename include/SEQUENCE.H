#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "LinkedList.h"
#include "DynamicArray.h"

template <class T>
class Sequence
{
    public:
        virtual T GetFirst() = 0;
        virtual T GetLast() = 0;
        virtual T Get(int index) = 0;
        virtual Sequence <T>* GetSubsequence(int startIndex, int endIndex) = 0;
        virtual int GetLength() = 0;

        virtual void Append(T item) = 0;
        virtual void Prepend(T item) = 0;
        virtual void InsertAt(T item, int index) = 0;
        virtual void Pop() = 0;
        virtual Sequence<T>* Concat(LinkedList <T> *l) = 0;
    /*protected:
        Sequence(T* items, int size)
        {
            this->arrayItems = new ArraySequence<T>(items, size);
            this->listItems = new LinkedListSequence<T>(items, size);
        }

    private:
        LinkedListSequence<T>* listItems;
        ArraySequence<T>* arrayItems;
    */
};
#endif // SEQUENCE_H
