

int Nachbar(int person1, int columns, int rows)
{
    int p1;
    int person2;

    // Eine Position über, unter, rechts oder links vom ausgewählten Wähler wird ausgeglichen

    p1 = rand() % 4;

    // Festlegung der Person mit der gesprochen werden soll:
    // Erst Personen am Rand beachten
    // Wenn Person ganz links und Person nach links -> Sprung nach ganz rechts (Prüfen, ob Division durch 20 ohne Rest)


    // Wenn Person ganz links und Person nach links -> Sprung nach ganz rechts (Prüfen, ob Division durch 20 ohne Rest)

    if (person1 % columns == 0 && p1 == 3)
    {
          person2 = person1 + (columns - 1);
    }
    // Wenn Person ganz rechts -> Sprung nach ganz links (Prüfen, ob Division von Wert -19 durch 20 ohne Rest)
    else if ((person1- (columns + 1)) % columns == 0 && p1 == 2)
        {
          person2 = person1 - (columns + 1);
        }

    // Wenn Person ganz oben und Nachbar oben -> Sprung in letzte Zeile
    else if (person1 < columns && p1 == 0)
        {
          person2 = columns * rows - (columns - person1);
        }
    // Wenn ganz untern und Nachbar unten -> Sprung ans andere Ende des Arrays
    else if (person1 >= (rows - 1) * columns && p1 == 1)
        {
          person2 = person1 - (rows - 1) * columns;
        }

    // sonst: Person über/ unter oder direkt neben der ausgewählten Person
    else
        {
        switch (p1){
          // Fall 0: Person über person1
        case 0:
          person2 = person1 - columns;
          break;

        // Fall 1: Person unter person1
        case 1:
          person2 = person1 + columns;
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
