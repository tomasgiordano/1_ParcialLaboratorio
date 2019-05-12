#include <stdio.h>
#include <stdlib.h>
#include "controlABM.h"
#define ELEMENTS 1000
#define G 5
#define A 10

int main()
{
    int opcion;
    int oneE;

    ePelicula list[ELEMENTS];
    initPelicula(list,ELEMENTS);

    eGenero Generos[G]={{1,"Accion"},{2,"Comedia"},{3,"Drama"},{4,"Romance"},{5,"Terror"}};
    eActor  Actors[A]={{1,"Scarlet Johansson","Argentina"},{2,"Robert Downey Jr","EEUU"},{3,"Mark Ruffalo","Canada"},{4,"Chris Evans","EEUU"},{5,"Chris Hemsworth","Argentina"},{6,"Samuel Jackson","EEUU"},{7,"Gwyneth Paltrow","Canada"},{8,"Paul Rudd","Argentina"},{9,"Bradley Cooper","EEUU"},{10,"Josh Brolin","Canada"}};
    ePelicula copy[1];
    eFecha fecha[ELEMENTS];

    //HARDCODEAR//
    hardcodePeliculaList(list,20);
    //HARDCODEAR//

    do
    {
        oneE=onePelicula(list,ELEMENTS);

        printf("---ABM PELICULAS---\n\n");
        printf("1)Nueva Pelicula\n");
        printf("2)Modificar por id\n");
        printf("3)Borrar pelicula\n");
        printf("4)Listado de peliculas\n");
        printf("5)Salir\n");
        printf("\nIngrese opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                addPeliculaMenu(list,ELEMENTS,Generos,G,Actors,A,fecha);
            break;
            case 2:
                if(oneE)
                {
                    modifyPeliculaMenu(list,ELEMENTS,Generos,G,Actors,A);
                }
                else
                {
                    printf("\nERROR. Lista de peliculas vacia.\n");
                    system("pause");
                }
            break;
            case 3:
                if(oneE)
                {
                    removePeliculaMenu(list,ELEMENTS,Generos,G);
                }
                else
                {
                    printf("\nERROR. Lista de peliculas vacia.\n");
                    system("pause");
                }
            break;
            case 4:
                if(oneE)
                {
                    showPeliculasMenu(list,ELEMENTS,Generos,G,copy,Actors,A);
                }
                else
                {
                    printf("\nERROR. Lista de peliculas vacia.\n");
                    system("pause");
                }
            break;
            case 5:
                printf("\nHasta luego!\n\n");
                system("pause");
            break;
            default:
                printf("\nERROR. Opcion no valida.\n");
                system("pause");
            break;
        }
        system("cls");

    }while(opcion!=5);

    return 0;
}
