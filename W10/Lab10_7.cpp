/*************************************************************************
	Dateiname:			Lab10_7.cpp
	Beschreibung: 		Wie oft kommt der Buchstabe 'a' in einem String vor. 
	Version:			1.0
	Aenderungsgrund: 	-
	Projekt:    		Woche 10 Aufgabe 3.1
	Datum:      		02.12.2019
	Bearbeiter:			
*************************************************************************/

/* Einbinden der Bibliotheken */
#include <stdio.h> /* fuer scanf_s und printf */
#include <string.h> /* fuer String funktionen (strcpm, fgets) */ 
#include <stdlib.h>

int main(void) {
    /* Initialisieren der Variablen */
    int gleiche_buchstaben = 0;
    char eingabe[101];
    char vergleichs_buchstabe1[2];
    char vergleichs_buchstabe2[2];

    /* Eingabe der Zeichenkette */
    printf("Bitte mit der Tastatur bis zu 100 Zeichen eingeben: ");
    fgets(eingabe,100, stdin);
    /* Eingabe des zuvergleichenden Buchstaben */
    printf("Bitte ein zu vergleicchendes Zeichen eingeben: ");
    scanf("%c", &vergleichs_buchstabe1[0]);
    /* Setzen des letzten Zeichens des zuvergleichenden Buchstaben auf "\0" */
    vergleichs_buchstabe1[1] = '\0';

    /* Beginn Auswertung */
    for (int i = 0; i< strlen(eingabe);i++){
        /* Seperieren der einzelnen Buchstaben um einen Vergleich durch zu fuehren */
        vergleichs_buchstabe2[0] = eingabe[i];
        /* Vergleich der beiden Buchstaben */
        if (strcmp(vergleichs_buchstabe1, vergleichs_buchstabe2) == 0){
            /* wird bei gleichen Buchstaben erhoeht */
            gleiche_buchstaben++;
        }
    }
    /* Ausgabe der Auswertung */
    printf("Der Buchstabe \'%c\' ist %d mal in der Zeichenkette enthalten.\n", vergleichs_buchstabe1[0], gleiche_buchstaben);
    return 0;    
}