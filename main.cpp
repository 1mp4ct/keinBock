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

    const int AnzahlEinwohner = 400;
    int AnzahlParteien = 2;

    // Array einwohner mit 400 Elementen wird erstellt
    int einwohner[AnzahlEinwohner];

    // Den Einwohnern wird eine Partei zugeordnet
    Einwohner(einwohner, AnzahlEinwohner, AnzahlParteien);

    Ausgabe(einwohner);
    Sleep(300);

    int person1;
    int iCounter;
    int iNumber = 0;

    for(iCounter = 0 ; iCounter < AnzahlEinwohner; iCounter ++)
    {
        // Z�hlt die Einwohner die Partei 0 w�hlen
        if(einwohner[iCounter] == 0)
        {
            iNumber++;
        }
    }

    int lCount = 0;
    // Wiederhole solange, bis alle Einwohner die gleiche Partei w�hlen
    while(iNumber != 0 && iNumber != 400)
    {
        lCount = lCount + 1;

        // Zuf�llige Auswahl einer der 400 Personen
        person1 = (rand() % (AnzahlEinwohner));

        // Mit wem soll die Person sprechen?
        int person2;
        person2 = Nachbar(person1);

        int iConvince;

        // Entscheindung, ob der zweite W�hler �berzeugt wird oder nicht
        // Gibt mit gleicher W'keit die Werte 0 oder 1 aus
        iConvince = rand() % 2;

        // wenn iConvince = 1 dann wird der W�hler �berzeugt
        if(iConvince == 1)
        {
            einwohner[person2] = einwohner[person1];
        }

        if (lCount % 10000 == 0)
        {
            Ausgabe(einwohner);
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

