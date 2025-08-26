#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];               // fd[0] = lectura, fd[1] = escritura
    char buffer[100];        // donde el padre guardará lo que lee

    pipe(fd);     // crear la tubería

    printf("\n%d, %d\n", fd[0], fd[1]);

    if (fork() == 0) {       // aquí entra el HIJO
        close(fd[0]);        // el hijo no lee, así que cierra el extremo de lectura

        char msg[] = "Hola papá, soy tu hijo";
        write(fd[1], msg, strlen(msg) + 1);  // escribe en la tubería
        close(fd[1]);        // cierra el extremo de escritura
    } else {                 // aquí entra el PADRE
        close(fd[1]);        // el padre no escribe, así que cierra el extremo de escritura

        read(fd[0], buffer, sizeof(buffer)); // lee lo que escribió el hijo
        printf("El padre recibió: %s\n", buffer);
        close(fd[0]);        // cierra el extremo de lectura
    }

    return 0;
}