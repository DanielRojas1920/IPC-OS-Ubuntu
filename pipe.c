#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];               // fd[0] = lectura, fd[1] = escritura
    char buffer[100];   // donde el padre guardará lo que lee
    char buffer_test[100];

    pipe(fd);     // crear la tubería

    if (fork() == 0) {  //Hijo
        close(fd[0]);      //Se cierra el extremo de lectura

        char msg[] = "Mensaje del hijo";
        char test[] = " Mensaje 2";
        write(fd[1], msg, strlen(msg+1));  // Manda el mensaje en el pipe
        write(fd[1], test, strlen(test) + 1);
        close(fd[1]);        // cierra el extremo de escritura
    } else {                 //Padre
        close(fd[1]);        // Se cierra el extremo de escritura

        read(fd[0], buffer, sizeof(buffer)); // lee lo que escribió el hijo
        read(fd[0], buffer_test, sizeof(buffer_test));
        printf("Mensaje recibido: %s\n", buffer);
        printf("Mensaje recibido: %s\n", buffer_test);
        close(fd[0]);        // cierra el extremo de lectura
    }


    return 0;
}