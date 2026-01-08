/*
to check whether a prime number or not and if prime number then convert to binary
*/

#include <stdio.h>
#include <math.h>
int isPrime(int n)
{
    if (n <= 1)
    {
        return 0; // Not prime
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0; // Not prime
        }
    }
    return 1; // Prime
}
void decimalToBinary(int n)
{
    if (n == 0)
    {
        printf("0");
        return;
    }
    while (n > 0)
    {
        printf("%d", n % 2);
        n /= 2;
    }
}

int main()
{
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    if (isPrime(num))
    {
        printf("The binary representation of the prime number %d is: ", num);
        decimalToBinary(num);
        printf("\n");
    }
    else
    {
        printf("%d is not a prime number.\n", num);
    }
    return 0;
}