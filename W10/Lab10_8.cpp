/*************************************************************************
	Dateiname:			Lab10_8.cpp
	Beschreibung: 		Verteilung der Buchstaben im String. 
	Version:			1.0
	Aenderungsgrund: 	-
	Projekt:    		Woche 10 Aufgabe 3.1
	Datum:      		04.12.2019
	Bearbeiter:			
*************************************************************************/

/* Einbinden der Bibliotheken */
#include <stdio.h>  /* fuer scanf_s und printf */
#include <string.h> /* fuer String funktionen (strcpm, fgets) */ 
#include <stdlib.h>

int main(void) 
{
    /* Initialisieren der Variablen */
    char eingabe[101];
    char vergleichs_buchstabe1[2] = {'\0','\0'};
    char vergleichs_buchstabe2[2] = {'\0','\0'};
    char alphabet[] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
    int gleiche_buchstaben[52];

    /* Anzahl aller Buchsteben auf 0 setzen */
    for (int i = 0; i < 52; i++)
    {
        gleiche_buchstaben[i] = 0;
    }
    

    /* Eingabe der Zeichenkette */
    printf("Bitte mit der Tastatur bis zu 100 Zeichen eingeben: ");
    fgets(eingabe,100, stdin);

    /* Beginn Auswertung */
    /* Durchlaufen des Alphabeths */
    for (int j = 0; j < strlen(alphabet); j++)
    {
        /* aktuellen Buchstaben in Vergleichsvariable schreiben */
        vergleichs_buchstabe1[0] = alphabet[j];

        /* aktuellen Buchstaben zaehlen */
        for (int i = 0; i< strlen(eingabe);i++)
        {
            /* Seperieren der einzelnen Buchstaben um einen Vergleich durch zu fuehren */
            vergleichs_buchstabe2[0] = eingabe[i];
            /* Vergleich der beiden Buchstaben */
            if (strcmp(vergleichs_buchstabe1, vergleichs_buchstabe2) == 0)
            {
                /* wird bei gleichen Buchstaben erhoeht */
                gleiche_buchstaben[j]++;
            }
        }
    }

    /* Ausgabe der Buchstaben aus der Eingabe mit der Anzahl */ 
    printf("Folgende Buchstaben sind in der Eingabe enthalten:\n");
    printf("+-----------+-----------+\n");
    printf("| Buchstabe |   Anzahl  |\n");
    printf("+-----------+-----------+\n");
    for (int i = 0; i < strlen(alphabet); i++)
    {
        if (gleiche_buchstaben[i] != 0)
        {
            printf("|     %c     |    %2d     |\n",alphabet[i],gleiche_buchstaben[i]);
        }
    }
    printf("+-----------+-----------+\n");
    return 0;    
}