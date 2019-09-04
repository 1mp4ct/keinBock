#include<iostream>
#include <windows.h>

using namespace std;

void Ausgabe(int einwohner[], int columns, int rows)
{
    int i;
    int j;
    // Ausgabe der Parteien als Block

    system("cls");

    //columns
    for (j = 0; j < columns; j ++)
    {
        //rows
        for (i = 0 + j * rows; i < rows + j * rows; i++) {

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
