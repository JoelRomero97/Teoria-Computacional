#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

int cadena(char cadena[],char cadena1[]);
int otraVez();
void palindromo (char cadena[]);
void concatenacion(char cadena[], char cadena1[]);
char * invertir (char cadena[]);
void potencia (char cadena[], int x);
void suf_pref(char cadena[]);
void subcadena(char cadena[]);

int main(int argc, char *argv[]) 
{
	char cad[TAM],cad1[TAM],aux[TAM],aux1[TAM];
	int x,resp,i=1,num, y;
	printf("Ingrese la cadena %d:\t",i);
	scanf("%[^\n]",cad);				//ARREGLAR QUE RECIBA CADENA CON ESPACIOS
	printf("Ingrese la cadena %d:\t",i+1);
	scanf("%s",cad1);
	strcpy(aux,cad);
	strcpy(aux1,cad1);
	MENU:
	strcpy(cad,aux);
	strcpy(cad1,aux1);
	printf("%s",cad);
	system("cls");
	printf("\n\n\n\t\t\tMENU\n\n");
	printf("\n1. Palindromo.\n");
	printf("2. Longitud.\n");
	printf("3. Concatenaci%cn.\n",162);
	printf("4. Inverso o Reflejo.\n");
	printf("5. Potencia.\n");
	printf("6. Prefijos y sufijos.\n");
	printf("7. Subcadenas.\n");
	printf("8. Salir\n\n");
	scanf("%d",&resp);
	system("cls");
	switch(resp)
	{
		case 1:
			x = cadena(cad,cad1);
			if(x==1)
			{
				printf("\n");
				palindromo(cad);
			}else if(x==2)
			{
				printf("\n");
				palindromo(cad1);
			}else
			{
				printf("\n\nOpci%cn inv%clida.",162,160);
			}
			if(otraVez()!=1)
			{
				return 0;
			}else
			{
				goto MENU;
			}
			break;
		case 2:
			x = cadena(cad,cad1);
			if(x==1)
			{
				y = strlen(cad);
				printf("La longitud de la cadena es: %d",y);
			}else if(x==2)
			{
				y = strlen(cad1);
				printf("La longitud de la cadena es: %d",y);
			}else
			{
				printf("\n\nOpci%cn inv%clida.",162,160);
			}
			if(otraVez()!=1)
			{
				return 0;
			}else
			{
				goto MENU;
			}
			break;
		case 3:
			x = cadena(cad,cad1);
			if(x==1)
			{
				concatenacion(cad,cad1);
			}else if(x==2)
			{
				concatenacion(cad1,cad);
			}else
			{
				printf("\n\nOpci%cn inv%clida.",162,160);
			}
			if(otraVez()!=1)
			{
				return 0;
			}else
			{
				goto MENU;
			}
			break;
		case 4:
			x = cadena(cad,cad1);
			if(x==1)
			{
				printf("%s",invertir(cad));
			}else if(x==2)
			{
				printf("%s",invertir(cad1));
			}else
			{
				printf("\n\nOpci%cn inv%clida.",162,160);
			}
			if(otraVez()!=1)
			{
				return 0;
			}else
			{
				goto MENU;
			}
			break;
		case 5:
			x = cadena(cad,cad1);
			printf("\n\n\nDigite la potencia:\t");
			scanf("%d",&num);
			if(x==1)
			{
				potencia(cad,num);
			}else if(x==2)
			{
				potencia(cad1,num);
			}else
			{
				printf("\n\nOpci%cn inv%clida.",162,160);
			}
			if(otraVez()!=1)
			{
				return 0;
			}else
			{
				goto MENU;
			}
			break;
		case 6:
			x = cadena(cad,cad1);
			if(x==1)
			{
				suf_pref(cad);
			}else if(x==2)
			{
				suf_pref(cad1);
			}else
			{
				printf("\n\nOpci%cn inv%clida.",162,160);
			}
			if(otraVez()!=1)
			{
				return 0;
			}else
			{
				goto MENU;
			}
			break;
		case 7:
			x = cadena(cad,cad1);
			if(x==1)
			{
				subcadena(cad);
			}else if(x==2)
			{
				subcadena(cad1);
			}else
			{
				printf("\n\nOpci%cn inv%clida.",162,160);
			}
			if(otraVez()!=1)
			{
				return 0;
			}else
			{
				goto MENU;
			}
			break;
		case 8:
			return 0;
			break;
		default:
			printf("\n\nOpci%cn inv%clida.",162,160);
	}
	return 0;
}

