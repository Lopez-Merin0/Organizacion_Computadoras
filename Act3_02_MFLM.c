//convierta un numero binario a su complemento a dos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Esta función se utiliza para invertir los bits de un número binario
void invertir_bits(char *binario) {
    int longitud = strlen(binario);
    for (int i = 0; i < longitud; i++) {
        if (binario[i] == '0') {
            binario[i] = '1';
        } else {
            binario[i] = '0';
        }
    }
}

// Esta función se utiliza para sumar 1 a un número binario
void sumar_uno(char *binario) {
    int longitud = strlen(binario);
    int carry = 1; // Inicialmente, el carry es 1 para sumar 1 al número binario
    for (int i = longitud - 1; i >= 0; i--) {
        if (carry == 0) {
            break; // Si no hay carry, termina la suma
        }
        if (binario[i] == '0') {
            binario[i] = '1';
            carry = 0; // Se lleva 1
        } else {
            binario[i] = '0';
            carry = 1; // Se lleva 1, pero continúa la suma
        }
    }
}

// Esta función se utiliza para obtener el complemento a dos de un número binario
char* complemento_a_dos(char *binario) {
    // Primero, invertimos los bits
    invertir_bits(binario);

    // Luego, sumamos 1 al resultado
    sumar_uno(binario);

    return binario;
}

int main() {
    char binario[33];
    char *resultado;

    // Solicita al usuario un número binario
    printf("Introduce un número binario: ");
    scanf("%s", binario);

    // Calcula el complemento a dos
    resultado = complemento_a_dos(binario);

    // Muestra el complemento a dos
    printf("El complemento a dos de %s es: %s\n", binario, resultado);

    return 0;
}