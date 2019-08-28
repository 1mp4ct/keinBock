#include <iostream>
#include <time.h>

#include <windows.h>

using namespace std;


void Ausgabe(int einwohner[])
{
    int i;
    int j;
    // Ausgabe der Parteien als Block

    system("cls");

    for (j = 0; j < 20; j ++)
    {
        for (i = 0 + j * 20; i < 20 + j * 20; i++) {

            if(einwohner[i] == 0)
            {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
            }
            else
            {
                HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
            }

            cout << einwohner[i] << " ";

            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hStdOut, FOREGROUND_RED |FOREGROUND_BLUE |FOREGROUND_GREEN);
        }
        cout << endl;
    }
    cout << endl;
}

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

int Nachbar(int person1)
{
    int p1;
    int person2;

    // Eine Position über, unter, rechts oder links vom ausgewählten Wähler wird ausgeglichen

    p1 = rand() % 4;

    // Festlegung der Person mit der gesprochen werden soll:
    // Erst Personen am Rand beachten
    // Wenn Person ganz links und Person nach links -> Sprung nach ganz rechts (Prüfen, ob Division durch 20 ohne Rest)


    // Wenn Person ganz links und Person nach links -> Sprung nach ganz rechts (Prüfen, ob Division durch 20 ohne Rest)

    if (person1 % 20 == 0 && p1 == 3)
    {
          person2 = person1 + 19;
    }
    // Wenn Person ganz rechts -> Sprung nach ganz links (Prüfen, ob Division von Wert -19 durch 20 ohne Rest)
    else if ((person1-19) % 20 == 0 && p1 == 2)
        {
          person2 = person1 - 19;
        }

    // Wenn Person ganz oben und Nachbar oben -> Sprung in letzte Zeile
    else if (person1 < 20 && p1 == 0)
        {
          person2 = 400 - (20 - person1);
        }
    // Wenn ganz untern und Nachbar unten -> Sprung ans andere Ende des Arrays
    else if (person1 > 379 && p1 == 1)
        {
          person2 = person1 - 380;
        }

    // sonst: Person über/ unter oder direkt neben der ausgewählten Person
    else
        {
        switch (p1){
          // Fall 0: Person über person1
        case 0:
          person2 = person1 - 20;
          break;

        // Fall 1: Person unter person1
        case 1:
          person2 = person1 + 20;
          break;

         // Fall 2: Person rechts von person1
         case 2:
            person2 = person1 + 1;
            break;

        // Fall 3: Person links von person1
        case 3:
              person2 = person1 - 1;
              break;
        }
      }
        return person2;
//       cout << person2;


}

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

