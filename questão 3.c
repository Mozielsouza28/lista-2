#include <stdio.h>
#include <string.h>

void somaMatrizes(int A[4][4], int B[4][4], int resultado[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            resultado[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtraiMatrizes(int A[4][4], int B[4][4], int resultado[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            resultado[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiplicaMatrizes(int A[4][4], int B[4][4], int resultado[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void imprimirMatriz(int matriz[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrizA[4][4];
    int matrizB[4][4];
    int resultado[4][4];
    char operacao[10];

    printf("Digite os elementos da matriz A (4x4):\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &matrizA[i][j]);
        }
    }

    printf("Digite os elementos da matriz B (4x4):\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &matrizB[i][j]);
        }
    }

    printf("Escolha a operação (soma, sub, mult): ");
    scanf("%s", operacao);

    if (strcmp(operacao, "soma") == 0) {
        somaMatrizes(matrizA, matrizB, resultado);
    } else if (strcmp(operacao, "sub") == 0) {
        subtraiMatrizes(matrizA, matrizB, resultado);
    } else if (strcmp(operacao, "mult") == 0) {
        multiplicaMatrizes(matrizA, matrizB, resultado);
    } else {
        printf("Operação inválida.\n");
        return 1;  // Encerra o programa com código de erro
    }

    printf("Resultado da operação:\n");
    imprimirMatriz(resultado);

    return 0;
}