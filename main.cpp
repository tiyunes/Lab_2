#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <stdexcept>
#include "QUEUE.H"
#include "Stack.h"
#include "doctest.h"

using namespace std;
TEST_CASE("testing Queue (ArraySequence)")
{
    try
    {
        Queue<int>* q1 = new Queue<int>();
        q1->push(9);
        q1->push(8);
        q1->push(5);
        CHECK(q1->front() == 9);
        CHECK(q1->back() == 5);
        CHECK(q1->size() == 3);
        CHECK(q1->empty() == FALSE);
        q1->pop();
        CHECK(q1->size() == 2);
        CHECK(q1->front() == 8);
        CHECK(q1->back() == 5);

        int items[3] = {11, 12, 13};
        Queue<int>* q2 = new Queue<int>(items, 3);
        CHECK(q2->size() == 3);
        CHECK(q2->front() == 11);
        CHECK(q2->back() == 13);
        CHECK(q2->empty() == FALSE);
    }
    catch(out_of_range &e)
    {
        cout << e.what() << endl;
    }
}
TEST_CASE("testing Stack (ArraySequence)")
{
    Stack<int>* s1 = new Stack<int>();
    s1->push(9);
    s1->push(8);
    s1->push(5);
    CHECK(s1->top() == 5);
    CHECK(s1->size() == 3);
    CHECK(s1->empty() == FALSE);
    s1->pop();
    CHECK(s1->size() == 2);
    CHECK(s1->top() == 8);

    int items[3] = {11, 12, 13};
    Stack<int>* s2 = new Stack<int>(items, 3);
    CHECK(s2->size() == 3);
    CHECK(s2->top() == 13);
    CHECK(s2->empty() == FALSE);
    s2->pop();
    s2->pop();
    s2->pop();
    CHECK(s2->empty() == TRUE);
}
/*
LinkedListSequence<int>* temp2 = new LinkedListSequence<int>();
temp2->Append(8);
temp2->Append(9);
temp2->Append(10);
cout << temp2->GetSubsequence(0,1)->GetFirst() << endl;
return 0;
*/

