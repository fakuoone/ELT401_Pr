/*************************************************************************
	Dateiname:			Lab8_6.cpp
	Beschreibung: 		Transponieren, vertauschen der Zeilen und Spalten, einer Matrix
	Version:			1.3
	Aenderungsgrund: 	-
	Projekt:    		Matrix transponieren
	Datum:      		28.11.2019
	Bearbeiter:			
*************************************************************************/

/* Einbinden der Bibliotheken */
#include <stdio.h>

/* Definition von Makros */
#define DIMENSION 5

int main(void){
	/* Initialisierung der Arrays */
    int matrix1[DIMENSION][DIMENSION], matrix2[DIMENSION][DIMENSION];

	/* Variable fuer den Uebertrag */
	int uebertrag = 0;

	/* Matrix mit fortlaufenden Zahlen fuellen */
	/** Schleife fure die Zeilen */
    for (int i = 0; i < DIMENSION; i++)
    {
		/* Schleife fuer die Spalten */
        for (int j = 0; j < DIMENSION; j++)
		{
			matrix1[i][j] = j + uebertrag + 1;
		}
		uebertrag += DIMENSION;
    }
	
	/* Matrix transponieren */
	/** Schleife fur die Zeilen */
	for (int i = 0; i < DIMENSION; i++)
	{
		/** Schleife fuer die Spalten **/
		for (int j = 0; j < DIMENSION; j++)
		{
			matrix2[j][i] = matrix1[i][j];
		}
	}

	/* Anzeige Matrix 1 */
	for (int i = 0; i < DIMENSION; i++)
	{
		for (int j = 0; j < DIMENSION; j++)
		{
			printf("%2d ",matrix1[i][j]);
		}
		printf("\n");
	}
	/* Zeilenumbruch fuer eine bessere Lesbarkeit in der Ausgabe */
	printf("\n");
	
	/* Anzeige Matrix 2 */
	for (int i = 0; i < DIMENSION; i++)
	{
		for (int j = 0; j < DIMENSION; j++)
		{
			printf("%2d ",matrix2[i][j]);
		}
		printf("\n");
	}
	return 0;
}