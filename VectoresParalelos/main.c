#include <stdio.h>
#include <stdlib.h>
#define TAMANIO 5

/* Objetivo principal:
    Ordenamiento de vectores paralelos, sin importar si los datos son hardcodeados
    Ordenar con burbujeo
    1.Hacer el alta.
    2.Hacer la baja(poner todo en cero)
    3.Modificar(todos menos el legajo)
*/
float sacarPromedio(int,int);//recordar castear
void mostrarAlumnos (char [][50],int [],int [],float [],int [],int []);
void cargarAlumnos (char [][50],int [],int [],float [],int [],int []);
int buscarLugar (int [], int []);

int main()
{
    char nombre[TAMANIO][50]={"Juan","Maria","Alfredo","Jose","Lili"};
    int notasUno[TAMANIO]={4,10,2,7,2};
    int notasDos[TAMANIO]={4,8,7,8,3};
    float promedios[TAMANIO]={4,9.5,4.5,8.5,2.5};
    int legajo[TAMANIO]={111,222,333,444,555};

    cargarAlumnos(nombre,notasUno,notasDos,promedios,legajo,TAMANIO);

    mostrarAlumnos(nombre,notasUno,notasDos,promedios,legajo,TAMANIO);
    return 0;
}

void mostrarAlumnos (char nombre[][50],int primeraNota[],int segundaNota[],float promedio[],int legajo[],int largo[])
{
    int i;

    for(i=0;i<largo;i++)
    {
        printf("\nl:%d n:%s n1:%d n2:%d p:%.2f", legajo[i],nombre[i],primeraNota[i],segundaNota[i],promedio[i]);
    }
}

void cargarAlumnos (char nombre[][50],int primeraNota[],int segundaNota[],float promedio[],int legajo[],int largo[])
{
    int indice;
    indice=buscarLugar(legajo, largo);


    legajo[indice]=666;
}

int buscarLugar (int legajo[], int largo[])
{
    int i;
    int indiceRetornado=-1;

    for(i=0;i<largo;i++)
    {
        if(legajo[i]==0)
        {
            indiceRetornado=i;
            break;
        }
    }

    return indiceRetornado;
}
