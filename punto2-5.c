#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Tarea
{
   int tareaID;
   char *Descripcion;
   int Duracion;
}Tarea;
typedef struct Nodo
{
    Tarea T;
    struct Nodo *siguiente;
}Nodo;

Nodo *CrearLista();
Nodo *CrearNodo(int a);
Tarea CrearTarea(int);
Nodo *BorrarTarea (Nodo *Lista);
void InsertarNodo (Nodo **lista , Nodo *Nuevo);
void MostrarLista(Nodo *Lista );
void *MoverTarea(Nodo **Lista, Nodo **Lrealizadas);
void BuscarPalabra (Nodo **Lpendiente, Nodo **Lrealizadas);


int main (void)
{
    srand(time(NULL));
    int CantidTarea=0;
    Nodo *TareaPendientes;
    Nodo *TareaRealizadas;
    Nodo *NuevoTarea=NULL;
    TareaPendientes=CrearLista();
    TareaRealizadas=CrearLista();
    while (CantidTarea == 0)
        {
        printf("Ingrese la cantidad de tareas :");
        scanf("%d", &CantidTarea);
        fflush(stdin);
        }
    for (int i = 0; i < CantidTarea; i++)
        {
        NuevoTarea=CrearNodo(i+1);
        InsertarNodo(&TareaPendientes, NuevoTarea);
        }
    printf("\n =========================================  TAREAS  : ===========================================\n");
    MostrarLista(TareaPendientes);
    MoverTarea(&TareaPendientes, &TareaRealizadas);
    printf("========================================= TAREA PENDIENTE: =====================================\n ");
    MostrarLista(TareaPendientes);
    printf("========================================= TAREA REALIZADA: ==================================== \n ");
    MostrarLista(TareaRealizadas);
    BuscarPalabra(&TareaPendientes, &TareaRealizadas);
    return 0;
}

Nodo *CrearLista()
{
    return NULL;    
}

Nodo *CrearNodo (int a)
{
    Nodo *NuevoNodo;
    NuevoNodo=(Nodo*)malloc(sizeof(Nodo));
    NuevoNodo->T=CrearTarea(a);
    NuevoNodo->siguiente=NULL;
    return NuevoNodo;
}

Nodo *BorrarTarea (Nodo *Lista)
{
    Nodo *aux = NULL;
    if (Lista != NULL)
    {
        aux = Lista;
        Lista = Lista->siguiente;
        aux->siguiente = NULL;
    }
    return aux;
}

Tarea CrearTarea(int a)
{
    Tarea TareaAux;
    char descrip[200];
        TareaAux.tareaID=(a);
        printf("Tarea numero %d : \n", TareaAux.tareaID);
        printf("Descripcion de la tarea: ");
        gets(descrip);
        fflush(stdin);
        TareaAux.Descripcion=(char*)malloc(sizeof(char)*strlen(descrip));
        strcpy(TareaAux.Descripcion, descrip);
        TareaAux.Duracion= rand()%100+10;
        printf("Duracion de la tarea:  %d \n", TareaAux.Duracion);
        printf("___________________________________________________________________________\n");
    return TareaAux;
}

void InsertarNodo (Nodo **lista , Nodo *Nuevo)
{
   Nuevo->siguiente=*lista;
   *lista=Nuevo;
}

void MostrarLista(Nodo *Lista)
{
        while(Lista != NULL)
        {
        printf("Numero de tarea %d : \n", Lista->T.tareaID);
        printf("Descripcion: %s \n", Lista->T.Descripcion );
        printf("Duracion de la tarea:  %d \n ", Lista->T.Duracion);
        printf("_____________________________________________________\n");
        Lista=Lista->siguiente;
        }   
}

void *MoverTarea(Nodo **Lpendiente, Nodo**Lrealizadas)
{
    char pregunta;
    Nodo *NodoAux;
    Nodo **Lista;
    Nodo *ListapendiAux=NULL;
    Lista =Lpendiente;
    while (*Lista != NULL)
    {
        NodoAux = *Lista;
        *Lista=(*Lista)->siguiente;
        printf("La tarea numero %d fue realizada ? (s/n) \n", NodoAux->T.tareaID);
        scanf("%c", &pregunta);
        fflush(stdin);
        if (pregunta == 's')
        {
          InsertarNodo(Lrealizadas, NodoAux);
          NodoAux=NULL;
          
        }
        else
        {
           InsertarNodo(&ListapendiAux, NodoAux);
           NodoAux=NULL; 
        }
    }
    *Lpendiente=ListapendiAux;
}

void BuscarPalabra (Nodo **Lpendiente, Nodo **Lrealizadas)
{
    char palabra[20];
    Nodo Aux;
    while ((*Lpendiente)->siguiente !=NULL || (*Lrealizadas)->siguiente != NULL)
    {
        printf("ingrese la palabra : ");
        gets(palabra);
        fflush(stdin);
        if (strcmp((*Lrealizadas)->T.Descripcion , palabra)== 0)
        {
            Aux.T = (*Lrealizadas)->T;
            printf("La Tarea es:\n ");
            printf("Numero de Tarea:  %d \n", Aux.T.tareaID);
            printf("Descripcion de la Tarea %c: ", Aux.T.Descripcion);
            printf("Duracion de a tarea : %d \n ", Aux.T.Duracion);
            (*Lrealizadas)=NULL;
            (*Lpendiente)=NULL;
        }
        else if (strcmp((*Lpendiente)->T.Descripcion , palabra)== 0 )
        {
            Aux.T = (*Lpendiente)->T;
            printf("La Tarea es: ");
            printf("Numero de Tarea:  %d \n", Aux.T.tareaID);
            printf("Descripcion de la Tarea : %c ", Aux.T.Descripcion);
            printf("Duracion de a tarea : %d \n ", Aux.T.Duracion);
            (*Lpendiente)=NULL;
            (*Lrealizadas)=NULL;
        }
    (*Lrealizadas)=(*Lrealizadas)->siguiente;
    (*Lpendiente)=(*Lpendiente)->siguiente;
    }

}