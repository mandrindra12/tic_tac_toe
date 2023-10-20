#ifndef __MORPION__
#define __MORPION__
#include <stdbool.h>
	bool is_invalid(int row, int column);
	void displayTable(char **table, int **boolTable, int li, int co);
	void **alloc(int li, int co);
	int input(int **boolTable, int *i, int *j,int *player);
	void setTable(char **table, int **boolTable, int li, int co, int player);
	bool game_over(char **table, int **boolTable);
	bool table_is_full(int **boolTable);
	bool is_empty(int **bool_table, int line, int column);

#endif
