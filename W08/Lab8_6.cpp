/*************************************************************************
Dateiname:			Lab8_6.cpp
Beschreibung : Transponieren, vertauschen der Zeilen und Spalten, einer Matrix
Version : 1.3
Aenderungsgrund : -
Projekt : Matrix transponieren
Datum : 28.11.2019
Bearbeiter :
************************************************************************* /

	/* Einbinden der Bibliotheken */
#include <stdio.h>

	/* Definition von Makros */
#define DIMENSION 5

	int main(void) {
	/* Initialisierung der Arrays */
	int matrix1[DIMENSION][DIMENSION], matrix2[DIMENSION][DIMENSION];

	/* Variable fuer den Uebertrag */
	int uebertrag = 0;

	/* Zaehlvariablen */
	int zeile, spalte;

	/* Matrix mit fortlaufenden Zahlen fuellen */
	/** Schleife fure die Zeilen */
	for (zeile = 0; zeile < DIMENSION; zeile++)
	{
		/* Schleife fuer die Spalten */
		for (spalte = 0; spalte < DIMENSION; spalte++)
		{
			matrix1[zeile][spalte] = spalte + uebertrag + 1;
		}
		uebertrag += DIMENSION;
	}

	/* Matrix transponieren */
	/** Schleife fur die Zeilen */
	for (zeile = 0; zeile < DIMENSION; zeile++)
	{
		/** Schleife fuer die Spalten **/
		for (spalte = 0; spalte < DIMENSION; spalte++)
		{
			matrix2[spalte][zeile] = matrix1[zeile][spalte];
		}
	}

	/* Anzeige Matrix 1 */
	printf("\nMatrix 1:\n");
	for (zeile = 0; zeile < DIMENSION; zeile++)
	{
		for (spalte = 0; spalte < DIMENSION; spalte++)
		{
			printf("%4d ", matrix1[zeile][spalte]);
		}
		printf("\n");
	}
	/* Zeilenumbruch fuer eine bessere Lesbarkeit in der Ausgabe */
	printf("\n");

	/* Anzeige Matrix 2 */
	printf("\nMatrix 2:\n");
	for (zeile = 0; zeile < DIMENSION; zeile++)
	{
		for (spalte = 0; spalte < DIMENSION; spalte++)
		{
			printf("%4d ", matrix2[zeile][spalte]);
		}
		printf("\n");
	}

	/* "In Place" transponieren */
	printf("\nMatrix 1 \"In Place\" transponiert:\n");
	for (zeile = 0; zeile < DIMENSION; zeile++)
	{
		for (spalte = 0; spalte  < DIMENSION; spalte++)
		{
			printf("%4d ", matrix1[spalte][zeile]);
		}
		printf("\n");
	}

	return 0;
}
