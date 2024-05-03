#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Client {
private:
    string name;
    int overdraft;
public:
    Client(string n, int o)
    {
        this->name = n;
        this->overdraft = o;
    }

    string get_name() { return this->name; }
    int get_overdraft() { return this->overdraft; }
};

class Financial {
private:
    vector<Client> clients;
    string file_name;
    string word1, word2;
public:
    Financial() { this->file_name = "dane.txt"; }

    bool is_file_open()
    {
        ifstream file(file_name);
        return file.is_open();
    }

    void read_from_file()
    {
        ifstream file(file_name);

        if (is_file_open())
        {
            /*while (getline(file, line))
            {
                cout << line[0] << endl;
            }*/

            while (file >> word1 >> word2)
            {
                // Client client(word1, stoi(word2));
                // clients.push_back(client);
                clients.push_back(Client(word1, stoi(word2)));

                if (word1 == "-1")
                    break;

            }
        }

        file.close();
    }

    void display_clients()
    {
        cout << "\nCLIENTS IN OUR FINANCIAL SYSTEM: \n";
        for (Client client : clients)
        {
            cout << client.get_name() << " " << client.get_overdraft() << endl;
        }
    }

    void read_data_from_user(string file_name)
    {
        ofstream file(file_name, ios::app);

        string name;
        int overdraft;

        cout << "ADD NEW CLIENT:" << endl;
        cout << "Name: "; cin >> name;
        cout << "Overdraft: (amount in zl): "; cin >> overdraft;

        if (file.is_open())
        {
            file << endl << name << " " << overdraft;
            file.close();
        }
    }

    int get_max_overdraft()
    {
        int maxi_overdraft = 0;
        for (Client clients : clients)
        {
            if (clients.get_overdraft() > maxi_overdraft)
                maxi_overdraft = clients.get_overdraft();
        }
        return maxi_overdraft;
    }

    string get_name_from_overdraft(int amount)
    {
        string name;
        for (Client client : clients)
        {
            if (client.get_overdraft() == amount)
                name = client.get_name();
        }
        return name;
    }
};

int main()
{
    Financial financial;
    financial.read_data_from_user("dane.txt");
    financial.read_from_file();
    financial.display_clients();

    cout << "\nThe max overdraft in our financial is: " << financial.get_max_overdraft()
        << " from: " << financial.get_name_from_overdraft(financial.get_max_overdraft()) << endl;

}


/*
    Napisz program, który wczyta dane klientów z pliku dane.txt do tablicy. 
    Plik dane.txt zawiera nazwisko klienta oraz wartość debetu (od 0 do 1000 - tylko liczby całkowite). 
    Załóż, że plik dane.txt nie jest pusty. Tablica jest polem klasy. Wszystkie elementy tablicy 
    są wyświetlane na ekranie. 
    
    Klasa zawiera conajmniej metody: 
        wczytującą dane, której argumentem jest nazwa pliku, wyświetlającą dane z tablicy 
        oraz wyszukującą największy debet. 
    Widzialność metody szukającej ogranicza się wyłącznie do klasy. 
    Metoda szukająca zwraca wartość największego debetu.
    Program powinien być napisany czytelnie z zasadami czystego kodu.
    Plik ma format:
    Nazwisko1 Debet1
    Nazwisko2 Debet2
    ...
    NazwiskoN DebetN
    Na końcu pliku jest wartość -1 oznaczająca koniec danych.    
*/