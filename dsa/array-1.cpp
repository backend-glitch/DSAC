#include <bits/stdc++.h>
using namespace std;

class Array {
private:
    int* arr;
    int size;
    int capacity;

public:
    // Constructor
    Array(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    // Destructor
    ~Array() {
        delete[] arr;
    }

    // Insert at end
    void push_back(int value) {
        if (size == capacity) {
            cout << "Array full\n";
            return;
        }
        arr[size++] = value;
    }

    // Access element
    int get(int index) {
        if (index < 0 || index >= size)
            return -1;
        return arr[index];
    }

    // Display
    void display() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void insertAt(int index, int value) {

    // Invalid index
    if (index < 0 || index > size) {
        cout << "Invalid index\n";
        return;
    }

    // Array full
    if (size == capacity) {
        cout << "Array full\n";
        return;
    }

    // Shift elements to right
    for (int i = size - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }

    // Insert value
    arr[index] = value;
    size++;
}


void deleteAt(int index) {

    // Invalid index
    if (index < 0 || index >= size) {
        cout << "Invalid index\n";
        return;
    }

    // Shift elements to left
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
}


};


int main(){

    Array a(5);   // capacity = 5

    a.push_back(10);
    a.push_back(20);
    a.push_back(30);

    a.display();   
}