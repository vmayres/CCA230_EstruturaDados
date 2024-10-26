#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
	int valor;
	struct Vertice* esq;
	struct Vertice* dir;
	struct Vertice* pai;
} Vertice;

typedef struct Arvore{
	Vertice* raiz;
	int qtde;
} Arvore;

//ERD
void in_ordem(Vertice * raiz) {
    if(raiz == NULL) return;
    in_ordem(raiz->esq);
    printf("%d ", raiz->valor);
    in_ordem(raiz->dir);
}

//RED
void pre_ordem(Vertice * raiz) {
    if(raiz == NULL) return;
    printf("%d ", raiz->valor);
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
}

//EDR
void pos_ordem(Vertice * raiz) {
    if(raiz == NULL) return;
    pos_ordem(raiz->esq);
    pos_ordem(raiz->dir);
    printf("%d ", raiz->valor);
}

Vertice *cria_vertice(Arvore *arvore, int valor){
	Vertice* novo = malloc(sizeof(Vertice));
	novo->dir = NULL;
	novo->esq = NULL;
	novo->pai = NULL;
	novo->valor = valor;
	
	return novo;
}

Arvore *cria_arvore(){
	Arvore* arvore = malloc(sizeof(Arvore));
	arvore->raiz = NULL;
	arvore->qtde = 0;

	return arvore;
}

void inserir(Arvore* arvore, int valor){
	Vertice* novo = cria_vertice(arvore, valor);
    Vertice* atual = arvore->raiz;
    Vertice* pai = NULL;
    
    //ordena a arvore balanciada
    while(atual != NULL){
        pai = atual;
        if(valor < atual->valor){
            atual = atual->esq;
        }else{
            atual = atual->dir;
        }
    }
    
    //add o novo vertice na arvore
    novo->pai = pai;
    if(pai == NULL){ //caso 1 : arvore vazia
        arvore->raiz = novo;
    }else{ //caso 2 : arvore com elementos
        if(valor < pai->valor){
            pai->esq = novo;
        }else{
            pai->dir = novo;
        }
    }
    arvore->qtde++;
}

int remover_vertice(Arvore* arvore, Vertice* vertice){
    Vertice* pai = vertice->pai;
    Vertice* esq = vertice->esq;
    Vertice* dir = vertice->dir;

    int filhos = 0;
    if(esq) filhos++;
    if(dir) filhos++;
    
    //caso 0 : vertice raiz
    if(filhos == 0){
        if(pai == NULL){
            arvore->raiz = NULL;
        }
        //caso 1 : vertice folha
        else{
            if(vertice == pai->esq){
                pai->esq = NULL;
            }
            if(vertice == pai->dir){
                pai->dir = NULL;
            }
        }
    }

    //caso 2 : arvore com 1 filho
    if(filhos == 1){
        if(esq == NULL){ //é o direito
            pai->dir = dir;
            dir->pai = pai;
        }
        if (dir == NULL){ //é o esquerdo
            esq->pai = pai;
            pai->esq = esq;
        }
    }

    //caso 3 : arvore com 2 filhos
    if(filhos == 2){
        Vertice* aux = esq;
        while(aux->dir != NULL){
            aux = aux->dir;
        }
        vertice->valor = aux->valor;
        remover_vertice(arvore, aux);
    }

	return vertice->valor;
    free(vertice);
    arvore->qtde--;

}

Vertice *buscar_valor(Arvore* arvore, int valor){
	Vertice* atual = arvore->raiz;
	while(atual != NULL){
		if(valor < atual->valor){
			atual = atual->esq;
		}else{
			if(valor > atual->valor){
				atual = atual->dir;
			}else{
				return atual;
			}
		}
	}
	return NULL;
}

int main(void) {
	int dados[] = {5, 3, 8, 2, 4, 7, 9, 1, 6, 10};
  	Arvore *arvore = cria_arvore();
  	
	for(int i = 0; i < 8; i++){
		inserir(arvore, dados[i]);
		printf("Inseriu %d mostra em ordem -> ", dados[i]);
		in_ordem(arvore->raiz);
		printf("\n");
		printf("Inseriu %d mostra em pré-ordem -> ", dados[i]);
		pre_ordem(arvore->raiz);
		printf("\n");
		printf("Inseriu %d mostra em pós-ordem -> ", dados[i]);
		pos_ordem(arvore->raiz);
		printf("\n");
	}
	
	for(int i = 0; i < 10; i++){
		Vertice *vertice = buscar_valor(arvore, dados[i]);
		if(vertice != NULL){
			remover_vertice(arvore, vertice);
		}
		printf("Removeu %d mostra em ordem -> ", dados[i]);
		in_ordem(arvore->raiz);
		printf("\n");
		printf("Removeu %d mostra em pré-ordem -> ", dados[i]);
		pre_ordem(arvore->raiz);
		printf("\n");
		printf("Removeu %d mostra em pós-ordem -> ", dados[i]);
		pos_ordem(arvore->raiz);
		printf("\n");
	}
		
  return 0;
}