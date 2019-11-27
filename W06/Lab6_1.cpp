/*
Projekt:    Promillerechner
Datum:      21.11.2019

*/

/* Einbinden der Bibliotheken */
#include <stdio.h>
#include <conio.h>
#define ENTER 10
#define ESC 27

float pilsner = 4.8;
float alk_dichte = 0.79;
int volumen_getraenk;
float koerpergewicht;

int kommentar(float promillewert) {
	if ((0 <= promillewert) && (promillewert <= 0.3)) {
	/* Ausgabe 0 bis 0,3 Promille */
	printf("Das geht noch");
	}
	else
	{
		if (promillewert <= 0.5)
		{
		/* Ausgabe 0,3 bis 0,5 Promille */
			printf("Achtung, es kann gefaehrlich werden");
		}
		else
		{
			if (promillewert <= 0.8)
			{
			/* Ausgabe 0,5 bis 0,8 Promille */
				printf("Das galt frueher");
			}
			else
			{
				if (promillewert > 0.8)
				{
				/* Ausgabe ab 0,8 Promille */
					printf("Kein Kommentar");
				}
				else
				{
				/* Ausgabe Fehlerabfang, wenn der Promillewert negativ ist */
					printf("Es wurde ein neagtiver Promillewert errechnet!\n");
					return 1;
				}
			}
		}
	}
	printf(".\n");
	return 0;
}

/* Funktion: Abfrage aller User Eingaben */
int eingabe(void) {
	/* Variable, ob das letzte Zeichen einer Eingabe ein ENTER war */
	char enter;
	/* Steuervariable, ob die Eingabe mit dem datentyp uebereinstimmt */
	int steuervariable;
	/* Erste Eingabe: Eingabe der Biermenge in ml */
	do {
		printf("Bitte die Biermenge angeben (ml): ");
		steuervariable = scanf_s("%d%c", &volumen_getraenk, &enter, 1);
		/* Fehlerabfang Falscheingabe */
		if ((steuervariable == 0) || (enter != ENTER)) {
			printf("Bitte eine korrekte Menge angeben\n");
			while (getchar() != '\n');
			steuervariable = 0;
		}
	} while (steuervariable == 0);
	/* Zweite Eingabe: Koerpergewicht in kg */
	do
	{
		printf("Bitte Ihr Gewicht eingeben: ");
		steuervariable = scanf_s("%f%c", &koerpergewicht, &enter, 1);
		/* Fehlerabfang Falscheingabe */
		if ((steuervariable == 0 || (enter != ENTER))) {
			printf("Bitte ein korrektes Gewicht angeben\n");
			while (getchar() != '\n');
			steuervariable = 0;
		}
	} while (steuervariable == 0);
	return 0;
}

/* Funktion für die die Menge (Gramm) an Alkohol in einem Getraenk */
float menge_alk(int milliliter) {
	return ((float)milliliter * pilsner/100 * alk_dichte);
}

/* Funktion fuer die Errechnung des Promillegehaltes */
float promille(float gewicht, float alkoholmenge) {
	return ((float)(alkoholmenge / (float(0.65)*gewicht)));
}

int main(void) {
	int prog_ende = 0;
	do {
		eingabe();
		kommentar(promille(koerpergewicht, menge_alk(volumen_getraenk)));
		/* Exit Bedingung fuer die die Schleife */
		printf("Programm beenden mit 'ESC', zum Fortsetzen beliebige andere Taste\n");
		prog_ende = _getch();
	} while (prog_ende != ESC);
	return 0;
}