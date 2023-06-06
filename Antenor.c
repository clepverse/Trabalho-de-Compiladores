#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int estado = 0;
// Função Utilizada Para Fazer as Transições Entre os Estados Para Saber se a
// Cadeia é ou não Aceita
int check(char pilha[], int tamanho) {
  estado = 0;
  int cont;
  // A S N O C D M E
  for (cont = 0; cont < tamanho; cont++) {
    if (estado == 0) {
      if (pilha[cont] == 'A' || pilha[cont] == 'C' || pilha[cont] == 'D' ||
          pilha[cont] == 'E' || pilha[cont] == 'F') {
        estado = 1;
      } else if (pilha[cont] == 'S') {
        estado = 5;
      } else if (pilha[cont] == 'N') {
        estado = 4;
      } else if (pilha[cont] == 'O') {
        estado = 3;
      } else if (pilha[cont] == 'M') {
        estado = 2;
      } else {
        return 0;
      }
    } else if (estado == 1) {
      if (pilha[cont] == 'A' || pilha[cont] == 'N' || pilha[cont] == 'O' ||
          pilha[cont] == 'C' || pilha[cont] == 'D' || pilha[cont] == 'M' ||
          pilha[cont] == 'E' || pilha[cont] == 'F') {
        estado = 1;
      } else {
        return 0;
      }
    } else if (estado == 2) {
      if (pilha[cont] == 'A' || pilha[cont] == 'C' || pilha[cont] == 'D' ||
          pilha[cont] == 'M' || pilha[cont] == 'E' || pilha[cont] == 'F') {
        estado = 1;
      } else if (pilha[cont] == 'S') {
        estado = 5;
      } else if (pilha[cont] == 'N') {
        estado = 4;
      } else if (pilha[cont] == 'O') {
        estado = 3;
      } else {
        return 0;
      }
    } else if (estado == 3) {
      if (pilha[cont] == 'A' || pilha[cont] == 'C' || pilha[cont] == 'D' ||
          pilha[cont] == 'E' || pilha[cont] == 'F') {
        estado = 1;
      } else if (pilha[cont] == 'S') {
        estado = 5;
      } else if (pilha[cont] == 'N') {
        estado = 4;
      } else if (pilha[cont] == 'O') {
        estado = 3;
      } else if (pilha[cont] == 'M') {
        estado = 2;
      } else {
        return 0;
      }
    } else if (estado == 4) {
      if (pilha[cont] == 'A' || pilha[cont] == 'O' || pilha[cont] == 'E') {
        estado = 1;
      } else if (pilha[cont] == 'S') {
        estado = 5;
      } else if (pilha[cont] == 'N') {
        estado = 4;
      } else if (pilha[cont] == 'C') {
        estado = 6;
      } else if (pilha[cont] == 'F') {
        estado = 11;
      } else if (pilha[cont] == 'D' || pilha[cont] == 'M') {
        estado = 2;
      } else {
        return 0;
      }
    } else if (estado == 5) {
      if (pilha[cont] == 'C') {
        estado = 8;
      } else if (pilha[cont] == 'F') {
        estado = 12;
      } else if (pilha[cont] == 'M' || pilha[cont] == 'D') {
        estado = 9;
      } else {
        return 0;
      }
    } else if (estado == 6) {
      if (pilha[cont] == 'A' || pilha[cont] == 'N' || pilha[cont] == 'O' ||
          pilha[cont] == 'E') {
        estado = 1;
      } else if (pilha[cont] == 'C') {
        estado = 6;
      } else if (pilha[cont] == 'F') {
        estado = 11;
      } else if (pilha[cont] == 'M' || pilha[cont] == 'D') {
        estado = 2;
      } else {
        return 0;
      }
    } else if (estado == 7) {
      if (pilha[cont] == 'M' || pilha[cont] == 'D') {
        estado = 9;
      } else if (pilha[cont] == 'S') {
        estado = 5;
      } else if (pilha[cont] == 'F') {
        estado = 12;
      } else if (pilha[cont] == 'N') {
        estado = 7;
      } else if (pilha[cont] == 'C') {
        estado = 8;
      } else {
        return 0;
      }
    } else if (estado == 8) {
      if (pilha[cont] == 'M' || pilha[cont] == 'D') {
        estado = 9;
      } else if (pilha[cont] == 'F') {
        estado = 12;
      } else {
        return 0;
      }
    } else if (estado == 9) {
      if (pilha[cont] == 'S') {
        estado = 5;
      } else if (pilha[cont] == 'N') {
        estado = 7;
      } else if (pilha[cont] == 'O') {
        estado = 10;
      } else {
        return 0;
      }
    } else if (estado == 10) {
      if (pilha[cont] == 'S') {
        estado = 5;
      } else if (pilha[cont] == 'M') {
        estado = 9;
      } else if (pilha[cont] == 'N') {
        estado = 7;
      } else if (pilha[cont] == 'O') {
        estado = 10;
      } else {
        return 0;
      }
    } else if (estado == 11) {
      if (pilha[cont] == 'A' || pilha[cont] == 'N' || pilha[cont] == 'O' ||
          pilha[cont] == 'C' || pilha[cont] == 'E' || pilha[cont] == 'F') {
        estado = 1;
      } else if (pilha[cont] == 'C') {
        estado = 6;
      } else if (pilha[cont] == 'M' || pilha[cont] == 'D') {
        estado = 2;
      } else {
        return 0;
      }
    } else if (estado == 12) {
      if (pilha[cont] == 'M' || pilha[cont] == 'D') {
        estado = 9;
      } else if (pilha[cont] == 'C') {
        estado = 8;
      } else {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  int xx = 1;
  while (xx == 1) {

    // Declaração das variáveis utilizadas
    char entrada[10];
    char palavra[11];
    int cont;
    printf("Digite uma palavra: ");
    scanf("%s", entrada);
    strncpy(palavra, entrada, 10);
    int tamanho = strlen(palavra);
    char pilha[tamanho];
    int a = 0, s = 0, n = 0, o = 0, cc = 0, d = 0, m = 0, e = 0, f = 0, md = 0;
    char alpha[] = "ABCDEFGHIJKLMNOPQRSUVabcdefghijklmnopqrsuvÁÀÂÃÄáàâãäÉÈÊËéèê"
                   "ëÍÌÏÎíìîïÓÒÕÔÖóòõôöÚÙÛÜúùûüÇç";
    char exclude[] = "TWXYZtwxyz";
    char special[] = "%$'&_=><´`^~;:,.?°ºª§| \"";
    // Identificação dos Síbolos e Computagem da Quantidade dos Mesmos
    for (cont = 0; cont < tamanho; cont++) {
      char c = palavra[cont];
      if (strchr(alpha, c)) {
        pilha[cont] = 'A';
        a++;
      } else if (strchr(exclude, c)) {
        pilha[cont] = 'S';
        s++;
      } else if (c >= '0' && c <= '9') {
        pilha[cont] = 'N';
        n++;
        if (cont != 0) {
          if (pilha[cont - 1] == 'F') {
            md++;
          }
        }

      } else if (c == '(' || c == '[' || c == '{') {
        pilha[cont] = 'O';
        o++;
      } else if (c == ')' || c == ']' || c == '}') {
        pilha[cont] = 'C';
        cc++;
      } else if (c == '!') {
        pilha[cont] = 'F';
        f++;
        if (cont != 0) {
          if (pilha[cont - 1] == 'F' || pilha[cont - 1] == 'D') {
            md++;
          }
        }

      } else if (c == '-') {
        pilha[cont] = 'M';
        m++;
        if (cont != 0) {
          if (pilha[cont - 1] == 'M' || pilha[cont - 1] == 'D') {
            md++;
          }
        }
      } else if (strchr(special, c)) {
        pilha[cont] = 'E';
        e++;
      } else if (c == '@' || c == '#' || c == '*' || c == '/' || c == '+') {
        pilha[cont] = 'D';
        d++;
        if (cont != 0) {
          if (pilha[cont - 1] == 'M' || pilha[cont - 1] == 'D') {
            md++;
          }
        }
      } else {
        printf("Identificado um caractere não permitido");
        return 0;
      }
    }
    puts(palavra);
    // Conferindo se a Cadeia é ou não Aceita
    if (a > 0 && s > 0) {
      printf("Palavra não aceita");
    } else {
      if (check(pilha, tamanho) == 1) {
        if (estado == 1 && pilha[0] != 'N') {
          printf("Palavra aceita");
        } else if (pilha[0] != 'D' && pilha[tamanho - 1] != 'O' &&
                   pilha[tamanho - 1] != 'D' && pilha[tamanho - 1] != 'M' &&
                   e == 0 && a == 0 && m + d != 0 && md == 0 && o - cc == 0 &&
                   (s != 0 || n != 0)) {
          printf("A palavra é uma expressão matemática");
        } else if (pilha[0] != 'D' && pilha[0] != 'F' &&
                   pilha[tamanho - 1] != 'O' && pilha[tamanho - 1] != 'D' &&
                   pilha[tamanho - 1] != 'M' && e == 0 && a == 0 && md == 0 &&
                   o - cc == 0 && (s != 0 || f != 0)) {
          printf("A palavra é uma expressão matemática");
        } else if (pilha[0] == 'N' && s == 0) {
          printf("Palavra reservada pelo sistema");
        } else if (s == 0) {
          printf("Palavra aceita");
        } else {
          printf("Palavra não aceita");
        }
      } else {
        printf("Palavra não aceita");
      }
    }
    printf("\n\n");
  }
  return 0;
}