#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "controlABM.h"
#define ELEMENTS 1000
#define S 4

                 ////////////////
                //TP FUNCTIONS//
               ////////////////


/** \brief  Inicializa todas las posiciones de la lista de peliculas
*           como vacias. Y ademas, le asigna un id diferente a cada posicion.(autoincremental)
*
* \param    ePelicula list[]
* \param    int len
* \return   (void)
*
*/
void initPelicula(ePelicula list[],int len)
{
    int i;
    int cantidadPeliculas=len+1;

    for(i=0;i<len;i++)
    {
        list[i].isEmpty=1;
        list[i].id=cantidadPeliculas;
        cantidadPeliculas=cantidadPeliculas+1;
    }

}
/**\brief Agrega un pelicula a la lista en el primer espacio vacio que encuentre, retorna 0 si
*           se pudo agregar, o -1 si no hay mas espacio.
*
* \param    ePelicula list[]
* \param    int len
* \param    char titulo[]
* \param    char fechaDeEstreno[]
* \param    float salary
* \param    int Genero
*
* \return   int space(-1 o 0)
*
*/
int addPelicula(ePelicula list[], int len, char titulo[],int Actor,int Genero,int dia,int mes,int anio)
{
    int i;
    int space=-1;

    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==1)
        {
            strncpy(list[i].titulo,titulo,51);
            list[i].fechaDeEstreno.dia=dia;
            list[i].fechaDeEstreno.mes=mes;
            list[i].fechaDeEstreno.anio=anio;
            list[i].idActor=Actor;
            list[i].idGenero=Genero;

            list[i].isEmpty=0;

            toUpperFirstLetter(list,len,i);

            space=0;
            break;
        }
    }

    return space;
}
/**\brief   Busca un id especifico en la lista y devuelve en que posicion de la lista esta y si no es
*           una posicion ocupada por ningun cliente, devuelve -1.
*
* \param    ePelicula list[]
* \param    int len
* \param    int id
*
* \return   int indexPosition
*/
int findPeliculaById(ePelicula list[], int len,int id)
{
    int i;
    int indexPosition=-1;

    for(i=0;i<len;i++)
    {
        if(list[i].id==id && list[i].isEmpty==0)
        {
            indexPosition=i;
            break;
        }
    }

    return indexPosition;
}
/**\brief  Pone un pelicula como "posicion vacia", pudiendo ser reescrita.
*          (Elimina un pelicula de la lista). Si la posicion no tiene ningun pelicula, devuelve 0.
*          De lo contrario, 1.
*
* \param    ePelicula list[]
* \param    int len
* \param    int id
*
* \return   int success
*
*/
int removePelicula(ePelicula list[], int len, int id)
{
    int find=findPeliculaById(list,len,id);
    int securityOpction;
    int success=0;

    if(find!=-1)
    {
        success=1;
        printf("Esta seguro que quiere eliminar al pelicula | %s | ?\n 1)Estoy seguro.\n 2)Volver.\n Ingrese una opcion: ",list[find].titulo);
        scanf("%d",&securityOpction);
        switch(securityOpction)
        {
            case 1:
                list[find].isEmpty=1;
                printf("\nPelicula eliminada de la lista con exito!\n\n");
            break;
            case 2:
                printf("\nVolviendo...\n\n");
            break;
            default:
                printf("\nERROR. Opcion no valida.\n\n");
            break;
        }
    }

    return success;
}

/** \brief Ordena la lista de los peliculas primero por Genero, luego alfabeticamente por apellido
*           de manera ascendente utilizando una copia de la estructura epelicula para "burbujear".
*
* \param    ePelicula list[]
* \param    int lenP
* \param    ePelicula copy[]
*
* \return   (void)
*
*/

