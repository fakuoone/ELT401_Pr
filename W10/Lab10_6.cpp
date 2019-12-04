/*************************************************************************
	Dateiname:			Lab10_6.cpp
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
    char vergleichs_buchstabe[2];

    /* Eingabe der Zeichenkette */
    printf("Bitte mit der Tastatur bis zu 100 Zeichen eingeben:\n");
    fgets(eingabe,100, stdin);

    /* Beginn Auswertung */
    for (int i = 0; i< strlen(eingabe);i++){
        /* Seperieren der einzelnen Buchstaben um einen Vergleich durch zu fuehren */
        vergleichs_buchstabe[0] = eingabe[i];
        /* Vergleich der beiden Buchstaben */
        if (strcmp(vergleichs_buchstabe,"a") == 0){
            /* wird bei gleichen Buchstaben 'a' erhoeht */
            gleiche_buchstaben++;
        }
    }
    printf("Der Buchstabe \'a\' ist %d mal enthalten\n", gleiche_buchstaben);
    return 0;    
}