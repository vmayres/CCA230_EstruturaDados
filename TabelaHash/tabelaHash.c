#include <stdio.h>
#include <stdlib.h>

#define tam_hash 11

typedef struct Celula {
    int valor;
    struct Celula* proximo;
}Celula;

typedef struct Lista{
    int qtd;
    Celula* primeiro;
}Lista;

typedef struct Hash{
    // implementar
    Lista* tabela[tam_hash];
}Hash;

Celula* creat_cell(int valor){
    Celula* c = malloc(sizeof(Celula)); //aloca um espa�o de memoria do tipo celula
	c->proximo = NULL;
	c->valor = valor;
	return c;
}

Lista* start_list() {
    Lista* l = malloc(sizeof(Lista));
    l->qtd = 0;
    l->primeiro = NULL;
    return l;
}

Hash* start_hash() {
    // implementar
    Hash* h = malloc(sizeof(Hash));
    for (int i = 0; i < tam_hash; i++) {
        h->tabela[i] = start_list();
    }
    return h;
}

void inserir_hash(Hash* h, int valor) {
    // implementar
    Celula* new = creat_cell(valor);
    int pos = valor % tam_hash;
    if(h->tabela[pos]->qtd == 0){
        h->tabela[pos]->primeiro = new;
    }
    else{
        Celula* atual = h->tabela[pos]->primeiro;
        Celula* anterior = NULL;
        if (anterior == NULL) {
			new->proximo = h->tabela[pos]->primeiro;
			h->tabela[pos]->primeiro = new;
		}
		else {
			anterior->proximo = new;
			new->proximo = atual;
		}
    }
    h->tabela[pos]->qtd++;
    
}

void remover_hash(Hash* h, int valor) {
    // implementar
    int pos = valor % tam_hash;
    Celula* atual = h->tabela[pos]->primeiro;
    Celula* anterior = NULL;
    while(atual != NULL && atual->valor != valor){
        anterior = atual;
        atual = atual->proximo;
    }
    if(atual != NULL){
        if(anterior == NULL){
            h->tabela[pos]->primeiro = atual->proximo;
        }
        else{
            anterior->proximo = atual->proximo;
        }
        free(atual);
        h->tabela[pos]->qtd--;
    }
}

void show_list(Lista* l) {
	Celula* atual = l->primeiro;
	while (atual != NULL) {
		printf("%d ", atual->valor);
		atual = atual->proximo;
	}
	printf("\n");
}

void imprimir(Hash* hash) {
    // implementar
    printf("---------------------\n");
    for (int i = 0; i < tam_hash; i++) {
        printf("%d -> ", i);
        show_list(hash->tabela[i]);
    }
    printf("---------------------\n");
}

int main(void) {
    Hash* hash = start_hash();
    int valor;
    while (1) {
        scanf("%d", &valor);
        if (valor == 0)
            break;
        inserir_hash(hash, valor);
    }
    imprimir(hash);
    while (1) {
        scanf("%d", &valor);
        if (valor == 0)
            break;
        remover_hash(hash, valor);
    }
    imprimir(hash);
    return 0;
}