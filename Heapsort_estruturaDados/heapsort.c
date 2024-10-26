#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LEN 100

typedef struct {
    int valores[LEN];
    int qtde;
} heap;


void trocar(int* i, int* j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

void Heapify(int v[], int n, int i) {
    int l = 2 * i + 1; // esuqerda
    int r = 2 * i + 2; // direita

    int maior = 0;


    if (l < n && v[l] > v[i]) {
        maior = l;
    }
    else {
        maior = i;
    }
    if (r < n && v[r] > v[maior]) {
        maior = r;
    }

    if (maior != i) {
        trocar(&v[i], &v[maior]);
        Heapify(v, n, i);
    }
}

void buildHeap(int v[], int n) {
    int ini = (n / 2) - 1; // ultimo pai
    //verifica se todos nao folhas tem propriedade de heap
    for (int i = ini; i > 0; i--) {
        Heapify(v, n, i - 1);
    }
}

void HeapSort(heap* h) {
    int* v = h->valores;
    int n = h->qtde;
    buildHeap(v, n);
    for (int i = n; i > 0; i--) {
        trocar(&v[0], &v[i]);
        Heapify(v, i, 0);
    }
}

void inserir(heap* h, int valor) {
    h->valores[h->qtde] = valor;
    h->qtde++;
    HeapSort(h);

}

void remover(heap* h) {
    h->valores[0] = h->valores[h->qtde - 1];
    h->qtde--;
    HeapSort(h);

}

void mostrar(heap* h) {
    for (int i = 0; i < h->qtde; i++) {
        printf("%d ", h->valores[i]);
    }
    printf("\n");
}

int main(void) {
    heap* h = malloc(sizeof(heap));
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