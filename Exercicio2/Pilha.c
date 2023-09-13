#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "item.h"
#include "Pilha.h"

typedef struct pilha {
    ITEM *itens[TAM];
    int tamanho;
} PILHA;

PILHA *pilha_criar() {
    PILHA *pilha = (PILHA *) malloc(sizeof(PILHA));

    if(pilha == NULL) {
        printf("Erro ao alocar memória para a pilha.\n");
        exit(1);
    }

    pilha->tamanho = 0;

    return pilha;
}

bool pilha_vazia(PILHA *pilha)
{
    if(pilha == NULL)
    {
        return false;
    }

    return ((pilha->tamanho == 0) ? true : false);
}

bool pilha_cheia(PILHA *pilha)
{
    if(pilha == NULL)
    {
        return true;
    }

    return ((pilha->tamanho == TAM) ? true : false);
}

void pilha_apagar(PILHA **pilha)
{
    if(*pilha != NULL && !pilha_vazia(*pilha))
    {
        while((*pilha)->tamanho != 0)
        {
            item_apagar(&((*pilha)->itens[(*pilha)->tamanho - 1]));
            (*pilha)->tamanho--;
        }
    }

    free(*pilha);
    *pilha = NULL;
}

int pilha_tamanho(PILHA *pilha)
{
    if(pilha == NULL)
    {
        printf("PILHA NAO EXISTE\n");
        return 0;
    }

    return pilha->tamanho;
}

ITEM *pilha_topo(PILHA *pilha)
{
    if(pilha == NULL)
    {
        printf("PILHA NAO EXISTE\n");
        exit(1);
    }

    if(pilha->tamanho == 0)
    {
        printf("PILHA VAZIA\n");
        return NULL;
    }

    return pilha->itens[pilha->tamanho-1];
}

bool pilha_empilhar(PILHA *pilha, ITEM *item)
{
    if(pilha == NULL || pilha_cheia(pilha))
    {
        printf("ERRO AO EMPILHAR\n");
        return false;
    }

    pilha->itens[pilha->tamanho] = item;
    pilha->tamanho++;
    return true;
}

ITEM *pilha_desempilhar(PILHA *pilha)
{
    if(pilha == NULL || pilha_vazia(pilha))
    {
        return NULL;
    }

    ITEM* item;

    item = pilha_topo(pilha);
    pilha->itens[pilha->tamanho-1] = NULL;
    pilha->tamanho--;
    return item;
}

void pilha_print(PILHA *pilha)
{
    if(pilha == NULL)
    {
        printf("PILHA NAO EXISTE");
        return;
    }

    for(int i = 0; i < pilha->tamanho; i++)
    {
        printf("%c ", item_get_chave(pilha->itens[pilha->tamanho-1]));
    }
}

bool balanceada(char* sequencia)
{
    // pilha para guardar cada enchaveamento
    PILHA* enchaveamentos = pilha_criar();

    // percorre a string ate o fim
    for(int i = 0; ; i++)
    {
        if(sequencia[i] == '\0')
        {
            break;
        }

        // empilha um parenteses caso haja (
        if(sequencia[i] == '(')
        {
            if(!pilha_empilhar(enchaveamentos, item_criar('(')))
            {
                printf("ERRO COM ABRE PARENTESES\n");
                return false;
            }
        }

        // desempilha um parenteses caso haja ) e retorna falso se a pilha nao tiver parenteses no topo
        if(sequencia[i] == ')')
        {
            ITEM* item = pilha_desempilhar(enchaveamentos);

            if(item == NULL)
            {
                return false;
            }

            if(item_get_chave(item) != '(')
            {
                return false;
            }
        }

        // empilha um colchetes caso haja (
        if(sequencia[i] == '[')
        {
            if(!pilha_empilhar(enchaveamentos, item_criar('[')))
            {
                printf("ERRO COM ABRE COLCHETES\n");
                return false;
            }
        }

        // desempilha um colchetes caso haja ] e retorna falso se a pilha nao tiver colchetes no topo
        if(sequencia[i] == ']')
        {
            ITEM* item = pilha_desempilhar(enchaveamentos);

            if(item == NULL)
            {
                return false;
            }

            if(item_get_chave(item) != '[')
            {
                return false;
            }
        }

        // empilha uma chaves caso haja (
        if(sequencia[i] == '{')
        {
            if(!pilha_empilhar(enchaveamentos, item_criar('{')))
            {
                printf("ERRO COM ABRE CHAVES\n");
                return false;
            }
        }

        // desempilha uma chaves caso haja ) e retorna falso se a pilha nao tiver chaves no topo
        if(sequencia[i] == '}')
        {
            ITEM* item = pilha_desempilhar(enchaveamentos);

            if(item == NULL)
            {
                return false;
            }

            if(item_get_chave(item) != '{')
            {
                return false;
            }
        }
    }

    if(!pilha_vazia(enchaveamentos))
    {
        return false;
    }

    return true;
}