#include <iostream>
#include <time.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include "Sorting.h"

using namespace std;



int main()
{
    int liczbaElementow;
    clock_t start,stop;
    double czas;
    char koniec = 'n';
    Film *sort;

    //inicjowanie generatora liczba losowych ("ziarna")
    srand(time(NULL));

    cout << "Program sortujacy zadanej wielkosci tablice wybranym algorytmem\n";

    while(koniec == 'n') {
        cout << "\nIle elementow w tablicy: ";
        cin >> liczbaElementow;

        //dynamiczna alokacja tablicy o zadanej wielkosci
        sort = new (nothrow) Film[liczbaElementow];
        
        //pobranie elementow tablicy z pliku
        fstream plik;
        plik.open("C:\\Users\\lukas\\source\\repos\\Project2\\Project2\\projekt2_dane.txt", ios::in);   //Otwarcie pliku

        if (plik.good() == false) {                    //Funkcja sprawdza czy poprawnie wczytano plik
            cout << "Plik nie istnieje" << endl;
            exit(0);
        }
        string linia;
        int numer = 0;
        srand(time(NULL));


        while (!plik.eof())           //Dopóki kolejna linia w pliku nie będzie pusta
        {
            getline(plik, linia, ';');
            sort[numer].id = atof(linia.c_str());

            cin.(plik, linia, ';');                //Pobieranie lini do znaku ;
            sort[numer].tytul = linia;

            getline(plik, linia);                    //Pobieranie lini od znaku ; do końca
            sort[numer].wynik = atof(linia.c_str());

            numer++;
        }

        plik.close();
                
        
        cout << "Podaj liczbe (od 0 do 1; 1 tworzy tablice posortowana malejaco) posortowania tablic: \n";
        double czescPosortowana;
        cin >> czescPosortowana;
        if(czescPosortowana == 1){
                Sorting::quicksort(sort, 0, liczbaElementow - 1);
                Sorting::odwracanie(sort, liczbaElementow);
            }
        }
        else if(czescPosortowana>0 || czescPosortowana<1){
            for(int i=0; i<liczbaTablic; i++)
                Sorting::quicksortCzesci(tablica[i], 0, liczbaElementow - 1, czescPosortowana);
        }
        int opcja;
        cout << "Wybierz sortowanie: \n"
                "1. quicksort\n"
                "2. mergesort\n"
                "3. introsort\n";
        cin >> opcja;
        if(opcja == 1) {
            start = clock();
            for(int i = 0; i < liczbaTablic; i++) {
                Sorting::quicksort(tablica[i], 0, liczbaElementow - 1);
            }
            stop = clock();
        }
        else if(opcja == 2) {
            start = clock();
            for(int i = 0; i < liczbaTablic; i++) {
                Sorting::mergesort(tablica[i], 0, liczbaElementow - 1);
            }
            stop = clock();
        }
        else if(opcja == 3) {
            start = clock();
            for(int i = 0; i < liczbaTablic; i++) {
                Sorting::introsort(tablica[i], liczbaElementow);
            }
            stop = clock();
        }

        bool sortowaniaDzialaja = true;
        for(int i = 0; i < liczbaTablic; i++) {
            if(!Sorting::posortowane(tablica[i], liczbaElementow))
                sortowaniaDzialaja = false;
        }

        if(!sortowaniaDzialaja) {
            cout << "Sortowanie nie powiodlo sie !!!!";
        }
        else {
            czas = (double)(stop-start) / CLOCKS_PER_SEC;
            cout<<"\nCzas sortowania: "<<czas<<" s"<<endl;

        }
        // zwolnienie tablic dynamicznych
        for(int i = 0; i < liczbaTablic; i++)
            delete [] tablica[i];
        delete [] tablica;

        cout << "Czy zakonczyc program? [t/n] ";
        cin >> koniec;
    }
    return 0;
}
