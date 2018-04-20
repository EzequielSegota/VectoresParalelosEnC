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
void OrdenamientoNombre(char [][50],int [],int [],float [],int [],int);

int main()
{
    char nombre[TAMANIO][50]={"Juan","Maria","Alfredo","Jose","Lili"};
    int notasUno[TAMANIO]={4,10,2,7,2};
    int notasDos[TAMANIO]={4,8,7,8,3};
    float promedios[TAMANIO]={4,9.5,4.5,8.5,2.5};
    int legajo[TAMANIO]={111,222,333,444,555};
    int opcion;
    char continuar='s';


    while(continuar=='s')
    {
        printf("\nPresione 1 para ingresar nombre\n");
        printf("\nPresione 2 para ingresar nota uno\n");
        printf("\nPresione 3 para ingresar nota dos\n");
        printf("\nPresione 4 para ingresar legajo\n");
        printf("\nPresione 5 para mostrar alumnos\n");
        printf("\nPresione 6 para ordenar por nombre\n");
        printf("\nPresione 7 para salir\n");


        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nombre);
            break;
        case 2:
            printf("Ingrese nota uno: ");

            scanf("%d",&notasUno);
            break;
        case 3:
            printf("Ingrese nota dos: ");
            scanf("%d",&notasDos);
            break;
        case 4:
            printf("Ingrese legajo: ");
            scanf("%d",&legajo);
            break;
        case 5:
            mostrarAlumnos(nombre,notasUno,notasDos,promedios,legajo,TAMANIO);
            break;
        case 6:
            OrdenamientoNombre(nombre,notasUno,notasDos,promedios,legajo,TAMANIO);
            break;
        case 7:
            continuar='n';
            break;
        }

    }

    cargarAlumnos(nombre,notasUno,notasDos,promedios,legajo,TAMANIO);
    return 0;
}

void mostrarAlumnos (char nombre[][50],int primeraNota[],int segundaNota[],float promedio[],int legajo[],int largo[])
{
    int i;

    for(i=0;i<largo;i++)
    {
        printf("\nL:%d N:%s N1:%d N2:%d P:%.2f", legajo[i],nombre[i],primeraNota[i],segundaNota[i],promedio[i]);
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

OrdenamientoNombre(char nombre[][50],int primeraNota[],int segundaNota[],float promedio[],int legajo[],int largo)
{
    int i,j,comparacion;
    float aux;
    char auxChar[largo];

    for(i=0;i<largo-1;i++)
    {
        for(j=i+1;j<largo;j++)
        {
            comparacion=strcmp(nombre[i], nombre[j]);
            if(comparacion==1)
            {
                strcpy(auxChar, nombre[j]);
                strcpy(nombre[j], nombre[i]);
                strcpy(nombre[i], auxChar);
            }
        }
    }
}
