#include "stdlib.h"
#include "stdio.h"

typedef struct Node node;
typedef struct Stack stack;
struct Node{   
    char *letter;
    node *next;
};
struct Stack{
    node *first;
};

char removeStack(stack *auxStack){
    if(auxStack->first == NULL) return NULL;
    node *removed = auxStack->first;
    char r;
    r = removed->letter;
    auxStack->first = auxStack->first->next;
    free(removed);    
    return r;
}

void insertStack(stack *auxStack, char word[]){
    int length = strlen(word);
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->next = auxStack->first;
    auxStack->first = newNode;
    newNode->letter = (char *)malloc(sizeof(char)*length);
    for(int i = 0; i < length; i++) newNode->letter[i] = word[i];
    return;
}

void encode(char string[], int stringSize){
    int count = 1;
    stack *auxStack;
    auxStack->first = (node*)malloc(sizeof(node));
    
    for(int i=stringSize-1; i>=0; i--){
        if(string[i] == auxStack->first->letter) count++;
        else{
            
        }
    }
}

int main(){
    char string[] = "AABBCCAAEEEEEEDDEAABBBB";
    int stringSize = sizeof(string)/sizeof(string[0]);
    encode(string, stringSize);
}