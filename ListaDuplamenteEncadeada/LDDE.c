#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
	int valor;
	struct celula* proximo;
	struct celula* anterio;
}celula;

typedef struct lista {
	int qtd;
	celula* primeiro;
}lista;

lista* creat_list() {
	lista* l = malloc(sizeof(lista)); //alocar uma quantidade de meria para a lista
	l->primeiro = NULL;
	l->qtd = 0;
	return l;
}

celula* creat_cell(int valor) {
	celula* c = malloc(sizeof(celula)); //aloca um espa�o de memoria do tipo celula
	c->proximo = NULL;
	c->anterio = NULL;
	c->valor = valor;
	return c;
}

void inserir(lista* l, int valor) {
	celula* new = creat_cell(valor); //cria uma nova celula
	if (l->qtd == 0) {
		l->primeiro = new; //se a lista estiver vazia, aloca celula na primeira posicao
	}
	else {
		celula* atual = l->primeiro; // cria um obj tipo celula anterior e atual 
		celula* anterior = NULL;
		while (atual != NULL && atual->valor < valor) { //percorre a lista ate encontrar a posicao correta
			anterior = atual;
			atual = atual->proximo;
		}
		if (atual == NULL) {
			anterior->proximo = new; 	// se a celula for a ultima, aloca a nova celula na ultima posicao
			new->anterio = anterior; 	// a nova celula aponta para a anterior
		}
		else{
			if (anterior == NULL) {
				new->proximo = atual;
				atual->anterio = new;
				l->primeiro = new;
			}
			else {
				//anterior <-> nova
				anterior->proximo = new; 	// aponta anterio para a nova celula
				new->anterio = anterior;	// a nova aponta para anterior
				// nova <-> atual
				new->proximo = atual; 		// a nova vai apontar a atual(proxima)
				atual->anterio = new; 		// a atual(proxima) aponta para a nova
			}
		}
	}
	//aumenta tamanho da lista
	l->qtd++;

}

void remover(lista* l, int valor) {
	if (l->qtd == 0) {
		return;
	}

	celula* atual = l->primeiro;
	celula* anterior = NULL;
	while (atual != NULL && atual->valor != valor) { //percorre a lista ate encontrar a celula
		anterior = atual;
		atual = atual->proximo;
	}
	if (atual == NULL) {
		return;
	}
	else {
		if (anterior == NULL) {
		l->primeiro = atual->proximo; // remove a primeira
	} else {
		anterior->proximo = atual->proximo; // remove a do meeio e do final
	}
	if (atual->proximo != NULL) {
		atual->proximo->anterio = anterior; // atuliza a lista
	}
		free(atual); // se for a ultima (SO LIBERAR)
		l->qtd--;
	}
}



void show(lista* l) {
	celula* atual = l->primeiro;
	printf("início -> ");
	while (atual != NULL) {
		printf("%d ", atual->valor);
		atual = atual->proximo;
	}
	printf("<- final\n");
}

void show_revers(lista* l) { //percorre a lista de tras pra frente
	celula* atual = l->primeiro;
	celula* anterior = NULL;
	while (atual != NULL) {
		anterior = atual;
		atual = atual->proximo;
	}
	atual = anterior;
	printf("final -> ");
	while (atual != NULL) {
		printf("%d ", atual->valor);
		atual = atual->anterio;
	}
	printf("<- início\n");
}


int main(void) {
	// não alterar essa função
	lista* l = creat_list();
	inserir(l, 10);
	inserir(l, 20);
	inserir(l, 15);
	show(l);
	show_revers(l);
	for (int i = 0; i < 10; i++) {
		inserir(l, i + 1);
	}
	show(l);
	show_revers(l);
	remover(l, 20);
	remover(l, 15);
	remover(l, 10);
	show(l);
	show_revers(l);
	remover(l, 20);
	remover(l, 15);
	remover(l, 10);
	for (int i = 0; i < 10; i++) {
		remover(l, i + 1);
	}
	show(l);
	show_revers(l);
	return 0;
}