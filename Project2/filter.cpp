#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>

using namespace std;
using namespace std::

int main() {
    cout << "Wpisz wielkosc danych do pozyskania : " << endl;
    int ROZMIAR;
    cin >> ROZMIAR;

    string* tytul = new string[ROZMIAR];

    float* wynik = new float[ROZMIAR];

    float* id = new float[ROZMIAR];

    clock_t start, stop;
    double czas;

    fstream file;
    file.open("projekt2_dane.txt", ios::in);            //Otwarcie pliku

    if (file.good() == false) {                         //Funkcja sprawdza czy poprawnie wczytano plik
        cout << "Plik nie istnieje" << endl;
        exit(0);
    }
    string linia;
    int numer = 0;
    srand(time(NULL));

    start = clock();
    while (!file.eof())                                 //zczytuje aż do wersu w pliku ktory bedzie pusty
    {
        fstream::getline(file, linia, ';');
        id[numer] = atof(linia.c_str());

        file.getline(file, linia, ';');                 //Pobieranie lini do znaku ;
        tytul[numer] = linia;

        file.getline(file, linia);                      //Pobieranie lini od znaku ; do końca
        wynik[numer] = atof(linia.c_str());
        if (wynik[numer] == '\0') {
            numer--;

        }
        numer++;
    }

    file.close();


    fstream file2;
    file2.open("C:\\Users\\lukas\\source\\repos\\Project2\\Project2\\projekt2_dane.txt", ios::out);

    cout << "Ilość tytułów :  " << numer << endl;       //Wyświetlanie zawartosci tablic

    for (int i = 0; i < numer; i++) {
        file2 << id[i] << " ; " << tytul[i] << " ; " << wynik[i] << endl;
    }
    file2.close();
    stop = clock();
    czas = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << "czas sortowania : " << czas << "s" << endl;

    return 0;