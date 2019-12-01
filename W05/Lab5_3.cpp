/*************************************************************************
	Dateiname:			Lab5_3_2.cpp
	Beschreibung: 		Mathepruefung
	Version:			1.0
	Aenderungsgrund: 	-
	Projekt:    		Mathepruefung 
	Datum:      		28.11.2019
	Bearbeiter:			
*************************************************************************/

/* Einbinden Bibliotheken */
#include <stdio.h>

/* Definition von Makros */
#define ENTER 10
#define ESC 27

    /* Definition globaler Variablen */
    int user_ergebnisse[4];

/* Funktion zur Berechnung der Summe */
int addition(int x, int y){
    return (x + y);
}

/* Funktion zur Berechnung der Subtraktion */
int subtraktion(int x, int y){
    return (x - y);
}

/* Funktion zur Berechnung der Multiplikation */
int multiplikation(int x, int y){
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

int abfrage_zahl1(void) {
    /* Steuervariablen fuer Eingabefehler */
    int scanf_return;
    char enter;
    int operand;
    do {
        printf("| Bitte eine Zahl zwischen 1 und 100 eingeben: ");
        scanf_return = scanf("%d%c", &operand, &enter);
        if ((scanf_return == 0) || (enter != ENTER)) {
            printf("| Sie haben keine gueltige Zahl eingegeben!\n| Bitte geben Sie eine richtige Zahl ein.\n");
            while (getchar() != ENTER);
        } else if (enter != ENTER) {
                while (getchar() != ENTER);
                scanf_return = 0;
        } else if ((operand < 1) || (operand > 100)) {
            printf("| Die Zahl ist ausserhalb des Bereichs!\n");
            scanf_return = 0;
        }
    } while(scanf_return == 0);
    return operand;
}

int abfrage_zahl2(void) {
    /* Steuervariablen fuer Eingabefehler */
    int scanf_return;
    char enter;
    
    int operand;
    do {
        printf("| Bitte eine weitere Zahl zwischen 1 und 100 eingeben: ");
        scanf_return = scanf("%d%c", &operand, &enter);
        if ((scanf_return == 0) || (enter != ENTER)) {
            printf("| Sie haben keine gueltige Zahl eingegeben!\n| Bitte geben Sie eine richtige Zahl ein.\n");
            while (getchar() != ENTER);
        } else if (enter != ENTER) {
                while (getchar() != ENTER);
                scanf_return = 0;
        } else if ((operand < 1) || (operand > 100)) {
            printf("| Die eingegebene Zahl ist ausserhalb des vorgebenen Bereichs!\n");
            scanf_return = 0;
        }
    } while(scanf_return == 0);
    return operand;
}

int abfrage_ergebnisse(void) {
    /* Steuervariablen fuer Eingabefehler */
    int scanf_return;
    char enter;

    for (size_t i = 0; i < 5; i++) {
        do {
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
            scanf_return = scanf("%d%c", &user_ergebnisse[i], &enter);
            if ((scanf_return == 0)  || (enter != ENTER))  {
                printf("| Sie haben keine gueltige Zahl eingegeben!\n| Bitte geben Sie eine richtige Zahl ein.\n");
                while (getchar() != ENTER);
            }
            else if (enter != ENTER) {
                while (getchar() != ENTER);
                scanf_return = 0;
            }
        } while (scanf_return == 0);
    }
    return 0;
}

int main(void){
    /* Eingabevariablen */
    int zahl1, zahl2;
    /* Ausgabevariablen */
    int ergebnisse[4];
    int gesamt_richtig = 0, 
        durchlauf = 0; 
    float prozent;

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

    do {
        /* Variablen fur einen Durchlauf */
        int richtig = 0;
        int gesamt_fragen;

        /* Durchlauf initialisieren */
        durchlauf++;
        gesamt_fragen = 5 * durchlauf;

        printf("+---------------------------------------------------------------+\n");
        printf("|                           RUNDE %2d                            |\n", durchlauf);
        printf("+---------------------------------------------------------------+\n");

        /* User-Eingaben */
        zahl1 = abfrage_zahl1();
        zahl2 = abfrage_zahl2();
                printf("+---------------------------------------------------------------+\n");

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

            if (ergebnisse[i] == user_ergebnisse[i]){
                richtig++;
                printf(" korrekt!\n");
            } else {
                printf(" falsch. Die richtige Antwort waere %d\n", ergebnisse[i]);
            }
        }

        /* Auswertung: Durchlauf */
                printf("+---------------------------------------------------------------+\n");

        if (richtig == 1) {
            printf("| In dieser Runde wurde %d von 5 Fragen richtig beantwortet. ", richtig);
        } else {
            printf("| In dieser Runde wurden %d von 5 Fragen richtig beantwortet. ", richtig);
        }
        prozent = 100 * richtig / 5;
        printf("\n| Das entspricht %.2f%%.\n", prozent);

            /* Auswertung: Gesamt */
            gesamt_richtig += richtig;
        if (richtig == 1) {
            printf("|\n| Im der %d. Runde wurde insgesamt %d von %d Fragen richtig beantwortet.\n", durchlauf, gesamt_richtig, gesamt_fragen);
        } else {
            printf("|\n| Im der %d. Runde wurden insgesamt %d von %d Fragen richtig beantwortet.\n", durchlauf, gesamt_richtig, gesamt_fragen);
        }
        prozent = 100 * gesamt_richtig / gesamt_fragen;
        printf("| Das entspricht %.2f%%.\n", prozent);

        /* Abfrage fuer weitere Runde */
        printf("+---------------------------------------------------------------+\n");

        printf("| Programm beenden mit 'ESC'.\n| Zum Fortsetzen beliebige andere Taste\n");
    } while (getchar() != ESC);
    printf("+---------------------------------------------------------------+\n");

    return 0;
}