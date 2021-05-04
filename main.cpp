#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <chrono>
#include "QUEUE.H"
#include "Stack.h"
#include "doctest.h"
#include "VECTOR.H"

using namespace std;
TEST_CASE("testing Queue")
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

        q2->concat(q1);
        CHECK(q2->size() == 5);
        CHECK(q2->front() == 11);
        CHECK(q2->back() == 5);
        CHECK(q2->empty() == FALSE);

        int* itemsv = new int[1000];
        for (int i = 0; i < 1000; i++)
        {
            itemsv[i] = i;
        }
        auto start1 = chrono::high_resolution_clock::now();
        Stack<int>* s3 = new Stack<int>(itemsv, 1000);
        auto end1 = chrono::high_resolution_clock::now();
        chrono::duration<float> duration = end1 - start1;
    }
    catch(out_of_range &e)
    {
        cout << e.what() << endl;
    }
}
TEST_CASE("testing Stack")
{
    try
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

        int items3[3] = {11, 12, 13};
        Stack<int>* s2 = new Stack<int>(items3, 3);
        CHECK(s2->size() == 3);
        CHECK(s2->top() == 13);
        CHECK(s2->empty() == FALSE);
        s2->pop();
        s2->pop();
        s2->pop();
        CHECK(s2->empty() == TRUE);
        s2->push(11);
        s2->push(12);
        s2->push(13);
        s2->concat(s1);
        CHECK(s2->size() == 5);
        CHECK(s2->top() == 9);
        CHECK(s2->empty() == FALSE);

    }
    catch(out_of_range &e)
    {
        cout << e.what() << endl;
    }
}

TEST_CASE("testing Vector")
{
    try
    {
        int items1[6] = {2, 6, 5 , 2 , 8};
        Vector<int>* v1 = new Vector<int>(items1, 5);
        CHECK(v1->GetLength() == 5);
        CHECK(v1->GetCoordinate(0) == 2);
        CHECK(v1->GetCoordinate(1) == 6);
        CHECK(v1->GetCoordinate(2) == 5);
        CHECK(v1->GetCoordinate(3) == 2);
        CHECK(v1->GetCoordinate(4) == 8);

        int items2[6] = {3, 3, 2 , 2 , 8};
        Vector<int>* v2 = new Vector<int>(items2, 5);
        CHECK(v2->GetLength() == 5);
        CHECK(v2->GetCoordinate(0) == 3);
        CHECK(v2->GetCoordinate(1) == 3);
        CHECK(v2->GetCoordinate(2) == 2);
        CHECK(v2->GetCoordinate(3) == 2);
        CHECK(v2->GetCoordinate(4) == 8);

        CHECK(v1->Sum(v2)->GetLength() == 5);
        CHECK(v1->Sum(v2)->GetCoordinate(0) == 5);
        CHECK(v1->Sum(v2)->GetCoordinate(1) == 9);
        CHECK(v1->Sum(v2)->GetCoordinate(2) == 7);
        CHECK(v1->Sum(v2)->GetCoordinate(3) == 4);
        CHECK(v1->Sum(v2)->GetCoordinate(4) == 16);


        CHECK(v1->Mult(2)->GetLength() == 5);
        CHECK(v1->Mult(2)->GetCoordinate(0) == 4);
        CHECK(v1->Mult(2)->GetCoordinate(1) == 12);
        CHECK(v1->Mult(2)->GetCoordinate(2) == 10);
        CHECK(v1->Mult(2)->GetCoordinate(3) == 4);
        CHECK(v1->Mult(2)->GetCoordinate(4) == 16);

        CHECK(v2->ScalarProd(v1)== 102);

        float items3[2] = {3, 4};
        Vector<float>* v3 = new Vector<float>(items3, 2);
        CHECK(v3->norm() == 5.0);
    }
    catch(out_of_range &e)
    {
        cout << e.what() << endl;
    }
}


