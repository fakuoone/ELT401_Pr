#include <stdio.h>
#include <string.h>
int main(void)
{
    char Kette[20];
    printf("Geben Sie bitte einen Text ein: ");
    scanf("%19s",Kette);
    printf("Der Inhalt der Zeichenkette ist %s\n\n",Kette);
    return 0;
}