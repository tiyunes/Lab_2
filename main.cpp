#include <iostream>
#include "LinkedList.h"
#include "LinkedListSequence.h"
#include "DynamicArray.h"
#include "ArraySequence.h"

using namespace std;

int main()
{
    int c[2]{9, 1};
    DynamicArray<int>* a = new DynamicArray<int>(2);
    a->Set(0, 5);
    a->Set(1, 6);

    return 0;
}
