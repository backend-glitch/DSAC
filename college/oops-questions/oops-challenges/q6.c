/*
In analyzing log data, a software tool needs to find if a specific keyword
(substring) exists within a longer string. Write a program to check if the keyword
exists, and if so, print its starting position.
*/

#include<stdio.h>
#include<stdbool.h>

int findSubstring(char text[], char keyword[]){
    int i, j;
    
    // Traverse through the main text
    for(i = 0; text[i] != '\0'; i++){
        
        // Check if substring starts at position i
        j = 0;
        while(keyword[j] != '\0' && text[i+j] != '\0' && text[i+j] == keyword[j]){
            j++;
        }
        
        // If we reached end of keyword, we found a match
        if(keyword[j] == '\0'){
            return i;  // Return starting position
        }
    }
    
    return -1;  // Not found
}

int main(){
    char text[200], keyword[100];
    
    printf("Enter the log data: ");
    fgets(text, sizeof(text), stdin);
    
    printf("Enter the keyword to search: ");
    scanf("%s", keyword);
    
    int position = findSubstring(text, keyword);
    
    if(position != -1){
        printf("Keyword found at position: %d\n", position);
    } else {
        printf("Keyword not found\n");
    }
    
    return 0;
}
