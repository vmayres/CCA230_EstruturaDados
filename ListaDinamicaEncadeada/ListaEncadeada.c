#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
	int valor;
	struct celula *proximo;
}celula;

typedef struct {
	int qtd;
	celula *primeiro;
}lista;

lista *creat_list() {
	lista *l = malloc(sizeof(lista));
	l->primeiro = NULL;
	l->qtd = 0;
	return l;
}

celula* creat_cell(int valor) {
	celula* c = malloc(sizeof(celula));
	c->proximo = NULL;
	c->valor = valor;
	return c;
}

void insert(lista *l, int valor){
	celula* new = creat_cell(valor);
	if (l->qtd == 0) {
		l->primeiro = new;
	}
	else{
		celula* atual = l->primeiro;
		celula* anterior = NULL;
		while (atual != NULL && atual->valor < valor) {
			anterior = atual;
			atual = atual->proximo;
		}
		if (anterior == NULL) {
			new->proximo = l->primeiro;
			l->primeiro = new;
		}
		else {
			anterior->proximo = new;
			new->proximo = atual;
		}
	}
	l->qtd++;
}

void remove_cell(lista  *l, int valor) {
	celula* atual = l->primeiro;
	celula* anterior = NULL;
	while (atual != NULL && atual->valor != valor) {
		anterior = atual;
		atual = atual->proximo;
	}
	if (atual != NULL) {
		if (anterior == NULL) {
			l->primeiro = atual->proximo;
		}
		else {
			anterior->proximo = atual->proximo;
		}
		free(atual);
		l->qtd--;
	}
}

void show(lista* l) {
	celula* atual = l->primeiro;
	while (atual != NULL) {
		printf("%d ", atual->valor);
		atual = atual->proximo;
	}
	printf("\n");
}

int main(void) {
	lista* l = creat_list();
	int valores[] = {2, 1, 0, 9, 3, 8, 5, 7, 6, 4};
	// inserção
	for(int i = 0; i < 10; i++){
		insert(l, valores[i]);
		show(l);
	}
	// remoção
	for(int i = 0; i < 10; i++){
		remove_cell(l, valores[i]);
		show(l);
	}
	
	return 0;
}