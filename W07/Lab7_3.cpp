/*************************************************************************
	Dateiname:			Lab7_3.cpp
	Beschreibung: 		4 Grundrechenarten fuer 2 Operanden mit SWITCH-CASE
	Version:			1.0
	Aenderungsgrund: 	-
	Projekt:    		4 Grundrechenarten mit switch-case
	Datum:      		28.11.2019
	Bearbeiter:			
*************************************************************************/

#include <stdio.h>

#define ENTER 10

/* Globale Variablen*/
int operand1, operand2, ergebnis, menue_eingabe;
float quotient_ergebnis;

/* Fuktionsdeklaration (Funktion: summe) */
int summe(int x, int y);

/* Fuktionsdeklaration (Funktion: differenz) */
int differenz(int x, int y);

/* Fuktionsdeklaration (Funktion: produkt) */
int produkt(int x, int y);

/* Fuktionsdeklaration (Funktion: quotient) */
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

/* Hauptprogramm */
int main(void){
    char enter;
    int fehler_menue = 0;
    int scanf_return = 0;
    
    /* erste Zahl eingeben */
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

    /* zweite Zahl eingeben */
    scanf_return = 0;   
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

    /* Menueabfrage */ 
    do {
        printf (" - Addition \t= 1\n - Division \t= 2\n - Produkt \t= 3\n - Quotient \t= 4\nWie wollen Sie die Zahlen zusammen rechnen? ");    
        scanf_s("%d",&menue_eingabe);    
        /* Eingabe Menue pruefen */   
        switch (menue_eingabe)
        {
        case 1:
            /* Summe berechnen und anzeigen */            
            ergebnis = summe(operand1, operand2);
            printf("Summe:\t\t%d + %d = %d\n", operand1, operand2, ergebnis);
            break;
        case 2:
            ergebnis = differenz(operand1, operand2);            
            /* Differenz berechnen und anzeigen */            
            printf("Differenz:\t%d - %d = %d\n", operand1, operand2, ergebnis);
            break;
        case 3:
            /* Produkt berechnen und anzeigen */            
            ergebnis = produkt(operand1, operand2);            
            printf("Produkt:\t%d * %d = %d\n", operand1, operand2, ergebnis);
            break;
        case 4:
            /* Quotient berechnen und anzeigen */            
            quotient_ergebnis = quotient(operand1, operand2);            
            printf("Quotient:\t%d / %d = %.4f\n", operand1, operand2, quotient_ergebnis);
            break;
        default:
            /* Fall, wenn kein gegebener Menuepunkt eingegeben wurde */
            printf("Bitte eine Zahl zwischen 1 und 4 eingeben!\n");
            fehler_menue = 1;
            break;
        }
    } while (fehler_menue = 1);
}