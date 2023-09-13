#include <stdio.h>
#include <stdlib.h>

#include "item.h"
#include "Pilha.h"

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