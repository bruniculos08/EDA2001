#include "stdlib.h"
#include "stdio.h"

typedef struct List list;
struct List {
    int number;
    list *next;
};

void intersection(list *linkedOne, list *linkedTwo){
    list *temp;
    temp = linkedOne;
    while(linkedOne != NULL && linkedTwo != NULL){
        while(temp != NULL){
            if(temp->number == linkedTwo->number){
                printf("%i\n", temp->number);
                return;
            }
            temp = temp->next;
        }
        linkedTwo = linkedTwo->next;
    }
}

int main(){
    list *linkedOne;
    list *linkedTwo;
    linkedOne = (list *)malloc(sizeof(list));
    linkedTwo = (list *)malloc(sizeof(list));
    linkedOne->next = NULL;
    linkedTwo->next = NULL;
    linkedOne->number = 4;
    linkedTwo->number = 4;
    intersection(linkedOne, linkedTwo);
}