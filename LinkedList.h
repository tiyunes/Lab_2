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
    LinkedList()
    {
        Size = 0;
        first = nullptr;
        last = nullptr;
    }

    LinkedList(const LinkedList<T>& l)
    {
        T item;
        Size = l.Size;
        first = new Node<T>(item, nullptr);
        first = l.first;
        last = l.last;
    }

    LinkedList(T* items, int c)
    {
        this->first = nullptr;
        this->last = nullptr;
        this->Size = 0;
        for (int i = 0; i < c; i++)
        {
            this->Append(items[i]);
        }
    }

    LinkedList(int c)
    {
        T item;
        this->first = nullptr;
        this->last = nullptr;
        this->Size = 0;
        for (int i = 0; i < c; i++)
        {
            this->Append(item);
        }
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
        return l->value;
    }

    T Get(int index)
    {
        if (index < 0 || index > this->Size)
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
        T item;
        Node<T> *buff = new Node<T>(item, nullptr);
        buff = this->first;
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

    void Set(T item, int index)
    {
        int c = 0;
        Node<T>* temp = this->first;
        while (temp!=nullptr)
        {
            if(c == index)
            {
                temp->value = item;
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
        if (index < 0 || index > this->Size)
        {
            throw std::out_of_range("Invalid index");
        }
        if (index == 0)
        {
            this->Prepend(item);
        }
        if (index == this->Size - 1)
        {
            this->Append(item);
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
            this->Size++;
        }
    }

    void Reverse()
    {
        T buff;
        LinkedList<T>* l = new LinkedList(this->GetLength());
        for (int i = 0; i < (this->GetLength() / 2); i++)
        {
            buff = this->Get(i);
            l->Set(this->Get(this->GetLength() - i - 1), i);
            l->Set(buff, this->GetLength() - i - 1);
        }
        this->first = l->first;
        this->last = l->last;
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

    ~LinkedList()
    {
     for (int i = 0; i < this->Size; i++)
     {
         this->Pop();
     }
    }


public:
    int Size;
    Node<T> *first;
    Node<T> *last;
};

#endif // LINKEDLIST_H
