/*************************************************************************
	Dateiname:			Lab5_3_2.cpp
	Beschreibung: 		Mathepruefung
	Version:			1.0
	Aenderungsgrund: 	-
	Projekt:    		Mathepruefung 
	Datum:      		28.11.2019
	Bearbeiter:			
*************************************************************************/

/* Einbinden Bobliotheken */
#include <stdio.h>

/* Definition von Makros */
#define ENTER 10

/* Definition globaler Variablen */
int user_ergebnisse[4];

/* Funktion zur Berechnung der Summe */
int summe(int x, int y){
    return (x + y);
}

/* Funktion zur Berechnung der Subtraktion */
int subtraktion(int x, int y){
    return (x - y);
}

/* Funktion zur Berechnung der Multiplikation */
int multiplikation(int x, int y){
    return (x * y);
}

/* Funktion zur Berechnung der Division */
int division(int x, int y) {
    return (x / y);
}

/* Funktion zur Berechnung des Modulus */
int modulus(int x, int y) {
    return (x % y);
}

int abfrage_zahl1(void) {
    /* Steuervariablen fuer Eingabefehler */
    int scanf_return;
    char enter;
    int operand;
    do {
        printf("Bitte eine Zahl zwischen 1 und 100 eingeben: ");
        scanf_return = scanf_s("%d%c", &operand, &enter, 1);
        if ((scanf_return == 0) || (enter != ENTER)) {
            printf("Sie haben keine gueltige Zahl eingegeben! Bitte geben Sie eine richtige Zahl ein.\n");
        } else if (enter != ENTER) {
                while (getchar() != ENTER);
                scanf_return = 0;
        } else if ((operand < 1) || (operand > 100)) {
            printf("Die eingegebene Zahl ist ausserhalb des vorgebenen Bereichs!");
            scanf_return = 0;
        }
    } while(scanf_return == 0);
    return operand;
}

int abfrage_zahl2(void) {
    /* Steuervariablen fuer Eingabefehler */
    int scanf_return;
    char enter;
    int operand;
    do {
        printf("Bitte eine weitere Zahl zwischen 1 und 100 eingeben: ");
        scanf_return = scanf_s("%d%c", &operand, &enter, 1);
        if ((scanf_return == 0) || (enter != ENTER)) {
            printf("Sie haben keine gueltige Zahl eingegeben! Bitte geben Sie eine richtige Zahl ein.\n");
        } else if (enter != ENTER) {
                while (getchar() != ENTER);
                scanf_return = 0;
        } else if ((operand < 1) || (operand > 100)) {
            printf("Die eingegebene Zahl ist ausserhalb des vorgebenen Bereichs!");
            scanf_return = 0;
        }
    } while(scanf_return == 0);
    return operand;
}

int abfrage_ergebnisse(void) {
    /* Steuervariablen fuer Eingabefehler */
    int scanf_return;
    char enter;
    for (size_t i = 0; i < 5; i++) {
        do {
            switch (i) {
            case 0:
                printf("Bitte die erwartete Summe eingeben: \t");
                break;
            case 1:
                printf("Bitte die erwartete Differenz eingeben:\t");
                break;
            case 2:
                printf("Bitte das erwartetes Produkt eingeben: \t");
                break;
            case 3:
                printf("Bitte den erwarteten Quotienten eingeben: ");
                break;
            case 4:
                printf("Bitte den erwarteten Rest eingeben: \t\t");
                break;
            }
            scanf_return = scanf_s("%d%c", &user_ergebnisse[i], &enter, 1);
            if ((scanf_return == 0)  || (enter != ENTER))  {
                printf("Sie haben keine gueltige Zahl eingegeben! Bitte geben Sie eine richtige Zahl ein.\n");
            }
            else if (enter != ENTER) {
                while (getchar() != ENTER);
                scanf_return = 0;
            }
        } while (scanf_return == 0);
    }
    return 0;
}

