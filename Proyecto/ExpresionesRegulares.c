#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

void creacionAlfabeto(char a[], char b[]);
int verificacionAlfabeto(char inicio, char final);
void recibirCadenas(char inicio, char final, char expresion[]);
int validarCadena(char p0[],char inicio,char final);
int validarExpresion(char expresion[], char c[]);
int verificacionExpresion(char inicio, char final, char expresion[], int x);

int main(int argc, char *argv[]) 
{
	char alfabeto[TAM],expresion[TAM];
	printf("\nEjemplo de alfabeto (Solo Letras y Numeros): A-Z\n\n");
	printf("\nDigite el alfabeto:\t");
	scanf("%s",alfabeto);
	system("cls");
	printf("\nEjemplo de expresion regular: (a|b)*");
	printf("\n\n\nDigite la expresi%cn regular:\t");
	scanf("%s",expresion);
	creacionAlfabeto(alfabeto,expresion);
	return 0;
}

void creacionAlfabeto(char alfabeto[], char expresion[])
{
	int x, y;
	char *pt = alfabeto;
	char final,inicio = *pt;
	for(;*pt!='\0';pt++);
	pt--;
	final = *pt;
	x = verificacionAlfabeto(inicio, final);
	y = verificacionExpresion(inicio, final, expresion, x);
	if(y!=0)
	{
		system("cls");
	}else
	{
		printf("ERROR: La expresion regular no corresponde al alfabeto.");
		exit(0);
	}
	if(x!=0)
	{
		system("cls");
		recibirCadenas(inicio, final, expresion);		
	}else
	{
		system("cls");
		printf("ERROR: El alfabeto solo acepta numeros y letras.\n\nEJEMPLO:\tA-Z");
	}
}

int verificacionAlfabeto(char inicio, char final)
{
	int x=1;
	if(inicio<='z'&&inicio>='a'&&final<='z'&&final>='a'&&final!=inicio)
	{
		return x;		//LETRAS MINUSCULAS
	}else if(inicio<='Z'&&inicio>='A'&&final<='Z'&&final>='A'&&final!=inicio)
	{
		return x=2;		//LETRAS MAYUSCULAS
	}else if(inicio<='9'&&inicio>='0'&&final<='9'&&final>='0'&&final!=inicio)
	{
		return x=3;		//NUMEROS
	}else
	{
		return x=0;
	}
}

void recibirCadenas(char inicio, char final, char expresion[])
{
	char p0[TAM];
	int opc,i=1,validacion,filtro;
	while(opc!=2)
	{
		printf("\n\nIntroduzca la cadena %d:\t",i++);
		scanf("%s",p0);
		validacion = validarCadena(p0,inicio,final);
		if(validacion==0)
		{
			printf("La cadena '%s' no pertenece al alfabeto '%c-%c'",p0,inicio,final);
			goto OTRA;
		}
		filtro = validarExpresion(expresion,p0);	/*AQUI SE VALIDA LA EXPRESION*/
		if(filtro!=0)
		{
			printf("\n\nLa cadena '%s' SI es valida segun la expresion '%s'.",p0,expresion);
		}else
		{
			printf("\n\nLa cadena '%s' NO es valida segun la expresion '%s'.",p0, expresion);
		}
		OTRA:
		printf("\n\n\n\n%cDesea introducir otra cadena?",168);
		printf("\n\n1.SI\t\t2.NO\t\t");
		scanf("%d",&opc);
		system("cls");
	}
}

int validarCadena(char p0[],char inicio,char final)
{
	char *pt = p0;
	int resp;
	for(;*pt!='\0';pt++)
	{
		if(*pt<=final&&*pt>=inicio)
		{
			resp = 1;
		}else
		{
			resp = 0;
			break;
		}
	}
	return resp;
}

int validarExpresion(char expresion[], char c[])
{
	int x = 1;
	char *pt = expresion;
	char *ptr = c;
	/*while(*ptr!='\0'&&*pt!='\0')
	{
		
		
		
		
		
		ptr++;
		pt++;
	}*/
	
	
	
	
	
	
	
	return x;
}

int verificacionExpresion(char inicio, char final, char expresion[], int x)
{
	int z;
	char *pt = expresion;
	if(x==1&&inicio<='z'&&inicio>='a'&&final<='z'&&final>='a')
	{
		for(;*pt!='\0';pt++)
		{
			if((*pt<=final&&*pt>=inicio)||*pt=='('||*pt=='*'||*pt=='|'||*pt==')')
			{
				z = 1;
			}else
			{
				z = 0;
				break;
			}
		}
	}else if(x==2&&inicio<='Z'&&inicio>='A'&&final<='Z'&&final>='A')
	{
		for(;*pt!='\0';pt++)
		{
			if((*pt<=final&&*pt>=inicio)||*pt=='('||*pt=='*'||*pt=='|'||*pt==')')
			{
				z = 1;
			}else
			{
				z = 0;
				break;
			}
		}
	}else if(x==3&&inicio<='9'&&inicio>='0'&&final<='9'&&final>='0')
	{
		for(;*pt!='\0';pt++)
		{
			if((*pt<=final&&*pt>=inicio)||*pt=='('||*pt=='*'||*pt=='|'||*pt==')')
			{
				z = 1;
			}else
			{
				z = 0;
				break;
			}
		}
	}else
	{
		z = 0;
	}
	return z;
}






