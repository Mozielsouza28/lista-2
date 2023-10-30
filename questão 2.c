#include <stdio.h>
          #include <string.h>

          struct Jogador {
              char nome[31];
              char posicao;
              int nivel;
          };

          float calcularForca(struct Jogador time[11]) {
              float forca = 0;

              for (int i = 0; i < 11; i++) {
                  struct Jogador jogador = time[i];
                  char posicao = jogador.posicao;
                  int nivel = jogador.nivel;

                  if (posicao == 'G') {
                      forca += 8 * nivel;
                  } else if (posicao == 'L' || posicao == 'Z') {
                      forca += 10 * nivel;
                  } else if (posicao == 'V' || posicao == 'A') {
                      forca += 8 * nivel;
                  } else if (posicao == 'M') {
                      forca += 11 * nivel;
                  }
              }

              return forca / 100;
          }

          int main() {
              struct Jogador time1[11];
              struct Jogador time2[11];
              char nomeTime1[31];
              char nomeTime2[31];

              printf("Digite o nome do primeiro time: ");
              scanf(" %[^\n]", nomeTime1);

              for (int i = 0; i < 11; i++) {
                  printf("Digite o nome, posição e nível de força do jogador %d do primeiro time (separados por ponto e vírgula): ", i + 1);
                  scanf(" %[^\n]", time1[i].nome);
                  scanf(" %c", &time1[i].posicao);
                  scanf(" %d", &time1[i].nivel);
              }

              printf("Digite o nome do segundo time: ");
              scanf(" %[^\n]", nomeTime2);

              for (int i = 0; i < 11; i++) {
                  printf("Digite o nome, posição e nível de força do jogador %d do segundo time (separados por ponto e vírgula): ", i + 1);
                  scanf(" %[^\n]", time2[i].nome);
                  scanf(" %c", &time2[i].posicao);
                  scanf(" %d", &time2[i].nivel);
              }

              float forcaTime1 = calcularForca(time1);
              float forcaTime2 = calcularForca(time2);

              printf("%s: %.2f de força\n", nomeTime1, forcaTime1);
              printf("%s: %.2f de força\n", nomeTime2, forcaTime2);

              if (forcaTime1 > forcaTime2) {
                  printf("%s é mais forte\n", nomeTime1);
              } else if (forcaTime2 > forcaTime1) {
                  printf("%s é mais forte\n", nomeTime2);
              } else {
                  printf("Os times têm a mesma força\n");
              }

              return 0;
          }