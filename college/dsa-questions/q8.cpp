#include <iostream>
using namespace std;

#define SIZE 10
#define EMPTY -1

int hash1(int key) {
    return key % 10;
}

int hash2(int key) {
    return 7 - (key % 7);  
}


void linearProbing(int keys[], int n) {
    int table[10];
    for (int i = 0; i < 10; i++) table[i] = -1;

    cout << "\n Linear Probing \n";
    for (int i = 0; i < n; i++) {
        int index = hash1(keys[i]);
        int collisions = 0;

        while (table[index] != -1) {
            collisions++;
            index = (index + 1) % 10;
        }

        table[index] = keys[i];
        cout << "Inserted " << keys[i]
             << "  Collisions: " << collisions << endl;
    }
}

void quadraticProbing(int keys[], int n) {
    int table[10];
    for (int i = 0; i < 10; i++) table[i] = -1;

    cout << "\n Quadratic Probing \n";
    for (int i = 0; i < n; i++) {
        int index = hash1(keys[i]);
        int collisions = 0;
        int j = 1;

        while (table[index] != -1) {
            collisions++;
            index = (hash1(keys[i]) + j * j) % 10;
            j++;
        }

        table[index] = keys[i];
        cout << "Inserted " << keys[i]
             << "  Collisions: " << collisions << endl;
    }
}


void doubleHashing(int keys[], int n) {
    int table[SIZE];
    for (int i = 0; i < 10; i++) table[i] = -1;

    cout << "\n Double Hashing \n";
    for (int i = 0; i < n; i++) {
        int index = hash1(keys[i]);
        int step = hash2(keys[i]);
        int collisions = 0;

        while (table[index] != -1) {
            collisions++;
            index = (index + step) % 10;
        }

        table[index] = keys[i];
        cout << "Inserted " << keys[i]
             << "  Collisions: " << collisions << endl;
    }
}

int main() {
    int n;
    int keys[10];

    cout << "Enter number of keys: ";
    cin >> n;

    cout << "Enter keys:\n";
    for (int i = 0; i < n; i++)
        cin >> keys[i];

    linearProbing(keys, n);
    quadraticProbing(keys, n);
    doubleHashing(keys, n);

    return 0;
}
