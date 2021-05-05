#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <chrono>
#include "QUEUE.H"
#include "QUEUE.h"
#include "Stack.h"
#include "doctest.h"
#include "VECTOR.H"

using namespace std;
TEST_CASE("testing Queue")
{
    try
    {
        Queue<int>* q1 = new Queue<int>();
        q1->Push(9);
        q1->Push(8);
        q1->Push(5);
        CHECK(q1->Front() == 9);
        CHECK(q1->Back() == 5);
        CHECK(q1->Size() == 3);
        CHECK(q1->Empty() == FALSE);
        q1->Pop();
        CHECK(q1->Size() == 2);
        CHECK(q1->Front() == 8);
        CHECK(q1->Back() == 5);

        int items[3] = {11, 12, 13};
        Queue<int>* q2 = new Queue<int>(items, 3);
        CHECK(q2->Size() == 3);
        CHECK(q2->Front() == 11);
        CHECK(q2->Back() == 13);
        CHECK(q2->Empty() == FALSE);

        q2->Concat(q1);
        CHECK(q2->Size() == 5);
        CHECK(q2->Front() == 11);
        CHECK(q2->Back() == 5);
        CHECK(q2->Empty() == FALSE);

        Queue<int>* q3 = new Queue<int>();
        q3->Push(10);
        q3->Push(20);
        q3->Push(30);
        q3->Push(40);
        q3->Push(50);
        CHECK(q3->Front() == 10);
        CHECK(q3->Back() == 50);
        CHECK(q3->Size() == 5);
        CHECK(q3->Empty() == FALSE);
        q3->Pop();
        CHECK(q3->Size() == 4);
        CHECK(q3->Front() == 20);
        CHECK(q3->Back() == 50);

        int elements1[5] = {7, 81, 12, 58, 93};
        Queue<int>* q4 = new Queue<int>(elements1, 5);
        CHECK(q4->Size() == 5);
        CHECK(q4->Front() == 7);
        CHECK(q4->Back() == 93);
        CHECK(q4->Empty() == FALSE);

        q4->Concat(q1);
        CHECK(q4->Size() == 7);
        CHECK(q4->Front() == 7);
        CHECK(q4->Back() == 5);
        CHECK(q4->Empty() == FALSE);

        int elements2[6] = {6, 57, 22, 10, 71, 15};
        Queue<int>* q5 = new Queue<int>(elements2, 6);
        CHECK(q5->Size() == 6);
        CHECK(q5->Front() == 6);
        CHECK(q5->Back() == 15);
        CHECK(q5->Empty() == FALSE);

        q5->Concat(q1);
        CHECK(q5->Size() == 8);
        CHECK(q5->Front() == 6);
        CHECK(q5->Back() == 5);
        CHECK(q5->Empty() == FALSE);

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
        s1->Push(9);
        s1->Push(8);
        s1->Push(5);
        CHECK(s1->Top() == 5);
        CHECK(s1->Size() == 3);
        CHECK(s1->Empty() == FALSE);
        s1->Pop();
        CHECK(s1->Size() == 2);
        CHECK(s1->Top() == 8);

        int items3[3] = {11, 12, 13};
        Stack<int>* s2 = new Stack<int>(items3, 3);
        CHECK(s2->Size() == 3);
        CHECK(s2->Top() == 13);
        CHECK(s2->Empty() == FALSE);
        s2->Pop();
        s2->Pop();
        s2->Pop();
        CHECK(s2->Empty() == TRUE);
        s2->Push(11);
        s2->Push(12);
        s2->Push(13);
        s2->Concat(s1);
        CHECK(s2->Size() == 5);
        CHECK(s2->Top() == 9);
        CHECK(s2->Empty() == FALSE);

        Stack<int>* s3 = new Stack<int>();
        s3->Push(12);
        s3->Push(46);
        s3->Push(3);
        s3->Push(17);
        s3->Push(108);
        CHECK(s3->Top() == 108);
        CHECK(s3->Size() == 5);
        CHECK(s3->Empty() == FALSE);
        s3->Pop();
        CHECK(s3->Size() == 4);
        CHECK(s3->Top() == 17);

        int items4[4] = {3, 81, 67, 52};
        Stack<int>* s4 = new Stack<int>(items4, 4);
        CHECK(s4->Size() == 4);
        CHECK(s4->Top() == 52);
        CHECK(s4->Empty() == FALSE);
        s4->Pop();
        s4->Pop();
        s4->Pop();
        CHECK(s2->Empty() == FALSE);
        s4->Concat(s1);
        CHECK(s4->Size() == 3);
        CHECK(s4->Top() == 9);
        CHECK(s4->Empty() == FALSE);
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

        CHECK(v2->ScalarProd(v1) == 102);

        float items5[2] = {3, 4};
        Vector<float>* v5 = new Vector<float>(items5, 2);
        CHECK(v5->Norm() == 5.0);

        CHECK(v2->ScalarProd(v1)== 102);

        int items4[5] = {11, 5, 4 , 3 , 10};
        Vector<int>* v3 = new Vector<int>(items4, 5);
        CHECK(v3->GetLength() == 5);
        CHECK(v3->GetCoordinate(0) == 11);
        CHECK(v3->GetCoordinate(1) == 5);
        CHECK(v3->GetCoordinate(2) == 4);
        CHECK(v3->GetCoordinate(3) == 3);
        CHECK(v3->GetCoordinate(4) == 10);
        CHECK(v3->Sum(v2)->GetCoordinate(0) == 14);
        CHECK(v3->Sum(v2)->GetCoordinate(1) == 8);
        CHECK(v3->Sum(v2)->GetCoordinate(2) == 6);
        CHECK(v3->Sum(v2)->GetCoordinate(3) == 5);
        CHECK(v3->Sum(v2)->GetCoordinate(4) == 18);
        CHECK(v3->ScalarProd(v1)== 158);

        float items6[2] = {3, 4};
        Vector<float>* v6 = new Vector<float>(items6, 2);
        CHECK(v6->Norm() == 5.0);
    }
    catch(out_of_range &e)
    {
        cout << e.what() << endl;
    }
}


