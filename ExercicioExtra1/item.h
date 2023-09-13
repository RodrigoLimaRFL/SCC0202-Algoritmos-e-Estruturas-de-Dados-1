#ifndef ITEM_H
	#define ITEM_H
	
	#include <stdbool.h>

	typedef struct item_ ITEM;

	ITEM *item_criar (int chave, int posX, int posY, int direction, bool visited);
	bool item_apagar(ITEM **item);
	void item_imprimir(ITEM *item);
	int item_get_chave(ITEM *item);
	int item_get_coordsX(ITEM *item);
	int item_get_coordsY(ITEM *item);
	int item_get_direction(ITEM *item);
	bool item_get_visited(ITEM *item);
	bool item_set_chave(ITEM *item, int chave);
	bool item_set_coords(ITEM *item, int posX, int posY);
	bool item_set_direction(ITEM *item, int direction);
	bool item_set_visited(ITEM *item, bool visited);

#endif