/*
3. Character Frequency in a File Name
A system administrator wants to count how many times a specific character (like
'e') appears in a file name. Write a program to find and display the frequency of a
given character in a user-input string.
*/

#include<stdio.h>

int countCharacter(char str[], char target) {
    int count = 0;
    
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == target) {
            count++;
        }
    }
    
    return count;
}

int main() {
    char str[100];
    char target;
    
    printf("Enter the string (file name): ");
    scanf("%s", str);  // or use fgets for strings with spaces
    
    printf("Enter the character to search: ");
    scanf(" %c", &target);  // Note the space before %c
    
    int frequency = countCharacter(str, target);
    
    printf("The character '%c' appears %d times in the string.\n", target, frequency);
    
    return 0;
}




// freq of all characters

#include<stdio.h>

void charFrequency(char word[], int n){
    int freq[256] = {0};  // Array to store frequency of all ASCII characters
    
    // Count frequency of each character
    for(int i = 0; i < n; i++){
        freq[(int)word[i]]++;
    }
    
    // Print characters that appear in the word
    printf("Character frequencies:\n");
    for(int i = 0; i < 256; i++){
        if(freq[i] > 0){
            printf("'%c' : %d\n", i, freq[i]);
        }
    }
}

int main(){
    int n;
    printf("Enter length of word: ");
    scanf("%d", &n);
    getchar(); // consume newline
    
    char word[n];
    printf("Enter the word: ");
    for(int i = 0; i < n; i++) scanf("%c", &word[i]);
    
    charFrequency(word, n);
    
    return 0;
}
// ```

// ## How it works:

// 1. **`freq[256]`**: Creates an array of size 256 (for all ASCII characters) initialized to 0
// 2. **`freq[(int)word[i]]++`**: Uses the ASCII value of each character as an index and increments its count
// 3. **Print only non-zero frequencies**: Loops through the frequency array and prints only characters that appeared

// ## Example:
// ```
// Input: "hello"
// Output:
// 'h' : 1
// 'e' : 1
// 'l' : 2
// 'o' : 1