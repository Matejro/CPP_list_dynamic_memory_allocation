// Lab2Zad10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Egzaminy { char przedmiot[20];  int ocena; };
struct Studenci { char kierunek[20]; int rok; Egzaminy** tab; };


int main()
{

    int ilu = 0;
    int** egzaminy;
    std::cout << "Witam w programie zapisujacym informacje o studentach, wpisz ilu studentow chcesz dodac: \n";
    cin >> ilu;

    Studenci** studenci;
    studenci = new Studenci*[ilu];
    egzaminy = new int* [ilu];

    for (int i = 0; i < ilu; i++) {
        int liczba = 0;
        studenci[i] = new Studenci;
        egzaminy[i] = new int;
        cout << "Podaj kierunek (max 20 liter) studenta nr "<<i+1<<endl;
        cin >> (*(studenci+i))->kierunek;
        cout << "Podaj na ktorym roku jest student nr " << i + 1 << endl;
        cin >> (studenci[i])->rok;
        cout << "Podaj ilosc egzaminow dla studenta nr " << i + 1 << endl;
        cin >> *(*(egzaminy+i));        
        studenci[i]->tab = new Egzaminy* [*(*(egzaminy + i))];
        for (int j = 0; j < *(*(egzaminy + i)); j++) {
            studenci[i]->tab[j] = new Egzaminy;
            
            cout << "Podaj nazwe egzaminu (max 20 liter) nr: " << j + 1 << " dla studenta numer " << i + 1 << endl;
            cin >> (studenci[i]->tab[j])->przedmiot;
            cout << "Podaj ocene z egzaminu nr: " << j + 1 << " dla studenta numer " << i + 1 << endl;
            cin>> (studenci[i]->tab[j])->ocena;
        }
     }

    for (int i = 0; i < ilu; i++) {
        cout << "Student numer " << i + 1 << " studiuje na kierunku " << (*(studenci + i))->kierunek << " jest na roku nr " << (*(studenci + i))->rok << endl;
        cout << "Zdal dotychczas egzaminy w ilosci " << *(*(egzaminy + i)) << " z kazdego z nich mial nastepujace oceny" << endl;
        for (int j = 0; j < *(*(egzaminy + i)); j++) {
            cout << "Przedmiot: " << (studenci[i]->tab[j])->przedmiot << " ocena: " << (studenci[i]->tab[j])->ocena << endl;
            delete[] studenci[i]->tab[j];
        }
        delete* (egzaminy + i);
        delete* (studenci+i);
    }
    delete[] egzaminy;
    delete[] studenci;



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
