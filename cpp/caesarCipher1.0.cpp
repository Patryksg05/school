#include <iostream>

using namespace std;

// content: caesar cipher

string encrypt(string text, int key)
{
    string result = "";

    for(int i=0; i<text.length(); i++)
    {
        if(isupper(text[i]))
            result += char(int(text[i]+key-65)%26 + 65);
        else
            result += char(int(text[i]+key-97)%26 + 97);
    }
    return result;
}

int main()
{
    string text = "ABCD";
    cout << text;
    cout << "\nCipher: " <<encrypt(text, 3);
    return 0;

}
