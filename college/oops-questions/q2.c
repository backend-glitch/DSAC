/*
checks whether a number is palindrome or not ,if palindrome then reverse the text.
*/

#include <stdio.h>
#include <string.h>
// Function to check if a string is a palindrome
int isPalindrome(char str[])
{
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++)
    {
        if (str[i] != str[n - i - 1])
        {
            return 0; // False
        }
    }
    return 1; // True
}
// Function to reverse a string
void reverseString(char str[])
{
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++)
    {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

int main()
{
    char review[256];

    printf("Enter the customer review: ");
    fgets(review, sizeof(review), stdin);
    review[strcspn(review, "\n")] = '\0'; // Remove newline character from input


    if (isPalindrome(review))
    {
        printf("The review '%s' is a unique palindrome review.\n", review);
    }
    else
    {
        reverseString(review);
        printf("The reversed review text is '%s'.\n", review);
    }
    return 0;
}