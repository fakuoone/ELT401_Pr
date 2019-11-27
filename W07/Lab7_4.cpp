/*************************************************************************
	Dateiname:			Lab7_4.cpp
	Beschreibung: 		Ausgabe einer Zahl, die vorher eingegeben wurde,
                        als Text
	Version:			1.0
	Aenderungsgrund: 	-
	Projekt:    		Textausgabe Zahl 0..9 mit switch-case
	Datum:      		28.11.2019
	Bearbeiter:			
*************************************************************************/

/* Bibliotheken einbinden */
#include <stdio.h>
#define ENTER 10

/* Deklaration Variablen */
int zahl;
char enter;
int scanf_return;

/* Zahl-Eingabe als Integer */
int eingabe(void) {
    do {
        printf("Bitte eine Zahl von 1 bis 9 eingeben: ");
        scanf_return = scanf_s("%i%c", &zahl, &enter, 1);
        if ((scanf_return == 0) || (zahl > 9) || (zahl < 1) || (enter != ENTER)) {
            printf("Falscheingabe! ");
            if (enter != ENTER) {
                while (getchar() == '\n');
            }
            scanf_return = 0;
        }
    } while (scanf_return == 0);
}

/* Textausgabe: Zahl als Text */
int ausgabe(void) {
    switch (zahl)
    {
        case 1:
            printf("eins\n");
            break;
        case 2:
            printf("zwei\n");
            break;
        case 3:
            printf("drei\n");
            break;
        case 4:
            printf("vier\n");
            break;
        case 5:
            printf("fuenf\n");
            break;
        case 6:
            printf("sechs\n");
            break;
        case 7:
            printf("sieben\n");
            break;
        case 8:
            printf("acht\n");
            break;
        case 9:
            printf("neun\n");
            break;    
        default:
            printf("Ein gravierenter Fehler ist aufgetreten, der Fehlerabfang der Eingabe hat nicht funktioniert.\n");
            break;
    }
}

/* Hauptprogamm */
int main(void) {
    eingabe();
    ausgabe();
    return 0;
}
