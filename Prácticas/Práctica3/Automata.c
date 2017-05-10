#include <stdio.h>
#include <stdlib.h>
#define TAM 100

void pedirQuintupla();
void pedirCadenas(char expresion[]);
int validarCadena(char cadena []);

////////////////////////////////////////////////////////////////////////////////////////
////								Automata.c 										////
////																				////
////																				////
//// Automata que verifica una expresión regular en particular, (0|1)*11001* y nos 	////
//// muestra su quintupla al pedir los estados y transiciones, además, verifica 	////
//// todas las cadenas que ingrese el usuario indicando si son válidas o no depende	////
//// de la expresión regular.														////
////																				////
////																				////
//// Autor: Romero Gamarra Joel Mauricio											////
////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	pedirQuintupla();
}

void pedirQuintupla()
{
	int nEstados,nSimbolos,otra = 0,nTransicion = 1, i = 0;
	char exp[TAM],transicion[TAM];
	char *pt = transicion;
	char estadoFinal,estadoInicial;
	printf("\n\nIngrese el numero de simbolos:\t");
	scanf("%d",&nSimbolos);
	fflush(stdin);
	printf("\n\nIngrese el estado inicial:\t");
	scanf("%c",&estadoInicial);
	fflush(stdin);
	printf("\n\nIngrese el estado final:\t");
	scanf("%c",&estadoFinal);
	fflush(stdin);
	while(otra < 9)
	{
		system("cls");
		printf("Transicion numero %d",nTransicion++);
		printf("\n\nIngrese estado origen:\t");
		scanf("%c",&transicion[i++]);
		fflush(stdin);
		printf("Ingrese el simbolo:\t");
		scanf("%c",&transicion[i++]);
		fflush(stdin);
		printf("Ingrese estado destino:\t");
		scanf("%c",&transicion[i++]);
		fflush(stdin);
		otra++;
	}
	transicion[i] = '\0';
	pedirCadenas(transicion);
}

void pedirCadenas(char expresion[])
{
	int nCadena = 1, opc;
	char cadena[TAM];
	while(opc!=2)
	{
		system("cls");
		printf("Ingrese la cadena %d:\t",nCadena++);
		scanf("%s",&cadena);
		validarCadena(cadena);
		printf("\n\n%cDesea ingresar otra cadena?",168);
		printf("\n\n1.SI\t\t2.NO\n\n");
		scanf("%d",&opc);
	}
}

int validarCadena(char cadena [])
{
	char *pt = cadena;
	int flag;
	VALIDAR:
	while(*pt!='\0')
	{
		if(*pt=='1')
		{
			if(*(pt+1)=='1')
			{
				if(*(pt+2)=='0')
				{
					if(*(pt+2)=='0')
					{
						pt++;pt++;pt++;pt++;
						goto KLEENE;
					}
				}
			}
		}
		pt++;
	}
	KLEENE:
	if(*pt!='\0')
	{	
		while(*pt!='\0')
		{
			if(*pt!='1')
			{
				flag = 0;
			}else
			{
				flag = 1;
			}
			pt++;
		}
		if(flag == 1)
		{
			printf("\n\nCadena valida");
		}else
		{
			printf("\n\nCadena Invalida");
		}
	}else
	{
		printf("\n\nCadena valida");
	}
}



