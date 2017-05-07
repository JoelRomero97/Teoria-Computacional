#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

int otraVez();
void validarLicencia(char licencia[]);

////////////////////////////////////////////////////////////
////				LicenciaSoftware.c					////
////													////
////													////
//// Verifica la correcta escritura de una licencia de 	////
//// una licencia de software de acuerdo a restricciones////
//// propias, todo escrito en mayuscula, separado en 	////
//// bloques de 4 por un espacio, 16 dígitos y solo 	////
//// incluya numeros y letras mayusculas.				////
////													////
////													////
//// Autor: Romero Gamarra Joel Mauricio				////
////////////////////////////////////////////////////////////

int main()
{
	char licencia[TAM];
	int opc,x;
	while(opc!=2)
	{
		printf("\n\nIngrese la licencia:\t");
		scanf("%*c%[^\n]",licencia);
		x = strlen(licencia);
		if(x==19)
		{
			system("cls");
			validarLicencia(licencia);
		}else
		{
			printf("\n\nLa licencia '%s' es incorrecta. :(\n\n",licencia);
		}
		opc = otraVez();
	}
	return 0;
}

int otraVez()
{
	int resp;
	printf("%cDesea ingresar otra licencia?\n\n",168);
	printf("1.SI\t\t2.NO\n\n\n");
	scanf("%d",&resp);
	system("cls");
	return resp;
}

void validarLicencia(char licencia[])
{
	char *pt = licencia;
	int flag = 0;
	for (pt;*pt!='\0';pt++)
	{
		if((*pt<='Z'&&*pt>='A')||(*pt>='0'&&*pt<='9'))		//SI ES MAYUSCULA O NUMERO
		{
			flag++;
		}else if(*pt==32&&flag==4)		//SI ES UN ESPACIO
		{
			flag = 0;
		}else
		{
			break;
		}
	}
	if(flag == 4)
	{
		printf("\n\nLa licencia '%s' es correcta. :)\n\n",licencia);
	}else
	{
		printf("\n\nLa licencia '%s' es incorrecta. :(\n\n",licencia);
	}
}
