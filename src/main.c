#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(int argc, char **argv){
	int player=1, i=0, j=0;
	int **boolTable=NULL;
	char **tableDuJeu=NULL;
	tableDuJeu=(char**)alloc(3, 3);
	boolTable=(int**)alloc(3, 3);
	while(!table_is_full(boolTable) && !game_over(tableDuJeu, boolTable)) {
		displayTable(tableDuJeu, boolTable, 3, 3);
		printf("\n\n\t\t\t\t\a PLAYER %d TURN NOW \n", player = (player%2) ? 1:2);
		input(boolTable, &i, &j, &player);
		setTable(tableDuJeu, boolTable, i, j, player);
		displayTable(tableDuJeu, boolTable, 3, 3);
	}
	if(game_over(tableDuJeu, boolTable)){
		printf("\n\n\a\t\t\t\tPLAYER %d WINS\n", (player%2 == 0) ? 1 : 2);
	}
	else if(table_is_full(boolTable)){
		printf("DRAW\n");
	}
	return 0;
}
