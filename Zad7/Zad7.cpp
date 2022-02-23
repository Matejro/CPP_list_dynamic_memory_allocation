// Zad7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4996)
#endif
using namespace std;

struct Wiz { int x; char* k; };


int main()
{
    char* s = new char[10];
    strcpy(s,"hello");
    
    
    Wiz** tab;
    int ile;
    cout << "Ilu elementowa powinna byæ tablica?: " << endl;
    cin >> ile;

    tab = new Wiz * [ile];
    for (int i = 0; i < ile; i++) {
        tab[i] = new Wiz;
        tab[i]->k = new char[100];
        cout << "Wypisz liczba dla elementu nr " << i + 1 << endl;
        
        cin >> (tab[i])->x;
        cout << "Wypisz slowo dla elementu nr " << i + 1 << endl;
        cin >> (*(tab + i))->k;

    }

    for (int i = 0; i < ile; i++) {
        cout << "element "<<i+1<<" zawiera odpowiednio liczbe "<<(tab[i])->x<<" jak i slowo "<< (tab[i])->k;
        delete tab[i]->k;
        delete* (tab + i);
       
    }
    delete[] tab;

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
