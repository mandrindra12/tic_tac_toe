#include <string.h>
#include <stdlib.h>

/*
split implementation in c

*/

char **split(char *string_to_split, char separator){
	char **splited=NULL;
	int j=0,k=0,count=0;

	/*
	Counting the number of field
	*/
	for(int i=0;i<strlen(string_to_split);i++){
		if(string_to_split[i]==separator) count++;
	}
	/*
	Allocate the appropriate memory size: no wasted memory
	*/
	splited=(char**)calloc(sizeof(char*),count+1);
	for(int i=0;i<count+1;i++){
		*(splited+i)=(char*)calloc(1,50);
	}


	for(int i=0;i<strlen(string_to_split);i++){
		if(string_to_split[i]==separator){
			k++;
			j=0;
		}else{
			*(*(splited+k)+j) = string_to_split[i];
			j++;
		}
	}
	return splited;
}