void sortPeliculas(ePelicula list[], int lenP,ePelicula copy[])
{
    int i;
    int j;

    for(i=0;i<lenP;i++)
    {
        for(j=i+1;j<lenP;j++)
        {
            if(list[i].fechaDeEstreno.anio>list[j].fechaDeEstreno.anio)
            {
                copy[0].id=list[i].id;
                copy[0].idGenero=list[i].idGenero;
                copy[0].fechaDeEstreno.dia=list[i].fechaDeEstreno.dia;
                copy[0].fechaDeEstreno.mes=list[i].fechaDeEstreno.mes;
                copy[0].fechaDeEstreno.anio=list[i].fechaDeEstreno.anio;
                strcpy(copy[0].titulo,list[i].titulo);
                copy[0].idActor=list[i].idActor;
                copy[0].isEmpty=list[i].isEmpty;

                list[i].id=list[j].id;
                list[i].idGenero=list[j].idGenero;
                list[i].fechaDeEstreno.dia=list[j].fechaDeEstreno.dia;
                list[i].fechaDeEstreno.mes=list[j].fechaDeEstreno.mes;
                list[i].fechaDeEstreno.anio=list[j].fechaDeEstreno.anio;
                strcpy(list[i].titulo,list[j].titulo);
                list[i].idActor=list[j].idActor;
                list[i].isEmpty=list[j].isEmpty;

                list[j].id=copy[0].id;
                list[j].idGenero=copy[0].idGenero;
                list[j].fechaDeEstreno.dia=copy[0].fechaDeEstreno.dia;
                list[j].fechaDeEstreno.mes=copy[0].fechaDeEstreno.mes;
                list[j].fechaDeEstreno.anio=copy[0].fechaDeEstreno.anio;
                strcpy(list[j].titulo,copy[0].titulo);
                list[j].idActor=copy[0].idActor;
                list[j].isEmpty=copy[0].isEmpty;
            }
        }
    }
}


/**\brief Imprime toda la lista de los peliculas
*
* \param
* \param
*
* \return
*
*/

void printPeliculas(ePelicula list[],int lenP,eGenero Generos[],int lenG)
{
    int i;
    for(i=0;i<lenP;i++)
    {
        if(list[i].isEmpty==0)
        {
            printOnePelicula(list,lenP,Generos,lenG,i);
        }
    }
}




                 /////////////////////
                //ANOTHER FUNCTIONS//
               /////////////////////




/** \brief  Modifica el nombre de un pelicula en la lista
 *
 * \param   epelicula list[]
 * \param   int len
 * \param   int position
 *
 * \return  (void)
 *
 */

void modifytituloPelicula(ePelicula list[],int len, int position)
{
    char newtitulo[26];
    fflush(stdin);

    printf("Ingrese el nuevo TITULO del pelicula | %s |: ",list[position].titulo);
    gets(newtitulo);
    while(strlen(newtitulo)>25)
    {
        printf("ERROR. Ingrese el titulo nuevamente: ");
        gets(newtitulo);
    }

    strcpy(list[position].titulo,"");
    strcat(list[position].titulo,newtitulo);

    printf("\nNombre modificado exitosamente!\n");
}

/** \brief Modifica el apellido de un pelicula
 *
 * \param   ePelicula list[]
 * \param   int len
 * \param   int position
 *
 * \return  (void)
 *
 */

void modifyfechaDeEstrenoPelicula(ePelicula list[],int len, int position)
{
    int dia;
    int mes;
    int anio;

    printf("Ingrese la nueva FECHA DE ESTRENO de la pelicula |%s|\n",list[position].titulo);
    printf("Dia: ");
    scanf("%d",&dia);
    while(dia>31||dia<1)
    {
        printf("ERROR. Ingrese un dia valido: ");
        scanf("%d",&dia);
    }
    printf("Mes: ");
    scanf("%d",&mes);
    while(mes>12||mes<1)
    {
        printf("ERROR. Ingrese un mes valido: ");
        scanf("%d",&mes);
    }
    printf("Año: ");
    scanf("%d",&anio);
    while(anio>2025||anio<1800)
    {
        printf("ERROR. Ingrese un año valido: ");
        scanf("%d",&anio);
    }

    list[position].fechaDeEstreno.dia=dia;
    list[position].fechaDeEstreno.mes=mes;
    list[position].fechaDeEstreno.anio=anio;

    printf("\nFecha de estreno modificada exitosamente!\n\n");
}

/** \brief  Modifica el Genero de un pelicula
 *
 *  \param   ePelicula list[]
 *  \param   int len
 *  \param   int position
 *  \param   eGenero Generos[]
 *  \param   int lenG
 *
 * \return   (void)
 *
 */

