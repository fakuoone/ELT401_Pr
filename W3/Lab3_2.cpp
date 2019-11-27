/* ELT401 Technische Informatik Praktikum
Rechnen zweier Zahlen mit Menuefuehrung 
27.10.2019  
Bearbeiter: 
*/

#include <stdio.h>

/* Globale Variablen*/
int a, b, c, m;
float q;

/* Fuktionsdeklaration (Funktion: summe) */
int summe(int x, int y);

/* Fuktionsdeklaration (Funktion: differenz) */
int differenz(int x, int y);

/* Fuktionsdeklaration (Funktion: produkt) */
int produkt(int x, int y);

/* Fuktionsdeklaration (Funktion: quotient) */
float quotient(int x, int y);

/* Hauptprogramm */
int main(void){
    /* erste Zahl eingeben */
    printf("Geben Sie eine Zahl ein (1-100): ");
    scanf_s("%d", &a);
    /* zweite Zahl eingeben */
    printf("Geben Sie eine weitere Zahl ein (1-100): ");
    scanf_s("%d", &b);    
    /* Menueabfrage */    
    printf (" - Addition \t= 1\n - Division \t= 2\n - Produkt \t= 3\n - Quotient \t= 4\nWie wollen Sie die Zahlen zusammen rechnen? ");    
    scanf_s("%d",&m);    
    /* Eingabe Menue pruefen */    
    if (m <= 4 && m >= 1){        
        if (m == 1) {            
            /* Summe berechnen und anzeigen */            
            c = summe(a, b);
            printf("Summe:\t\t%d + %d = %d\n", a, b, c);
        }         
        if (m == 2) {            
            /* Differenz berechnen und anzeigen */            
            c = differenz(a, b);            
            printf("Differenz:\t%d - %d = %d\n", a, b, c);
        }        
        if (m == 3) {            
            /* Produkt berechnen und anzeigen */            
            c = produkt(a, b);            
            printf("Produkt:\t%d * %d = %d\n", a, b, c);
        }        
        if (m == 4) {            
            /* Quotient berechnen und anzeigen */            
            q = quotient(a, b);            
            printf("Quotient:\t%d / %d = %.4f\n", a, b, q);
        }    } 
        else {        
            printf("Bitte eine Zahl zwischen 1 und 4 eingeben");    
        }
}

/* Definition der Funktion "summe" */
int summe(int x, int y) {
    return (x + y);
}

/* Definition der Funktion "differenz" */
int differenz(int x, int y) {
    return (x - y);
}

/* Definition der Funktion "produkt" */
int produkt(int x, int y) {
    return (x * y);
}

/* Definition der Funktion "quotient" */
float quotient(int x, int y) {    
    if (y == 0) {        
        printf("Division durch null nicht möglich\n");        
        return 0;    
    } else {    
        return ((float)x / (float)y);    
    }
}