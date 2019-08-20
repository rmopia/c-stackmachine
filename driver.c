#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackm.h"

char *trim(char *str){
    int i;

    while (isspace(*str))                           //trims left side of string
        str++;

    for(i = strlen(str)-1; isspace(str[i]); i--){   //trims right side of a string
        continue;            
    }                                               
    str[i+1] = '\0';                                // '\0' are automatically placed at the end of every char ptr

    return str;       
}


int main(int argc, char *argv[]){

    STACK *st = MakeStack(64);
    char *token;
    char *coin;
    char *temp;
    char *last;
    char *trimmedArg;
    int counter = 0;
    int pushCount = 0;
    int convert;

    
    temp = (char*) malloc(256);
    last = (char*) malloc(128);
    trimmedArg = (char*) malloc(256);
  
    char *ch = argv[1];
    int N = atoi(ch);

    if(N == 0){
        printf("\n");
        printf("This program expects a single command line argument.\n");
        exit(0);                                                                    //exits program entirely 
    }
    
    char arg[256]; //argument arg with less than 256 arguments


    

    for(int i = 0; i < N; i++){
        printf("> ");
        fgets(arg, 256, stdin);
            trimmedArg = trim(arg);
            strcpy(arg, trimmedArg);
            strcpy(temp, arg); //dest: temp, src: arg
       
/****************************************************************/  
              
            for(int i = 0; arg[i] != 0; i++){       //counts amount of strings in char[] prior to strtok 
                if(arg[i] == ' ' || arg[i] == '\n')
                    counter++;
            }
            
            if(temp[0] != '\n'){                    //finds last token
                coin = strtok(temp, " \n");
                 while(coin){
                    last = coin;
                    coin = strtok(NULL, " ");
                    }
                }

/***************************************************************/
            if(arg[0] != '\n'){
                token = strtok(arg," \n");
                
              
                while(token != NULL){

                    if((counter == 1) && (pushCount == 0) && (strncmp(token, "push", 4) == 0)){
                        convert = atoi(last);
                        Push(st, convert);
                        pushCount++;
                        //printf("I will push\n");       
                    }

                    else if((counter == 0) && (strncmp(token, "pop", 3) == 0)){ 
                        printf("%d\n",Pop(st));
                        //printf("I will pop\n");
                    }
                

                token = strtok(NULL, " ");
                }
                    
                                   
                counter = 0;
                pushCount = 0;
                continue;
            }
            
        }
    }
        
    


