#include <stdio.h>
#include <stdlib.h>
#define LENGHT 5 //Los definidos no ocupan lugar en memoria, las variables si

/* Objetivo principal: ordenamiento de vectores paralelos, sin importar si los datos son hardcodeados.
    Para ordenar ls vectores tengo que mandarle todos los vectores a la funcion
   1. Hacer el alta
   2. Hacer la baja (poner todos los vectores en 0)
   3. Modificar (todo menos el legajo, modifico los demas datos a partir del legajo)
*/

void mostrarAlumnos(char [][50], int[], int[], float[], int[], int); //El ultimo int es del tamaño
int buscarLugarVacio(int[], int); // Siempre que paso un array con corchetes tengo que pasar otro int especificando el tamaño
float sacarPromedio(int, int);
void altaAlumno(char [][50], int[], int[], float[], int[], int);
void bajaAlumno(char [][50], int[], int[], float[], int[], int);
void ordenarNotaAlta(char [][50], int[], int[], float[], int[], int);
void ordenarNombre(char [][50], int[], int[], float[], int[], int);
void modificarAlumno(char [][50], int[], int[], float[], int[], int);
void ordenarLegajo(char [][50], int[], int[], float[], int[], int);
void mostrarAlumno(char [][50], int[], int[], float[], int[], int);

int main()
{
    char respuesta='s';
    int opcion=0;

    char nombre[LENGHT][50]={"Juan", "Maria", "Afredo", "Jose", "Lily"}; //Array de palabras de 50 caracteres c/u
    int notaUno[LENGHT]={4,10,2,7,2};
    int notaDos[LENGHT]={4,8,7,8,3};
    float promedio[LENGHT]={4,9.5,4.5,8.5,2.5};
    int legajo[LENGHT]={111,222,333,444,555};

    sacarPromedio(notaUno, notaDos);

    do{
        printf("1. Mostrar todos los alumnos");
        printf("\n2. Alta de alumno");
        printf("\n3. Baja de alumno");
        printf("\n4. Modificar alumno");
        printf("\n5. Ordenar alumnos por promedio de notas mas alto");
        printf("\n6. Ordenar alumnos por nombre");
        printf("\n7. Ordenar alumnos por legajo");
        printf("\n8. Mostrar alumno a partir de legajo");
        printf("\n9. Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                    mostrarAlumnos(nombre, notaUno, notaDos, promedio, legajo, LENGHT);
                    break;
            case 2:
                    altaAlumno(nombre, notaUno, notaDos, promedio, legajo, LENGHT);
                    break;
            case 3:
                    bajaAlumno(nombre, notaUno, notaDos, promedio, legajo, LENGHT);
                    break;
            case 4:
                    modificarAlumno(nombre, notaUno, notaDos, promedio, legajo, LENGHT);
                    break;
            case 5:
                    ordenarNotaAlta(nombre, notaUno, notaDos, promedio, legajo, LENGHT);
                    break;
            case 6:
                    ordenarNombre(nombre, notaUno, notaDos, promedio, legajo, LENGHT);
                    break;
            case 7:
                    ordenarLegajo(nombre, notaUno, notaDos, promedio, legajo, LENGHT);
                    break;
            case 8:
                    mostrarAlumno(nombre, notaUno, notaDos, promedio, legajo, LENGHT);
                    break;
            case 9:
                    respuesta='n';
                    break;
        }
        }while(respuesta=='s');

    return 0;
}

void mostrarAlumno(char nombre[][50], int nota1[], int nota2[], float promedio[], int legajo[], int largo)
{
    int legajoBuscado,i;

    printf("Ingrese legajo del alumno a buscar: ");
    scanf("%d",&legajoBuscado);

    for(i=0;i<largo;i++)
    {
        if(legajoBuscado==legajo[i])
        {
            printf("L: %d N:%s N1: %d N2: %d P: %.2f\n", legajo[i],nombre[i],nota1[i],nota2[i],promedio[i]);
        }
    }
}

void bajaAlumno(char nombre[][50], int nota1[], int nota2[], float promedio[], int legajo[], int largo)
{
    int legajoBuscado,i;

    printf("Ingrese legajo de alumno a dar de baja (ingrese 0 para eliminar todos): ");
    scanf("%d", &legajoBuscado);

    if(legajoBuscado==0)
    {
        for(i=0;i<largo;i++)
        {
            nota1[i]=0;
            strcpy(nombre[i],"");
            nota2[i]=0;
            promedio[i]=0;
            legajo[i]=0;
        }
    }

    for(i=0;i<largo;i++)
    {
        if(legajo[i]==legajoBuscado)
        {
            nota1[i]=0;
            strcpy(nombre[i],"");
            nota2[i]=0;
            promedio[i]=0;
            legajo[i]=0;
            break;
        }
        if(i==largo-1)
        printf("No existe alumno con dicho legajo.\n");
    }
}

void altaAlumno(char nombre[][50], int nota1[], int nota2[], float promedio[], int legajo[], int largo)
{
    int index;

    index=buscarLugarVacio(legajo, largo);

    if(index!=-1)
    {
            printf("3. Ingrese legajo\n");
            scanf("%d",&legajo[index]);
            printf("1. Ingrese primera nota: ");
            scanf("%d",&nota1[index]);
            printf("\n2. Ingrese segunda nota: ");
            scanf("%d",&nota2[index]);
            printf("4. Ingrese nombre\n");
            fflush(stdin);
            gets(nombre[index]);

            promedio[index]=sacarPromedio(nota1[index],nota2[index]);
    }
    else printf("No se pueden ingresar mas alumnos.\n");
}

