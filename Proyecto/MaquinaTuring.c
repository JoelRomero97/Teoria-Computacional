#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define LIM_X 90
#define LIM_Y 21

void gotoxy(int x, int y);
void encerrarCadenas (char * c, int n);
void recorrerCabezalDerecha (char * c, int x);

int main(int argc, char const *argv[])
{
	system("cls");
	char *c = (char *)malloc(sizeof(char));
	printf("Ingresa una palabra:\t");
	scanf("%s",c);
	encerrarCadenas(c);
	return 0;
}

void gotoxy(int x, int y)
{  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);
}

void encerrarCadenas (char * c, int n)
{
	int longitudPalabra, numGuiones, x, i;
	longitudPalabra = strlen(c);					//Obtenemos la longitud de la cadena
	numGuiones = (longitudPalabra * 2)+1;			//Calculamos los guiones para simular la cinta
	x = (LIM_X-(longitudPalabra * 2))/2;			//Centramos la cadena
	gotoxy(x,10);
	for (i = 0; i < numGuiones; i ++)
	{
		printf("_");
	}
	gotoxy(x,11);
	for (i = 0; i < longitudPalabra; i ++)
	{
		printf("|%c", c[i]);
	}
	printf("|");
	gotoxy(x,12);
	for (i = 0; i < numGuiones; i ++)
	{
		printf("%c",238);
	}
	recorrerCabezalDerecha(c, x);
}

void recorrerCabezalDerecha (char * c, int x)
{
	int j = x + 1;
	char * pt = c;
	gotoxy(j, 13);
	for (;*pt != '\0'; pt ++)
	{
		printf("%c", 140);
		Sleep(700);
		gotoxy(j, 13);
		printf(" ");
		j++;j++;
		gotoxy(j, 13);
	}
}