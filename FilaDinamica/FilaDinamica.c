#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int valor;
    struct celula *proximo;
    struct celula *anterior;
}celula;

typedef struct fila{
    int qtd;
    celula *head;
    celula *tail;
}fila;

celula* creat_cell(int valor){
    celula *c = malloc(sizeof(celula));
    c->proximo = NULL;
    c->anterior = NULL;
    c->valor = valor;
    return c;
}

fila* creat_queue(){
    fila *f = malloc(sizeof(fila));
    f->head = NULL;
    f->tail = NULL;
    f->qtd = 0;
    return f;
}

void enqueue(fila *f, int valor){
    celula *new = creat_cell(valor);
    if(f->qtd == 0){
        f->head = new;
        f->tail = new;
    }
    else{
        new->anterior = f->tail;
        f->tail->proximo = new;
        f->tail = new;
    }
    f->qtd++;
}

int dequeue(fila *f){
    if(f->qtd == 0){
        printf("Fila vazia\n");
        return -1;
    }
    //
    int val = f->head->valor;
    celula *temp = f->head;
    //
    if(f->qtd == 1){
        f->head = NULL;
        f->tail = NULL;
        free(temp);
    }
    else{
        
        f->head = f->head->proximo;
        f->head->anterior = NULL;
        free(temp);
    }
    f->qtd--;
    return val; //retorna o proximo valor da fila
}

void print_queue(fila *f){
    celula *temp = f->head;
    while(temp != NULL){
        printf("%d ", temp->valor);
        temp = temp->proximo;
    }
    printf("\n");
}

void print_queue_reverse(fila *f){
    celula *temp = f->tail;
    while(temp != NULL){
        printf("%d ", temp->valor);
        temp = temp->anterior;
    }
    printf("\n");
}


int main(void) {
	fila *qnum1 = creat_queue();
	fila *qnum2 = creat_queue();
	fila *res = creat_queue();
	
	char num1[100];
	char num2[100];
	fgets(num1, sizeof(num1), stdin);
	fgets(num2, sizeof(num2), stdin);

	int i = 0;
	while(num1[i] != '\n'){		
		enqueue(qnum1, (int)(num1[i]) - 48);
		enqueue(qnum2, (int)(num2[i]) - 48);
		i++;
	}

    //implementar a soma
   int k = qnum1->qtd > qnum2->qtd ? qnum1->qtd : qnum2->qtd;
	while( k > 0){
        int n1 = qnum1->qtd > 0 ? dequeue(qnum1) : 0;
        int n2 = qnum2->qtd > 0 ? dequeue(qnum2) : 0;
        int soma = n1 + n2;
        enqueue(res, soma);
        k--;
    }
    celula *temp = res->tail;
    while (temp != NULL){
        if (temp->valor > 9){
            if (temp->anterior == NULL){
                celula *new = creat_cell(1);
                new->proximo = res->head;
                res->head->anterior = new;
                res->head = new;
            }
            else{
                temp->anterior->valor += 1;
            }
            temp->valor = temp->valor - 10;
        }
        temp = temp->anterior;
    }
    print_queue(res);
}