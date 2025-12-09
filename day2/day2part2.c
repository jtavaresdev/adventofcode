#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool sequencia_rep(long long num, long long *contador) {
  char str[25];
  sprintf(str, "%lld", num);

  int len = strlen(str);

  for (int tam = 1; tam <= len / 2; tam++) {
    if (len % tam == 0) {
      bool repete = true;
      int num_blocos = len / tam;

      for (int bloco = 1; bloco < num_blocos; bloco++) {
        for (int i = 0; i < tam; i++) {
          if (str[i] != str[bloco * tam + i]) {
            repete = false;
            break;
          }
        }
        if (!repete)
          break;
      }

      if (repete) {
        *contador += num;
        return true;
      }
    }
  }

  return false;
}
int main() {
  FILE *arquivo;
  long long num1, num2;
  char linha[1000];
  long long count = 0;

  arquivo = fopen("inputs.txt", "r");

  if (arquivo == NULL) {
    printf("Arquivo inválido\n");
    return 1;
  }

  while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    linha[strcspn(linha, "\n")] = 0;

    char *token = strtok(linha, ",");

    while (token != NULL) {
      char *separador = strchr(token, '-');
      if (separador != NULL) {
        *separador = '\0';

        num1 = atoll(token);
        num2 = atoll(separador + 1);

        for (long long i = num1; i <= num2; i++) {
          sequencia_rep(i, &count);
        }
      }
      token = strtok(NULL, ",");
    }
  }

  printf("SOMA = %lld\n", count);
  fclose(arquivo);
  return 0;
}
