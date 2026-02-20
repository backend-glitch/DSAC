/*
4. Reverse Product Codes
A company stores its product codes in reverse order. Write a program to reverse
a given product code (string) entered by the use.

*/
#include<stdio.h>

void reversenum(char word[], int n){
    char temp;
    for(int i = 0; i < n/2; i++){
        temp = word[i];                  // Save current character
        word[i] = word[n-i-1];           // Copy from end
        word[n-i-1] = temp;              // Put saved character at end
    }
}

int main(){
    int n;
    scanf("%d", &n);
    getchar(); // consume newline
    
    char word[n+1];  // +1 for null terminator
    scanf("%s", word);  // No & needed for array name
    
    reversenum(word, n);
    
    printf("%s", word);
    
    return 0;
}