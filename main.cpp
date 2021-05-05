#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <chrono>
<<<<<<< HEAD
#include "QUEUE.H"
=======
#include "QUEUE.h"
>>>>>>> 3ad575f (Added tests)
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

<<<<<<< HEAD
=======
        Queue<int>* q3 = new Queue<int>();
        q3->push(10);
        q3->push(20);
        q3->push(30);
        q3->push(40);
        q3->push(50);
        CHECK(q3->front() == 10);
        CHECK(q3->back() == 50);
        CHECK(q3->size() == 5);
        CHECK(q3->empty() == FALSE);
        q3->pop();
        CHECK(q3->size() == 4);
        CHECK(q3->front() == 20);
        CHECK(q3->back() == 50);

        int elements1[5] = {7, 81, 12, 58, 93};
        Queue<int>* q4 = new Queue<int>(elements1, 5);
        CHECK(q4->size() == 5);
        CHECK(q4->front() == 7);
        CHECK(q4->back() == 93);
        CHECK(q4->empty() == FALSE);

        q4->concat(q1);
        CHECK(q4->size() == 7);
        CHECK(q4->front() == 7);
        CHECK(q4->back() == 5);
        CHECK(q4->empty() == FALSE);

        int elements2[6] = {6, 57, 22, 10, 71, 15};
        Queue<int>* q5 = new Queue<int>(elements2, 6);
        CHECK(q5->size() == 6);
        CHECK(q5->front() == 6);
        CHECK(q5->back() == 15);
        CHECK(q5->empty() == FALSE);

        q5->concat(q1);
        CHECK(q5->size() == 8);
        CHECK(q5->front() == 6);
        CHECK(q5->back() == 5);
        CHECK(q5->empty() == FALSE);

>>>>>>> 3ad575f (Added tests)
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

<<<<<<< HEAD
=======
        Stack<int>* s3 = new Stack<int>();
        s3->push(12);
        s3->push(46);
        s3->push(3);
        s3->push(17);
        s3->push(108);
        CHECK(s3->top() == 108);
        CHECK(s3->size() == 5);
        CHECK(s3->empty() == FALSE);
        s3->pop();
        CHECK(s3->size() == 4);
        CHECK(s3->top() == 17);

        int items4[4] = {3, 81, 67, 52};
        Stack<int>* s4 = new Stack<int>(items4, 4);
        CHECK(s4->size() == 4);
        CHECK(s4->top() == 52);
        CHECK(s4->empty() == FALSE);
        s4->pop();
        s4->pop();
        s4->pop();
        CHECK(s2->empty() == FALSE);
        s4->concat(s1);
        CHECK(s4->size() == 3);
        CHECK(s4->top() == 9);
        CHECK(s4->empty() == FALSE);

>>>>>>> 3ad575f (Added tests)
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

<<<<<<< HEAD
        CHECK(v2->ScalarProd(v1) == 102);

        float items3[2] = {3, 4};
        Vector<float>* v3 = new Vector<float>(items3, 2);
        CHECK(v3->norm() == 5.0);
=======
        CHECK(v2->ScalarProd(v1)== 102);

        int items3[5] = {11, 5, 4 , 3 , 10};
        Vector<int>* v3 = new Vector<int>(items3, 5);
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

        float items4[2] = {3, 4};
        Vector<float>* v4 = new Vector<float>(items4, 2);
        CHECK(v4->norm() == 5.0);

>>>>>>> 3ad575f (Added tests)
    }
    catch(out_of_range &e)
    {
        cout << e.what() << endl;
    }
}


