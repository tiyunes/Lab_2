#include "SEQUENCE.H"
#include "LinkedList.h"
#ifndef LINKEDLISTSEQUENCE_H
#define LINKEDLISTSEQUENCE_H

template<class T>
class LinkedListSequence: public Sequence<T>
{
    public:
        friend class LinkedList<T>;

        LinkedListSequence();
        LinkedListSequence(T* items, int c);
        LinkedListSequence(const LinkedList<T>& l);
        T GetFirst() override;
        T GetLast() override;
        T Get(int index) override;
        Sequence <T>* GetSubsequence(int startIndex, int endIndex) override;
        int GetLength() override;

        void Append(T item) override;
        void Prepend(T item) override;
        void InsertAt(T item, int index) override;
        Sequence<T>* Concat(Sequence <T> *l) override;
        virtual ~LinkedListSequence();
    protected:

    private:
        LinkedList<T>* items;
};

#endif // LINKEDLISTSEQUENCE_H
