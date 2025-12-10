#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encontrarMaiorNumero(const char *linha, int manter, char *resultado) {
  int tamanho = strlen(linha);
  int pos_resultado = 0;
  int inicio = 0;

  for (int i = 0; i < manter; i++) {
    char max_digito = '0';
    int max_pos = inicio;

    int limite = tamanho - (manter - i - 1);

    for (int j = inicio; j < limite; j++) {
      if (linha[j] > max_digito) {
        max_digito = linha[j];
        max_pos = j;
      }
    }

    resultado[pos_resultado++] = max_digito;
    inicio = max_pos + 1;
  }

  resultado[pos_resultado] = '\0';
}

int main() {
  FILE *arquivo;
  unsigned long long soma = 0;
  char linha[256];

  arquivo = fopen("inputs.txt", "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir arquivo\n");
    return -1;
  }

  while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    linha[strcspn(linha, "\n")] = '\0';
    int tamanho = strlen(linha);

    char resultado[256];

    if (tamanho >= 12) {
      encontrarMaiorNumero(linha, 12, resultado);
    } else {
      strcpy(resultado, linha);
    }

    printf("%s\n", resultado);
    soma += strtoull(resultado, NULL, 10);
  }

  printf("Soma = %llu\n", soma);
  fclose(arquivo);
  return 0;
}
