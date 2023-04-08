#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>

class Kalkulator {
private:
	T num1, num2;
public:
	Kalkulator(T l1, T l2) : num1(l1), num2(l2) {}

	T dodawanie() { return num1 + num2; }
	T odejmowanie() { return num1 - num2; }
	T mnozenie() { return num1 * num2; }
	T dzielenie() { return (num1 == 0 || num2 == 0) ? -1: num1/num2;}
	T potegowanie() { return std::pow(num1, num2); }
	T nwd()
	{
		while (num1 != num2)
		{
			if (num1 > num2)
				num1 =- num2;
			else
				num2 -= num1;
		}
		return num1;
	}
	T nww() 
	{
		return num1 * num2 / nwd(num1, num2);
	}

	void displayResult()
	{
		std::cout << "\n\nWYNIKI: ";
		std::cout << "suma: " << dodawanie() <<
			"\nodejmowanie: " << odejmowanie() <<
			"\nmnozenie: " << mnozenie() <<
			"\ndzielenie: " << dzielenie() <<
			"\npotegowanie: " << potegowanie();
	}
};

int main()
{
	Kalkulator<int> kalkulator(10,2);
	Kalkulator<float> kalkulator2(3.14,1.5);
	Kalkulator<double> kalkulator3(3.1415,1.245);
	//kalkulator.displayResult();
	//kalkulator2.displayResult();
	//kalkulator3.displayResult();
	
	try {
		char buffer[256];
		ifstream myfile("zadanie_szablony.txt");
		myfile.exceptions(ifstream::eofbit | ifstream::failbit | ifstream::badbit);
		while (!myfile.eof())
		{
			myfile.getline(buffer, 100);
			cout << buffer << endl;
		}
		myfile.close();

	}
	catch (std::exception const& e) {
		cout << "There was an error: " << e.what() << endl;
	}

	return 0;
}
