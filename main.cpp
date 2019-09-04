#include <iostream>
#include <time.h>
#include<nachbar.cpp>
#include<ausgabe.cpp>
#include<einwohner.cpp>

#include <windows.h>

using namespace std;

int main()
{
    srand( (unsigned) time(NULL));

    const int columns = 20;
    const int rows = 20;
    const int AnzahlEinwohner = columns * rows;
    int AnzahlParteien = 2;

    // Array einwohner mit 400 Elementen wird erstellt
    int einwohner[AnzahlEinwohner];

    // Den Einwohnern wird eine Partei zugeordnet
    Einwohner(einwohner, AnzahlEinwohner, AnzahlParteien);

    Ausgabe(einwohner, columns, rows);
    Sleep(300);

    int person1;
    int iCounter;
    int iNumber = 0;

    for(iCounter = 0 ; iCounter < AnzahlEinwohner; iCounter ++)
    {
        // Zählt die Einwohner die Partei 0 wählen
        if(einwohner[iCounter] == 0)
        {
            iNumber++;
        }
    }

    int lCount = 0;
    // Wiederhole solange, bis alle Einwohner die gleiche Partei wählen
    while(iNumber != 0 && iNumber != 400)
    {
        lCount = lCount + 1;

        // Zufällige Auswahl einer der 400 Personen
        person1 = (rand() % (AnzahlEinwohner));

        // Mit wem soll die Person sprechen?
        int person2;
        person2 = Nachbar(person1);

        int iConvince;

        // Entscheindung, ob der zweite Wähler überzeugt wird oder nicht
        // Gibt mit gleicher W'keit die Werte 0 oder 1 aus
        iConvince = rand() % 2;

        // wenn iConvince = 1 dann wird der Wähler überzeugt
        if(iConvince == 1)
        {
            einwohner[person2] = einwohner[person1];
        }

        if (lCount % 10000 == 0)
        {
            Ausgabe(einwohner, columns, rows);
            cout << lCount << endl;
            Sleep(300);

            int iCounter;
            iNumber = 0;
            for(iCounter = 0 ; iCounter < 400; iCounter ++)
            {
                if(einwohner[iCounter] == 0)
                {
                    iNumber++;
                }
            }
        }

    }
}

