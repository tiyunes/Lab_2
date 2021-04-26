#include <iostream>
#include "QUEUE.H"
#include "Stack.h"
/*#include "SEQUENCE.H"
#include "LinkedList.h"
//#include "LinkedListSequence.h"
#include "DynamicArray.h"
//#include "ArraySequence.h"
*/

using namespace std;

int main()
{
    cout << "ok" << endl;
    Stack<int>* temp = new Stack<int>();
    cout << "Ok" << endl;
    temp->push(5);
    temp->push(6);
    temp->push(7);
    cout << temp->empty() << endl;
    temp->pop();
    cout << temp->top() << endl;
    return 0;

}
