#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

//1) Zarządzanie bazą danych klientów :
//Stwórz program, który umożliwia dodawanie, usuwanie, edytowanie i wyświetlanie 
//klientów w bazie danych.Każdy klient powinien mieć unikalny identyfikator, imię, 
//nazwisko, adres e - mail, numer telefonu itp.Można wykorzystać kontenery z biblioteki 
//STL, takie jak vector, map lub unordered_map, aby przechowywać dane klientów.
//Można również wykorzystać algorytmy STL do sortowania, wyszukiwania lub filtrowania danych klientów.

class Client {
private:
    int id;
    static int counter;
    string first_name;
    string last_name;
    string email_address;
    string phone_number;

public:
    Client(string fN, string lN, string eA, string pN)
    {
        this->id = counter++;
        this->first_name = fN;
        this->last_name = lN;
        this->email_address = eA;
        this->phone_number = pN;
    }

    int get_id() { return this->id; }
    string get_first_name() { return this->first_name; }
    string get_last_name() { return this->last_name; }
    string get_email_address() { return this->email_address; }
    string get_phone_number() { return this->phone_number; }
};

int Client::counter = 0;

class Database {
private:
    vector<Client> clients;
public:
    Database() {}

    void add_client(Client client) { clients.push_back(client); }
    int number_of_clients() { return clients.size(); }
    string get_first_client_last_name() { return clients[0].get_last_name(); }

    void display_clients()
    {
        cout << "CLIENTS IN DATABASE:\n";

        for (Client client : clients)
        {
            cout << "First Name: " << client.get_first_name() << 
                ", Last Name: " << client.get_last_name() << endl;
        }
    }

    void data_from_client_after_last_name(string lN)
    {
        for (Client client : clients)
        {
            if (lN == client.get_last_name())
            {
                cout << "Data with client of surname: " << lN
                    << "\nId: " << client.get_id()
                    << "\nFirst name: " << client.get_first_name() << endl; 
            }
        }
    }
};

/*3) System zarządzania zadaniami :
Stwórz program, który pozwala użytkownikowi zarządzać zadaniami 
do wykonania.Każde zadanie powinno mieć nazwę, opis, priorytet oraz 
status(np.zakończone, w trakcie realizacji, oczekujące).Możesz wykorzystać 
kontenery z biblioteki STL, takie jak vector lub list, do przechowywania zadań.
Można również użyć algorytmów STL do sortowania zadań według różnych kryteriów, 
takich jak priorytet lub data dodania.Dodatkowo, można użyć struktur danych z 
biblioteki STL do reprezentacji priorytetowej kolejki, aby zarządzać zadaniami zgodnie z ich priorytetami*/

class Task {
private:
    string name;
    string desc;
    bool priority;
    int condition; // 0 - zakonczone 1 - w trakcie 2 - oczekujace

public:
    Task(string n, string d, bool p, int c)
    {
        this->name = n;
        this->desc = d;
        this->priority = p;
        this->condition = c;
    }

    Task(string n, string d)
    {
        this->name = n;
        this->desc = d;
        this->priority = false;
        this->condition = 2;
    }

    string get_name() { return this->name; }
    string get_desc() { return this->desc; }
    bool get_priority() { return this->priority; }
    int get_condition() { return this->condition; }

    void set_priority() { (priority == true)?priority = false : priority = true; }
    void set_condition(int c) { this->condition = c; }
};

class TaskManagmentSystem {
private:
    vector<Task> tasks;
public:
    TaskManagmentSystem() {}

    void add_task_to_tms(Task task)
    {
        tasks.push_back(task);
    }

    void display_the_most_important_tasks()
    {
        cout << "The most important tasks:\n";

        for (Task task : tasks)
        {
            if (task.get_priority() && task.get_condition() != 0)
            {
                cout << "Name: " << task.get_name()
                    << "\nDescription: " << task.get_desc()
                    << "\nCondition: " << task.get_condition() << endl << endl;
            }
        }
    }

    void to_string()
    {
        cout << "TASKS IN OUR SYSTEM\n";

        for (Task task : tasks)
        {
            cout << "Name: " << task.get_name()
                << "\nDescription: " << task.get_desc()
                << "\nPriority: " << task.get_priority()
                << "\nCondition: " << task.get_condition() << endl << endl;
        }
    }
};

