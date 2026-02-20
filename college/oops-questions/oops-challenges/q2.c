// 2. Count Vowels in a Sentence
// A speech recognition program needs to determine how many vowels are present
// in a user-input sentence. Write a program to count the vowels (both uppercase
// and lowercase).

#include<stdio.h>

int countvowels(char word[], int n){
    char vowels[] = {'a','e','i','o','u','A','E','I','O','U'};
    int count = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<10; j++){
            if(word[i] == vowels[j]) count++; 
        }
    }
    return count;
}

int main(){
    int n;
    scanf("%d", &n);

    
    getchar(); // consume the newline after the number

    char word[n];
    for(int i=0; i<n; i++) scanf("%c", &word[i]);

    int ans = countvowels(word, n);
    printf("%d", ans);
    
    return 0;
}