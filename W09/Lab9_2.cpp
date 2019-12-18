/*************************************************************************
Dateiname:			Lab9_4.cpp
Beschreibung: 		Mathepruefung mit vorgegebenen Zahlen
Version:			1.0
Aenderungsgrund: 	-
Projekt:    		Mathepruefung
Datum:      		12.12.2019
Bearbeiter:
*************************************************************************/

/* Einbinden Bibliotheken */
#include <stdio.h>
#include <stdlib.h> /* fuer rand() */
#include <time.h>
#include <conio.h>

/* Definition von Makros */
#define ENTER (char)('\n')
#define ESC 27
#define O_1 79
#define O_2 111

/* Definition globaler Variablen */
int user_ergebnisse[5];
int parameter_schwierigkeit[2];

/* Funktion zur Berechnung der Summe */
int addition(int x, int y) {
	return (x + y);
}

/* Funktion zur Berechnung der Subtraktion */
int subtraktion(int x, int y) {
	return (x - y);
}

/* Funktion zur Berechnung der Multiplikation */
int multiplikation(int x, int y) {
	return (x * y);
}

/* Funktion zur Berechnung der Division */
int division(int x, int y) {
	return (x / y);
}

/* Funktion zur Berechnung des Modulus */
int modulus(int x, int y) {
	return (x % y);
}

int abfrage_ergebnisse(void) {
	/* Steuervariablen fuer Eingabefehler */
	int scanf_return;
	char enter;

	for (size_t i = 0; i < 5; i++) {
		do {
			scanf_return = 1;
			switch (i) {
			case 0:
				printf("| Bitte die erwartete Summe eingeben:       ");
				break;
			case 1:
				printf("| Bitte die erwartete Differenz eingeben:   ");
				break;
			case 2:
				printf("| Bitte das erwartetes Produkt eingeben:    ");
				break;
			case 3:
				printf("| Bitte den erwarteten Quotienten eingeben: ");
				break;
			case 4:
				printf("| Bitte den erwarteten Rest eingeben:       ");
				break;
			}
			scanf_return = scanf_s("%d%c", &user_ergebnisse[i], &enter,1);
			if ((scanf_return == 0) || (enter != ENTER)) {
				printf("| Sie haben keine gueltige Zahl eingegeben!                     |\n| Bitte geben Sie eine richtige Zahl ein.                       |\n");
				while (getchar() != ENTER);
				if (enter != ENTER) {
					scanf_return = 0;
				}
			}
		} while (scanf_return == 0);
	}
	return 0;
}

void abfrage_schwierigkeit(void) {
	char enter;
	int schwierigkeit;
	int scanf_return;

	printf("+---------------------------------------------------------------+\n");
	printf("| Schwierigkeit waehlen:                                        |\n");
	printf("| 1: Einfach - Eeide Zahlen sind einstellig                     |\n");
	printf("| 2: Mittel1 - Eine Zahl ist zweistellig und eine einstellig    |\n");
	printf("| 3: Mittel2 - Eine Zahl ist dreistellig und eine einstellig    |\n");
	printf("| 4: Schwer1 - Beide Zahlen sind zweistellig                    |\n");
	printf("| 5: Schwer2 - Eine Zahl ist dreistellig und eine zweistellig   |\n");
	printf("| 6: Hart    - Beide Zahlen sind dreistellig                    |\n");
	printf("+---------------------------------------------------------------+\n");

	do {
		printf("| Bitte eine Schwierigkeit waehlen: ");
		scanf_return = scanf_s("%d%c", &schwierigkeit, &enter,1);
		if ((scanf_return == 0) || (enter != ENTER)) {
			printf("| Sie haben keine gueltige Zahl eingegeben!                     |\n| Bitte geben Sie eine richtige Zahl ein.                       |\n");
			if (enter != ENTER) {
				while (getchar() != ENTER);
				scanf_return = 0;
			}
		}
			else {
				switch (schwierigkeit)
				{
				case 1:
					break;
				case 2:
					parameter_schwierigkeit[0] = 99;
					parameter_schwierigkeit[1] = 9;
					break;
				case 3:
					parameter_schwierigkeit[0] = 999;
					parameter_schwierigkeit[1] = 9;
					break;
				case 4:
					parameter_schwierigkeit[0] = 99;
					parameter_schwierigkeit[1] = 99;
					break;
				case 5:
					parameter_schwierigkeit[0] = 999;
					parameter_schwierigkeit[1] = 99;
					break;
				case 6:
					parameter_schwierigkeit[0] = 999;
					parameter_schwierigkeit[1] = 999;
					break;
				default:
					printf("+---------------------------------------------------------------+\n");

					printf("| Bitte eine Zahl zwischen 1 und 6 eingeben!                    |\n");
					scanf_return = 0;
					break;
				}
			}
	} while (scanf_return == 0);
}

