
#include "LinkedList.h"


/*template<class T>
void LinkedList<T>::Append(T item)
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

template<class T>
LinkedList<T>::LinkedList(T* items, int c)
{
    Size = c;
    for (int i = 0; i < c; i++)
    {
        Append(*(items + i));
    }
}

template<class T>
LinkedList<T>::LinkedList()
{
    Size = 0;
    first = nullptr;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> & l)
{
    this->Size = l->Size;
    this->first = new T;
    this->first = l->first;
}

template<class T>
void LinkedList<T>::Prepend(T item)
{
    Node<T> *first = new Node<T>(item, first);
	this->Size++;
}

template<class T>
void LinkedList<T>::InsertAt(T item, int index)
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
        oldNode->next = newNode->next;
    }
    Size++;
}

template<class T>
T LinkedList<T>:: GetFirst()
{
    Node<T>* f = this->first;
    return f->value;
}

template<class T>
T LinkedList<T>::GetLast()
{
    Node<T>* l = this->first;
    for (int i = 0; i < this->Size; i++)
    {
        l = l->next;
    }
    return l->value;
}

template<class T>
T LinkedList<T>::Get(int index)
{
    Node<T>* fit = this->first;
    for (int i = 0; i < index; i++)
    {
        fit = fit->next;
    }
    return fit->value;
}

template<class T>
LinkedList<T>* LinkedList<T>::GetSubList(int startIndex, int endIndex)
{
    Node<T>* n = this->first;
    for (int i = 0; i < startIndex; i++)
    {
        n = n->next;
    }
    LinkedList<T>* listIndex = new LinkedList();
    for (int j = startIndex; j < endIndex; j++)
    {
        listIndex->Append(n->value);
        n = n->next;
    }
    return listIndex;
}

template<class T>
int LinkedList<T>::GetLength()
{
    return this->Size;
}

template<class T>
LinkedList<T>* LinkedList<T>::Concat(LinkedList<T> *l)
{
    Node<T>* n = this->first;
    LinkedList<T>* concatList = new LinkedList(l);
    for (int i = 0; i < this->Size; i++)
    {
        concatList = Apppend(n->value);
        n = n->next;
    }
    return concatList;
}
*/
