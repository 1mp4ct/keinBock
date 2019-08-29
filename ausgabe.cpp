#include<iostream>
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
