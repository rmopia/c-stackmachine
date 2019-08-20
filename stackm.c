#include "stackm.h"
#include <stdio.h>
#include <stdlib.h>

STACK* MakeStack(int initialCapacity){
    struct stack* new = (struct stack*) malloc(sizeof(struct stack));
    new->size = 0;                                                          //amount of elements currently in stack
    new->capacity = initialCapacity;                                        //amount stack can hold (max amount)
    new->data = (int*) malloc(sizeof(int)*1000);                            //amount of memory allocated we 'could' need
    return new;
}

void Push(STACK *stackPtr, int data){
    if(stackPtr->size == stackPtr->capacity){
        Grow(stackPtr);
    }
    stackPtr->data[stackPtr->size] = data;
    stackPtr->size++;

}

int Pop(STACK *stackPtr){
    if(stackPtr->size == 0){
        return -1;
    }
    stackPtr->size--;
    return stackPtr->data[stackPtr->size];

}

void Grow(STACK *stackPtr){
    stackPtr->capacity = (stackPtr->capacity)*2;                                //doubles capacity                     
    stackPtr->data = (int*)realloc(stackPtr->data, sizeof(int) * 10);            
                                                                                //realloc also acts as a free() for our previous uses of malloc

}
