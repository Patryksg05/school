#include <iostream>
#include <vector>

using namespace std;

vector<int> even_numbers(const int tab[], int size)
{
	vector<int> even;
	for (int i = 0; i < size; i++)
		if (tab[i] % 2 == 0)
			even.push_back(tab[i]);

	return even;
}

int get_mini_value(int tab[], int s)
{
	int mini = tab[0];
	for (int i = 0; i < s; i++)
	{
		if (mini > tab[i])
			mini = tab[i];
	}
	return mini;
}

int* even_number_as_tab(const int tab[], int size, int &result_size)
{
	result_size = 0;
	for (int i = 0; i < size; i++)
		if (tab[i] % 2 == 0)
			result_size++;

	int* result = new int[result_size];
	int index = 0;

	for (int i = 0; i < size; i++)
	{
		if (tab[i] % 2 == 0)
			result[index++] = tab[i];
	}
	return result;
}

double median(int tab[], int s)
{
	if (s % 2 == 0)
		return (tab[s / 2 - 1] + tab[s / 2]) / 2.0;
	else
		return tab[s / 2];
}

int main()
{
	cout << "EXERCISE: _19_02\nzad1.1" << endl;

	// zad1.1
	int tab[12];

	for (int i = 0; i < 12; i++)
		tab[i] = rand() % 10;

	for (int i = 0; i < 12; i++)
		cout << tab[i] << " ";

	cout << endl;

	vector<int> even = even_numbers(tab, 12);
	int sum = 0;
	for (int num : even)
	{
		cout << num << " ";
		sum += num;
	}

	cout << endl << "Even numbers count: " << even.size() << endl;
	cout << "Average: " << (double)sum / even.size() << endl;
	
	// zad1.2
	cout << "zad1.2" << endl;
		
	int d_size;
	cout << "Size of array: "; cin >> d_size;
	int* d_tab = new int[d_size];

	for (int i = 0; i < d_size; i++)
		d_tab[i] = 20 + rand() % ((60 + 1) - 20);

	for (int i = 0; i < d_size; i++)
		cout << d_tab[i] << " ";
	
	cout << endl << "Mini value: " << get_mini_value(d_tab, d_size) << endl;
	int r_s;
	int* even_result = even_number_as_tab(d_tab, d_size, r_s);
	
	for (int i = 0; i < r_s; i++)
		cout << even_result[i] << " ";

	for (int i = 0; i < r_s; i++)
	{
		for (int j = i + 1; j < r_s; j++)
		{
			if (even_result[i] > even_result[j])
			{
				int temp = even_result[i];
				even_result[i] = even_result[j];
				even_result[j] = temp;
			}
		}
	}
	cout << "\nAsc sort even num: ";
	for (int i = 0; i < r_s; i++)
		cout << even_result[i] << " ";
	cout << "\nMedian: " << median(even_result, r_s);
}

/*
	Zadanie na ocenę 1:
		Zdefiniuj dwunastoelementowa tablicę statyczną do której losowane(lub wpisywane)
		będą wartości z zakresu od 0 do 9. Wyznacz ile jest w tablicy liczb parzystych oraz 
		ich średnią arytmetyczną. Program powinien wyświetlać wylosowaną tablicę, ilość liczb 
		parzystych oraz ich średnią arytmetyczną. (2)
	Zadanie na ocenę 2 :
		Zdefinuj tablicę dynamiczną.
		Użytkownik definiuje ile elementów ma być w tablicy.
		Do tablicy losowane są wartości całkowite z zakresu 20 do 60.
		Program ma najpierw wyświetlić zawartość tablicy, a następnie wszystkie parzyste
		elementy tablicy posortowane rosnąco. (3 - 4)
		Program ma również wyznaczać medianę z parzystych elementóœ tablicy. (5)
		Mediana, to wartość środkowa z uporządkowanego zbioru liczb(nieparzysta ilość liczb) lub
		średnia arytmetyczna dwóch środkowych liczb(parzysta ilość liczb).
*/
