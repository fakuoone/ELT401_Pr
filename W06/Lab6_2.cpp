/*
Projekt:    Cafetariaautomat
Datum:      21.11.2019

*/

/* Einbinden der Bibliotheken */
#include <stdio.h>
#include <conio.h>
/* Percompileranweisungen */
#define ENTER 10
#define MAX_ARTIKEL 7
#define J_1 74
#define J_2 106
/* Globale Variablen */
float geld_betrag = 0;
/* Funktion zum Auflisten des Angebots */
int liste_artikel(void) {
    printf("+-------------------------------------+\n");
    printf("|          CAFETERIA-AUTOMAT          |\n");
    printf("+-------------------------------------+\n");
    printf("| Angebot:                            |\n");
    printf("| 1 - Kaffee                1,20 Euro |\n");
    printf("| 2 - Tee                   1,00 Euro |\n");
    printf("| 3 - Kakao                 1,20 Euro |\n");
    printf("| 4 - Wasser                0,80 Euro |\n");
    printf("| 5 - Sandwich Salami       2,50 Euro |\n");
    printf("| 6 - Sandwich Schinken     2,50 Euro |\n");
    printf("| 7 - Sandwich Deluxe       3,00 Euro |\n");
    printf("+-------------------------------------+\n");
    return 0;
}
/* Funktion zur Errechnung der Zwischensumme */
float zwischensumme(int auswahl, int anzahl) {
    if (auswahl == 1) {
        return (float)(anzahl * 1.2);
    }
    else if (auswahl == 2)
    {
        return (float)(anzahl * 1);
    }
    else if (auswahl == 3)
    {
        return (float)(anzahl * 1.2);
    }
    else if (auswahl == 4)
    {
        return (float)(anzahl * 0.8);
    }
    else if (auswahl == 5)
    {
        return (float)(anzahl * 2.5);
    }
    else if (auswahl == 6)
    {
        return (float)(anzahl * 2.5);
    }
    else
    {
        return (float)(anzahl * 3);
    }
}

/* Funktion fuer die Artikelauswahl */
int artikel_auswahl(void) {
    /* Eingabefehlerabfangvariablen */
    char steuervariable;
    char enter = 0;
    /* Definition privater Variablen */
    int auswahl = 0;
    int anzahl = 0;
    /* Produktwahl */
    do {
        printf("| Bitte treffen Sie Ihre Auswahl: ");
        steuervariable = scanf_s("%d%c", &auswahl, &enter, 1);
        if ((steuervariable == 0) || (enter != ENTER) || (auswahl < 1) || (auswahl > MAX_ARTIKEL))
        {
            printf("| Bitte eine korrekte Auswahl treffen.|\n");
            /* Puffer leeren wenn mehr als ein CHAR gelesen wurde */
            if (enter != ENTER) {
                while (getchar() != '\n');
        }
        steuervariable = 0;
        }
    } while (steuervariable == 0);
    /* Wahl der Anzahl */
    do {
        printf("| Anzahl                              |\n");
        printf("| (bei falscher Artikelwahl           |\n");
        printf("| Menge 0 eingeben): ");
        steuervariable = scanf_s("%d%c", &anzahl, &enter, 1);
        if ((steuervariable == 0) || (enter != ENTER) || (anzahl < 0))
        {
            printf("| Bitte eine korrekte Menge angeben! |\n");
            /* Puffer leeren wenn mehr als ein CHAR gelesen wurde */
            if (enter != ENTER) {
                while (getchar() != '\n');
            }
            steuervariable = 0;
        }
        } while (steuervariable == 0);
        /* Ermittlung der Zwischensumme */
        geld_betrag += zwischensumme(auswahl, anzahl);
        printf("| aktuelle Zwischensumme: %.2f Euro |\n", geld_betrag);
        return 0;
}

int bezahlvorgang() {
    /* Definition der Variablen dieser Funktion */
    float eingegebenes_geld = 0;
    float gezahlter_betrag = 0;
    float offener_bertag = 0;
    printf("+-------------------------------------+\n");
    printf("| Zu zahlender Betrag:      %.2f Euro |\n", geld_betrag);
    do {
        printf("| Bitte Geld eingeben:     ");
        /* Dummy-Anweisung, da im echten Leben ein Muenzautomat und nicht eine
        Texteingabe genutzt wird.
        Es wird davon ausgegangen, dass der Muenzautomat korrekte Werte an das
        Programm weiter gibt. */
        scanf_s("%f", &eingegebenes_geld);
        /* Berechnung des bereits gezahlten Betrages */
        gezahlter_betrag += eingegebenes_geld;
        /* Betrag, der noch offen ist, bzw. wenn der Wert negativ ist, dann ent-
        spricht dieser dem Wechselgeld */
        offener_bertag = geld_betrag - gezahlter_betrag;
        /* Pruefung, ob noch ein Restbetrag offen ist */
        if (offener_bertag > 0) {
            printf("| Gezahlter Betrag:         %.2f Euro |\n", gezahlter_betrag);
            printf("| offener Betrag:           %.2f Euro |\n", (geld_betrag - gezahlter_betrag));
        }
        else
        {
            printf("| Gezahlter Betrag:         %.2f Euro |\n", gezahlter_betrag);
            printf("| Wechselgeld:              %.2f Euro |\n", (offener_ber-tag * (-1)));
            printf("+-------------------------------------+\n");
            printf("|   Vielen Dank fuer Ihren Einkauf!   |\n");
            printf("|    Beehren Sie uns bald wieder!     |\n");
            printf("+-------------------------------------+\n");
        }
    } while (gezahlter_betrag < geld_betrag);
    return 0;
}

int main(void)
{
    /* Variable um den Bezahlvorgang einzuleiten */
    char prog_ende = 0;
    do {
        liste_artikel();
        artikel_auswahl();
        /* User eingabe um weitere Artikel zu kaufen */
        printf("| Haben Sie noch einen Wunsch? (j/N) |\n");
        prog_ende = _getch();
    } while ((prog_ende == J_1) || (prog_ende == J_2));
    bezahlvorgang();
    return 0;
}