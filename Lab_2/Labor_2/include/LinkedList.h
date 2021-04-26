#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdexcept>
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
        last = nullptr;
    }

    LinkedList(const LinkedList<T>& l)
    {
        Size = l.Size;
        first = new Node<T>(0, nullptr);
        first = l.first;
        last = l.last;
    }

    T GetFirst()
    {
        if (this->Size == 0)
        {
            throw std::out_of_range("List is empty");
        }
        Node<T>* f = this->first;
        return f->value;
    }

    T GetLast()
    {
        if (this->Size == 0)
        {
            throw std::out_of_range("List is empty");
        }
        Node<T>* l = this->last;
        /*
        for (int i = 0; i < this->Size - 1; i++)
        {
            l = l->next;
        }
        */
        return l->value;
    }
    T Get(int index)
    {
        if (index < 0 || index >= this->Size)
        {
            throw std::out_of_range("Invalid index");
        }
        Node<T>* fit = this->first;
        for (int i = 0; i < index; i++)
        {
            fit = fit->next;
        }
        return fit->value;
    }

    void Pop()
    {
        Node<T> *buff = this->first;
        this->first = this->first->next;
        delete buff;
        this->Size--;
    }

    LinkedList<T>* GetSubList(int startIndex, int endIndex)
    {
        if (startIndex < 0 || startIndex >= this->Size || endIndex < 0 || endIndex >= this->Size)
        {
            throw std::out_of_range("Invalid startIndex/endIndex");
        }
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

    void Append(T item)
    {
        if(this->first == nullptr)
        {
            this->first = new Node<T>(item, nullptr);
            this->last = new Node<T>(item, nullptr);
        }
        else
        {
            Node<T> *temp = this->first;
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new Node<T>(item, temp->next);
            this->last = temp->next;
        }
        this->Size++;
    }
    void Prepend(T item)
    {
        if (this->Size == 0)
        {
            this->first = new Node<T>(item, first);
            this->last = new Node<T>(item, first);
        }
        else
        {
            this->first = new Node<T>(item, first);
        }
        this->Size++;
    }
    void InsertAt(T item, int index)
    {
        if (index < 0 || index >= this->Size)
        {
            throw std::out_of_range("Invalid index");
        }
        if (index == 0)
        {
            Prepend(item);
        }
        if (index == this->Size - 1)
        {
            Append(item);
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


public:
    int Size;
    Node<T> *first;
    Node<T> *last;
};

#endif // LINKEDLIST_H