int main(void) {
	/* Eingabevariablen */
	int zahl1, zahl2;
	/* Ausgabevariablen */
	int ergebnisse[5];
	int gesamt_richtig = 0,
		durchlauf = 0;
	float prozent;
	/* Variable zur spaeteren Schiwerigkeitswahl */
	int level;

	/* Initialisieren der Zufallszahlen */
	srand((unsigned int)time(NULL));

	printf("+---------------------------------------------------------------+\n");
	printf("|      ###   ###    ####   ########  ##   ##  ######            |\n");
	printf("|      #### ####   ##  ##     ##     ##   ##  ##                |\n");
	printf("|      ## ### ##  ########    ##     #######  ####    ####      |\n");
	printf("|      ##     ##  ##    ##    ##     ##   ##  ##                |\n");
	printf("|      ##     ##  ##    ##    ##     ##   ##  ######            |\n");
	printf("|                                                               |\n");
	printf("| ######   ######   ##   ##  #######  ##   ##  ##   ##   #####  |\n");
	printf("| ##   ##  ##   ##           ##       ##   ##  ###  ##  ##      |\n");
	printf("| ######   ######   ##   ##  ######   ##   ##  ## # ##  ##  ### |\n");
	printf("| ##       ##   ##  ##   ##  ##       ##   ##  ##  ###  ##   ## |\n");
	printf("| ##       ##   ##    ###    ##         ###    ##   ##   ###### |\n");
	printf("|                                                            ## |\n");
	printf("+---------------------------------------------------------------+\n");
	abfrage_schwierigkeit();
	printf("+---------------------------------------------------------------+\n");

	do {
		/* Variablen fur einen Durchlauf */
		int richtig = 0;
		int gesamt_fragen;

		/* Durchlauf initialisieren */
		durchlauf++;
		gesamt_fragen = 5 * durchlauf;
		zahl1 = (rand() % parameter_schwierigkeit[0]) + 1;
		zahl2 = (rand() % parameter_schwierigkeit[1]) + 1;


		printf("+---------------------------------------------------------------+\n");
		printf("|                           RUNDE %2d                            |\n", durchlauf);
		printf("+---------------------------------------------------------------+\n");
		printf("| Die Zahlen in dueser Runde lauten:                            |\n", zahl1);
		printf("| Zahl 1: %3d                                                   |\n", zahl1);
		printf("| Zahl 2: %3d                                                   |\n", zahl2);
		printf("+---------------------------------------------------------------+\n");

		/* User-Eingaben */
		abfrage_ergebnisse();
		/* Berechnung */
		ergebnisse[0] = addition(zahl1, zahl2);
		ergebnisse[1] = subtraktion(zahl1, zahl2);
		ergebnisse[2] = multiplikation(zahl1, zahl2);
		ergebnisse[3] = division(zahl1, zahl2);
		ergebnisse[4] = modulus(zahl1, zahl2);

		/* Auswertung: Rechnen */
		printf("+---------------------------------------------------------------+\n");

		for (int i = 0; i < 5; i++) {
			printf("| ");
			switch (i) {
			case 0:
				printf("Summe");
				break;
			case 1:
				printf("Differenz");
				break;
			case 2:
				printf("Produkt");
				break;
			case 3:
				printf("Quotient");
				break;
			case 4:
				printf("Rest");
				break;
			default:
				break;
			}

			if (ergebnisse[i] == user_ergebnisse[i]) {
				richtig++;
				printf(" korrekt!\n");
			}
			else {
				printf(" falsch. Die richtige Antwort waere %d\n", ergebnisse[i]);
			}
		}

		/* Auswertung: Durchlauf */
		printf("+---------------------------------------------------------------+\n");

		if (richtig == 1) {
			printf("| In dieser Runde wurde %d von 5 Fragen richtig beantwortet. ", richtig);
		}
		else {
			printf("| In dieser Runde wurden %d von 5 Fragen richtig beantwortet. ", richtig);
		}
		prozent = (float)(100 * richtig / 5);
		printf("\n| Das entspricht %.2f%%.\n", prozent);

		/* Auswertung: Gesamt */
		gesamt_richtig += richtig;
		if (richtig == 1) {
			printf("|\n| Im der %d. Runde wurde insgesamt %d von %d Fragen richtig beantwortet.\n", durchlauf, gesamt_richtig, gesamt_fragen);
		}
		else {
			printf("|\n| Im der %d. Runde wurden insgesamt %d von %d Fragen richtig beantwortet.\n", durchlauf, gesamt_richtig, gesamt_fragen);
		}
		prozent = (float)(100 * gesamt_richtig / gesamt_fragen);
		printf("| Das entspricht %.2f%%.\n", prozent);

		/* Abfrage fuer weitere Runde */
		printf("+---------------------------------------------------------------+\n");

		printf("| Programm beenden mit 'ESC'.                                   |\n| Schwierigkeit aendern mit \"s\"                               |\n| Zum Fortsetzen beliebige andere Taste druecken                |\n");
		printf("+---------------------------------------------------------------+\n");

		/* Moeglichkeit zur Aenderung der Schwierigkeit */
		level = _getwch();
		if ((level == O_1) || (level == O_2))
		{
			abfrage_schwierigkeit();
		}
	} while (_getwch() != ESC);
	printf("+---------------------------------------------------------------+\n");

	return 0;
}