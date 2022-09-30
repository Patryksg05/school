#include <iostream>

using namespace std;

void lookingForKey(int tab[], string key)
{
    tab[key.length()];
    for (int i = 0; i < key.length(); i++)
        if(key[i] >= 48 && key[i] <= 57) // >= 0 && <= 9
            tab[i] = key[i] - 48;
        else if(key[i] >= 97 && key[i] <= 122) // >= a && <= z
            tab[i] = key[i] - 97 + 1;
        else if(key[i] >= 65 && key[i] <= 90) // >= A && <= Z
            tab[i] = key[i] - 65 + 27;
        else if(key[i] >= 33 && key[i] <= 47) // >= ! && <= /
            tab[i] = key[i] - 33 + 53;
        else if(key[i] >= 58 && key[i] <= 64) // >= : && <= @
            tab[i] = key[i] - 57 + 68;
        else if(key[i] >= 91 && key[i] <= 96) // >= [ && <= `
            tab[i] = key[i] - 91 + 75;
        else if(key[i] >= 123 && key[i] <= 126) // >= { && <= ~
            tab[i] = key[i] - 123 + 81;
        else
          tab[i] = 0;
}

string encryption(string text, string key)
{
  string result = "";
  int tab[key.length()];
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

    return result;
}

// text = zaszyfrowane = result w driver code
string decryption(string text, string key)
{
    string result = "";
    int tab[key.length()];
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

    return result;
}

int main()
{
    string text, key;
    cout << "KEY = "; cin >> key;
    cout << "TEXT = "; cin >> text;
    string result = encryption(text, key);

    // encryption
    cout << "\n---- ENCRYPTION ----\n";
    cout << "\tENCRYPTED WORD = " << result;
    cout << "\n---- --------- ----";

    // decryption
    cout << "\n\n---- DECRYPTION ----\n";
    string decrypted = decryption(result, key);
    cout << "\tDECRYPTED WORD = " << decrypted;
    cout << "\n---- --------- ----\n";

    return 0;
}
