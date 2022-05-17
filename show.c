#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct Table table;
struct Table {
    char *token;
    int token_len;
    table *next;
    int line;
    int column;
};

table *pilhaDeTokens = NULL;
int numeroDeTokens = 0;

void addToken(char *string){
    numeroDeTokens++;
    if(pilhaDeTokens == NULL){
        pilhaDeTokens = (table *)malloc(sizeof(table));
        pilhaDeTokens->token = string;
        pilhaDeTokens->token_len = strlen(string);
        pilhaDeTokens->next = NULL;
    }
    else{
        table *newToken;
        newToken = (table *)malloc(sizeof(table));
        newToken->token = string;
        newToken->token_len = strlen(string);
        newToken->next = pilhaDeTokens;
        pilhaDeTokens = newToken;
    }
}

int main(){
    addToken("id");
    printf("%s\n", pilhaDeTokens->token);
    printf("%i\n", pilhaDeTokens->token_len);
    addToken("id2");
    printf("%s\n", pilhaDeTokens->token);
    printf("%i\n", pilhaDeTokens->token_len);
}