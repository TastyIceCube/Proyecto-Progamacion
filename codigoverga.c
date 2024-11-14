#include <stdio.h>
#include <string.h>

//Estructura de materias
struct Materia{
    //nombre de la materia
    char nombre[50];

    //salón
    char salon[10];

    // posibilidad de agregar hasta 10 categorias con sus respectivos nombres
    char nombreCategorias[10];

    /*Estas son las calificaciones de cada trabajo, 
    PRIMER ELEMENTO DEBE SER LA PONDERACION DE LA
    CATEGORIA SOBRE CALIFICACION FINAL Y SEGUNDO ELEMENTO EL NUMERO DE TRABAJOS*/
    float categorias[10][1000];

    //nombre de profe
    char profesor[100];

    //6 dias por semana, el primer elemento debe ser 1 si se tiene clase o 0 si no
    //Los otros 2 elementos son la hora a la que inicia y la duración de la clase
    float horario[6][3];
};


void menu(){
    printf("Seleccione una opción:\n");
    printf("1. Agregar materia\n");
    printf("2. Consultar información de las materias \n");
    printf("3. Consultar información de una materia\n");
    printf("4. Mostrar materias\n");
    printf("5. Calcular promedio de una materia/categoría\n");
    printf("6. Consultar calificaciones de una materia \n");
    printf("7. agregar tareas a realizar\n");
    printf("8. Eliminar tareas\n");
    printf("9. mostar tareas\n");
    printf("10. Salir\n");
}


//Funcion que calcula promedio general o por categorias de una materia
void promedio(struct Materia materia){
    int opcion;
    int suma;
    int promedio;
    printf("Seleccione una opción:\n");    
    printf("1. Promedio general");
    printf("2. Promedio por categorías");
    scanf("%d", &opcion);
    if (opcion == 1){
        for (int i = 0; i < 10; i++){
            for (int j=0;j< materia.categorias[i][1];j++){
                suma += materia.categorias[i][j];
                promedio += suma/materia.categorias[i][1] * materia.categorias[i][0];
            }
        }
        printf("Promedio general: %.2f\n", promedio);
    }
    else if (opcion == 2){
        for (int i = 0; i < 10; i++){
            for (int j=0;j< materia.categorias[i][1];j++){
                suma += materia.categorias[i][j];
            }
            promedio = suma/materia.categorias[i][1] * materia.categorias[i][0];
            printf("Promedio de la categoria %c: %.2f\n", materia.nombreCategorias[i], promedio);
        }
    }
}

struct Materia materias[10];
char tareas[100][1000];
int materiaelegida;
void agregar_materia(){
    int numeroMaterias = 0;
    int numeroCategorias = 0;
    printf("Ingrese el numero de materias a agregar: ");
    scanf("%d", &numeroMaterias);

    //ingresa la información esencial de las materias que se van a registrar
    for (int i = 0; i < numeroMaterias; i++) {
        printf("Ingrese el nombre de la materia: ");
        scanf("%s", materias[i].nombre);
        printf("Ingrese el salón de la materia: ");
        scanf("%s", materias[i].salon);
        printf("Ingrese el profesor de la materia: ");
        scanf("%s", materias[i].profesor);
        for (int j = 0; j < 6; j++) {
            printf("Ingrese si hay clase el dia %d (1 para si, 0 para no): ", j + 1);
            scanf("%d", &materias[i].horario[j][0]);
            if (materias[i].horario[j][0] == 1) {
                printf("Ingrese la hora de inicio de la clase en formato de 24 horas, sin am o pm, y sin :, ejemplo 1310 para 13:10: ");
                scanf("%f", &materias[i].horario[j][1]);
                printf("Ingrese la duración de la clase en horas: ");
                scanf("%f", &materias[i].horario[j][2]);
            }
        }
        printf("Ingrese el numero de categorias de la materia (no mas de 10): ");
        scanf("%d", &numeroCategorias);
        for (int j = 0; j < numeroCategorias; j++) {
            printf("Ingrese el nombre de la categoria %d: ", j + 1);
            scanf("%s", materias[i].categorias[j]);
            printf("Ingrese la ponderación de la categoria %d sobre la calificación final: ", j + 1);
            scanf("%f", &materias[i].categorias[j]);
        }
    }

}
void consultar_materias(){
    for (int i = 0; i < 10; i++){
        printf("Nombre de la materia: %s\n", materias[i].nombre);
        printf("Salón de la materia: %s\n", materias[i].salon);
        printf("Profesor de la materia: %s\n", materias[i].profesor);
        printf("Horario de la materia:\n");
        for (int j = 0; j < 6; j++) {
            if (materias[i].horario[j][0] == 1) {
                printf("Dia %d: De %d a %d\n", j + 1, materias[i].horario[j][1], materias[i].horario[j][1] + materias[i].horario[j][2]);
            }
        }
        printf("Categorias de la materia:\n");
        for (int j = 0; j < 10; j++) {
            printf("Categoria %d: %s\n", j + 1, materias[i].categorias[j]);
        }
    }
}
void mostrar_materias(){
    for (int i = 0; i < 10; i++){
        printf("Nombre de la materia: %s\n", materias[i].nombre);
    }
}
void seleccionar_materia(){            
    printf("Seleccione la materia: \n");
            for (int i = 0; i < 10; i++){
                printf("(%d) %s\n",i, materias[i].nombre);
                
                scanf("&d", &materiaelegida);
            }

}
void consultar_materia(int numMateria){
        printf("Nombre de la materia: %s\n", materias[numMateria].nombre);
        printf("Salón de la materia: %s\n", materias[numMateria].salon);
        printf("Profesor de la materia: %s\n", materias[numMateria].profesor);
        printf("Horario de la materia:\n");
        for (int j = 0; j < 6; j++) {
            if (materias[numMateria].horario[j][0] == 1) {
                printf("Dia %d: De %d a %d\n", j + 1, materias[numMateria].horario[j][1], materias[numMateria].horario[j][1] + materias[numMateria].horario[j][2]);
            }
        }
        printf("Categorias de la materia:\n");
        for (int j = 0; j < 10; j++) {
            printf("Categoria %d: %s\n", j + 1, materias[numMateria].categorias[j]);
        }

}
void consultar_calificaciones(int numMateria){
    for (int i = 0; i < 10; i++){
        printf("Categoria %d: %s\n", i + 1, materias[numMateria].categorias[i]);
        for (int j = 0; j < materias[numMateria].categorias[i][1]; j++){
            printf("Nota %d: %f\n", j + 1, materias[numMateria].categorias[i][j]);
        }
    }
}
void agregar_tareas(){
    int numeroTareas = 0;
    printf("Ingrese el numero de tareas a agregar: ");
    scanf("%d", &numeroTareas);
    for (int i = 0; i < numeroTareas; i++){
        printf("Ingrese la tarea %d: ", i + 1);
        scanf("%s", tareas[i]);
    }
}
void mostrar_tareas(){
    for (int i = 0; i < 100; i++){
        printf("Tarea %d: %s\n", i + 1, tareas[i]);
    }
}

