#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    int data;
    struct Celula *prox;
} Celula;

typedef struct Pilha{
    Celula *topo;
    int qtd;
} Pilha;

Celula *creat_cell(int data){
    Celula *c = malloc(sizeof(Celula));
    c->data = data;
    c->prox = NULL;
    return c;
}

Pilha *creat_pile(){
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = NULL;
    p->qtd = 0;
    return p;
}

void push(Pilha *p, int data){
    if(p == NULL){
        printf("Pilha nao alocada\n");
        exit(1);
    }
    Celula *nova = creat_cell(data);
    nova->prox = p->topo;
    p->topo = nova;
    p->qtd++;

    printf("Elemento adicionado: %d\n", data);
}

void pop(Pilha *p){
    if(p->topo == NULL){
        printf("Pilha vazia\n");
        exit(1);
    }
    Celula *temp = p->topo;
    p->topo = p->topo->prox;
    p->qtd--;

    printf("Elemento removido: %d\n", temp->data);
    free(temp);

}

void show(Pilha *p){
    Celula *temp = p->topo;
    printf("Topo\n");
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->prox;
    }
    printf("Base\n");
    printf("\n");
}

int main(void){
    Pilha *p = creat_pile();
    push(p, 1);
    push(p, 2);
    push(p, 3);
    push(p, 4);
    push(p, 5);
    show(p);
    printf("\n");
    for(int i = 0; i < 3; i++){
    pop(p);
    show(p);
    printf("\n");
    }

    return 0;
}

