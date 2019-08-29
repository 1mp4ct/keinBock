

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