int cadena(char cadena[],char cadena1[])
{
	int x;
	printf("%cQue cadena desea utilizar?",168);
	printf("\n\n1. %s\n",cadena);
	printf("2. %s\n\n",cadena1);
	scanf("%d",&x);
	return x;
}

int otraVez()
{
	int x;
	printf("\n\n%cDesea hacer otra operaci%cn?\n\n1.SI\t\t2.NO\n\n",168,162);
	scanf("%d",&x);
	return x;
}

void palindromo (char cadena[])
{
	char *inicio = cadena;
	char *final = cadena;
	int j;
	for(final;*final!='\0';final++);
	final--;
	for(inicio;inicio<=final;inicio++)
	{
		if(*inicio==32)
		{
			inicio++;
		}else if(*final==32)
		{
			final--;
		}else if(*inicio==*final)
		{
			j=1;
		}else
		{
			j=0;
			break;
		}
		final--;
	}
	if(j!=0)
	{
		printf("La cadena SI es un palindromo");
	}else
	{
		printf("La cadena NO es palindromo");
	}
}

void concatenacion(char cadena[], char cadena1[])
{
	char *final = cadena;
	char *inicio1 = cadena1;
	for(;*final!='\0';final++);
	for(;*inicio1!='\0';inicio1++)
	{
		*final = *inicio1;
		final++;
	}
	*final='\0';
	puts(cadena);
}

char * invertir (char cadena[])
{
	char *inicio = cadena;
	char *final = cadena;
	char aux;
	for(;*final!='\0';final++);
	final--;
	for(;inicio<=final;inicio++)
	{
		aux=*inicio;
		*inicio=*final;
		*final=aux;
		final--;
	}
	return cadena;
}

void potencia (char cadena[], int x)
{
	char *inicio = cadena;
	char *final = cadena;
	char *aux;
	int i;
	for(;*final!='\0';final++);
	if(x==0)
	{
		printf("%c",156);
		return;
	}else if(x==1)
	{
		puts(cadena);
		return;
	}else if (x>1)
	{
			FUNCION:
		for(i=1;i<x;i++)
		{
			aux = final-1;
			for(;inicio<=aux;inicio++)
			{
				*final = *inicio;
				final++;
			}
			*final='\0';
		}
	puts(cadena);
	}else
	{
		x*=-1;
		invertir(cadena);
		goto FUNCION;
	}
}

void suf_pref(char cadena[])
{
	char *pt = cadena;
	char *ptr = cadena;
	system("cls");
	printf("\n\nPREFIJOS\n\n");
	printf("%c\n",156);
	for(;*pt!='\0';pt++)
	{
		for(;ptr<=pt;ptr++)
		{
			printf("%c",*ptr);
		}
		ptr = cadena;
		printf("\n");
	}
	invertir(cadena);
	pt = cadena;
	printf("\n\nSUFIJOS\n\n");
	printf("%c\n",156);
	for(;*pt!='\0';pt++)
	{
		for(ptr = pt;*ptr!='\0';ptr--)
		{
			printf("%c",*ptr);
		}
		printf("\n");
	}
}

void subcadena(char cadena[])
{
	char *pt = cadena;
	char *ptr = cadena;
	char *aux = cadena;
	printf("\n\n\t\t\tSUBCADENAS\n\n");
	printf("%c\n",156);
	for(;*aux!='\0';aux++)
	{
		pt=aux;
		for(;*pt!='\0';pt++)
		{
			ptr = aux;
			printf("\n");
			for(;ptr<=pt;ptr++)
			{
				printf("%c",*ptr);
			}
		}
		printf("\n");
	}
}
