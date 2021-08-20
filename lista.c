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

int adicionar_inicio(Lista *l, char valor) {
  No *temp = malloc(sizeof(No));

  // se não há mais memória no computador
  if (temp == NULL) {
    return -1;
  }

  temp->valor = valor;
  temp->prox = l->primeiro;

  l->primeiro = temp;

  l->quantidade++;

  return 0;
}

int adicionar_final(Lista *l, char valor) {
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

  l->quantidade++;

  return 0;
}

int buscar_valor(Lista *l, char valor_buscado) {
  No *atual = l->primeiro;
  int i = 0;

  while (atual != NULL) {
    if (atual->valor == valor_buscado) {
      return i;
    }

    atual = atual->prox;
    i++;
  }

  return -1;
}

char acessar_posicao(Lista *l, int pos) {
  No *atual = l->primeiro;
  int i = 0;

  while (atual != NULL) {
    if (i == pos) {
      return atual->valor;
    }

    atual = atual->prox;
    i++;
  }

  return '\0';
}

int tamanho_lista(Lista *l) {
  return l->quantidade;
}

void remover(Lista *l, int pos) {
  No *anterior = NULL, *atual = l->primeiro;
  int i = 0;

  // se a lista só tiver um elemento
  if (l->quantidade == 1) {
    l->primeiro = l->ultimo = NULL;
    free(atual);

    l->quantidade--;

    return;
  }

  // se for o primeiro elemento. aser removido
  if (pos == 0) {
    // faz a lista mudar o primeiro nó para o próximo e destroi o atual (que era o primeiro)
    l->primeiro = atual->prox;
    free(atual);

    l->quantidade--;

    return;
  }

  // o "anterior" agora aponta para o primeiro e o "atual" para o segundo
  anterior = atual;
  atual = atual->prox;

  // atualiza a posição para 1 (que é a posição do "atual")
  i = 1;

  // enquanto eu não chegar no final da lista
  while (atual != NULL) {
    // achei a posição que eu procurava!
    if (i == pos) {
      // achei a aposição! vou apagar o nó!

      // se este for o último nó da lista
      if (atual->prox == NULL) {
        // faz o "ultimo" da lista apontar para o meu anterior (já que eu vou ser destruio e não posso continuar sendo o último)
        l->ultimo = anterior;
      }

      // vou ligar meu "anterior" com o meu "proximo" e me auto-destruir!
      anterior->prox = atual->prox;
      free(atual);

      l->quantidade--;

      return;
    }

    anterior = atual;
    atual = atual->prox;
    i++;
  }
}

int adicionar_meio(Lista *l, int pos, char valor) {
  printf("Não implementada\n");
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