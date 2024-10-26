#include <stdio.h>
#include <stdlib.h>

#define LEN 10

typedef struct {
    int valores[LEN];
    int qtde;
} heap;

int filho_esq(int pai) { return (2 * pai) + 1; }

int filho_dir(int pai) { return (2 * pai) + 2; }

int pai(int filho) { return (filho - 1) / 2; }

int ultimo_pai(heap *h) { return (h->qtde / 2) - 1; }

void trocar(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

void peneirar(heap *h, int pai) {
    int l = filho_esq(pai); // esquerda
    int r = filho_dir(pai); // direita
    int n = h->qtde;

    int maior = pai;

    if (l < n && h->valores[l] > h->valores[maior]) {
        maior = l;
    }
    if (r < n && h->valores[r] > h->valores[maior]) {
        maior = r;
    }

    if (maior != pai) {
        trocar(&h->valores[pai], &h->valores[maior]);
        peneirar(h, maior); // Recursive call with the index of the moved child
    }
}

void mostrar(heap *h) {
    for (int i = 0; i < h->qtde; i++) {
        printf("%d ", h->valores[i]);
    }
    printf("\n");
}

void construir(heap *h) {
    int ini = ultimo_pai(h); // ultimo pai
    //verifica se todos nao folhas tem propriedade de heap
    for (int i = ini; i > 0; i--) {
        peneirar(h, i-1);
    }
}

void inserir(heap *h, int valor) {
  h->valores[h->qtde] = valor;
  h->qtde++;
  
  for (int i = h->qtde; i >= 0; i--) {
    peneirar(h, i);
  }
  
  construir(h);
}

void remover(heap *h) {
    h->valores[0] = h->valores[h->qtde - 1];
    h->qtde--;

    peneirar(h, 0);
}

int main(void) {
    heap *h = malloc(sizeof(heap));
    int valor;
    h->qtde = 0;
    for (int i = 0; i < LEN; i++) {
        scanf("%d", &valor);
        inserir(h, valor);
        mostrar(h);
    }
    for (int i = 0; i < LEN; i++) {
        remover(h);
        mostrar(h);
    }

    free(h);
    return 0;
}
