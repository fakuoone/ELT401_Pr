/*************************************************************************
	Dateiname:			Lab8_4.cpp
	Beschreibung: 		Befuellenm eines Arrays mit der Zahl 48 und ein werteres mit den Zahlen 1 bis 100
	Version:			1.0
	Aenderungsgrund: 	-
	Projekt:    		Promillerechner
	Datum:      		28.11.2019
	Bearbeiter:			
*************************************************************************/

/* Biblotheken einbinden */
#include <stdio.h>

int main(void) {
    int array1[100], array2[100];

    /* befuellen der Arrays */
    for (int i = 0; i < 99; i++)
    {
        array1[i] = 48; /* Jedes Feld eird mit 48 beschrieben */
        array2[i] = i +1; /* Da i als ersten wert 0 hat, muss immer eine 1 zu i addiert werden, dass die Zahlen 1 - 100 in die Felder geschrieben werden */
    }
}
    