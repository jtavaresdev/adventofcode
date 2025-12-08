#include <stdio.h>
#include <string.h>

int main() {
  FILE *arquivo;
  char linha[100];
  arquivo = fopen("inputs.txt", "r");

  int dial_init = 50;

  if (arquivo == NULL) {
    printf("Erro ao abrir arquivo\n");
    return 1;
  }

  char rotation;
  int magnitude;
  int count = 0;

  while (fgets(linha, sizeof(linha), arquivo)) {
    linha[strcspn(linha, "\n")] = '\0';

    rotation = linha[0];

    if (sscanf(linha + 1, "%d", &magnitude) == 1) {
      if (rotation == 'R') {
        dial_init = (dial_init + magnitude) % 100;
      } else if (rotation == 'L') {
        dial_init = (dial_init - magnitude) % 100;
        if (dial_init < 0) {
          dial_init += 100;
        }
      }

      if (dial_init == 0) {
        count++;
      }
    } else {
      printf("Erro ao ler magnitude da linha: %s\n", linha);
    }
  }

  printf("%d", count);
  fclose(arquivo);
  return 0;
}
