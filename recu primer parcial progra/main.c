#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5
typedef struct
{
    int id;
    char procesador[25];
    char marca[20];
    float precio;
} eNotebook;

float aplicarDescuento(float precio);
int contarCaracteres(char* cadena, char caracter);
void mostrarNotebook(eNotebook notebook);
void mostrarNotebooks(eNotebook lista[], int tam);
void ordenarNotebook(eNotebook lista[], int tam);


int main()
{
    /*1. Crear una función llamada aplicarDescuento que reciba como parámetro el precio de un producto
    y devuelva el valor del producto con un descuento del 5%. Realizar la llamada desde el main. */
    float precio=500;
    float precioConDescuento;
    precioConDescuento=aplicarDescuento(precio);
    printf("\nEl precio original es de %.2f y con descuento %.2f",precio,precioConDescuento);

    /*2. Crear una función que se llame contarCaracteres que reciba una cadena de caracteres como primer parámetro
    y un carácter como segundo y devuelva la cantidad de veces que ese carácter aparece en la cadena */

    char nombre[20] = "Damian";
    char caracter= 'a';
    int cantidad;
    cantidad=contarCaracteres(nombre,caracter);

    printf("\n\nLa cantidad de veces que aparece el caracter %c en el nombre %s es de %d veces\n", caracter,nombre,cantidad);


    /*3. Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita
     ordenar un array de dicha estructura por marca. Ante igualdad de marca deberá
    ordenarse por precio. Hardcodear datos y mostrarlos desde el main. */


    eNotebook notebooks[TAM]=
    {
        {1212, "AMD Ryzen 5","Acer",120000},
        {1415, "Core i9-10980XE","Asus",600000},
        {5451, "Celeron J4025 ","HP",60000},
        {4571, "Core i5-10210U","Dell",110000},
        {1815, "Pentium Silver N5030"," Lenovo",85000},
    };

    mostrarNotebooks(notebooks,TAM);
    ordenarNotebook(notebooks,TAM);
    mostrarNotebooks(notebooks,TAM);


    return 0;
}
float aplicarDescuento(float precio)
{
    float descuento;
    if(precio>0)
    {
        descuento = precio*5/100;
        precio=precio-descuento;
    }
    return precio;
}

int contarCaracteres(char* cadena, char caracter)
{
    int contadorCaracter=0;
    if(cadena!=NULL)
    {
        strlwr(cadena);
        for(int i =0; i<strlen(cadena); i++)
        {
            if(cadena[i]==caracter)
            {
                contadorCaracter++;
            }
        }
    }
    return contadorCaracter;
}

void mostrarNotebook(eNotebook notebook)
{

    printf("%d %25s %10s  %2.f\n"
           ,notebook.id
           ,notebook.procesador
           ,notebook.marca
           ,notebook.precio
          );
}



void mostrarNotebooks(eNotebook lista[], int tam)
{


    printf("                Listado de notebooks\n");
    printf("\nId              Procesador         Marca    Precio");

    for(int i=0; i<tam; i++)
    {
        mostrarNotebook(lista[i]);
    }
    printf("\n\n");
}


void ordenarNotebook(eNotebook lista[], int tam)
{
    eNotebook auxNotebook;
    for(int i=0; i<tam-1; i++ )
    {
        for(int j= i+1; j<tam; j++)
        {
            if( (strcmp(lista[i].marca,lista[j].marca)<0)|| ((strcmp(lista[i].marca,lista[j].marca)==0) && lista[i].precio<lista[j].precio) )
            {
                auxNotebook= lista[i];
                lista[i]=lista[j];
                lista[j]= auxNotebook;
            }
        }
    }
}
