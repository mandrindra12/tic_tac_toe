#include <stdio.h>
#include <stdlib.h>
extern char **split(char*, char);

int main(void) {
        char *env = getenv("QUERY_STRING");
        char **query = split(env, '&');
        int player = atoi(split(query[0], '=')[1]);
        int row = atoi(split(query[1], '=')[1]);
        int column = atoi(split(query[2], '=')[1]);

        printf("Content-type: text/html\n\n");
        printf("<html>");
        printf("player: %d\nrow: %d\ncolumn: %d\n", player, row, column);
        printf("</html>");
        return 0;
}