#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <chrono>
#include <complex>
#include "QUEUE.H"
#include "QUEUE.h"
#include "Stack.h"
#include "doctest.h"
#include "VECTOR.H"
#include "STUDENTS.H"
#include "TEACHER.H"

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

TEST_CASE("testing queue (complex, float, student, teacher)")
{
    try
    {
        Queue<Student>* q1 = new Queue<Student>();
        StudentID* id1 = new StudentID(1, 2);
        string* firstName = new string("Ivan");
        string* lastName = new string("Ivanov");
        Student s1(id1, firstName, lastName);
        q1->Push(s1);
        CHECK(q1->Size() == 1);
        CHECK(q1->Front() == s1);
        StudentID* id2 = new StudentID(3, 4);
        string* firstName2 = new string("Alex");
        string* lastName2 = new string("Smith");
        Student s2(id2, firstName2, lastName2);
        q1->Push(s2);
        CHECK(q1->Size() == 2);
        CHECK(q1->Front() == s1);
        CHECK(q1->Back() == s2);

        Queue<complex<int>>* q2 = new Queue<complex<int>>();
        complex<int> c1(1, 2);
        complex<int> c2(10, 6);
        complex<int> c3(7, 11);
        q2->Push(c1);
        q2->Push(c2);
        q2->Push(c3);
        CHECK(q2->Size() == 3);
        CHECK(q2->Front() == c1);
        CHECK(q2->Back() == c3);

        Queue<float>* q3 = new Queue<float>();
        float f1 = 1.0;
        float f2 = 3.0;
        float f3 = 16.1;
        q3->Push(f1);
        q3->Push(f2);
        q3->Push(f3);
        CHECK(q3->Size() == 3);
        CHECK(q3->Front() == f1);
        CHECK(q3->Back() == f3);

        Queue<Teacher>* q4 = new Queue<Teacher>();
        TeacherID* id4 = new TeacherID(1, 2);
        string* firstName4 = new string("Ilya");
        string* lastName4 = new string("Butusov");
        string* subject1 = new string("Math");
        Teacher t1(id4, firstName4, lastName4, subject1);
        q4->Push(t1);
        CHECK(q4->Size() == 1);
        CHECK(q4->Front() == t1);
        TeacherID* id5 = new TeacherID(3, 4);
        string* firstName5 = new string("Matvey");
        string* lastName5 = new string("Popov");
        string* subject2 = new string("Phys");
        Teacher t2(id5, firstName5, lastName5, subject2);
        q4->Push(t2);
        CHECK(q4->Size() == 2);
        CHECK(q4->Front() == t1);
        CHECK(q4->Back() == t2);
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

TEST_CASE("testing stack (complex, float, student, teacher)")
{
    try
    {
        Stack<Student>* stack1 = new Stack<Student>();
        StudentID* id1 = new StudentID(1, 2);
        string* firstName = new string("Ivan");
        string* lastName = new string("Ivanov");
        Student s1(id1, firstName, lastName);
        stack1->Push(s1);
        CHECK(stack1->Size() == 1);
        CHECK(stack1->Top() == s1);
        StudentID* id2 = new StudentID(3, 4);
        string* firstName2 = new string("Alex");
        string* lastName2 = new string("Smith");
        Student s2(id2, firstName2, lastName2);
        stack1->Push(s2);
        CHECK(stack1->Size() == 2);
        CHECK(stack1->Top() == s2);

        Stack<complex<int>>* stack2 = new Stack<complex<int>>();
        complex<int> c1(1, 2);
        complex<int> c2(10, 6);
        complex<int> c3(7, 11);
        stack2->Push(c1);
        stack2->Push(c2);
        stack2->Push(c3);
        CHECK(stack2->Size() == 3);
        CHECK(stack2->Top() == c3);

        Stack<float>* stack3 = new Stack<float>();
        float f1 = 1.0;
        float f2 = 3.0;
        float f3 = 16.1;
        stack3->Push(f1);
        stack3->Push(f2);
        stack3->Push(f3);
        CHECK(stack3->Size() == 3);
        CHECK(stack3->Top() == f3);

        Stack<Teacher>* stack4 = new Stack<Teacher>();
        TeacherID* id4 = new TeacherID(1, 2);
        string* firstName4 = new string("Ilya");
        string* lastName4 = new string("Butusov");
        string* subject1 = new string("Math");
        Teacher t1(id4, firstName4, lastName4, subject1);
        stack4->Push(t1);
        CHECK(stack4->Size() == 1);
        CHECK(stack4->Top() == t1);
        TeacherID* id5 = new TeacherID(3, 4);
        string* firstName5 = new string("Matvey");
        string* lastName5 = new string("Popov");
        string* subject2 = new string("Phys");
        Teacher t2(id5, firstName5, lastName5, subject2);
        stack4->Push(t2);
        CHECK(stack4->Size() == 2);
        CHECK(stack4->Top() == t2);
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

TEST_CASE("testing Vector Complex")
{
    try
    {
        complex<int> items_complex[3] = {complex<int>(1, 1), complex<int>(5, 6), complex<int>(7, 8)};
        Vector<complex<int>>* v1 = new Vector<complex<int>>(items_complex, 3);
        complex<int> c1(1, 1);
        complex<int> c2(5, 6);
        complex<int> c3(7, 8);
        CHECK(v1->GetLength() == 3);
        CHECK(v1->GetCoordinate(0) == c1);
        CHECK(v1->GetCoordinate(1) == c2);
        CHECK(v1->GetCoordinate(2) == c3);

        complex<int> items_complex2[3] = {complex<int>(10, 7), complex<int>(11, 2), complex<int>(16, 1)};
        Vector<complex<int>>* v2 = new Vector<complex<int>>(items_complex2, 3);
        complex<int> c4(10, 7);
        complex<int> c5(11, 2);
        complex<int> c6(16, 1);
        CHECK(v2->GetLength() == 3);
        CHECK(v2->GetCoordinate(0) == c4);
        CHECK(v2->GetCoordinate(1) == c5);
        CHECK(v2->GetCoordinate(2) == c6);

        complex<int> c7(11, 8);
        complex<int> c8(16, 8);
        complex<int> c9(23, 9);
        CHECK(v1->Sum(v2)->GetLength() == 3);
        CHECK(v1->Sum(v2)->GetCoordinate(0) == c7);
        CHECK(v1->Sum(v2)->GetCoordinate(1) == c8);
        CHECK(v1->Sum(v2)->GetCoordinate(2) == c9);

        complex<int> c10(2, 2);
        complex<int> c11(10, 12);
        complex<int> c12(14, 16);
        CHECK(v1->Mult(2)->GetLength() == 3);
        CHECK(v1->Mult(2)->GetCoordinate(0) == c10);
        CHECK(v1->Mult(2)->GetCoordinate(1) == c11);
        CHECK(v1->Mult(2)->GetCoordinate(2) == c12);
    }
    catch(out_of_range &e)
    {
        cout << e.what() << endl;
    }
}