void eliminar_tareas(){
    int numeroTareas = 0;
    printf("Ingrese el numero de tarea a eliminar: ");
    mostrar_tareas();
    scanf("%d", &numeroTareas);
    for (int i = 0; i < 1000; i++) {
        tareas[numeroTareas][i] = '\0';
    }
}


int main(){
    agregar_materia();
    int selector=1;
    while (selector!=0){
        menu();
        int opcion = 0;
        scanf("%d", &opcion);
        switch (opcion){
            case 1:
                agregar_materia();
                break;
            case 2:
                consultar_materias();
                break;
            case 3:
                seleccionar_materia();
                consultar_materia(materiaelegida);
                break;
            case 4:
                mostrar_materias();
                break;
            case 5:
                seleccionar_materia();
                promedio(materias[materiaelegida]);
                break;
            case 6:
                seleccionar_materia();
                consultar_calificaciones(materiaelegida);
                break;
            case 7:
                agregar_tareas();
                break;
            case 8:
                mostrar_tareas();
                break;
            case 9:
                eliminar_tareas();
                break;
            case 10:
                return 0;
                selector =0;
                break;
        }
    }
    return 0;
}


    



    /*
    int numMaterias, i;
    float promedio, sumaNotas, nota;

    printf("Ingrese el número de materias: ");
    scanf("%d", &numMaterias);
 //esto de aqui debe de contar a modo de ciclo cuantas materias va a registrar la persona
 //el problema es que realmente no esta generando un array con el numero de variables (quiero que quede en array para manejarlo en archivo)
    for (i = 1; i <= numMaterias; i++) {
        sumaNotas = 0;
        int numCalificaciones;

        printf("\nMateria %d:\n", i);
        printf("Ingrese el número de calificaciones: "); //esta cosa de aqui existe debido a que no pude encontrar una forma de hacer el promedio mejor (no voy a sacarme una funcion del culo ahorita)
        scanf("%d", &numCalificaciones);

        for (int j = 0; j < numCalificaciones; j++) {
            printf("Ingrese la calificación %d: ", j + 1); //se le pide al user que meta calificacion por calificacion para hacer el promedio (en teoria esto deberia ir en un array, pero no)
            scanf("%f", &nota);
            sumaNotas += nota;
        }

        promedio = sumaNotas / numCalificaciones; //promedio
        printf("Promedio de la materia %d: %.2f\n", i, promedio);

        if (promedio >= 8.0) { //grupos dependiendo de como se desempeña el wey
            printf("Desempeño: Excelente\n");
        } else if (promedio >= 5.1) {
            printf("Desempeño: Regular\n");
        } else {
            printf("Desempeño: Malo\n");
        }
    }

    return 0;*/

