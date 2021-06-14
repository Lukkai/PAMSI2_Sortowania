#ifndef TESTS_SORTING_H
#define TESTS_SORTING_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>

struct Film
{
    string tytul;
    int wynik;
    float id;
};

class Sorting {
public:
    bool static posortowane(Film *tablica, int liczbaElementow);
    void static quicksort(Film *tablica, int lewy, int prawy);
    void static mergesort(Film tablica[], int *tab1, string *pom, int l, int r);
    void static quicksortCzesci(Film *tablica, int lewy, int prawy, double czesc);
    void static introsort(Film *tablica, int liczbaElementow);
    void static odwracanie(Film *tablica, int liczbaElementow);
private:
    static int Partition(Film *tablica, int lewy, int prawy);
    void static maxheapify(Film *tablica, int kopiec, int cos);
    void static heapsort(Film *tablica, int liczbaElementow);
    void static insertionsort(Film *tablica, int liczbaElementow);
    void static merge(Film tablica[], int l, int m, int r);
};

#endif //TESTS_SORTING_H
