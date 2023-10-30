#include <stdio.h>

void deslizarJanela(int valores[], int n) {
    int resultado[n];

    printf("Valores iniciais:\n");
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            printf("%d ", valores[i]);
        } else {
            printf("%d\n", valores[i]);
        }
    }

    while (n > 1) {
        int novaLista[n];
        int novaN = 0;

        for (int i = 0; i < n; i += 2) {
            if (i + 1 < n) {
                novaLista[novaN] = valores[i] + valores[i + 1];
            } else {
                novaLista[novaN] = valores[i];
            }
            novaN++;
        }

        for (int i = 0; i < novaN; i++) {
            valores[i] = novaLista[i];
        }

        n = novaN;

        printf("\nValores após deslizar a janela:\n");
        for (int i = 0; i < n; i++) {
            if (i != n - 1) {
                printf("%d ", valores[i]);
            } else {
                printf("%d\n", valores[i]);
            }
        }
    }

    printf("Resultado final:\n");
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            printf("%d ", valores[i]);
        } else {
            printf("%d\n", valores[i]);
        }
    }
}

int main() {
    int valores[10];

    printf("Informe os 10 valores: ");

    for (int i = 0; i < 10; i++) {
        scanf("%d", &valores[i]);
    }

    printf("Processando valores...\n");
    deslizarJanela(valores, 10);

    return 0;
}