// 4) Napisz proszę program w języku C++, który odczyta plik liczby.txt i 
// znajdzie w nim informację ile jest takich liczb, których cyfry pierwsza i 
// ostatnia są takie same.Zapisz tę z nich, która występuje w pliku liczby.txt 
// jako pierwsza.Załóż, że w pliku jest co najmniej jedna taka liczba.

class File {
private:
    string line;
    string file_name;
    vector<string> condtion_nums;
public:
    File(string fN) { this->file_name = fN; }

    bool is_file_open() {
        ifstream file(file_name);
        return file.is_open();
    }

    void read_data()
    {
        ifstream file(file_name);
        if (is_file_open())
        {
            while (getline(file, line))
            {
                // cout << line << endl;
                if (line[0] == line[line.size() - 1])
                    cout << line << endl;
            }
        }
        else
            cout << "Error with file opening.." << endl;
    }

    int first_and_last_the_same()
    {
        int counter = 0;
        ifstream file(file_name);

        if (is_file_open())
        {
            while (getline(file, line))
            {
                if (line[0] == line[line.size() - 1])
                    counter++;
            }
        }
        return counter;
    }

    string first_the_same_condition()
    {
        ifstream file(file_name);

        if (is_file_open())
        {
            while (getline(file, line))
            {
                if (line[0] == line[line.size() - 1])
                    condtion_nums.push_back(line);
            }
        }
        return condtion_nums.at(0);
    }
};

// 2) Kalkulator wyrażeń matematycznych z odwrotną notacją polską(ONP) :
//Napisz program, który pobiera od użytkownika wyrażenie matematyczne w postaci ONP 
//i oblicza jego wartość.Wykorzystaj stos(stack) z biblioteki STL do obsługi operacji 
//na stosie, takich jak operatory arytmetyczne i operandy. Możesz również użyć strumieni 
//wejścia - wyjścia z biblioteki STL do pobierania wyrażeń od użytkownika.

int notation(vector<string>& v)
{
    stack<int> st;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != "+" && v[i] != "-" && v[i] != "/" && v[i] != "*") {
            st.push(stoi(v[i]));
            continue;
        }
        else {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (v[i] == "+")
                st.push(a + b);
            else if (v[i] == "-")
                st.push(a - b);
            else if (v[i] == "*")
                st.push(a * b);
            else
                st.push(a / b);
        }
    }
    return st.top();
}

int main()
{
    cout << "_8_04 => file task, before quiz" << endl;
    

    //vector<string> res1 = { "4", "7", "-" };
    //vector<string> res2 = { "4", "2", "+", "8", "*" };

    //int r1 = notation(res1);
    //int r2 = notation(res2);

    //cout << endl << "Results: " << r1 << " " << r2 << endl;


    //File file("liczby.txt");
    //cout << "Is file open:? " << file.is_file_open();
    //// file.read_data();
    //cout << "\nFirst and the same counter: " << file.first_and_last_the_same();
    //cout << "\nFirst num with condtion: " << file.first_the_same_condition();

    //Client client1("John", "Jones", "jone.jones@gmail.com", "999");
    //Client client2("Edward", "Noob", "edward.jones@gmail.com", "998");
    //Client client3("Josh", "Misunderstanding", "josh.jones@gmail.com", "997");

    //Database database;

    //database.add_client(client1);
    //database.add_client(client2);
    //database.add_client(client3);
    //
    //cout << "Number of clients using our database: " << database.number_of_clients() << endl;
    //database.display_clients();

    //cout << endl;
    //database.data_from_client_after_last_name("Noob");
    //database.data_from_client_after_last_name("any");

    /*
    Task task1("quiz from physics", "counting", false, 2);
    Task task2("quiz from chemistry", "changing", false, 2);
    Task task3("app in android", "on sth changed", true, 1);

    TaskManagmentSystem taskManagmentSystem;

    task2.set_priority();
    task1.set_priority();

    task3.set_condition(0);

    taskManagmentSystem.add_task_to_tms(task1);
    taskManagmentSystem.add_task_to_tms(task2);
    taskManagmentSystem.add_task_to_tms(task3);

    taskManagmentSystem.display_the_most_important_tasks(); */
    // taskManagmentSystem.to_string();

    return 0;
}
