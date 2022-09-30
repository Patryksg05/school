#include <iostream>

using namespace std;

string reverseSTR(string str){
    string r;
    int length = str.length();
    for(int i=length-1; i>=0; i--)
        r += str[i];
    return r;
}

int main(){

    string s; cout << "String: ";
    cin >> s;
    s = reverseSTR(s);
    cout << "Po zamianie: " << s;
    return 0;

}
