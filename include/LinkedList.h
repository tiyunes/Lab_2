#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

using namespace std;
template<class T>
class Node
{
    public:
        Node(T value, Node *next = nullptr)
        {
            this->value = value;
            this->next = next;
        }
        Node* next;
        T value;
};

template<class T>
class LinkedList
{
public:
    friend class Node<T>;
    LinkedList(T* items, int c)
    {
        Size = c;
        for (int i = 0; i < c; i++)
        {
            Append(*(items + i));
        }
    }

    LinkedList()
    {
        Size = 0;
        first = nullptr;
    }

    LinkedList(const LinkedList<T>& l)
    {
        Size = l.Size;
        first = new Node<T>(0, nullptr);
        first = l.first;
    }

    T GetFirst()
    {
        Node<T>* f = this->first;
        return f->value;
    }

    T GetLast()
    {
        Node<T>* l = this->first;
        for (int i = 0; i < this->Size - 1; i++)
        {
            l = l->next;
        }
        return l->value;
    }

    T Get(int index)
    {
        Node<T>* fit = this->first;
        for (int i = 0; i < index; i++)
        {
            fit = fit->next;
        }
        return fit->value;
    }

    LinkedList<T>* GetSubList(int startIndex, int endIndex)
    {
        Node<T>* n = this->first;
        for (int i = 0; i < startIndex; i++)
        {
            n = n->next;
        }
        LinkedList<T>* listIndex = new LinkedList();
        for (int j = startIndex; j <= endIndex; j++)
        {
            listIndex->Append(n->value);
            n = n->next;
        }
        return listIndex;
    }

    int GetLength()
    {
        return this->Size;
    }

    void Append(T item)
    {
        if(this->first == nullptr)
        {
            this->first = new Node<T>(item, nullptr);
        }
        else
        {
            Node<T> *temp = this->first;
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new Node<T>(item, temp->next);
        }
        this->Size++;
    }

    void Prepend(T item)
    {
        this->first = new Node<T>(item, first);
        this->Size++;
    }

    void InsertAt(T item, int index)
    {
        if (index == 0)
        {
            Prepend(item);
        }
        else
        {
            Node<T> *oldNode = this->first;
            for (int i = 0; i < index - 1; i++)
            {
                oldNode = oldNode->next;
            }
            Node<T>* newNode = new Node<T>(item, oldNode->next);
            oldNode->next = newNode;
            Size++;
        }
    }

    LinkedList<T>* Concat(LinkedList<T> *l)
    {
        Node<T>* n = this->first;
        LinkedList<T>* concatList = new LinkedList<T>(*l);
        for (int i = 0; i < this->Size; i++)
        {
            concatList->Append(n->value);
            n = n->next;
        }
        return concatList;
    }
    T& operator[](int index)
    {
        int c = 0;
        Node<T>* temp = this->first;
        while (temp!=nullptr)
        {
            if(c == index)
            {
                return temp->value;
            }
            temp = temp->next;
            c++;
        }
    }

public:
    int Size;
    Node<T> *first;
};

#endif // LINKEDLIST_H
