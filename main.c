#include <stdio.h>
#include "lista.h"

int main(void) {
  int x;
  char v;
  Lista *l;

  l = criar_lista();

  adicionar_final(l, 'R');
  adicionar_final(l, 'A');
  adicionar_final(l, 'F');
  adicionar_final(l, 'A');

  imprimir_lista(l);

  adicionar_final(l, 'E');
  adicionar_final(l, 'L');

  imprimir_lista(l);

  adicionar_inicio(l, 'W');
  adicionar_inicio(l, 'X');
  adicionar_inicio(l, 'Y');

  imprimir_lista(l);

  x = buscar_valor(l, 'E');
  printf("Letra E encontrada na posição %d\n", x);

  v = acessar_posicao(l, 3);
  printf("Valor da posição 3: %c\n", v);

  v = acessar_posicao(l, 0);
  printf("Valor da posição 0: %c\n", v);

  v = acessar_posicao(l, 10);
  printf("Valor da posição 10: %c\n", v);

  x = tamanho_lista(l);
  printf("Tamanho da lista: %d\n", x);

  imprimir_lista(l);

  remover(l, 2);
  imprimir_lista(l);
  remover(l, 0);
  imprimir_lista(l);
  remover(l, 6);
  imprimir_lista(l);
  remover(l, 0);
  remover(l, 0);
  remover(l, 0);
  remover(l, 0);
  remover(l, 0);
  remover(l, 0);

  imprimir_lista(l);

  adicionar_final(l, 'W');
  imprimir_lista(l);
  adicionar_inicio(l, 'X');
  adicionar_inicio(l, 'Y');

  imprimir_lista(l);

  x = tamanho_lista(l);
  printf("Tamanho da lista: %d\n", x);

  adicionar_meio(l, 1, 'R');

  imprimir_lista(l); // saída correta: [ Y R X W ]

  liberar_lista(l);

  return 0;
}