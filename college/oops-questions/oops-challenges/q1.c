/*
1. Detecting Palindrome Words
A group of linguists wants to analyze if a given word is a palindrome (reads the
same forward and backward). Write a program to check this for any user-input
word.


*/

#include<stdio.h>

int ispalindrome(char word[],int n){

    for(int i=0;i<n/2;i++){
         if(word[i] != word[n-i-1]) return 0;
    }
    return 1;
}

int main(){

    int n;
    scanf("%d",&n);

    scanf(" "); // to consum \n.

    char word[n+1];
    for(int i=0;i<n;i++) scanf("%c",&word[i]);

    int ans = ispalindrome(word,n);

    if(ans == 1){
        printf("a palindrome");
    }else{
        printf("not a plaindrome");
    }
}

