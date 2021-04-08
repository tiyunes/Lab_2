#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<class T>
class Node
{
    public:
        Node(T value, Node *next = nullptr)
        {
            this->value = value;
            this->next = next;
        }
    private:
        Node* next;
        T value;
};

template<class T>
class LinkedList
{
public:
    friend class Node<T>;
    LinkedList(T* items, int c);
    LinkedList();
    LinkedList(const LinkedList <T>& l);
    T GetFirst();
    T GetLast();
    T Get(int index);
    LinkedList<T>* GetSubList(int startIndex, int endIndex);
    int GetLength();
    void Append(T item);
    void Prepend(T item);
    void InsertAt(T item, int index);
    LinkedList<T>* Concat(LinkedList<T> *l);
    virtual ~LinkedList();

private:
    int Size;
    Node<T> *first;
};

#endif // LINKEDLIST_H
