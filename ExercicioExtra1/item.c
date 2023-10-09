#include <stdlib.h>
#include <stdio.h>
#include "item.h"

struct item_{ 
   int chave;
   int posX;
   int posY;
   // 0 = sul, 1 = oeste, 2 = norte, 3 = leste;
   int direction;
   bool visited;
};

ITEM *item_criar (int chave, int posX, int posY, int direction, bool visited){
          ITEM *item;
          
          item = (ITEM *) malloc(sizeof(ITEM));
          
          if (item != NULL){
             item->chave = chave;
             item->posX = posX;
             item->posY = posY;
             item->direction = direction;
             item->visited = visited;
             return(item);
          }
          return(NULL);
}

bool item_apagar(ITEM **item){
   if (*item != NULL){
      free (*item);
      *item = NULL; /*Boa prática!*/
      return(true);
   }
   return(false);
}

int item_get_chave(ITEM *item){
    if (item != NULL)
      return(item->chave);
    exit(1);
}

int item_get_coordsX(ITEM *item){
   if(item == NULL)
      exit(1); //aborta o programa (sai do programa

   return(item->posX);
}

int item_get_coordsY(ITEM *item){
   if(item == NULL)
      exit(1); //aborta o programa (sai do programa

   return(item->posY);
}

int item_get_direction(ITEM *item){
   if(item == NULL)
      exit(1);

   return item->direction;
}

bool item_get_visited(ITEM *item){
   if(item == NULL)
      exit(1);

   return item->visited;
}

bool item_set_chave(ITEM *item, int chave){
  if (item != NULL){
    item->chave = chave;
    return (true);
  }
  return (false);
}

bool item_set_coords(ITEM *item, int posX, int posY){
   if(item == NULL)
      return(false);

   item->posX = posX;
   item->posY = posY;

   return(true);
}

bool item_set_direction(ITEM *item, int direction){
   if(item == NULL)
      return(false);

   item->direction = direction;

   return(true);
}

bool item_set_visited(ITEM *item, bool visited){
   if(item == NULL)
      return(false);

   item->visited = visited;

   return(true);
}

void item_imprimir(ITEM *item){
     if (item != NULL)
        printf("\n(%i, %i)", item->posX, item->posY);
}