/*************************************************************************
	Dateiname:			Lab7_3.cpp
	Beschreibung: 		4 Grundrechenarten fuer 2 Operanden mit SWITCH-CASE
	Version:			2.0
	Aenderungsgrund: 	Entfernen von Globalenvariablen
	Projekt:    		4 Grundrechenarten mit switch-case
	Datum:      		28.11.2019
	Bearbeiter:			
*************************************************************************/

#include <stdio.h>

#define ENTER 10

/* Funktionsdeklaration (Eingabe 1. Operand) */
int eingabe_operand1(void){
    char enter;
    int scanf_return;
    int operand1;
    do {
            printf("Geben Sie eine Zahl ein (1-100): ");
            scanf_return = scanf_s("%d%c", &operand1, &enter, 1);
            if ((scanf_return == 0) || (enter != ENTER)) {
                printf("Fehlerhafte Eingabe!");
                if (enter != ENTER) {
                    while (getchar() != '\n');
                }
                scanf_return = 0;
            }
    } while (scanf_return == 0);
    return operand1;
}

/* Funktionsdeklaration (Eingabe 2. Operand) */
int eingabe_operand2(void){
    char enter;
    int scanf_return;
    int operand2;
    do {
            printf("Geben Sie eine weitere Zahl ein (1-100): ");
            scanf_return = scanf_s("%d%c", &operand2, &enter, 1);    
            if ((scanf_return == 0) || (enter != ENTER)) {
                printf("Fehlerhafte Eingabe!");
                if (enter != ENTER) {
                    while (getchar() != '\n');
                }
                scanf_return = 0;
            }
    } while (scanf_return == 0);
    return operand2;
}

/* Funktionsdeklaration (Funktion: summe) */
int summe(int x, int y);

/* Funktionsdeklaration (Funktion: differenz) */
int differenz(int x, int y);

/* Funktionsdeklaration (Funktion: produkt) */
int produkt(int x, int y);

/* Funktionsdeklaration (Funktion: quotient) */
float quotient(int x, int y);


/* Definition der Funktion "summe" */
int summe(int x, int y) {
    return (x + y);
}

/* Definition der Funktion "differenz" */
int differenz(int x, int y) {
    return (x - y);
}

/* Definition der Funktion "produkt" */
int produkt(int x, int y) {
    return (x * y);
}

/* Definition der Funktion "quotient" */
float quotient(int x, int y) {    
    if (y == 0) {        
        printf("Division durch null nicht moeglich\n");        
        return 0;    
    } else {    
        return ((float)x / (float)y);    
    }
}

/* Rechenart-Abfrage mit Aufruf der Rechenoperationen und der Ausgabe */
int auswahl_rechenart_mit_ausgabe(int operand1, int operand2) {
    /* Deklartion Steuervariablen */
    int fehler_menue;
    int rechenart;
    /* Schleife fur Fehlerabfang */
    do {
        printf (" - Addition \t= 1\n - Division \t= 2\n - Produkt \t= 3\n - Quotient \t= 4\nWie wollen Sie die Zahlen zusammen rechnen? ");    
        scanf_s("%d",&rechenart);    
        /* Eingabe Menue pruefen */   
        switch (rechenart)
        {
        case 1:
            /* Summe berechnen und anzeigen */            
            printf("Summe:\t\t%d + %d = %d\n", operand1, operand2, summe(operand1, operand2));
            break;
        case 2:           
            /* Differenz berechnen und anzeigen */            
            printf("Differenz:\t%d - %d = %d\n", operand1, operand2, differenz(operand1, operand2));
            break;
        case 3:
            /* Produkt berechnen und anzeigen */            
            printf("Produkt:\t%d * %d = %d\n", operand1, operand2, produkt(operand1, operand2));
            break;
        case 4:
            /* Quotient berechnen und anzeigen */            
            printf("Quotient:\t%d / %d = %.4f\n", operand1, operand2, quotient(operand1, operand2));
            break;
        default:
            /* Fall, wenn kein gegebener Menuepunkt eingegeben wurde */
            printf("Bitte eine Zahl zwischen 1 und 4 eingeben!\n");
            fehler_menue = 1;
            break;
        }
    } while (fehler_menue = 1);
    return 0;
}

/* Hauptprogramm */
int main(void){
    auswahl_rechenart_mit_ausgabe(eingabe_operand1(), eingabe_operand2());
    return 0;
}