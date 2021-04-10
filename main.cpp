#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    int i;
    LinkedList<int> a{};
    a.Append(5);
    a.Prepend(1);
    a.InsertAt(6, 1);
    LinkedList<int>* b = a.GetSubList(0, 0);
    LinkedList<int> c(a);
    LinkedList<int>* d = c.Concat(b);
    for (i = 0; i < d->GetLength(); i++)
    {
        cout << d->Get(i) << endl;
    }
    return 0;
}
