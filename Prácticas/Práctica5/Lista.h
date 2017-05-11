#define TRUE 1
#define FALSE 0
#define TAM 25

//Estructura elemento (Modificable por el usuario)
typedef struct elemento
{
	char c[TAM];
	char id;
}elemento;

//Tipo de dato boolean (Modelado con un char)
typedef unsigned char boolean;

//Estructura de un NODO DOBLEMENTE LIGADO(No modificar)
typedef struct nodo
{
	elemento e;	
	struct nodo *adelante;	
	struct nodo *atras;

}nodo;

//Estructura lista
typedef struct lista
{
	nodo *frente;
	nodo *final;
	int tam;
}lista;

//Definición de una posición
typedef nodo* posicion;

//Operaciones de construcción
void Initialize(lista *l);
void Destroy(lista *l);

//Operaciones de posicionamiento y busqueda
posicion Final(lista *l);
posicion First(lista *l);
posicion Following(lista *l, posicion p);
posicion Previus(lista *l, posicion p);
posicion Search(lista *l, elemento e);

//Operaciones de consulta
elemento Position(lista *l, posicion p);
boolean ValidatePosition(lista *l, posicion p);
elemento Element(lista *l, int n);
posicion ElementPosition(lista *l, int n);
int Size(lista *l);
boolean Empty(lista *l);

//Operaciones de modificación
void Insert(lista *l, elemento e, posicion p,boolean b);
void Add(lista *l,elemento e);
void Remove(lista *l,posicion p);
void Replace(lista *l,posicion p, elemento e);