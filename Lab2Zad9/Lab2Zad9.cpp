// Lab2Zad9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

char* znajdz(char* s, char c){
    int count=0;
    char* result=NULL;
    for (int i = 0; i < strlen(s)+1; i++) {
        if (count>1) {
            result = new char;
            *result = s[i-1];
            break;
        }
        else if(tolower(s[i])==tolower(c)){
            count += 1;
        }
    }
    cout << "rozmiar tekstu to " << strlen(s) << endl;
    if (count == 2) {
       
        return result;
    }
    else {
        delete result;
        return NULL;
    }             
}

int main()
{
    char sentence[10];
    char c;
    cout << "Podaj sentencje max 10 znakow" << endl;
    cin >> sentence;
    cout << "Podaj szukany znak" << endl;
    cin >> c;
    char* p;
    p = znajdz(sentence, c);
    char z = !p ? '0' : *p;
    cout << "Szukana wartosc to " << z << " jest zapisana pod adresem " << &p << endl;
    delete p;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
