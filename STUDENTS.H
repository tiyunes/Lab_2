#ifndef STUDENTS_H
#define STUDENTS_H
#include <string>

using namespace std;

class StudentID
{
public:
    StudentID()
    {
        this->number = 0;
        this->series = 0;
    }

    StudentID(int number, int series)
    {
        this->number = number;
        this->series = series;
    }

    bool operator==(StudentID& id1)
    {
        return (this->number == id1.number && this->series == id1.series);
    }
private:
    int number;
    int series;
};

class Student
{
public:
    friend class StudentID;
    Student()
    {
        this->id = new StudentID();
        string* s1 = new string;
        s1->clear();
        this->firstName = s1;
        this->lastName = s1;
    }

    Student(StudentID* id, string* firstName, string* lastName)
    {
        this->id = id;
        this->firstName = firstName;
        this->lastName = lastName;
    }

    StudentID* GetID()
    {
        return this->id;
    }

    string* GetFirstName()
    {
        return this->firstName;
    }

    string* GetLastName()
    {
        return this->lastName;
    }

    bool operator==(Student& s)
    {
        return s.id == this->id && s.firstName == this->firstName && s.lastName == this->lastName;
    }
protected:

private:
    StudentID* id;
    string* firstName;
    string* lastName;
};

#endif // STUDENTS_H
