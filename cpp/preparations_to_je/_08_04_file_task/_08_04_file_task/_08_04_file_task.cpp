#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

int main()
{
    cout << "_8_04 => file task, before quiz" << endl;

    Client client1("John", "Jones", "jone.jones@gmail.com", "999");
    Client client2("Edward", "Noob", "edward.jones@gmail.com", "998");
    Client client3("Josh", "Misunderstanding", "josh.jones@gmail.com", "997");

    Database database;

    database.add_client(client1);
    database.add_client(client2);
    database.add_client(client3);
    
    cout << "Number of clients using our database: " << database.number_of_clients() << endl;
    database.display_clients();

    cout << endl;
    database.data_from_client_after_last_name("Noob");
    database.data_from_client_after_last_name("any");

    return 0;
}
