typedef struct
{
    int idGenero;
    char descripcion[20];

}eGenero;

typedef struct
{
    int idActor;
    char nombre[51];
    char nacionalidad[51];

}eActor;

typedef struct
{
    int id;
    char titulo[26];
    char fechaDeEstreno[12];
    int idActor;
    int idGenero;
    int isEmpty;

}ePelicula;

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;


// TP FUNCTIONS //

void initPelicula(ePelicula[],int len);
int addPelicula(ePelicula[],int len,char Titulo[],char fechaDeEstreno[],float salary,int);
int findPeliculaById(ePelicula[], int len,int id);
int removePelicula(ePelicula[], int len, int id);
void sortPeliculas(ePelicula[], int lenP,ePelicula[]);
void printPeliculas(ePelicula[], int lenP,eGenero[],int lenG);

// ANOTHER FUNCTIONS //

void modifyTituloPelicula(ePelicula[],int len, int position);
void modifyfechaDeEstrenoPelicula(ePelicula[],int len, int position);
void modifyGeneroPelicula(ePelicula[],int lenP, int position,eGenero[],int lenG);
void modifyActorPelicula(ePelicula[],int lenP,int position,eActor[],int lenA);
int validateGenero(eGenero[],int len);
int validateActor(eActor[],int lenA);
void printOnePelicula(ePelicula[],int lenP,eGenero[],int lenG,int position);
int searchGeneroDescription(ePelicula[],eGenero[],int lenG,int position);
void toUpperFirstLetter(ePelicula[],int len,int position);
void hardcodePeliculaList(ePelicula[],int len);
int onePelicula(ePelicula[],int len);
void printActors(eActor[],int len);
void sortActors(eActor[],int lenA);
void validarTitulo(ePelicula[],int lenP);

// MENU FUNCTIONS //

void addPeliculaMenu(ePelicula[],int lenP,eGenero[],int lenG,eActor[],int lenA);
void removePeliculaMenu(ePelicula[],int len);
void modifyPeliculaMenu(ePelicula[],int lenP,eGenero[],int lenG,eActor[],int lenA);
void showPeliculasMenu(ePelicula[],int lenP,eGenero[],int lenG,ePelicula[],eActor[],int lenA);

