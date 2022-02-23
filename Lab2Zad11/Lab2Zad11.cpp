// Lab2Zad11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
void zadanie11()
{
    struct osoba {
        string imie;
        string nazwisko;
        int wiek;
        osoba* next;
    };
    osoba* head = NULL;
    osoba* tmp = 0;
    osoba* node = 0;
    osoba** tablica;
    int wtab = 0;
    char znak = 't';
    cout << " czy chcesz dodac nowego studenta? t/n ";
    cin >> znak;

    //dodawanie elementu do listy
    while (znak == 't') {
        wtab++;
        node = new osoba;
        node->next = NULL;
        cout << "Podaj imie:\n";
        cin >> node->imie;
        cout << "Podaj nazwisko:\n";
        cin >> node->nazwisko;
        cout << "Podaj wiek:\n";
        cin >> node->wiek;
        //czy lista jest pusta
        if(head) {
            tmp = head;
            while (tmp->next) {
                tmp = tmp->next;
            }
            tmp->next = node;
        }
        else {
            head = node;
        }
        cout << " czy chcesz dodac nowego studenta? t/n ";
        cin >> znak;
    }
    // wyswietlamy elementy listy i wstawianie do tablicy
    tablica = new osoba * [wtab];
    tmp = head;
    
    int i = 1;
    while (tmp) {
        cout << "Imie osoby nr " << i << " to " << tmp->imie << " nazwisko to " << tmp->nazwisko << " wiek " << tmp->wiek << endl;
        tablica[i - 1] = new osoba;
        (*(tablica + (i - 1)))->imie = tmp->imie;
        (*(tablica + (i - 1)))->nazwisko = tmp->nazwisko;
        (*(tablica + (i - 1)))->wiek = tmp->wiek;
        (*(tablica + (i - 1)))->next = NULL;
        tmp = tmp->next;        
        i++;
    }
    // wyswietlamy elementow tablicy
    for (int i = 0; i < wtab; i++) {
        cout << "Imie osoby z tablice nr " << i+1 << " to " << tablica[i]->imie << " nazwisko to " << tablica[i]->nazwisko << " wiek " << tablica[i]->wiek << endl;
    }

   

    

    // usuwanie dowolnego elementu z listy
    //cout << "Podaj imie które chcesz usunac ";
    //string imie;
    //cin >> imie;
    //tmp = head;
    //if (tmp->imie == imie) {
    //    osoba* xyz = tmp;
    //    head = tmp->next;
    //    delete(xyz);
    //    tmp = head;
    //}

    //while (tmp->next!=nullptr) {
    //    if (tmp->next->imie == imie) {
    //        osoba* xyz = tmp->next;
    //        tmp->next = tmp->next->next;
    //        delete(xyz);            
    //    }
    //    tmp = tmp->next;
    //}

    //// wyswietlamy elementy listy
    //tmp = head;
    //i = 1;
    //while (tmp) {
    //    cout << "Imie osoby nr " << i << " to " << tmp->imie << " nazwisko to " << tmp->nazwisko << " wiek " << tmp->wiek << endl;
    //    tmp = tmp->next;
    //    i++;
    //}


    //dodawanie elentow do srodka listy 

    cout << "czy chcesz dodac nowego studenta? t/n\n";
    cin >> znak;
    osoba* node2;

    if (znak == 't') {
        //usuniecie elementow ze tablicy
        for (int i = 0; i < wtab; i++) {
            delete* (tablica + i);
        }
        delete[] tablica;
    }


    if (znak == 't') {
        wtab++;
        int pozycja = 0;
        cout << "na jaka pozycje chcialbys wstawic nowy element? Powinien to byc numer miedzy 1 a " << i-1 << endl;;
        cin >> pozycja;

        node2 = new osoba;
        node2->next = 0;

        cout << "Podaj imie:\n";
        cin >> node2->imie;
        cout << "Podaj nazwisko:\n";
        cin >> node2->nazwisko;
        cout << "Podaj wiek:\n";
        cin >> node2->wiek;
                
        tmp = head;
        if (pozycja == 1) {
            node2->next = tmp;
            head = node2;
        }
        else if (pozycja == i-1) {
            for (int j = 1;j<i ;j++) {
                if (j == pozycja) {
                    tmp->next = node2;                    
                }
                else {
                    tmp = tmp->next;
                }               
            }
        }
        else {
            for (int j = 1; j < pozycja; j++) {
                if (j == pozycja - 1) {
                    node2->next = tmp->next;
                    tmp->next = node2;
                }
                else {
                    tmp = tmp->next;
                }
            }
        }
    }

    
    // wyswietlamy elementy listy
    tmp = head;
    tablica = new osoba * [wtab];
    i = 1;
    while (tmp) {
        cout << "Imie osoby nr " << i << " to " << tmp->imie << " nazwisko to " << tmp->nazwisko << " wiek " << tmp->wiek << endl;
        tablica[i - 1] = new osoba;
        (*(tablica+(i - 1)))->imie= tmp->imie;
        (*(tablica + (i - 1)))->nazwisko = tmp->nazwisko;
        (*(tablica + (i - 1)))->wiek = tmp->wiek;
        (*(tablica + (i - 1)))->next = NULL;
        tmp = tmp->next;
        i++;
    }

    for (int i = 0; i < wtab; i++) {
        cout << "Imie osoby z tablicy nr " << i + 1 << " to " << tablica[i]->imie << " nazwisko to " << tablica[i]->nazwisko << " wiek " << tablica[i]->wiek << endl;
    }

    // usuwamy elementy listy
    tmp = head;
    osoba* pom;
    while (tmp->next) {
        pom = tmp;
        tmp = tmp->next;
        delete(pom);
    }
    cout << endl;

    for (int i = 0; i < wtab; i++) {
        delete* (tablica + i);
    }
    delete[] tablica;

}





int main()
{
    zadanie11();
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
