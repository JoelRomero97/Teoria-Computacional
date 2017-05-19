#include <stdio.h>
#include <stdlib.h>
#include "pila.c"

boolean verificarCadena (char *cadena);
typedef struct Septupla
{
	char * estados;
	char * alfabetoEntrada;
	char * alfabetoPila;
	char * estadoInicial;
	char * simboloFondoPila;
	char * estadoFinal;
}septupla;

////////////////////////////////////////////////////////////////////////////////////////
////								AutomataPila.c 									////
////																				////
////																				////
//// Automata de pila que reconoce el lenguaje que haya igual número de 0's que 	////
//// de 1's, el autómata fue diseñado personalmente y la septupla junto con la 		////
//// tabla de transiciones son obtenidas de un archivo.								////
//// Modificar: "Septupla.txt" y "TablaTransiciones.txt".							////
////																				////
////																				////
//// Autor: Romero Gamarra Joel Mauricio											////
////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[])
{
	
	return 0;
}