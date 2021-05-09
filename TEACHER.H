#ifndef TEACHER_H
#define TEACHER_H


class TeacherID
{
public:
    TeacherID()
    {
        this->number = 0;
        this->series = 0;
    }

    TeacherID(int number, int series)
    {
        this->number = number;
        this->series = series;
    }

    bool operator==(TeacherID& id1)
    {
        return (this->number == id1.number && this->series == id1.series);
    }
private:
    int number;
    int series;
};

class Teacher
{
public:
    friend class TeacherID;
    Teacher()
    {
        this->id = new TeacherID();
        string* s1 = new string;
        s1->clear();
        this->firstName = s1;
        this->lastName = s1;
        this->subject = s1;
    }

    Teacher(TeacherID* id, string* firstName, string* lastName, string* subject)
    {
        this->id = id;
        this->firstName = firstName;
        this->lastName = lastName;
        this->subject = subject;
    }

    TeacherID* GetID()
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

    string* GetSubject()
    {
        return this->subject;
    }

    bool operator==(Teacher& t)
    {
        return t.id == this->id && t.firstName == this->firstName && t.lastName == this->lastName && t.subject == this->subject;
    }
protected:

private:
    TeacherID* id;
    string* firstName;
    string* lastName;
    string* subject;
};

#endif // TEACHER_H
