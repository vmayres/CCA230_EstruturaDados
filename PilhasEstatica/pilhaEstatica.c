#include <stdio.h> 
#include <stdlib.h>

#define LEN 100


typedef struct Pilha{
    int data[LEN];
    int topo;
} Pilha;

Pilha *creat_pile(){
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = 0;
    return p;
}

//add elemento no topo da pilha
void push(Pilha *p, int data){
    if(p->topo == LEN){
        printf("Pilha cheia\n");
        exit(1);
    }
    else{
        p->data[p->topo++] = data;
    }

    printf("Elemento adicionado: %d\n", data);
}

//remove elemento do topo da pilha
void pop(Pilha *p){
    int data;
    if(p->topo == 0){
        printf("Pilha vazia\n");
        exit(1);
    }
    else{
        data = p->data[--p->topo];
    }

    printf("Elemento removido: %d\n", data);    
}

void show(Pilha *p){
    printf("Topo\n");
    for(int i = p->topo - 1 ; i >=0 ; i--){
        printf("%d\n", p->data[i]);
    }
    printf("Base\n");
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