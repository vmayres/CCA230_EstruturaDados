#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEN 100

typedef struct Queue{
    char data[LEN];
    int head;
    int tail;
    int qdt;
} Queue;

void creat_queue(Queue *q){
    q->head = 0;
    q->tail = 0;
    q->qdt = 0;
}


void Isfull(Queue *q){
    if(q->qdt == LEN){
        printf("Fila cheia\n");
        exit(1);
    }
}

void IsEmpty(Queue *q){
    if(q->qdt == 0){
        printf("Fila vazia\n");
        exit(1);
    }
}

void enqueue(Queue *q, char c){
    Isfull(q);
    q->data[q->tail] = c;
    q->tail = (q->tail + 1) % LEN;
    q->qdt++;
}

void dequeue(Queue *q){
    IsEmpty(q);
    q->head = (q->head + 1) % LEN;
    q->qdt--;
}

void show(Queue *q){
    int i = q->head;
    for(int j = 0; j < q->qdt; j++){
        printf("%c ", q->data[i]);
        i = (i + 1) % LEN;
    }
}

int main(void) {
    char s[LEN];
    bool C = false;
    int num = 0;

    fgets(s, sizeof(s), stdin);

    // implementar
    Queue fila;
    creat_queue(&fila);
    for(int i = 0; s[i] != '\0'; i++){
        enqueue(&fila, s[i]);
    }
    int k = fila.qdt;
    for(int i = 0; i < k; i++){
        char temp = fila.data[fila.head];
        if( temp == '('){
            C = true;
            num++;
        }
        if( temp == ')' && C == true){
            num--;
        }
        if( temp == ')' && C == false){
            printf("incorreto");
            return 0;
        }

        if(num < 0){
            printf("incorreto");
            return 0;
        }
        
        dequeue(&fila);
        show(&fila);
    }
    if(num == 0){
        printf("correto");
    }
    else{
        printf("incorreto");
    }

    return 0;
}
