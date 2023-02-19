#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int octalToDecimal(int octalNumber)
{
	int decimalNumber = 0, i = 0, rem;
	while (octalNumber != 0)
	{
		rem = octalNumber % 10;
		octalNumber /= 10;
		decimalNumber += rem * pow(8, i);
		++i;
	}
	return decimalNumber;
}

bool isRacing(string n)
{
	for (int i = 0; i < n.size()-1; i++)
	{
		if (n[i] > n[i + 1])
		{
			return false;
			break;
		}
	}
	return true;
}

int maxi_value(vector<int> elements)
{
	if (elements.size() == 0)
		return -1;

	int maxi = elements.at(0);
	for (size_t i = 0; i < elements.size(); i++)
	{
		if (maxi < elements.at(i))
			maxi = elements.at(i);
	}
	return maxi;
}

int mini_value(vector<int> elements)
{
	if (elements.size() == 0)
		return -1;

	int mini = elements.at(0);
	for (size_t i = 0; i < elements.size(); i++)
	{
		if (mini > elements.at(i))
			mini = elements.at(i);
	}
	return mini;
}

int main()
{
	ifstream file("dane.txt");
	string line, decimalString;

	int firstEqualsLastOctal = 0;
	int firstEqualsLastDecimal = 0;
	int racingNum = 0;
	int decimal, max_value = 112267, min_value = 112267; // 112267 => pierwszy liczba spelniajaca warunek

	vector<int> racingNumbers;
	//if (file.good())
	//{
	//	getline(file, firstElement);
	//	cout << firstElement;
	//}
		
	for (int i = 0; i < 5000; i++)
	{
		file >> line;
		//cout << line << " " << line[0] << " " << line[line.size() - 1] << endl;
		if (line[0] == line[line.size() - 1])
			firstEqualsLastOctal++;

		decimal = octalToDecimal(stoi(line));
		decimalString = to_string(decimal);

		if (decimalString[0] == decimalString[decimalString.size() - 1])
			firstEqualsLastDecimal ++;

		if (isRacing(line))
		{
			racingNum++;
			racingNumbers.push_back(stoi(line)); // sposob I

			// II sposob: 
			//cout << line << " " << endl; 
			// max_value i min_value ustawiona wartosc na 
			// pierwszy element spelniajacy warunek: 

			if (max_value < stoi(line))
				max_value = stoi(line);

			if (min_value > stoi(line))
				min_value = stoi(line);
		}
	}

	cout << "a. Pierwsza rowna ostatniej: " << firstEqualsLastOctal;
	cout << endl << "b. Pierwsza rowna ostatniej: " << firstEqualsLastDecimal;
	cout << endl << "c. Cyfry rosnace(razem): " << racingNum;
	cout << endl << "\t- (sposob I) max element: " << maxi_value(racingNumbers);
	cout << endl << "\t- (sposob I) min element: " << mini_value(racingNumbers);
	cout << endl << "\t- (sposob II) max element: " << max_value;
	cout << endl << "\t- (sposob II) min element: " << min_value;

	return 0;

	/*
		odpowiedzi: 
			a. 447 + 1
			b. 324 + 1
			c. liczba: 49
	*/
}
