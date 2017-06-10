#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define LIM_X 90
#define LIM_Y 21

void gotoxy(int x, int y);
void encerrarCadena (char * c);
void recorrerCabezalDerecha (char * c, int x);

////////////////////////////////////////////////////////////////////////////////////////
////								MaquinaTuring.c									////
////																				////
////																				////
//// Maquina de Turing simulando una cinta para encerrar los numeros binarios que 	////
//// ingrese el usuario, y posteriormente con un apuntador a la cadena del numero 	////
//// se simula el cabezal que se mueve en las 2 cadenas, y por ultimo, en la tercer	////
//// cinta se muestra el resultado de la suma.										////
////																				////
////																				////
//// Autor: Romero Gamarra Joel Mauricio											////
////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[])
{
	system("cls");
	char *c = (char *)malloc(sizeof(char));
	printf("Ingresa una palabra:\t");
	scanf("%s",c);
	encerrarCadena(c);
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

void encerrarCadena (char *c)
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

void recorrerCabezalDerecha (char *c, int x)
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
		gotoxy(j, 11);
		printf("1");
		j++;j++;
		gotoxy(j, 13);
	}
}