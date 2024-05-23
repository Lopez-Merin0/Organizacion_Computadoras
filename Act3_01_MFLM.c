// sumar, restar, multiplicar y dividir dos números binarios
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Esta función se utiliza para convertir un número binario representado como cadena a su equivalente entero
int binario_a_decimal(char *binario) {
    int longitud = strlen(binario);
    int decimal = 0;
    int potencia = 1;

    for (int i = longitud - 1; i >= 0; i--) {
        if (binario[i] == '1') {
            decimal += potencia;
        }
        potencia *= 2;
    }

    return decimal;
}

// Esta función se utiliza para convertir un número decimal a su equivalente binario representado como cadena
char* decimal_a_binario(int decimal) {
    char *binario = (char*)malloc(33 * sizeof(char)); // Aqui se reserva espacio para un número binario de hasta 32 bits
    if (!binario) {
        printf("Error: No se pudo asignar memoria.");
        exit(EXIT_FAILURE);
    }

    // Inicializa la cadena binaria
    binario[0] = '\0';

    if (decimal == 0) {
        strcpy(binario, "0");
    } else {
        int i = 0;
        while (decimal > 0) {
            binario[i++] = (decimal % 2) + '0';
            decimal /= 2;
        }
        binario[i] = '\0';
        strrev(binario); // Revierte la cadena binaria
    }

    return binario;
}

// Esta función se utiliza para sumar dos números binarios
char* sumar_binarios(char *bin1, char *bin2) {
    int decimal1 = binario_a_decimal(bin1);
    int decimal2 = binario_a_decimal(bin2);
    int suma = decimal1 + decimal2;
    return decimal_a_binario(suma);
}

// Esta función se utiliza para restar dos números binarios
char* restar_binarios(char *bin1, char *bin2) {
    int decimal1 = binario_a_decimal(bin1);
    int decimal2 = binario_a_decimal(bin2);
    int resta = decimal1 - decimal2;
    return decimal_a_binario(resta);
}

// Esta función se utiliza para multiplicar dos números binarios
char* multiplicar_binarios(char *bin1, char *bin2) {
    int decimal1 = binario_a_decimal(bin1);
    int decimal2 = binario_a_decimal(bin2);
    int producto = decimal1 * decimal2;
    return decimal_a_binario(producto);
}

// Esta función se utiliza para dividir dos números binarios
char* dividir_binarios(char *bin1, char *bin2) {
    int decimal1 = binario_a_decimal(bin1);
    int decimal2 = binario_a_decimal(bin2);

    if (decimal2 == 0) {
        printf("Error: No se puede dividir por cero.\n");
        exit(EXIT_FAILURE);
    }

    if (decimal1 % decimal2 != 0) {
        printf("Error: La división no es exacta.\n");
        exit(EXIT_FAILURE);
    }

    int division = decimal1 / decimal2;
    return decimal_a_binario(division);
}

int main() {
    char bin1[33];
    char bin2[33];
    char *resultado;

    // Solicita al usuario los dos números binarios
    printf("Introduce el primer número binario: ");
    scanf("%s", bin1);
    printf("Introduce el segundo número binario: ");
    scanf("%s", bin2);

    // Suma
    resultado = sumar_binarios(bin1, bin2);
    printf("Suma: %s\n", resultado);
    free(resultado);

    // Resta
    resultado = restar_binarios(bin1, bin2);
    printf("Resta: %s\n", resultado);
    free(resultado);

    // Multiplicación
    resultado = multiplicar_binarios(bin1, bin2);
    printf("Multiplicación: %s\n", resultado);
    free(resultado);

    // División
    resultado = dividir_binarios(bin1, bin2);
    printf("División: %s\n", resultado);
    free(resultado);

    return 0;
}