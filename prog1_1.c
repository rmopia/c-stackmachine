#include <stdio.h>

int main(){
    printf("Assignment #1-1, Robert Mopia, rmopia7587@sdsu.edu\n");

    int limit = 40;
    char name[limit];
    printf("What is your name?\n");
    gets(name, limit, stdin);
    printf("Hello %s!\n", name);

    return 0;

}
