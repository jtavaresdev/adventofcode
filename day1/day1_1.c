#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *arquivo;
  char linha[100];

  arquivo = fopen("inputs.txt", "r");
  if (arquivo == NULL) {
    arquivo = fopen("test.txt", "r");
    if (arquivo == NULL) {
      printf("Erro ao abrir arquivo\n");
      return 1;
    }
  }

  int pos = 50;
  int p1 = 0;
  int p2 = 0;
  int linha_num = 0;

  char direction;
  int magnitude;

  while (fgets(linha, sizeof(linha), arquivo)) {
    linha[strcspn(linha, "\n")] = '\0';

    if (strlen(linha) == 0)
      continue;

    direction = linha[0];
    magnitude = atoi(linha + 1);

    int inicio = pos;

    for (int i = 0; i < magnitude; i++) {
      if (direction == 'L') {
        pos = (pos - 1 + 100) % 100;
      } else if (direction == 'R') {
        pos = (pos + 1) % 100;
      }

      if (pos == 0) {
        p2++;
      }
    }
    if (pos == 0) {
      p1++;
    }
    linha_num++;
  }
  printf("\nPart 1 (final de rotação): %d\n", p1);
  printf("\n*** PASSWORD (Part 2): %d ***\n", p2);
  fclose(arquivo);
  return 0;
}
