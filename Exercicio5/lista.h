
#ifndef LISTA_H
	#define LISTA_H

	#define TAM_MAX 100 /*estimativa do tamanho máximo da lista*/
	#define inicial 0
	#define ERRO -32000
	#define ORDENADA 1 // 0 = lista não ordenada, 1 = lista ordenada

	#include "item.h"

	typedef struct no_ NO;
	typedef struct lista_ LISTA;

	LISTA *lista_criar(void);
	bool lista_inserir(LISTA *lista, ITEM *item);
	// funcao para inserir ordenado
	bool lista_inserir_busca(LISTA *lista, ITEM *item);
	ITEM *lista_remover(LISTA *lista, int chave);
	// funcao para remover todos os itens em ordem de entrada
	ITEM **lista_remover_todos(LISTA *lista, int *chaves, int n);
	void lista_apagar(LISTA **lista);
	ITEM *lista_busca(LISTA *lista, int chave);

	int lista_tamanho(LISTA *lista);
	bool lista_vazia(LISTA *lista);
	bool lista_cheia(LISTA *lista);
	void lista_imprimir(LISTA *lista);

	bool lista_inverter(LISTA **lista);

#endif
