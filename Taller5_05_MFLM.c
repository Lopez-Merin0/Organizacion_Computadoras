// Utilizando instrucciones en línea para sumar a y b en ensamblador

#include <stdio.h>

int main() {
    int a = 5, b = 7, result;

    __asm__ (
        "mov eax, %[a]\n"   // Mover el valor de a a eax
        "add eax, %[b]\n"   // Sumar el valor de b a eax
        "mov %[result], eax\n" // Mover el resultado de eax a result
        : [result] "=r" (result) // Declaración de las salidas
        : [a] "r" (a), [b] "r" (b) // Declaración de las entradas
        : "eax" // Lista de registros que se utilizan dentro del bloque de ensamblador
    );

    // Imprimir el resultado
    printf("La suma de %d y %d es: %d\n", a, b, result);

    return 0;
}
