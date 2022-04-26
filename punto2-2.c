#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct 
{
    int TareaID; //Numerado en ciclo iterativo
    char *Descripcion;
    int Duracion; // entre 10 -100
}Tarea;

void CargarTareas (Tarea **buff, int a);
void MoverTarea (Tarea **buff, int a , Tarea **Trealizada);
void MostrarTarea (Tarea **buff, int a);
void Buscar_ID (Tarea **Tpendiente, Tarea **Trealizada, int a);

int main ()
{
    srand(time(NULL));
    int CantTarea =0;
    Tarea **tarea;
    Tarea **tarea_realizada;
    tarea=(Tarea**)malloc(sizeof(Tarea*)*CantTarea);
    tarea_realizada = (Tarea**)malloc(sizeof(Tarea*)*CantTarea);
   while (CantTarea == 0)
   {
    printf("Ingrese la cantidad de tareas a cargar: ");
    scanf("%d", &CantTarea);
    fflush(stdin);
   }
    printf("\n_______________________Cargar Tareas___________________________\n");
    CargarTareas(tarea , CantTarea);
     printf("\n_______________________Mover Tareas___________________________\n");
    MoverTarea(tarea, CantTarea, tarea_realizada);
    printf("\n_______________________Tareas Realizadas________________________\n");
    MostrarTarea(tarea_realizada, CantTarea);
    printf("\n_______________________Tareas Pendientes________________________\n");
    MostrarTarea(tarea, CantTarea);
    printf("\n_______________Buscar Tarea por ID__________________________\n");
    Buscar_ID(tarea_realizada,tarea, CantTarea);
return 0;
}

void CargarTareas(Tarea **buff, int a)
{
   
    for (int i = 0; i < a ; i++)
    {
        buff[i]=(Tarea*)malloc(sizeof(Tarea));
        char AuxDescripcion[1000];
        buff[i]->TareaID= 1+ i;
        printf("Tarea numero Numero %d :", buff[i]->TareaID);
        printf("\nDescripcion de la tarea numero %d: ", buff[i]->TareaID);
        gets(AuxDescripcion);
        fflush(stdin);
        int Caracter = strlen(AuxDescripcion);
        buff[i]->Descripcion = (char*)malloc(sizeof(char)*Caracter);
        strcpy(buff[i]->Descripcion, AuxDescripcion);
        buff[i]->Duracion= 10 + rand ()%100;
        printf("\nDuracion: %d ", buff[i]->Duracion);
        printf("\n ________________________________________________________\n");
        Caracter= 0; 
    } 
}

void MoverTarea (Tarea **Tpendiente, int a, Tarea **Trealizada )
{
    char pregunta;
    for (int i = 0; i < a; i++)
    {
      printf("Tarea Numero: %d", Tpendiente[i]->TareaID);
      printf("¿La tarea fue realizada? (s o n)  ");
      scanf("%c" , &pregunta);
      fflush(stdin);
        if (pregunta == 's')
             {
                Trealizada [i]= (Tarea*)malloc(sizeof(Tarea));
                Trealizada[i]->TareaID = Tpendiente[i]->TareaID;
                Trealizada[i]->Descripcion = (char *) malloc(sizeof(char)*strlen(Tpendiente[i]->Descripcion));
                strcpy(Trealizada[i]->Descripcion, Tpendiente[i]->Descripcion);
                Trealizada[i]->Duracion = Tpendiente[i]->Duracion; 
                Tpendiente[i]=NULL;
             }
        else 
            {
                Trealizada[i] = NULL;
            }
    }
   
}

void MostrarTarea (Tarea **buff, int a)
{
    for (int i = 0; i < a; i++)
    {
       if (buff[i] != NULL)
       {
        printf("Tarea numero : %d \n ", buff[i]->TareaID);
        printf("Descripcion de la tarea:  %s \n", buff[i]->Descripcion);
        printf("Duracion %d : \n", buff[i]->Duracion);
       }  
    }
}

void Buscar_ID (Tarea **Tpendiente, Tarea **Trealizada, int a)
{
    int ID;
    printf("Ingrese el numero de la tarea que quiere buscar: \n");
    scanf("%d", &ID);
    for (int i = 0; i < a; i++)
    {
        if (Tpendiente[i] != NULL)
        {
            if (Tpendiente[i]->TareaID == ID)
            {
                printf("Tarea Numero %d \n", Tpendiente[i]->TareaID);
                printf("Descripcion : %s \n", Tpendiente[i]->Descripcion);
                printf("Duracion : %d \n", Tpendiente[i]->Duracion);
            }
        }
        else 
        {
            if (Trealizada[i] != NULL)
            {
                if (Trealizada[i]->TareaID == ID)
                {
                    printf("Tarea Numero %d \n", Trealizada[i]->TareaID);
                    printf("Descripcion : %s \n", Trealizada[i]->Descripcion);
                    printf("Duracion : %d \n", Trealizada[i]->Duracion);
                }
                
            }
            
        }
        
    }
    
}