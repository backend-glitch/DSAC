#include<stdio.h>

void stringCopy(char source[], char destination[]){
    int i = 0;
    
    // Copy characters one by one until we hit null terminator
    while(source[i] != '\0'){
        destination[i] = source[i];
        i++;
    }
    
    // Don't forget to add null terminator at the end!
    destination[i] = '\0';
}

int main(){
    char source[100], destination[100];
    
    printf("Enter filename to copy: ");
    scanf("%s", source);
    
    // Copy source to destination
    stringCopy(source, destination);
    
    printf("Original filename: %s\n", source);
    printf("Copied filename: %s\n", destination);
    
    return 0;
}