void modifyGeneroPelicula(ePelicula list[],int lenP, int position,eGenero Generos[],int lenG)
{
    int newGenero;

    printf("Ingrese el nuevo GENERO del pelicula | %s |:\n",list[position].titulo);
    newGenero=validateGenero(Generos,lenG);
    list[position].idGenero=newGenero;

    printf("\nGenero modificado exitosamente!\n\n");
}

/** \brief  Valida si el Genero ingresado esta en la lista de Generoes validos. Y cuando
 *              se ingresa uno valido, lo devuelve(id del Genero).
 *
 * \param   eGenero Generos[]
 * \param   int lenG
 *
 * \return  int Genero
 *
 */

int validateGenero(eGenero Generos[],int lenG)
{
    int Genero;
    int i;

    for(i=0;i<lenG;i++)
    {
        printf("%d)%s\n",Generos[i].idGenero,Generos[i].descripcion);
    }
    printf("Genero: ");
    scanf("%d",&Genero);

    while(Genero>lenG || Genero<=0)
    {
        printf("ERROR. Genero no valido, ingrese nuevamente el Genero: ");
        scanf("%d",&Genero);
    }
    return Genero;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 void modifyActorPelicula(ePelicula list[],int lenP,int position,eActor Actors[],int lenA)
{
    int newActor;

    printf("Ingrese el nuevo ACTOR de la pelicula | %s |:\n",list[position].titulo);
    newActor=validateActor(Actors,lenA);
    list[position].idActor=newActor;

    printf("\nActor modificado exitosamente!\n\n");

}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


int validateActor(eActor Actors[],int lenA)
{
    int Actor;
    int i;

    for(i=0;i<lenA;i++)
    {
        printf("%d)%s\n",Actors[i].idActor,Actors[i].nombre);
    }
    printf("\n\nId Actor: ");
    scanf("%d",&Actor);

    while(Actor>lenA || Actor<=0)
    {
        printf("ERROR. Actor no valido, ingrese nuevamente el id del Actor: ");
        scanf("%d",&Actor);
    }
    return Actor;
}

/** \brief  Imprime un solo pelicula de una posicion en especifica.
 *
 * \param   ePelicula list[]
 * \param   int lenP
 * \param   eGenero Generos[]
 * \param   int lenG
 * \param   int position
 *
 * \return  (void)
 *
 */

void printOnePelicula(ePelicula list[],int lenP,eGenero Generos[],int lenG,int position)
{
    int GeneroDescription;
    GeneroDescription=searchGeneroDescription(list,Generos,lenG,position);

    printf("\t%d\t%d/%d/%d\t\t%s\t\t\t%s\n",list[position].id,list[position].fechaDeEstreno.dia,list[position].fechaDeEstreno.mes,list[position].fechaDeEstreno.anio,list[position].titulo,Generos[GeneroDescription].descripcion);
}

/** \brief  Busca la descripcion del Genero segun el id Genero del pelicula. Devuelve la posicion de "Generos" en la que
 *           esta la descripcion del Genero que le pertenece al idGenero del pelicula.
 *
 * \param   ePelicula list[]
 * \param   eGenero Generos[]
 * \param   int lenG
 * \param   int position
 *
 * \return  int i
 *
 */

 int searchGeneroDescription(ePelicula list[],eGenero Generos[],int lenG,int position)
 {
    int i;

    for(i=0;i<lenG;i++)
    {
        if(list[position].idGenero==Generos[i].idGenero)
        {
            break;
        }
    }
    return i;
 }

/** \brief Hace mayuscula la primer letra de una palabra y vuelve minusculas todas las demas
 *
 * \param   ePelicula list[]
 * \param   int len
 * \param   int position
 *
 * \return  (void)
 *
 */

 void toUpperFirstLetter(ePelicula list[],int len,int position)
 {
    int i;

    list[position].titulo[0]=toupper(list[position].titulo[0]);
    for(i=1;i<51;i++)
    {
        list[position].titulo[i]=tolower(list[position].titulo[i]);
    }
 }

 /** \brief Hardcodea una lista de 20 peliculas
  *
  * \param  ePelicula list[]
  * \param  int tam
  *
  * \return (void)
  *
  */

void hardcodePeliculaList(ePelicula list[],int tam)
{
    int i;

    char titulos[][51]= {"Avengers EndGame","Thor","Cellular","Men in Black 4","IronMan","13  Going on 30","Lucy","Nace una estrella","¿Dime con cuantos?","Guardianes de la galaxia","A perfect murder","La isla","Que paso ayer","Home Alone 3","Deadpool","Sherlock Holmes","Men in Black 3","Avengers infinity war","Grandes esperanzas","SWAT","XxX"};
    eFecha fechas[]={{20,4,2019},{10,6,2013},{2,5,2004},{10,7,2019},{5,9,2012},{7,5,2004},{9,2,2014},{8,3,2018},{4,4,2010},{20,5,2014},{6,8,1995},{3,10,2005},{5,2,2013},{6,10,2005},{7,12,2015},{5,6,2011},{2,5,2010},{6,4,2017},{8,12,1995},{11,5,1992}};
    int Genero[]={1,2,3,4,1,2,3,4,2,1,3,4,2,1,2,4,1,3,4,1};

    for(i=0; i<tam; i++)
    {
        strcpy(list[i].titulo, titulos[i]);
        list[i].fechaDeEstreno.dia=fechas[i].dia;
        list[i].fechaDeEstreno.mes=fechas[i].mes;
        list[i].fechaDeEstreno.anio=fechas[i].anio;
        list[i].isEmpty = 0;
        list[i].idGenero = Genero[i];
    }
}

/** \brief  Si no hay ningun pelicula en la lista, devuelve 0, si hay por lo menos uno, devuelve 1.
*
* \param    ePelicula list[]
* \param    int len
*
* \return   int oneE
*
*/


int onePelicula(ePelicula list[],int len)
{
    int i;
    int oneE=0;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==0)
        {
            oneE=1;
            break;
        }
    }
    return oneE;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


