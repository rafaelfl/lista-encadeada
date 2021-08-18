#include <stdio.h>
#include "lista.h"

int main(void) {
  Lista *l;

  l = criar_lista();

  adicionar_lista(l, 'R');
  adicionar_lista(l, 'A');
  adicionar_lista(l, 'F');
  adicionar_lista(l, 'A');

  imprimir_lista(l);

  adicionar_lista(l, 'E');
  adicionar_lista(l, 'L');

  imprimir_lista(l);

  liberar_lista(l);

  return 0;
}