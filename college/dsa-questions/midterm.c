#include <stdio.h>

int main() {
    int A[100], A1[100], A2[100];
    int n, n1 = 0, n2 = 0;
    int oddnum=0,evennum=0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    for(int i = 0; i < n; i++) {

        if(A[i] % 2 == 0) {
            // Insert into A1 (even array) using pos method
            int pos = 0;

            while(pos < n1 && A1[pos] < A[i]) {
                pos++;
            }

            for(int j = n1; j > pos; j--) {
                A1[j] = A1[j - 1];
            }

            A1[pos] = A[i];
            n1++;
            evennum++;
        }
        else {
            // Insert into A2 (odd array) using pos method
            int pos = 0;

            while(pos < n2 && A2[pos] < A[i]) {
                pos++;
            }

            for(int j = n2; j > pos; j--) {
                A2[j] = A2[j - 1];
            }

            A2[pos] = A[i];
            n2++;
            oddnum++;
        }
    }
    
    A1[n1++] = evennum;
    A2[n2++] = oddnum;
    
    int maxeven = A1[0];
    for(int i=0;i<n1;i++){
        if(maxeven < A1[i]) maxeven = A1[i];
    }

 int minodd = A2[0];
    for(int i=0;i<n2;i++){
        if(minodd > A2[i]) minodd = A2[i];
    }

    printf("\nEven Elements (Sorted): ");
    for(int i = 0; i < n1; i++)
        printf("%d ", A1[i]);

    printf("\nOdd Elements (Sorted): ");
    for(int i = 0; i < n2; i++)
        printf("%d ", A2[i]);

    int avg = (minodd + maxeven) / 2;
    printf("\nthe avg is : %.2d",avg);

    return 0;
}