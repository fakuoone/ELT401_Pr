/*************************************************************************
	Dateiname:			Lab8_5.cpp
	Beschreibung: 		Ausgabe einer 9x9 Matrix mit dem kleinen "Ein-Mal-Eins"
	Version:			1.1
	Aenderungsgrund: 	-
	Projekt:    		"Eim-Mal-Eins"-Matrix"
	Datum:      		28.11.2019
	Bearbeiter:			
*************************************************************************/

/* Einbinden der Bibliotheken */
#include <stdio.h>

/* Definition von Makros */
#define NIEDRIGSTER_ZAHL 1
#define HOECHSTE_ZAHL 9

int main(void){
    for (int i = NIEDRIGSTER_ZAHL; i <= HOECHSTE_ZAHL; i++)
    {
        for (int j = NIEDRIGSTER_ZAHL; j <= HOECHSTE_ZAHL; j++)
        {
            printf("%dx%d=%2d  ",i,j,(i*j));
        }
    printf("\n");
    }
    return 0;
}