#include <iostream>
#include <string>
#include <vector>
#include <stack>

/*
	a) na której pozycji występuje wzorzec (jeżeli w ogóle)
	b) ile razy wzorzec się pojawia w tekscie
	c) w którym wierszu pliku wzorzec pojawia się najczęściej i ile razy
	d) polska notacja 
	e) cipher
*/

using namespace std;

int looking_for_pattern(string specific, string text) {
	for (int i = 0; i < text.size() - specific.size(); i++)
	{
		int c = 0;
		for (int j = 0; j < specific.size(); j++)
		{
			if (specific[j] != text[i + c])
				break;
			if (j == specific.size() - 1) {
				return i;
			}
			++c;
		}
	}
	return -1;
}

void print_occurrences(string txt, string pattern) {
	cout << "index: ";
	int found = txt.find(pattern);
	while (found != string::npos) {
		//"until the end of the string
		cout << found << " ";
		found = txt.find(pattern, found + 1);
	}
}

int count_occurrences(string txt, string pattern) {
	int counter = 0;
	int found = txt.find(pattern);
	while (found != string::npos) {
		counter++;
		found = txt.find(pattern, found + 1);
	}
	return counter;
}

int if_pattern(string txt, string pattern, int start) {
	int j;
	for (j = 0; j < pattern.length(); j++) {
		if (txt[start + j] != pattern[j]) return -1;
	}
	return j-1;
}

bool is_palin(string txt) {
	bool is_palin = true;
	int last_elemnent = txt.length() - 1;
	for (int i = 0; i < txt.length(); i++) {
		if (txt[i] != txt[last_elemnent]) {
			is_palin = false;
			break;
		}
		last_elemnent--;
	}
	return is_palin;
}

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

void lookingForKey(int tab[], string key) {
	tab[key.length()];
	for (int i = 0; i < key.length(); i++)
		if (key[i] >= 48 && key[i] <= 57) // >= 0 && <= 9
			tab[i] = key[i] - 48;
		else if (key[i] >= 97 && key[i] <= 122) // >= a && <= z
			tab[i] = key[i] - 97 + 1;
		else if (key[i] >= 65 && key[i] <= 90) // >= A && <= Z
			tab[i] = key[i] - 65 + 27;
		else if (key[i] >= 33 && key[i] <= 47) // >= ! && <= /
			tab[i] = key[i] - 33 + 53;
		else if (key[i] >= 58 && key[i] <= 64) // >= : && <= @
			tab[i] = key[i] - 57 + 68;
		else if (key[i] >= 91 && key[i] <= 96) // >= [ && <= `
			tab[i] = key[i] - 91 + 75;
		else if (key[i] >= 123 && key[i] <= 126) // >= { && <= ~
			tab[i] = key[i] - 123 + 81;
		else
			tab[i] = 0;
}

string encryption(string text, string key) {
	string result = "";
	int* tab = new int[key.length()];
	lookingForKey(tab, key);

	for (int i = 0; i < text.length(); i++)
		if (text[i] >= 48 && text[i] <= 57)
			result += (char)((text[i] - 48 + tab[i % key.length()]) % 10 + 48);
		else if (text[i] >= 97 && text[i] <= 122)
			result += (char)((text[i] - 97 + tab[i % key.length()]) % 26 + 97);
		else if (text[i] >= 65 && text[i] <= 90)
			result += (char)((text[i] - 65 + tab[i % key.length()]) % 26 + 65);
		else if (text[i] >= 33 && text[i] <= 47)
			result += (char)((text[i] - 33 + tab[i % key.length()]) % 15 + 33);
		else if (text[i] >= 58 && text[i] <= 68)
			result += (char)((text[i] - 58 + tab[i % key.length()]) % 7 + 58);
		else if (text[i] >= 91 && text[i] <= 96)
			result += (char)((text[i] - 91 + tab[i % key.length()]) % 6 + 91);
		else if (text[i] >= 123 && text[i] <= 126)
			result += (char)((text[i] - 123 + tab[i % key.length()]) % 4 + 123);
		else
			result += text[i];

	delete[] tab;
	return result;
}

string decryption(string text, string key) {
	string result = "";
	int* tab = new int[key.length()];
	lookingForKey(tab, key);

	for (int i = 0; i < text.length(); i++)
		if (text[i] >= 48 && text[i] <= 57)
			result += (char)((text[i] - 48 - tab[i % key.length()] + 10) % 10 + 48);
		else if (text[i] >= 97 && text[i] <= 122)
			result += (char)((text[i] - 97 - tab[i % key.length()] + 26) % 26 + 97);
		else if (text[i] >= 65 && text[i] <= 90)
			result += (char)((text[i] - 65 - tab[i % key.length()] + 26) % 26 + 65);
		else if (text[i] >= 33 && text[i] <= 47)
			result += (char)((text[i] - 33 - tab[i % key.length()] + 15) % 15 + 33);
		else if (text[i] >= 58 && text[i] <= 68)
			result += (char)((text[i] - 58 - tab[i % key.length()] + 7) % 7 + 58);
		else if (text[i] >= 91 && text[i] <= 96)
			result += (char)((text[i] - 91 - tab[i % key.length()] + 6) % 6 + 91);
		else if (text[i] >= 123 && text[i] <= 126)
			result += (char)((text[i] - 123 - tab[i % key.length()] + 4) % 4 + 123);
		else
			result += text[i];
	delete[] tab;
	return result;
}

int main()
{
	cout << "PATTERN IN A STRING\n";
	string txt = "abcdefghcd";
	string pattern = "cd";
	cout << "TEXT: " << txt << " PATTERN:" << pattern << endl;
	print_occurrences(txt, pattern);
	cout << endl << "Occurrencies: " << count_occurrences(txt, pattern);
	cout << endl << if_pattern(txt, pattern, 0);
	cout <<  " " << if_pattern(txt, pattern, 2);
	cout << " " << if_pattern(txt, pattern, 3);

	cout << endl << "--------\nPALINDROMS\n";
	cout << is_palin("kajak") << " ";
	cout << is_palin("lalka") << " ";
	cout << is_palin("anna") << " ";

	cout << endl << "--------\nPOLISH NOTATION";

	vector<string> res1 = { "4", "7", "-"};
	vector<string> res2 = { "4", "2", "+", "8", "*"};

	int r1 = notation(res1);
	int r2 = notation(res2);
	cout << endl << "Results: " << r1 << " " << r2 << endl;

	cout << "--------\nCIPHER\n";
	string text, key, result;
	cout << "KEY = "; cin >> key;
	cout << "TEXT = "; cin >> text;
	result = encryption(text, key);

	// encryption
	cout << "---- ENCRYPTION ----\n";
	cout << "\tENCRYPTED WORD = " << result;
	cout << "\n---- --------- ----";

	// decryption
	cout << "\n---- DECRYPTION ----\n";
	string decrypted = decryption(result, key);
	cout << "\tDECRYPTED WORD = " << decrypted;
	cout << "\n---- --------- ----\n";


}
