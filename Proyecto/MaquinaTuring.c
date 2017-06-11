#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define LIM_X 90
#define LIM_Y 21

void gotoxy(int x, int y);
void encerrarNumeros (char * num1, char * num2);
void realizarSuma (char * num1, char * num2, int x1, int x2);

////////////////////////////////////////////////////////////////////////////////////////
////								MaquinaTuring.c									////
////																				////
////																				////
//// Maquina de Turing simulando una cinta para encerrar los numeros binarios que 	////
//// ingrese el usuario, y posteriormente con un apuntador a la cadena del numero 	////
//// se simula el cabezal que se mueve en las 2 cadenas, y por ultimo, en la tercer	////
//// cinta se muestra el resultado de la suma de ambos numeros binarios.			////
////																				////
////																				////
//// Autor: Romero Gamarra Joel Mauricio											////
////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[])
{
	system("cls");
	char * num1 = (char *)malloc (sizeof (char));
	char * num2 = (char *)malloc (sizeof (char));
	gotoxy(32,2);
	printf("SUMA DE 2 NUMEROS BINARIOS\n\n\n\n");
	printf("Ingresa el primer numero:\t");
	scanf("%s",num1);
	printf("Ingresa el segundo numero:\t");
	scanf("%s",num2);
	encerrarNumeros(num1, num2);
	gotoxy (5,19);
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

void encerrarNumeros (char * num1, char * num2)
{
	system("cls");
	int longitudPalabra1, numGuiones1, x1, i;
	int longitudPalabra2, numGuiones2, x2;
	longitudPalabra1 = strlen(num1);					//Obtenemos la longitud de la cadena
	longitudPalabra2 = strlen(num2);					//Obtenemos la longitud de la cadena 2
	numGuiones1 = (longitudPalabra1 * 2)+1;				//Calculamos los guiones para simular la cinta
	numGuiones2 = (longitudPalabra2 * 2)+1;				//Calculamos los guiones para simular la cinta 2
	x1 = (LIM_X- (longitudPalabra1 * 2))/2;				//Centramos la cadena
	x2 = (LIM_X - (longitudPalabra2 * 2))/2;			//Centramos la cadena 2
	if (longitudPalabra2 > longitudPalabra1)
		x2 -= (longitudPalabra2 - longitudPalabra1);		//Alineamos con la cadena 1
	else
		x1 -= (longitudPalabra1 - longitudPalabra2);
	//ENCERRAMOS EL PRIMER NÚMERO
	gotoxy(x1,5);
	for (i = 0; i < numGuiones1; i ++)
	{
		printf("_");
	}
	gotoxy(x1,6);
	for (i = 0; i < longitudPalabra1; i ++)
	{
		printf("|%c", num1[i]);
	}
	printf("|");
	gotoxy(x1,7);
	for (i = 0; i < numGuiones1; i ++)
	{
		printf("%c",238);
	}
	//ENCERRAMOS EL SEGUNDO NÚMERO
	gotoxy(x2,10);
	for (i = 0; i < numGuiones2; i ++)
	{
		printf("_");
	}
	gotoxy(x2,11);
	for (i = 0; i < longitudPalabra2; i ++)
	{
		printf("|%c", num2[i]);
	}
	printf("|");
	gotoxy(x2,12);
	for (i = 0; i < numGuiones2; i ++)
	{
		printf("%c",238);
	}
	realizarSuma(num1, num2, x1, x2);
}

void realizarSuma (char * num1, char * num2, int x1, int x2)
{
	int j1 = (x1 + (strlen(num1) * 2) - 1);
	int j2 = (x2 + (strlen (num2) * 2) - 1);
	char * pt1 = num1;
	char * pt2 = num2;
	char * resultado = (char *)malloc (sizeof (char));
	for (; *pt1 != '\0'; pt1 ++);
	for (; *pt2 != '\0'; pt2 ++);
	if (strlen (num1) > strlen (num2))
	{
		for (pt1 --; pt1 >= num1; pt1 --)
		{
			gotoxy (j1, 8);
			printf ("%c", 140);
			if (pt2 > num2)
			{
				gotoxy (j2, 13);
				printf ("%c", 140);
			}
			Sleep (700);
			gotoxy (j1, 8);
			printf (" ");
			if (pt2 > num2)
			{
				gotoxy (j2, 13);
				printf (" ");
			}
			gotoxy (j1, 6);
			printf ("#");
			if (pt2 > num2)
			{
				gotoxy (j2, 11);
				printf("#");
			}			
			j1--;j1--;j2--;j2--;pt2--;
		}
	}else
	{
		for (pt2 --; pt2 >= num2; pt2 --)
		{
			gotoxy (j2, 13);
			printf ("%c", 140);
			if (pt1 > num1)
			{
				gotoxy (j1, 8);
				printf ("%c", 140);
			}
			Sleep (700);
			gotoxy (j2, 13);
			printf (" ");
			if (pt1 > num1)
			{
				gotoxy (j1, 8);
				printf (" ");
			}
			gotoxy (j2, 11);
			printf ("#");
			if (pt1 > num1)
			{
				gotoxy (j1, 6);
				printf("#");
			}			
			j1--;j1--;j2--;j2--;pt1--;
		}
	}
}