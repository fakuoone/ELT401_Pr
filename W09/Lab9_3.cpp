/*************************************************************************
	Dateiname:			Lab9_3.cpp
	Beschreibung: 		"6 aus 49" mit Zusatzzahl und Superzahl
	Version:			1.0
	Aenderungsgrund: 	-
	Projekt:    		"6 aus 49"
	Datum:      		01.12.2019
	Bearbeiter:			
*************************************************************************/

/* Bibliotheken einbinden */
#include <stdlib.h> /* fuer rand */
#include <time.h> 	/* fuer time */
#include <stdio.h>	/* fuer scanf_s und printf */

/* Makros definiren */
#define ENTER (char)('\n')

/* Globale Variablen */
int lottozahlen[8]; 	/* 1 - 6: Lottozahlen;  7: Zusatzzahl; 8: Superzahl */
int lottoschein[8]; 	/* 1 - 6: Lottozahlen;  7: Zusatzzahl; 8: Superzahl */


/* Lottoschein ausfuellen */
void schein_ausfuellen(){
	/* Variablen definieren */
	int scanf_return = 0; 	/* Steuervariable fur Eingabefehler */
	char enter; 			/* Variable um auf ein Enter am Zeilenende zu pruefen */
	
	printf("Lottoschein bitte ausfuellen:\n");
	for (int i = 0; i < 8; i++) {
		if (i < 7) {
		/* Eintragung der 6 Lottozahlen mit Zusatzzahl */
			do
			{
				if (i < 6){
					printf("%d. Zahl:    ", (i+1));
				} else {
					printf("Zusatzzahl: ");
				} 
				scanf_return = scanf("%d%c", &lottoschein[i], &enter);
				if ((scanf_return == 0) || (enter != ENTER))
				{
					/* Fehlerabfang: keine Zahl */
					printf("Sie haben keine gueltige Zahl eingegeben!\nBitte geben Sie eine Zahl ein.\n");
					if (enter != ENTER)
					{
						scanf_return = 0;
					}
					while (getchar() != ENTER);
				}
				else if ((lottoschein[i] < 1) || (lottoschein[i] > 49))
				{
					/* Fehlerabfang: Zahl ausserhalb des Bereichs */
					printf("Die Zahl ist ausserhalb des Bereichs! Bitte eine Zahl zwischen 1 und 49 eingeben.\n");
					scanf_return = 0;
				}
				else
				{
					/* Fehlerabfang: Doppelte Zahlen */
					for (int j = 0; j < i; j++)
					{
						if (lottoschein[i] == lottoschein[j]) {
							printf("Die zahlen koennen nicht doppelt angekreuzt werden!\n");
							scanf_return = 0;
						}
					}
					
				}
			} while (scanf_return == 0);
		} else {
		/* Eintragung der Superzahl */
			do {
				printf("Superzahl:  ");
				scanf_return = scanf("%d%c", &lottoschein[i], &enter);
				if ((scanf_return == 0) || (enter != ENTER)) {
					printf("Sie haben keine gueltige Zahl eingegeben!\nBitte geben Sie eine Zahl ein.\n");
					if (enter != ENTER) {
						scanf_return = 0;
					}
					while (getchar() != ENTER);
				} else if ((lottoschein[i] < 0) || (lottoschein[i] > 9)) {
					printf("Die Zahl ist ausserhalb des Bereichs! Bitte eine Zahl zwischen 0 und 9 eingeben.\n");
					scanf_return = 0;
				}
			} while (scanf_return == 0);
		}
	}
}

/* Ziehung der Zahlen */
void ziehung(void){
	/* Variablen Deklarieren */
	int steuervariable;

	/* Beginn der Ziehung */
	for (int i = 0; i < 8; i++)
	{
		do
		{
			steuervariable = 1;
			/* Ziehung der 6 Zahlen + Zusatzzahl */
			if (i < 7)
			{
				lottozahlen[i] = (rand() % 49)+1;
				/* Fehlerabfang: doppelte Zahlen */
				for (int j = 0; j < i ; j++) {
					if (lottozahlen[i] == lottozahlen[j]) {
						steuervariable = 0;
					}
				}
			} else {
			/* Ziehung der Superzahl */
				lottozahlen[i] = (rand() % 9)+1;
			}
		} while (steuervariable == 0);
	}
}

void auswertung(void) {
	int treffer[3] = { 		/* Variablen fuer korrekte Tipps */
	0,			/* Treffer einzelner Lottozahlen */
	0,			/* Treffer Zusatzzahl */
	0}; 		/* Treffer Superzahl */

	/* Auswertung: Lottoschein */
	printf("\n+----+----+----+----+----+----+----+----+\n");
	printf("|                Ziehung                |\n");
	printf("+----+----+----+----+----+----+----+----+\n");
	printf("|  1 |  2 |  3 |  4 |  5 |  6 |  Z |  S |\n");
	printf("+----+----+----+----+----+----+----+----+\n");
	for (int i = 0; i < 8; i++){
			printf("| %2d ", lottozahlen[i]);
	}
	printf("|\n+----+----+----+----+----+----+----+----+\n\n");
	printf("Lottoschein:\n");

	for (int i = 0; i < 8; i++)
	{
		if (i < 6)
		{
			/* Auswertung der 6 Zahlen */
			printf("%d. Zahl:    %2d", (i+1), lottoschein[i]);
			for (int j = 0; j < 6; j++)
			{
				if (lottoschein[i] == lottozahlen[j]) {
					treffer[0]++;
					printf("    Treffer");
				}
			}
			printf("\n");
		} else if (i < 7)
		{
			/* Auswertung der Zusatzzahhl */
			printf("Zusatzzahl: %2d", lottoschein[6]);
			if (lottoschein[i] == lottozahlen[i]) {
				treffer[1]++;
				printf("    Treffer");
			}
			printf("\n");
		} else
		{
			/* Auswertung der Superzahl */
			printf("Superzahl:  %2d", lottoschein[6]);
			if (lottoschein[i] == lottozahlen[i]) {
				treffer[2]++;
				printf("    Treffer");
			}
			printf("\n");
		} 
		printf("\n");
	}
	
	/* Auswertung: Ergebnisse */
	switch (treffer[0])
	{
	case 1:
		printf("Ein Einer");
		break;
	case 2:
		printf("Ein Zweier");
		break;
	case 3:
		printf("Ein Dreier");
		break;
	case 4:
		printf("Ein Vierer");
		break;
	case 5:
		printf("Ein Fuenfer");
		break;
	case 6:
		printf("EIN SECHSER");
		break;
	default:
		printf("Leider hatten Sie diesmal kein Glueck! Viel Erfolg beim naechsten Mal.");
		break;
	}

	if ((treffer[1] > 0) && (treffer[0] > 0))
	{
		printf(" mit Zusatzzahl");
		if (treffer[2])
		{
			printf(" und Superzahl!");
		}
		else
		{
			printf("!");
		}
	} else if ((treffer[0] > 0) && (treffer[2] > 0)) {
		printf(" mit Superzahl!");
	} else if (treffer[0] > 0)
	{
		printf(" ohne Zusatz- oder Superzahl.");
	}
	printf("\n");
}

int	main(void) {
	/* Initialisierung des Zufallsgenerators */
	srand((unsigned int)time(NULL));

	ziehung();
	schein_ausfuellen();
	auswertung();
	
	return 0;
}
