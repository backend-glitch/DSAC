
#include <iostream>
using namespace std;

class CircularQueue {
private:
    static const int MAX = 5;
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {
        if ((rear + 1) % MAX == front) {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1)  
            front = 0;

        rear = (rear + 1) % MAX;
        arr[rear] = x;
        cout << x << " inserted\n";
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << arr[front] << " removed\n";

        if (front == rear) {  // last element removed
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    
    void display() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }

    void showPointers() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Front index: " << front << endl;
        cout << "Rear index: " << rear << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    while (true) {
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Show Front & Rear\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            q.showPointers();
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice\n";
        }
    }
}
