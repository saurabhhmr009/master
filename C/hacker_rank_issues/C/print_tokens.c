#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Method 1
/*int main() {

    char *s;
    char *i = NULL;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    
    for(i=s; *i != '\0'; i++) {
        if(*i == ' ' ) {
            printf("\n");
        }
        else {
            printf("%c", *i);
        }
    }
    return 0;
}*/

// Method 2
int main() {

    char *s;
    int i;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    
    for(i = 0; i < strlen(s); i++) {
        if (*(s+i) == ' '){
            printf("\n");
        }
        else {
            printf("%c", *(s+i));
        }
    }
    return 0;
}
