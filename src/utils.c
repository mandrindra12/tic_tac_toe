#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


bool is_invalid(int row, int column) {
	if(row>2 || row < 0 || column < 0 || column > 2) {
 		printf("INVALID INPUT row<2 or row > 0 or column > 0 or column < 2\n\a");
		return true;
	}
	return false;
}
bool is_empty(int **bool_table, int line, int column) {
	if(bool_table[line][column] == 0) return true;
	else return false;
}

bool game_over(char **table, int **boolTable) {

	int j = 0;
	//horizontal
	for(int i = 0; i < 3; i++) {
		if(boolTable[i][j] == 1 && boolTable[i][j+1] == 1 && boolTable[i][j+2] == 1) {
			if(table[i][j] == table[i][j+1] && table[i][j] == table[i][j+2]) return true;
		}
		/* for(int j = 0; j < 0; j++) {
			if(boolTable[i][j] == 1) ++is_set;
		}
		is_set = 0; */
	}

	//vertical
	for(int j = 0; j < 3; j++) {
		if(boolTable[0][j] == 1 && boolTable[1][j] == 1 && boolTable[1][j] == 1) {
			if(table[0][j] == table[1][j] && table[0][j] == table[2][j]) return true;
		}
		/* for(int j = 0; j < 0; j++) {
			if(boolTable[j][i] == 1) ++is_set;
		}
		is_set = 0; */
	}
	
	// diagonal
	if(boolTable[0][0] == 1 && boolTable[1][1] == 1 && boolTable[2][2] == 1) {
		if(table[0][0] == table[1][1] && table[0][0] == table[2][2]) return true;
	}
	if(boolTable[2][0] == 1 && boolTable[1][1] == 1 && boolTable[0][2] == 1) {
		if(table[2][0] == table[1][1] && table[2][0] == table[0][2]) return true;
	}
	

	return false;

}

bool table_is_full(int **boolTable){
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j){
			if(boolTable[i][j] == 0) return false;
		}
	}
	return true;
}

void **alloc(int li, int co) {
	void **tab = NULL;
	tab=calloc(li, sizeof(void*));
	for(int i=0; i < li; i++){
		*(tab+i) = calloc(co, sizeof(void));
	}
	return tab;
}

void setTable(char **table, int **boolTable, int i, int j, int player) {
	if(boolTable[i][j] == 1 && player%2 == 0)
		table[i][j]='x';
	else if(boolTable[i][j] == 1 && player%2 != 0)
		table[i][j]='o';
}

void input(int **boolTable, int *i, int *j, int *player) {
	int line=0, column=0, r = 0;
	do{
		c:
		printf("ROW, COLUMN: ");
		r = scanf(" %d %d", &line, &column);
		if(r!=2) goto c;
	}while(r!=2 || is_invalid(line,column) || !is_empty(boolTable, line, column));
	*(player)+=1;
	*i=line;*j=column;
	boolTable[line][column] = 1;
}
void displayTable(char **table, int **boolTable, int li, int co) {
	#ifdef _WINDOWS_
		system("cls");
	#endif
	#ifdef _LINUX_
		system("clear");
	#endif
	printf("\n\t\t\t\t---------------\n");
	for (int i = 0; i < li; ++i){
		for (int j = 0; j < co; ++j){
			if(j == 0){
				if(boolTable[i][j] == 1) printf("\t\t\t\t| %c |", table[i][j]);
				else printf("\t\t\t\t|   |");	
			} else {
				if(boolTable[i][j] == 1) printf("| %c |", table[i][j]);
				else printf("|   |");
			}
		}
		printf("\n\t\t\t\t---------------\n");
	}
}

