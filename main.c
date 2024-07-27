#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char desc[100];
    char dueDate[100];
    int prior;
    char craDay[100];
    char estado[100];
} task;

void add(const char *filename) {
    FILE *fptr;
    fptr = fopen(filename, "a"); // Abrir en modo de añadir
    if (fptr == NULL) {
        printf("Error al abrir el archivo %s\n", filename);
        exit(1);
    }
    
    task t1;
    
    printf("Ingrese el titulo: \n");
    scanf("%s", t1.title);
    fprintf(fptr, "Titulo: %s\n", t1.title);
    
    printf("Ingrese una descripción: \n");
    scanf("%s", t1.desc);
    fprintf(fptr, "Descripcion: %s\n", t1.desc);
    
    printf("Ingrese la fecha de vencimiento: \n");
    scanf("%s", t1.dueDate);
    fprintf(fptr, "Fecha de vencimiento: %s\n", t1.dueDate);
    
    printf("Ingrese la prioridad\n");
    printf("1 -> Prioridad alta\n");
    printf("2 -> Prioridad media\n");
    printf("3 -> Prioridad baja\n");
    scanf("%d", &t1.prior);
    fprintf(fptr, "Prioridad: %d\n", t1.prior);
    
    printf("Indique la fecha en que se agrega la tarea: \n");
    scanf("%s", t1.craDay);
    fprintf(fptr, "Fecha de creación: %s\n\n", t1.craDay);
    
    fclose(fptr);
}

void edit(const char *filename){
    FILE *fptr;
    fptr = fopen(filename, "w"); // Abrir en modo de añadir
    if (fptr == NULL) {
        printf("Error al abrir el archivo %s\n", filename);
        exit(1);
    }
    
    task t1;
    int option = 0;
    
    printf("What do you wanna Edit?\n");
    printf("1 -> Title\n");
    printf("2 -> Description\n");
    printf("3 -> Due date\n");
    printf("4 -> Priority\n");
    printf("5 -> Creation date\n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        printf("write what you wanna change: \n");
        scanf("%s", t1.title);
        fprintf(fptr, "Title: %s\n", t1.title);
        break;
    case 2:
        printf("write what you wanna change: \n");
        scanf("%s", t1.desc);
        fprintf(fptr, "Description: %s\n", t1.desc);
        break;
    case 3:
        printf("write what you wanna change: \n");
        scanf("%s", t1.dueDate);
        fprintf(fptr, "Due Date: %s\n", t1.dueDate);
        break;
    case 4:
        printf("write what you wanna change: \n");
        scanf("%d", &t1.prior);
        fprintf(fptr, "Priority: %d\n", t1.prior);
        break;
    case 5:
        printf("write what you wanna change: \n");
        scanf("%s", t1.craDay);
        fprintf(fptr, "Creation day: %s\n", t1.craDay);
        break;
    default:
        break;
    }
    fclose(fptr);
    

}


void search(const char *filename){
    FILE *fptr;
    fptr = fopen(filename, "r");
    if (fptr == NULL){
        printf("the file does not exist\n");
        exit(1);
    } else {
        printf("file founded\n");
    }
}





int main() {
    char filename[100];
    
    
    int option;
    do {
        printf("What do you wanna do?\n");
        printf("Options:\n");
        printf("1.- Add a task\n");
        printf("2.- Edit a task\n");
        printf("3.- Delete a task\n");
        printf("4.- Search a task\n");
        printf("0.- Exit\n");
        
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("write de file name: \n");
                scanf("%s", filename);
                add(filename);
                break;
            case 2:
                printf("Write the file name\n");
                scanf("%s", filename);
                edit(filename);
                break;
            case 3:
                printf("Write the file name\n");
                scanf("%s", filename);
                if (remove(filename) == 0)
                {
                    printf("remove succesfully\n");
                }
                else {
                    printf("unable to delete file");
                }
                break;
            case 4:
                printf("Write the file name.\n");
                scanf("%s", filename);
                search(filename);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 0);
    
    return 0;
}
