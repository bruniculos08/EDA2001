#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct Node node;
struct Node {
    table *item;
    node *next;
};

typedef struct Table table;
struct Table {
    char *token;
    int token_len;
};

table *tabelaDeTokens = NULL;
int numeroDeTokens = 0;

void addToken(char *string){
    numeroDeTokens++;
    if(tabelaDeTokens == NULL) tabelaDeTokens = (table *)malloc(numeroDeTokens * sizeof(table));
    else tabelaDeTokens = realloc(tabelaDeTokens, numeroDeTokens * sizeof(table));
    tabelaDeTokens[numeroDeTokens-1].token = (char *)malloc(strlen(string) * sizeof(char));
    tabelaDeTokens[numeroDeTokens-1].token_len = strlen(string);
    tabelaDeTokens[numeroDeTokens-1].token = string;
}

int main(){
    addToken("id");
    printf("%s\n", tabelaDeTokens[numeroDeTokens-1].token);
    addToken("id2");
    printf("%s\n", tabelaDeTokens[numeroDeTokens-1].token);
    printf("%i\n", tabelaDeTokens[numeroDeTokens-1].token_len);
}