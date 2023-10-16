#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

struct no_{
    ITEM *item;
    NO *proximo;
};

struct listaEnc_{
    NO *inicio;
    int tamanho;
};

#pragma region Lista_Seq

    struct listaSeq_{
        ITEM *itens[MAX];
        int tamanho;
    };

    LISTASEQ *lista_criar_seq()
    {
        LISTASEQ *lista = (LISTASEQ*) malloc(sizeof(LISTASEQ));

        lista->tamanho = 0;

        return lista;
    }

    bool lista_cheia_seq(LISTASEQ *lista)
    {
        if(lista == NULL)
        {
            return true;
        }

        return lista->tamanho == MAX;
    }

    int lista_busca_seq(int inf, int sup, LISTASEQ *lista, int chave)
    {
        if(inf > sup)
        {
            return -1;
        }

        int mid = (inf + sup)/2;

        int chaveMid = item_get_chave(lista->itens[mid]);

        if(chaveMid == chave)
        {
            return mid;
        }
        else if(chaveMid > chave)
        {
            return lista_busca_seq(inf, mid-1, lista, chave);
        }
        else
        {
            return lista_busca_seq(mid+1, sup, lista, chave);
        }
    }
    
    bool lista_inserir_seq(LISTASEQ *lista, ITEM *item)
    {
        if(lista == NULL || lista_cheia_seq(lista))
        {
            return false;
        }

        if(lista->tamanho == 0)
        {
            lista->itens[0] = item;
            lista->tamanho++;
            return true;
        }

        int inf = 0;
        int sup = lista->tamanho - 1;
        int mid = (inf+sup)/2;
        int chaveMid = item_get_chave(lista->itens[mid]);
        int chaveItem = item_get_chave(item);

        while(inf <= sup)
        {
            printf("a ");
            mid = (inf+sup)/2;
            chaveMid = item_get_chave(lista->itens[mid]);

            if(chaveMid == chaveItem)
            {
                break;
            }
            else if(chaveMid > chaveItem)
            {
                sup = mid-1;
            }
            else
            {
                inf = mid+1;
            }
        }

        if(chaveMid <= chaveItem)
        {
            for(int i = lista->tamanho; i > mid + 1; i--)
            {
                lista->itens[i] = lista->itens[i-1];
            }

            lista->itens[mid+1] = item;
        }
        else
        {
            for(int i = lista->tamanho; i > mid; i--)
            {
                lista->itens[i] = lista->itens[i-1];
            }

            lista->itens[mid] = item;
        }

        lista->tamanho++;

        return true;
    }

    ITEM *lista_remover_seq(LISTASEQ *lista, int chave)
    {
        if(lista == NULL || lista->tamanho == 0)
        {
            return NULL;
        }

        int pos = lista_busca_seq(0, lista->tamanho, lista, chave);

        ITEM *item = lista->itens[pos];

        for(int i = pos + 1; i < lista->tamanho; i++)
        {
            lista->itens[i-1] = lista->itens[i];
        }

        lista->tamanho--;

        return item;
    }

    void lista_imprimir_seq(LISTASEQ *lista)
    {
        if(lista == NULL)
        {
            return;
        }

        for(int i = 0; i < lista->tamanho; i++)
        {
            item_imprimir(lista->itens[i]);
        }
    }

    bool lista_apagar_seq(LISTASEQ **lista)
    {
        if(*lista == NULL)
        {
            return false;
        }

        for(int i = 0; i < (*lista)->tamanho; i++)
        {
            item_apagar(&((*lista)->itens[i]));
        }

        free(*lista);
        *lista = NULL;

        return true;
    }

#pragma endregion Lista_Seq

