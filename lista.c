#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista *criar_lista() {
  Lista *l = malloc(sizeof(Lista));
  
  l->quantidade = 0;
  l->primeiro = l->ultimo = NULL;

  return l;
}

void liberar_lista(Lista *l) {
  // aponta para o primeiro
  No *atual = l->primeiro;

  // enquanto existirem nós na lista
  while (atual != NULL) {
    // salva o endereço do proximo no
    No *proximo_no = atual->prox;

    // destroi o nó atual
    free(atual);

    // "caminha" o atual para o proximo nó
    atual = proximo_no;
  }

  // destroi a propria lista
  free(l);
}

int adicionar_lista(Lista *l, char valor) {
  No *temp = malloc(sizeof(No));

  // se não há mais memória no computador
  if (temp == NULL) {
    return -1;
  }

  temp->valor = valor;
  temp->prox = NULL;

  // a lista está vazia
  if (l->primeiro == NULL) {
    // esse nó é o primeiro da lista
    l->primeiro = temp;
  }

  // se existir um elemento na ultima posicao
  if (l->ultimo != NULL) {
    // altere o campo "prox" dele para o novo nó
    No *ultimo_no = l->ultimo;
    ultimo_no->prox = temp;
  }

  l->ultimo = temp;

  return 0;
}

void imprimir_lista(Lista *l) {
  No *atual = l->primeiro;

  printf("[");

  // enquanto atual estiver apontando para algum nó
  while (atual != NULL) {
    printf(" %c ", atual->valor);

    atual = atual->prox;
  }

  printf("]\n");

}