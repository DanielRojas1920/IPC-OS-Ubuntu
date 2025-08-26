#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork(); //El proceso duplicado continua la ejecuación del proceso
                        //padre desde la ejecución de fork()

    if (pid < 0) {
        printf("Error al intentar duplicar el proceso");
        return 1;
    } else if (pid == 0) {
        printf("\nProceso hijo");
    } else {
        printf("\nProceso padre\n");
    }

    return 0;
}