#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int maior_numero = 0;
    char digito1 = '0', digito2 = '0';

    for (int i = 0; linha[i] != '\0'; i++) {
      if (isdigit(linha[i])) {
        for (int j = i + 1; linha[j] != '\0'; j++) {
          if (isdigit(linha[j])) {
            char num_str[3] = {linha[i], linha[j], '\0'};
            int num = atoi(num_str);

            if (num > maior_numero) {
              maior_numero = num;
            }
          }
        }
      }
    }
    soma += maior_numero;
  }

  printf("Soma = %lld\n", soma);

  fclose(arquivo);
  return 0;
}
