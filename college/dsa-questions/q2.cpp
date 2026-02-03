#include <iostream>
using namespace std;


void listInt(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
void listChar(char b[], int n) {
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << endl;
}

int main() {
    int A[100], nA;
    char B[100];
    int nB;

    
    cout << "Enter number of elements in list A: ";
    cin >> nA;
    cout << "Enter elements of list A:\n";
    for (int i = 0; i < nA; i++)
        cin >> A[i];
    cout << "Enter number of elements in list B: ";
    cin >> nB;
    cout << "Enter elements of list B:\n";
    for (int i = 0; i < nB; i++)
        cin >> B[i];




    int pos, val;
  
    cin >> pos >> val;

    for (int i = nA; i > pos; i--)
        A[i] = A[i - 1];
    A[pos] = val;
    nA++;

    cout << "List A after insertion: ";
    listInt(A, nA);

    cout << "\nDelete position from A: ";
    cin >> pos;

    for (int i = pos; i < nA - 1; i++)
        A[i] = A[i + 1];
    nA--;

    cout << "List A after deletion: ";
    listInt(A, nA);

  
    int mid = nA / 2;
    cout << "\nSplitting list A:\nFirst half: ";
    for (int i = 0; i < mid; i++)
        cout << A[i] << " ";

    cout << "\nSecond half: ";
    for (int i = mid; i < nA; i++)
        cout << A[i] << " ";

    cout << endl;

    return 0;
}
