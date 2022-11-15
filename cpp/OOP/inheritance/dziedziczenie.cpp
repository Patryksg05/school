#include <iostream>
#include <cstdlib>

using namespace std;

class Person {
private:
    int id;
    string firstName, lastName;
public:
    Person(string fN, string lN):
        firstName(fN), lastName(lN)
    {
        this -> id = rand()%100+1;
    }

    int getId() {return id;}
    string getFirstName() {return firstName;}
    string getLastName() {return lastName;}

    string whoYouAre() {return "Person";}

    void toString() {
        cout << "Object: " << whoYouAre()
             << "\nid: " << Person::getId()
             << "\nfirstName: " << Person::getFirstName()
             << "\nlastName: " << Person:: getLastName();
    }
};

class Student: public Person {
private:
    int albumNumber;
public:
    Student(string fN, string lN)
        : Person(fN, lN)
    {
        int randomAlbum = rand()% 100 + 1;
        this -> albumNumber = randomAlbum;
    }

    int getAlbumNumber() {return albumNumber;}

    string whoYouAre(){return "Student";}

    void toString() {
        cout << "Object: " << whoYouAre()
             << "\nid: " << Person::getId()
             << "\nfirstName: " << Person::getFirstName()
             << "\nlastName: " << Person:: getLastName()
             << "\nalbum number: " << Student::getAlbumNumber();
    }
};

class Graduate: public Student {
private:
    int diplomNumber;
public:
    Graduate(string fN, string lN)
    : Student(fN, lN)
    {
        int dN = rand() % 100 +1;
        this -> diplomNumber = dN;
    }
    string whoYouAre() {return "Graduate";}

    void toString() {
        cout << "Object: " << whoYouAre()
             << "\nid: " << Person::getId()
             << "\nfirstName: " << Person::getFirstName()
             << "\nlastName: " << Person:: getLastName()
             << "\nalbum number: " << Student::getAlbumNumber()
             << "\ndiplomNumber: " << Graduate::diplomNumber;
    }
};

class Time {
private:
    int hour, minute, second;
public:
    Time () {}
    Time(int a, int b, int c):
        hour(a), minute(b), second(c)
    {}

    int getHour(){return this -> hour;}
    int getMinute(){return this -> minute;}
    int getSecond(){return this -> second;}

    void setHour(int h) {this -> hour = h;}
    void setMinute(int m) {this -> minute = m;}
    void setSecond(int s) {this -> second = s;}

    void toString() {
        cout << getHour() << ":" << getMinute()
            << ":" << getSecond();
    }
};

class TimeWithControl: public Time {
public:
    TimeWithControl() {}
    TimeWithControl(int x, int y, int z)
        :Time(x,y,z)
    {}

    bool validateTheHour() {
        if(Time::getHour()>0 && Time::getHour()<25)
            return true;
        else
            return false;
    }

    bool validateTheMinute() {
        if(Time::getMinute()>0 && Time::getMinute() < 61)
            return true;
        else
            return false;
    }

    bool validateTheSecond() {
        if(Time::getSecond()>0 && Time::getSecond() < 61)
            return true;
        else
            return false;
    }

    void toString() {
        if(TimeWithControl::validateTheHour()
           && TimeWithControl::validateTheMinute()
           && TimeWithControl::validateTheSecond())
            cout << Time::getHour() << ":" << Time::getMinute()
            << ":" << Time::getSecond();
        else if(!TimeWithControl:: validateTheHour())
            cout << "This hour not exists!";
        else if(!TimeWithControl:: validateTheMinute())
            cout << "This minute not exists!";
        else if(!TimeWithControl:: validateTheSecond())
            cout << "This second not exists!";
        else
            cout << "Everything was wrong!";
    }

};

int main()
{
    Student student1("Bradley", "Cooper");
    student1.toString();

    cout << endl << endl;

    Graduate graduate1("Smith", "John");
    graduate1.toString();

    cout << endl << endl;

    Person person1("Justin", "Barttra");
    person1.toString();

    cout << endl << endl;

    Time time1(10, 40, 23);
    time1.toString();

    cout << endl << endl;

    TimeWithControl timeWithControl1 (10, 56, 58);
    timeWithControl1.toString();

    return 0;
}
