#include <cmath>

using namespace std;

#include "Sorting.h"

bool Sorting::posortowane(Film *tablica, int liczbaElementow) {
    for(int i = 0; i < liczbaElementow - 1; i++)
        if(tablica[i].wynik > tablica[i+1].wynik)
            return false;
    return true;
}

void Sorting::quicksort(Film *tablica, int lewy, int prawy) {
    int x = tablica[(lewy+prawy)/2].wynik;                      //wyznaczanie srodka
    int i,j,k;                                                  //przypisanie odpowiednich wartosci tablic po podzieleniu
    i=lewy;                                                     
    j=prawy;
    do{
        while(tablica[i].wynik<x) i++;
        while(tablica[j].wynik>x) j--;
        if(i<=j)
        {
            x = tablica[i].wynik;
            tablica[i].wynik = tablica[j].wynik;
            tablica[j].wynik = k;
            swap(tablica[i].tytul, tablica[j].tytul);
            i++;
            j--;
        }
    }
    while(i<=j);
    if(j>lewy) 
        quicksort(tablica,lewy, j);
    if(i<prawy) 
        quicksort(tablica, i, prawy);
}

void Sorting::mergesort(Film tablica[], int* tab1, string* pom, int l, int r)
{
    if(l<r)
    {
        int m = (l+r)/2;
        mergesort(tablica, tab1, pom, l, m);
        mergesort(tablica, tab1, pom, m + 1, r);
        merge(tablica, l, m, r);
    }
}

void Sorting::merge(Film tablica[], int l, int m, int r)
{
    int i=l;
    int j=m+1;
    int k=l;

    int ile = (r-1)+1;
    int temp[ile];

    while(i<=m && j<=r)
    {
        if(tablica[i].wynik <= tablica[j].wynik)
        {
            temp[k]=tablica[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=tablica[j];
            j++;
            k++;
        }
    }
    while(i<=m)
    {
        temp[k]=tablica[i];
        i++;
        k++;
    }
    while(j<=r)
    {
        temp[k]=tablica[j];
        j++;
        k++;
    }
    for(int s=l;s<=r;s++)
    {
        tablica[s]=temp[s];
    }
}

void Sorting::quicksortCzesci(Film *tablica, int lewy, int prawy, double czesc)
{
    quicksort(tablica, lewy, prawy * czesc);
}

int Sorting::Partition(Film *tablica, int lewy, int prawy) {
    int pivot = tablica[prawy].wynik;
    Film temp;
    int i = lewy;

    for (int j = lewy; j < prawy; ++j)
    {
        if (tablica[j].wynik <= pivot)
        {
            temp = tablica[j];
            tablica[j] = tablica[i];
            tablica[i] = temp;
            i++;
        }
    }

    tablica[prawy] = tablica[i];
    tablica[i].wynik = pivot;

    return i;
}

void Sorting::maxheapify(Film *tablica, int kopiec, int cos) {
    int lewy = (cos + 1) * 2 - 1;
    int prawy = (cos + 1) * 2;
    int wiekszy = 0;

    if (lewy < kopiec && tablica[lewy].wynik > tablica[cos].wynik)
        wiekszy = lewy;
    else
        wiekszy = cos;

    if (prawy < kopiec && tablica[prawy].wynik > tablica[wiekszy].wynik)
        wiekszy = prawy;

    if (wiekszy != cos)
    {
        Film temp = tablica[cos];
        tablica[cos] = tablica[wiekszy];
        tablica[wiekszy] = temp;

        maxheapify(tablica, kopiec, wiekszy);
    }
}

void Sorting::heapsort(Film *tablica, int liczbaElementow) {
    int kopiec = liczbaElementow;

    for (int p = (kopiec - 1) / 2; p >= 0; --p)
        maxheapify(tablica, kopiec, p);

    for (int i = liczbaElementow - 1; i > 0; --i)
    {
        Film temp = tablica[i];
        tablica[i] = tablica[0];
        tablica[0] = temp;

        --kopiec;
        maxheapify(tablica, kopiec, 0);
    }
}

void Sorting::insertionsort(Film *tablica, int liczbaElementow) {
    for (int i = 1; i < liczbaElementow; ++i)
    {
        int j = i;

        while ((j > 0))
        {
            if (tablica[j - 1].wynik > tablica[j].wynik)
            {
                tablica[j - 1].wynik ^= tablica[j].wynik;
                tablica[j].wynik ^= tablica[j - 1].wynik;
                tablica[j - 1].wynik ^= tablica[j].wynik;

                --j;
            }
            else
            {
                break;
            }
        }
    }
}

void Sorting::introsort(Film *tablica, int liczbaElementow) {
    int rozmiar = Partition(tablica, 0, liczbaElementow - 1);

    if (rozmiar < 16)
    {
        insertionsort(tablica, liczbaElementow);
    }
    else if (rozmiar >(2 * log(liczbaElementow)))
    {
        heapsort(tablica, liczbaElementow);
    }
    else
    {
        Sorting::quicksort(tablica, 0, liczbaElementow - 1);
    }
}

void Sorting::odwracanie(Film *tablica, int liczbaElementow)
{
    for (int i = 0; i < liczbaElementow / 2; i++)
    {
        Film tmp = tablica[i];
        tablica[i] = tablica[liczbaElementow - i - 1];
        tablica[liczbaElementow - i - 1] = tmp;
    }
}