#pragma region Lista_Enc //com no cabeca

    LISTAENC *lista_criar_enc()
    {
        LISTAENC *lista = (LISTAENC*) malloc(sizeof(LISTAENC));
        NO *cabeca = (NO*) malloc(sizeof(NO));

        cabeca->item = NULL;
        cabeca->proximo = NULL;

        lista->inicio = cabeca;
        lista->tamanho = 0;

        return lista;
    }

    bool lista_cheia_enc(LISTAENC *lista)
    {
        if(lista == NULL)
        {
            return true;
        }

        NO *noTeste = (NO*) malloc(sizeof(NO));

        if(noTeste == NULL)
        {
            free(noTeste);
            return(true);
        }

        free(noTeste);
        noTeste = NULL;

        return false;
    }

    bool lista_inserir_enc(LISTAENC *lista, ITEM *item)
    {
        if(lista == NULL || lista_cheia_enc(lista))
        {
            return false;
        }

        NO *noItem = (NO*) malloc(sizeof(NO));
        noItem->item = item;

        if(lista->tamanho == 0)
        {
            lista->tamanho++;
            noItem->proximo = NULL;
            lista->inicio->proximo = noItem;

            return true;
        }

        NO *no = lista->inicio->proximo;
        NO *noAnterior = lista->inicio;
        int itemChave = item_get_chave(item);
        int noChave;

        for(int i = 0; i < lista->tamanho; i++)
        {
            noChave = item_get_chave(no->item);

            if(noChave >= itemChave)
            {
                noAnterior->proximo = noItem;
                noItem->proximo = no;

                lista->tamanho++;

                return true;
            }

            noAnterior = no;
            no = no->proximo;
        }

        noAnterior->proximo = noItem;
        noItem->proximo = NULL;

        lista->tamanho++;

        return true;
    }

    ITEM *lista_remover_enc(LISTAENC *lista, int chave)
    {
        if(lista == NULL || lista->tamanho == 0)
        {
            return NULL;
        }

        lista->tamanho--;

        NO* no = lista->inicio->proximo;
        NO* noAnterior = lista->inicio;

        for(int i = 0; i < lista->tamanho; i++)
        {
            if(item_get_chave(no->item) == chave)
            {
                noAnterior->proximo = no->proximo;

                ITEM *item = no->item;
                
                free(no);
                no = NULL;

                return item;
            }

            noAnterior = no;
            no = no->proximo;
        }

        return NULL;
    }

    void lista_imprimir_enc(LISTAENC *lista)
    {
        if(lista == NULL)
            return;

        NO *no = lista->inicio->proximo;

        for(int i = 0; i < lista->tamanho; i++)
        {
            item_imprimir(no->item);
            no = no->proximo;
        }
    }

    bool lista_apagar_enc(LISTAENC **lista)
    {
        NO *no = (*lista)->inicio;
        NO *noAux;

        for(int i = 0; i < (*lista)->tamanho + 1; i++)
        {
            item_apagar(&(no->item));

            noAux = no;
            no = no->proximo;
            free(noAux);
            noAux = NULL;
        }

        free(*lista);
        *lista = NULL;
    }

#pragma endregion Lista_Enc

#pragma region Lista_Gen

    struct noGen_{
        int tipo;
        union {
            ITEM *atomo;
            NO *sublista;
        }info;
        NO *proximo;
    };

    struct listaGen_{
        NO *inicio;
        int profundidade;
    };

#pragma endregion Lista_Gen

int lista_strlen(LISTAENC *lista)
{
    return lista->tamanho;
}

int strcmp(LISTAENC *lista1, LISTAENC *lista2)
{
    int tam;

    if(lista1->tamanho > lista2->tamanho)
        tam = lista2->tamanho;
    else
        tam = lista1->tamanho;

    NO *no1 = lista1->inicio->proximo;
    NO *no2 = lista2->inicio->proximo;

    for(int i = 0; i < tam; i++)
    {
        if(item_get_chave(no1->item) != item_get_chave(no2->item))
        {
            return item_get_chave(no1->item) - item_get_chave(no2->item);
        }

        no1 = no1->proximo;
        no2 = no2->proximo;
    }

    if(lista1->tamanho == lista2->tamanho)
    {
        return 0;
    }
    else if(lista1->tamanho > lista2->tamanho)
    {
        return item_get_chave(no1);
    }
    else if(lista1->tamanho < lista2->tamanho)
    {
        return item_get_chave(no2);
    }
}

LISTAENC *strcpy(LISTAENC *dest, LISTAENC *origem)
{
    lista_apagar(dest);

    dest = lista_criar_enc();

    NO* no = origem->inicio->proximo;

    for(int i = 0; i < origem->tamanho; i++)
    {
        lista_inserir_enc(dest, no->item);
        no = no->proximo;
    }

    return dest;
}