/*************************************************************************
Dateiname:			Lab7_1.cpp
Beschreibung: 		Berechnung des Blutalkoholwerts auf Basis
des Koerpergewichtes und der Biermenge
Version:			2.0
Aenderungsgrund: 	-
Projekt:    		Promillerechner
Datum:      		28.11.2019
Bearbeiter:
*************************************************************************/

/* Einbinden der Bibliotheken */
#include <stdio.h>
#include <conio.h>

/* Definition von Makros */
#define ENTER 10
#define ESC 27
#define PILSNER 4.8f
#define ALKOHOLDICHTE 0.79f
#define KONSTANTE_MAENNLICH 0.65f

/* Funktion um einen Kommentar abhaengig vom Alkoholwert aus zu geben */
int kommentar(float promillewert) {
	if ((0 <= promillewert) && (promillewert <= 0.3)) {
		/* Ausgabe 0 bis 0,3 Promille */
		printf("Das geht noch");
	}
	else if (promillewert <= 0.5)
	{
		/* Ausgabe 0,3 bis 0,5 Promille */
		printf("Achtung, es kann gefaehrlich werden");
	}
	else if (promillewert <= 0.8)
	{
		/* Ausgabe 0,5 bis 0,8 Promille */
		printf("Das galt frueher");
	}
	else if (promillewert > 0.8)
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
	printf(".\n");
	return 0;
}

/* Erste Eingabe: Eingabe des Volumens der verzehrten Getränke */
int eingabe_volumen(void) {
	/* Ausgabevariable */
	int volumen_getraenk; 
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
		else
		{
			if (volumen_getraenk < 0)
			{
				printf("Man kann keine negativen Bieren trinken. \nBitte ein plausibles Volumen angeben");
			}
		}
	} while (steuervariable == 0);
	return volumen_getraenk;
}

/* Zweite Eingabe: Koerpergewicht in kg */
float eingabe_gewicht(void) {
	/* Ausgabevariable */
	float koerpergewicht;
	/* Variable, ob das letzte Zeichen einer Eingabe ein ENTER war */
	char enter;
	/* Steuervariable, ob die Eingabe mit dem datentyp uebereinstimmt */
	int steuervariable;
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
		else
		{
			if (koerpergewicht <= 0)
			{
				printf("Bitte ein  plausibles Gewicht angeben!");
				steuervariable = 0;
			}
		}
	} while (steuervariable == 0);
	return (float)koerpergewicht;
}

/* Funktion für die die Menge (Gramm) an Alkohol in einem Getraenk */
float menge_alk(int milliliter) {
	return ((float)milliliter * PILSNER / 100 * ALKOHOLDICHTE);
}

/* Funktion fuer die Errechnung des Promillegehaltes */
float promille(float gewicht, float alkoholmenge) {
	return ((float)(alkoholmenge / (KONSTANTE_MAENNLICH*gewicht)));
}

int main(void) {
	/* Variable: fue das Benenden des Programms */
	int prog_ende = 0;
	int volumen;
	float gewicht;
	do {
		volumen = eingabe_volumen();
		gewicht = eingabe_gewicht();
		kommentar(promille(gewicht, menge_alk(volumen)));
		/* Exit Bedingung fuer die die Schleife */
		printf("Programm beenden mit 'ESC', zum Fortsetzen beliebige andere Taste\n");
		prog_ende = _getch();
	} while (prog_ende != ESC);
	return 0;
}
