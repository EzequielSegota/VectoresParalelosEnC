#include <stdio.h>
#include <stdlib.h>
#define TAMANIO 5

void mostrarAlumnos (char [][50],int [],int [],float [],int [],int []);
void cargarAlumnos (char [][50],int [],int [],float [],int [],int []);
int buscarLugar (int [], int []);

int main()
{
    char nombre[TAMANIO][50]={"Juan","Maria","Alfredo","Jose","Lili"};
    int notasUno[TAMANIO]={0};
    int notasDos[TAMANIO]={0};
    float promedios[TAMANIO]={0};
    int legajo[TAMANIO]={0};

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
    indice=buscarLugar(legajo largo);


    legajo[1]=666;
}

int buscarLugar (int legajo[], int [])
{
    int i;
    int indiceRetornado=-1;

    for(i=0;i<TAMANIO;i++)
    {
        if(legajo[i]==0)
        {
            indiceRetornado=i
            break;
        }
    }

    return indiceRetornado;
}
