#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork(); //El proceso duplicado continua la ejecuación del proceso
                        //padre desde la ejecución de fork()

    if (pid < 0) { //En caso de error
        printf("Error al intentar duplicar el proceso");
        return 1;
    } else if (pid == 0) { //Proceso duplicado
        printf("\nProceso hijo");
    } else { //Proceso padre
        printf("\nProceso padre\n");
    }

    return 0;
}