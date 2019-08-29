#include<iostream>

using namespace std;

void Einwohner(int einwohner[], int AnzahlEinwohner, int AnzahlParteien)
    {
    int i;
    bool bFall;
    cout << "0 - Trennung Parteien: oben / unten" << endl;
    cout << "1 - Zuf\x84llige Verteilung der Parteien" << endl;
    cin >> bFall;
    if(bFall == 1)
    {
        for(i = 0; i < AnzahlEinwohner; i++)
        {
            einwohner[i] = rand() % AnzahlParteien;
        }

      }
    else{

        for (i = 0; i < (AnzahlEinwohner/AnzahlParteien); i++) {
            einwohner[i]=0;
        };


        for (i = (AnzahlEinwohner/AnzahlParteien); i < (AnzahlEinwohner); i++) {
            einwohner[i]=1;
        };
    }
    }
