
typedef struct _no {
  char valor;
  struct _no *prox;
} No;

typedef struct _lista {
  No *primeiro;
  No *ultimo;

  int quantidade;
} Lista;

Lista *criar_lista();

void liberar_lista(Lista *l);

int adicionar_final(Lista *l, char valor);

int adicionar_inicio(Lista *l, char valor);

int adicionar_meio(Lista *l, int pos, char valor);

int buscar_valor(Lista *l, char valor_buscado);

char acessar_posicao(Lista *l, int pos);

void remover(Lista *l, int pos);

int tamanho_lista(Lista *l);

void imprimir_lista(Lista *l);