// sume y reste números binarios con punto flotante
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Esta función se utiliza para convertir un número binario con punto flotante a su equivalente decimal
double binario_a_decimal(char *binario) {
    int longitud = strlen(binario);
    int punto_pos = -1; // Posición del punto decimal
    double decimal = 0.0;

    // Buscar la posición del punto decimal
    for (int i = 0; i < longitud; i++) {
        if (binario[i] == '.') {
            punto_pos = i;
            break;
        }
    }

    // Calcular la parte entera
    for (int i = 0; i < longitud; i++) {
        if (binario[i] == '.') {
            continue; // Ignorar el punto decimal
        }
        if (binario[i] == '1') {
            decimal += pow(2, punto_pos - i - 1);
        }
    }

    return decimal;
}

// Esta función se utiliza para convertir un número decimal a su equivalente binario con punto flotante
char* decimal_a_binario(double decimal, int precision) {
    char *binario = (char*)malloc((precision + 1) * sizeof(char)); // Reserva espacio para la parte binaria
    if (!binario) {
        printf("Error: No se pudo asignar memoria.");
        exit(EXIT_FAILURE);
    }

    int parte_entera = (int)decimal;
    double parte_decimal = decimal - parte_entera;

    // Convertir la parte entera a binario
    int i = 0;
    while (parte_entera > 0) {
        binario[i++] = parte_entera % 2 + '0';
        parte_entera /= 2;
    }

    // Invertir la parte entera binaria
    int longitud_entera = i;
    for (int j = 0; j < longitud_entera / 2; j++) {
        char temp = binario[j];
        binario[j] = binario[longitud_entera - j - 1];
        binario[longitud_entera - j - 1] = temp;
    }

    // Agregar el punto decimal
    binario[longitud_entera] = '.';
    i++;

    // Convertir la parte decimal a binario
    while (precision--) {
        parte_decimal *= 2;
        int bit = (int)parte_decimal;
        binario[i++] = bit + '0';
        parte_decimal -= bit;
    }

    binario[i] = '\0';

    return binario;
}

// Esta función se utiliza para sumar dos números binarios con punto flotante
char* sumar_binarios(char *bin1, char *bin2, int precision) {
    double decimal1 = binario_a_decimal(bin1);
    double decimal2 = binario_a_decimal(bin2);
    double suma = decimal1 + decimal2;
    return decimal_a_binario(suma, precision);
}

// Esta función se utiliza para restar dos números binarios con punto flotante
char* restar_binarios(char *bin1, char *bin2, int precision) {
    double decimal1 = binario_a_decimal(bin1);
    double decimal2 = binario_a_decimal(bin2);
    double resta = decimal1 - decimal2;
    return decimal_a_binario(resta, precision);
}

int main() {
    char bin1[33];
    char bin2[33];
    int precision;

    // Solicitar al usuario los dos números binarios
    printf("Introduce el primer número binario: ");
    scanf("%s", bin1);
    printf("Introduce el segundo número binario: ");
    scanf("%s", bin2);
    printf("Introduce la precision del resultado (número de dígitos decimales): ");
    scanf("%d", &precision);

    // Suma
    char *resultado_suma = sumar_binarios(bin1, bin2, precision);
    printf("Suma: %s\n", resultado_suma);
    free(resultado_suma);

    // Resta
    char *resultado_resta = restar_binarios(bin1, bin2, precision);
    printf("Resta: %s\n", resultado_resta);
    free(resultado_resta);

    return 0;
}