void printActors(eActor Actors[],int lenA)
{
    int i;
    for(i=0;i<lenA;i++)
    {
        printf("%d\t%s\t%s\n",Actors[i].idActor,Actors[i].nombre,Actors[i].nacionalidad);
    }
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


void sortActors(eActor Actors[],int lenA)
{
    eActor copy[1];
    int i;
    int j;
    int comp;

    for(i=0;i<lenA;i++)
    {
        for(j=i+1;j<lenA;j++)
        {
            comp=stricmp(Actors[i].nacionalidad,Actors[j].nacionalidad);
            if(comp>0)
            {
                copy[0].idActor=Actors[i].idActor;
                strcpy(copy[0].nombre,Actors[i].nombre);
                strcpy(copy[0].nacionalidad,Actors[i].nacionalidad);

                Actors[i].idActor=Actors[j].idActor;
                strcpy(Actors[i].nombre,Actors[j].nombre);
                strcpy(Actors[i].nacionalidad,Actors[j].nacionalidad);

                Actors[j].idActor=copy[0].idActor;
                strcpy(Actors[j].nombre,copy[0].nombre);
                strcpy(Actors[j].nacionalidad,copy[0].nacionalidad);
            }
        }
    }

}






                 //////////////////
                //MENU FUNCTIONS//
               //////////////////






/** \brief  Menu alta de peliculas
 *
 * \param   ePelicula list[]
 * \param   int lenP
 * \param   eGenero Generos[]
 * \param   int lenG
 *
 * \return void
 *
 */

void addPeliculaMenu(ePelicula list[],int lenP,eGenero Generos[],int lenG,eActor Actors[],int lenA,eFecha fechas[])
{
    int space;

    char titulo[26];
    int dia;
    int mes;
    int anio;
    int Actor;
    int Genero;

    printf("\n--MENU DE CREACION DE PELICULA--\n\n");
    fflush(stdin);
    printf("Ingrese el Titulo: ");
    gets(titulo);
    while(strlen(titulo)>25)
    {
        printf("ERROR. Ingrese nuevamente el titulo: ");
        gets(titulo);
    }

    printf("Ingrese la fecha de estreno:\n");
    printf("Dia: ");
    scanf("%d",&dia);
    while(dia>31||dia<1)
    {
        printf("ERROR. Ingrese un dia valido: ");
        scanf("%d",&dia);
    }
    printf("Mes: ");
    scanf("%d",&mes);
    while(mes>12||mes<1)
    {
        printf("ERROR. Ingrese un mes valido: ");
        scanf("%d",&mes);
    }
    printf("Año: ");
    scanf("%d",&anio);
    while(anio>2025||anio<1800)
    {
        printf("ERROR. Ingrese un año valido: ");
        scanf("%d",&anio);
    }

    printf("Ingrese el id de un actor:\n");
    Actor=validateActor(Actors,lenA);

    printf("Ingrese el Genero del pelicula:\n");
    Genero=validateGenero(Generos,lenG);

    space=addPelicula(list,ELEMENTS,titulo,Actor,Genero,dia,mes,anio);

    if(space==0)
    {
        printf("\nPelicula dada de ALTA con exito!\n\n");
    }
    else
    {
        printf("\nERROR. No hay mas lugar en la lista.\n\n");
    }
    system("pause");
}

/** \brief Menu de baja de pelicula
 *
 * \param ePelicula list[]
 * \param int len
 *
 * \return void
 *
 */

void removePeliculaMenu(ePelicula list[],int len,eGenero Generos[],int lenG)
{
    int id;
    int success;

    printf("\n--MENU DE BAJA DE pelicula--\n\n");
    printPeliculas(list,len,Generos,lenG);
    printf("Ingrese el id del pelicula que desea eliminar: ");
    scanf("%d",&id);

    success=removePelicula(list,len,id);

    if(success!=1)
    {
        printf("\nERROR. El id que ha ingresado no le pertenece a ningun pelicula en la lista.\n\n");
    }

    system("pause");
}

/** \brief Menu de modificacion de pelicula
 *
 * \param ePelicula list[]
 * \param int len
 * \param eGenero Generos[]
 * \param int lenG
 *
 * \return void
 *
 */

void modifyPeliculaMenu(ePelicula list[], int lenP,eGenero Generos[],int lenG,eActor Actors[],int lenA)
{
    int id;
    int position;
    int option;

    printf("\n--MENU DE MODIFICACION DE PELICULA--\n\n");
    printPeliculas(list,lenP,Generos,lenG);
    printf("\nIngrese el id del pelicula que desea modificar: ");
    scanf("%d",&id);

    position=findPeliculaById(list,lenP,id);

    if(position!=-1)
    {
        printf("Que desea modificar del pelicula | %s |?\n\n1)Titulo\n2)Fecha de estreno\n3)Genero\n4)Actor\n\n",list[position].titulo);
        printf("Ingrese opcion: ");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
                modifytituloPelicula(list,lenP,position);
            break;
            case 2:
                modifyfechaDeEstrenoPelicula(list,lenP,position);
            break;
            case 3:
                modifyGeneroPelicula(list,lenP,position,Generos,lenG);
            break;
            case 4:
                modifyActorPelicula(list,lenP,position,Actors,lenA);
            break;
            default:
                printf("\nERROR. Opcion no valida.\n\n");
            break;
        }
    }
    else
    {
        printf("\nERROR. El id que ha ingresado no le pertenece a ningun pelicula en la lista.\n\n");
    }
    system("pause");
}

/** \brief  Mostrar lista de peliculas e informacion que pedia el tp
 *
 * \param   ePelicula list[]
 * \param   int lenP
 * \param   eGenero Generos[]
 * \param   int lenG
 * \param   ePelicula copy[]
 *
 * \return  void
 *
 */

void showPeliculasMenu(ePelicula list[],int lenP,eGenero Generos[],int lenG,ePelicula copy[],eActor Actors[],int lenA)
{

    printf("\n--LISTA DE PELICULAS--\n\n");
    printf("\tID\tFECHA DE ESTRENO\tTITULO\t\t\tGENERO\n\n");

    sortPeliculas(list,lenP,copy);
    printPeliculas(list,lenP,Generos,lenG);

    printf("\n\n--ACTORES--\n\n");
    sortActors(Actors,lenA);
    printActors(Actors,lenA);

    system("pause");
}
