#include <stdio.h>
#include <string.h>
int main(void)
{
char Kette[20];
printf("Geben Sie bitte einen Text ein: ");
fgets(Kette,20,stdin);
printf("Der Inhalt der Zeichenkette ist %s",Kette);
return 0;
}
