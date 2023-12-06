#ifndef AVL_H
#define AVL_H
#include <stdbool.h>

typedef struct no_ NO;
typedef struct avl_ AVL;

AVL *avl_criar();
bool avl_inserir(AVL *arvore, int chave);
bool avl_remover(AVL *arvore, int chave);
bool avl_excluir(AVL **arvore);
void avl_imprimir(AVL *arvore);
void avl_imprimir_nivel(AVL *arvore);
bool avl_busca(AVL *arvore, int chave);
int avl_num_nos(AVL *arvore);
int avl_somar_nos(AVL *arvore);
int avl_profundidade(AVL *arvore);
bool avl_completa(AVL *arvore);

#endif // AVL_H