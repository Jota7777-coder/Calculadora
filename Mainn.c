#include <stdio.h>
#include <math.h>
#include <stdint.h>


void decimalParaBinario(int num) {
    printf("Convertendo %d para binário:\n", num);
    int binario[32]; 
    int i = 0;
    
    while (num > 0) {
        binario[i] = num % 2; 
        printf("%d / 2 = %d (resto = %d)\n", num, num / 2, binario[i]);
        num = num / 2; 
        i++;
    }

    printf("Número em binário: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]); 
    }
    printf("\n\n");
}


void decimalParaOctal(int num) {
    printf("Convertendo %d para octal:\n", num);
    int octal[32]; 
    int i = 0;

    while (num > 0) {
        octal[i] = num % 8; 
        printf("%d / 8 = %d (resto = %d)\n", num, num / 8, octal[i]);
        num = num / 8; 
        i++;
    }

    printf("Número em octal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]); 
    }
    printf("\n\n");
}


void decimalParaHexadecimal(int num) {
    printf("Convertendo %d para hexadecimal:\n", num);
    char hexadecimal[32]; 
    int i = 0;

    while (num > 0) {
        int temp = num % 16;
        printf("%d / 16 = %d (resto = %d)\n", num, num / 16, temp);
        if (temp < 10) {
            hexadecimal[i] = temp + '0'; 
        } else {
            hexadecimal[i] = temp - 10 + 'A'; 
        }
        num = num / 16; 
        i++;
    }

    printf("Número em hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]); 
    }
    printf("\n\n");
}


void decimalParaBCD(int num) {
    printf("Convertendo %d para BCD:\n", num);
    int digitos[10]; 
    int i = 0;

    while (num > 0) {
        digitos[i] = num % 10; 
        printf("Dígito: %d\n", digitos[i]);
        num = num / 10; 
        i++;
    }

    printf("Número em BCD: ");
    for (int j = i - 1; j >= 0; j--) {
        printf(" ");
        
        for (int k = 3; k >= 0; k--) {
            printf("%d", (digitos[j] >> k) & 1);
        }
    }
    printf("\n\n");
}


void decimalParaComplemento2(int num) {
    printf("Convertendo %d para complemento a 2 (16 bits):\n", num);
    
    int16_t comp2 = (int16_t)num; 
    printf("Número em binário (com sinal): ");
    
    for (int i = 15; i >= 0; i--) {
        printf("%d", (comp2 >> i) & 1); 
    }
    
    printf("\n\n");
}


void floatParaBinario(float num) {
    printf("Convertendo %.6f para representação IEEE 754 (float):\n", num);
    
    union {
        float f;
        uint32_t i;
    } floatUnion;
    
    floatUnion.f = num;
    
    uint32_t bits = floatUnion.i;
    
    
    printf("Sinal: %d\n", (bits >> 31) & 1);
    
    
    printf("Expoente: ");
    for (int i = 30; i >= 23; i--) {
        printf("%d", (bits >> i) & 1);
    }
    printf("\n");

    
    int expoente = ((bits >> 23) & 0xFF) - 127;
    printf("Expoente com viés: %d\n", expoente);
    
    
    printf("Fração: ");
    for (int i = 22; i >= 0; i--) {
        printf("%d", (bits >> i) & 1);
    }
    printf("\n\n");
}


void doubleParaBinario(double num) {
    printf("Convertendo %.6lf para representação IEEE 754 (double):\n", num);
    
    union {
        double d;
        uint64_t i;
    } doubleUnion;
    
    doubleUnion.d = num;
    
    uint64_t bits = doubleUnion.i;
    
    
    printf("Sinal: %d\n", (bits >> 63) & 1);
    
   
    printf("Expoente: ");
    for (int i = 62; i >= 52; i--) {
        printf("%d", (bits >> i) & 1);
    }
    printf("\n");

    
    int expoente = ((bits >> 52) & 0x7FF) - 1023;
    printf("Expoente com viés: %d\n", expoente);
    
    
    printf("Fração: ");
    for (int i = 51; i >= 0; i--) {
        printf("%d", (bits >> i) & 1);
    }
    printf("\n\n");
}


int main() {
    int numero;
    float numFloat;
    double numDouble;

    
    printf("Digite um número decimal: ");
    scanf("%d", &numero);

    decimalParaBinario(numero);
    decimalParaOctal(numero);
    decimalParaHexadecimal(numero);
    decimalParaBCD(numero);
    decimalParaComplemento2(numero);

    
    printf("Digite um número real (float): ");
    scanf("%f", &numFloat);
    floatParaBinario(numFloat);

    printf("Digite um número real (double): ");
    scanf("%lf", &numDouble);
    doubleParaBinario(numDouble);

    return 0;
}
