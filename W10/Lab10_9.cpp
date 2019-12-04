/*************************************************************************
	Dateiname:			Lab10_8.cpp
	Beschreibung: 		Verteilung der Buchstaben im String. 
	Version:			1.0
	Aenderungsgrund: 	-
	Projekt:    		Woche 10 Aufgabe 3.1
	Datum:      		04.12.2019
	Bearbeiter:			
*************************************************************************/

/* Einbinden der Bibliotheken */
#include <stdio.h>  /* fuer scanf_s und printf */ 
#include <stdlib.h> /**/

#define J_1 74  /* ASCII Code fuer das kleine "j" */
#define J_2 106 /* ASCII Code fuer das grosse "J" */ 

int main(void) 
{
    /* Variablen Deklatarion und Definition */
    char passwort[9];   /* Variable fuer den Passwort String */
    int i = 0;          /* Zaehlvariable */
    char steuervariable[2]; /* Steuervariable, ob das Passwort angezeigt werden soll */

    printf("Bitte ein 8 Zeichen langes Passwort eingeben: \n");
    do 
    {
        passwort[i] = _getwch();
        i++; 
    } while ((passwort[i-1]) == '\n' || (i == 8));

    printf("Soll das Passwort angezeigt werden? (j/N):\n");
    steuervariable[0] = getchar();
    if ((steuervariable[0] == J_1) || (steuervariable[0] == J_2))
    {
        printf("%8s",passwort);
    }
    return 0;    
}