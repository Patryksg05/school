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

    return 0;
}
