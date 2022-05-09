#include "stdlib.h"
#include "stdio.h"

void encode(char string[], int stringSize){
    if(stringSize == 0) return;
    int letter = string[0];
    int count = 1;
    for(int i = 1; i < stringSize; i++){
        if(letter == string[i]) count++;
        else{
            printf("%i%c", count, letter);
            letter = string[i];
            count = 1;
        }  
    }
}

int main(){
    char string[] = "AABBCCAAEEEEEEDDEAABBBB";
    int stringSize = sizeof(string)/sizeof(string[0]);
    encode(string, stringSize);
}