void mostrarAlumnos(char nombre[][50], int primeraNota[], int segundaNota[], float promedio[], int legajo[], int largo)
{
    int i;

    for(i=0; i<largo; i++)
    {
        printf("L: %d, N: %s, N1: %d, N2: %d, P: %.2f\n\n",legajo[i],nombre[i],primeraNota[i],segundaNota[i],promedio[i]);
    }
}


int buscarLugarVacio(int legajo[],int tamanio)
{
    int indiceRetornado=-1, i;

    for(i=0;i<tamanio;i++)
    {
        if(legajo[i]==0)
        {
            indiceRetornado=i;
            break;
        }
    }

    return indiceRetornado;
}

float sacarPromedio(int nota1, int nota2)
{
    float promedio;

    promedio=(float)(nota1+nota2)/2;

    return promedio;
}

void ordenarNotaAlta(char nombre[][50], int primeraNota[], int segundaNota[], float promedio[], int legajo[], int largo)
{
    int i,j;
    float aux;
    char auxChar[largo];

    for(i=0;i<largo-1;i++)
    {
        for(j=i+1; j<largo; j++)
        {
            if(promedio[j]>promedio[i])
            {
                aux=promedio[j];
                promedio[j]=promedio[i];
                promedio[i]=aux;

                aux=primeraNota[j];
                primeraNota[j]=primeraNota[i];
                primeraNota[i]=aux;

                aux=segundaNota[j];
                segundaNota[j]=segundaNota[i];
                segundaNota[i]=aux;

                aux=legajo[j];
                legajo[j]=legajo[i];
                legajo[i]=aux;

                strcpy(auxChar, nombre[j]);
                strcpy(nombre[j], nombre[i]);
                strcpy(nombre[i], auxChar);
            }
        }
    }
}

void ordenarNombre(char nombre[][50], int primeraNota[], int segundaNota[], float promedio[], int legajo[], int largo)
{
    int i,j, comparacion=0;
    float aux;
    char auxChar[largo];

    for(i=0;i<largo-1;i++)
    {
        for(j=i+1; j<largo; j++)
        {
            comparacion=strcmp(nombre[j],nombre[i]);

            if(comparacion==-1)
            {
                aux=promedio[j];
                promedio[j]=promedio[i];
                promedio[i]=aux;

                aux=primeraNota[j];
                primeraNota[j]=primeraNota[i];
                primeraNota[i]=aux;

                aux=segundaNota[j];
                segundaNota[j]=segundaNota[i];
                segundaNota[i]=aux;

                aux=legajo[j];
                legajo[j]=legajo[i];
                legajo[i]=aux;

                strcpy(auxChar, nombre[j]);
                strcpy(nombre[j], nombre[i]);
                strcpy(nombre[i], auxChar);
            }
        }
    }
}

void modificarAlumno(char nombre[][50], int primeraNota[], int segundaNota[], float promedio[], int legajo[], int largo)
{
    int legajoBuscado,i, opcionModificar, flag=0;

    printf("Ingrese legajo de alumno a modificar: ");
    scanf("%d", &legajoBuscado);

    for(i=0;i<largo;i++)
    {
        if(legajo[i]==legajoBuscado)
        {
            flag=1;
            printf("1. Modificar primera nota\n");
            printf("2. Modificar segunda nota\n");
            printf("3. Modificar legajo\n");
            printf("4. Modificar nombre\n");

            scanf("%d",&opcionModificar);

            switch(opcionModificar)
            {
                case 1:
                        scanf("%d",&primeraNota[i]);
                        break;
                case 2:
                        scanf("%d",&segundaNota[i]);
                        break;
                case 3:
                        scanf("%d",&legajo[i]);
                        break;
                case 4:
                        {
                            fflush(stdin);
                            gets(nombre[i]);
                        }
                        break;
            }

            promedio[i]=sacarPromedio(primeraNota[i],segundaNota[i]);
            break;
        }

    }
    if(0==flag)
    printf("No existe alumno con dicho legajo.\n");
}

void ordenarLegajo(char nombre[][50], int primeraNota[], int segundaNota[], float promedio[], int legajo[], int largo)
{
    int i,j;
    float aux;
    char auxChar[largo];

    for(i=0;i<4;i++)
    {
        for(j=i+1; j<5; j++)
        {
            if(legajo[j]>legajo[i])
            {
                aux=legajo[j];
                legajo[j]=legajo[i];
                legajo[i]=aux;

                aux=primeraNota[j];
                primeraNota[j]=primeraNota[i];
                primeraNota[i]=aux;

                aux=segundaNota[j];
                segundaNota[j]=segundaNota[i];
                segundaNota[i]=aux;

                aux=promedio[j];
                promedio[j]=promedio[i];
                promedio[i]=aux;

                strcpy(auxChar, nombre[j]);
                strcpy(nombre[j], nombre[i]);
                strcpy(nombre[i], auxChar);

            }
        }
    }
}
