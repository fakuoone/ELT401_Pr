/*PragrammMathepruefungDatum:19.11.2019Max MustermannPraktikum ELT401Seite: 5
JustusWeinholdVersion1.0*/
#include <stdio.h> 
#include <conio.h> 
//fuergetch
#include<Windows.h>
//fuersystem
#define ESC27    //Tasten code fuer die Taste "ESC" um Programm zu beenden
//Variablen
int zahl1, zahl2; 
int k_addition, k_subtraktion, k_multiplikation, k_division, k_rest; 
int ergebnis_addition, ergebnis_subtraktion, ergebnis_multiplikation, ergebnis_division, ergebnis_rest; 
int scanf_return; 
float AuswertungGesamt; 
float richtig=0; 
char programm_ende=0; 
//Funktionsdeklaration
int summe(int x, int y); 
int differenz(int x, int y);  
int multiplikation(int x, int y); 
int division(int x, int y); 
int rest(int x, int y); 

int erste_zahl(void){

}


//Hauptprogramm
int main(void){
    do{ 
    //Kopfzeile
        printf("Rechenprogramm fuer die 4 Grundrechenarten\n");
        printf("------------------------------------------\n"); 
        //Abfragen der ersten Zahl mit hinweis auf Fehleingabe
        do{
            //1.Schleife zur Kontrolle der richtigen Eingabe fuer Zahl 1 
            printf("Geben Sie die 1. Zahl hier ein(1-100):\t");
            scanf_return=scanf_s("%5d", &zahl1); 
            //fehlerhafte Eingabe = Kontrolle 
            if(0 == scanf_return || 0 > zahl1 || 100 < zahl1) {
                printf("Sie haben leider keine gueltige ganze Zahl eingegeben! Bitte geben Sie eine richtige Zahl ein.\n"); 
                //(Tastaturpuffer) Zeichenweise Tastatur leeren bis Enter
                while (getchar() != '\n');
            }
        } while(0 == scanf_return || 0 > zahl1 || 100 < zahl1); 
        //Abfragen der zweiten Zahl mit hinweis auf Fehleingabe
        do{
            //2.Schleife zur Kontrolle der richtigen Eingabe fuer Zahl 2 
            printf("Geben Sie die 2. Zahl hier ein(1-100):\t"); scanf_return=scanf_s("%5d", &zahl2); 
            //fehlerhafte Eingabe = Kontrolle 
            if(0 == scanf_return || 0 > zahl2 || 100 < zahl2){
                printf("Sie haben leider keine gueltige ganze Zahl eingegeben! Bitte geben Sie eine richtige Zahl ein.\n"); 
                while(getchar()!='\n'); //(Tastaturpuffer) Zeichenweise Tastatur leeren bis Enter 
            } 
        } while(0 == scanf_return || 0 > zahl2 || 100 < zahl2);
         
        //Berechnung der Additions aufgabe 
        k_addition = summe(zahl1, zahl2); 
        //Berechnung der Subtraktion 
        k_subtraktion = differenz(zahl1, zahl2); 
        //Berechnung der Multiplikation 
        k_multiplikation = multiplikation(zahl1, zahl2); 
        //Berechnung Division 
        k_division = division(zahl1, zahl2); 
        //Berechnung Rest 
        k_rest = rest(zahl1, zahl2);
        //Abfrage der Rechenergebnisse
        //Schleife fuer hinweis auf falsch eingebene Zahl
        do{
            printf("%d + %d= ", zahl1, zahl2); 
            scanf_return = scanf_s("%d", &ergebnis_addition); 
            //fehlerhafte Eingabe = Kontrolle 
            if(0 == scanf_return){
                printf("Sie haben leider keine gueltige ganze Zahl eingegeben! Bitte geben Sie eine richtige Zahlein.\n");
                while(getchar() != '\n'); 
                //(Tastaturpuffer) Zeichenweise Tastatur leeren bis Enter
            }
        } while(0 == scanf_return || 0 > zahl2 || 100 < zahl2); 
        //Schleife fuer hinweis auf falsch eingebene Zahl
        do {
            printf("%d - %d = ", zahl1, zahl2); 
            scanf_return = scanf_s("%d", &ergebnis_subtraktion); 
            //fehlerhafte Eingabe = Kontrolle 
            if(0 == scanf_return) {
                printf(" Sie haben leider keine gueltige ganze Zahl eingegeben! Bitte geben Sie eine richtige Zahl ein.\n"); 
                while(getchar() != '\n'); //(Tastaturpuffer) Zeichenweise Tastatur leeren bis Enter
            }
        } while(0 == scanf_return || 0 > zahl2 || 100 < zahl2); 
        //Schleife fuer hinweis auf falsch eingebene Zahl
        printf("%d * %d = ", zahl1, zahl2); 
        scanf_return = scanf_s("%d", &ergebnis_multiplikation); 
        //fehlerhafte Eingabe = Kontrolle 
        if( 0 == scanf_return) {
            printf("Sie haben leider keine gueltige ganze Zahl eingegeben! Bitte geben Sie eine richtige Zahl ein.\n");
        do{
            while(getchar() != '\n');  //(Tastaturpuffer) Zeichenweise Tastatur leeren bis Enter
        }
    } while(0 == scanf_return || 0 > zahl2 || 100 < zahl2); 
    //Schleife fuer hinweis auf falsch eingebene Zahl 
    printf("%d / %d = ", zahl1, zahl2); 
    scanf_return = scanf_s("%d", &ergebnis_division); //fehlerhafte Eingabe = Kontrolle 
    if( 0 == scanf_return){
        printf("Sie haben leider keine gueltige ganze Zahl eingegeben! Bitte geben Sie eine richtige Zahl ein.\n");
        while (getchar() != '\n'); //(Tastaturpuffer) Zeichenweise Tastatur leeren bis Enter
    }
} while( 0 == scanf_return || 0 > zahl2 || 100 < zahl2); 
//Schleife fuer hinweis auf falsch eingebene Zahl 
printf("Der Rest von %d / %d ist: ", zahl1, zahl2); 
scanf_return = scanf_s("%d", &ergebnis_rest); 
//fehlerhafte Eingabe = Kontrolle
if(0 == scanf_return) {
    printf("Sie haben leider keine gueltige ganze Zahl eingegeben! Bitte geben Sie eine richtige Zahl ein.\n"); 
    while(getchar() != '\n'); //(Tastaturpuffer) Zeichenweise Tastatur leeren bis Enter
}
} while( 0 == scanf_return || 0 > zahl2 || 100 < zahl2); 
//AbgleichderErgebnisse
//Abgleich Addition
if(ergebnis_addition == k_addition) { 
    printf("\nIhr selbst errechnetes Ergebnis der Addition %d ist richtig.\n", ergebnis_addition);
    richtig++;
} else {
    do {
        do {
            printf("\nIhr selbst errechnetes Ergebnis der Addition%distflasch!Richtig waere %d.\n", ergebnis_addition, k_addition); 
        } 
        //Abgleich Subtraktion
        if(ergebnis_subtraktion == k_subtraktion) {
            printf("\nIhr selbst errechnetes Ergebnis der Subtraktion %d ist richtig.\n", ergebnis_subtraktion); 
            richtig++; 
        } else { 
            printf("\nIhre selbst errechnetes Ergebnis der Subtraktion %d ist flasch! Richtig waere %d.\n", ergebnis_subtraktion, k_subtraktion); 
        }
        //Abgleich Multiplikation
        if(ergebnis_multiplikation == k_multiplikation) {
            printf("\nIhr selbst errechnetes Ergebnis der Multiplikation %d ist richtig.\n", ergebnis_multiplikation); 
            richtig++;
        } else {
            printf("\nIhr selbst errechnetes Ergebnis der Multiplikation %d ist flasch! Richtig waere%d.\n", ergebnis_multiplikation, k_multiplikation);
        }
        //Abgleich Division 
        if(ergebnis_division == k_division) {
            printf("\nIhr selbst errechnetes Ergebnis der Division %d ist richtig.\n", ergebnis_division); 
            richtig++; 
            } else { 
                printf("\nIhr selbst errechnetes Ergebnis der Division%distflasch!Richtigwaere%d.\n", ergebnis_division, k_division); }
        //AbgleichRest
        if(ergebnis_rest==k_rest) {
            printf("\nIhr selbst errechnetes Ergebnis fuer den Rest %d ist richtig.\n",  ergebnis_rest); 
            richtig++; 
        }
        else { 
            printf("\nIhr selbst errechnetes Ergebnis fuer den Rest %d ist flasch! Richtig waere %d.\n",  ergebnis_rest,  k_rest);  
        } 
        //Auswertung in Prozent der selbst ausgerechneten Ergebnisse
        AuswertungGesamt = richtig/5*100; 
        richtig = 0; 
        printf("\nSie haben %.0f prozent richtig erechnete Ergebnisse.\n\n", AuswertungGesamt); 
        //Abfrage zum Programm beenden
        printf("Programm beenden mit 'ESC', zum Fortsetzen beliebige andere Taste druecken.\n"); 
        //Tastaturabfrage 1 zeichen
        programm_ende = _getch(); 
        //Bildschirm loeschen
        system("cls");
        } while(programm_ende != ESC); 
        //Code, das Programm so lange ausgefuehrt wird, bis ESC gedrueckt wird
        return0; 
}
//Rueckgabe der Werte
//Rueckgabe der Addition
int summe(int x, int y) {
    return(x+y); 
}
//Rueckgabe der Subtraktion
int differenz(int x, int y) {
    return(x-y); 
}
//Rueckgabe der Multiplikation
int multiplikation(int x, int y) {
    return(x*y);
} 
//Rueckgabe der Division
int division(int x, int y) {
    return(x/y); 
}
//Rueckgabe Rest 
int rest(int x, int y) {
    return(x%y); 
}