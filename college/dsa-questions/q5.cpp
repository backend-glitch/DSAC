#include <iostream>
using namespace std;

class Deque {
private:
    static const int MAX = 5;
    int arr[MAX];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    void enqueueFront(int x) {
        if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
            cout << "Deque Overflow\n";
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX - 1;
        } else {
            front--;
        }

        arr[front] = x;
        cout << x << " inserted at front\n";
    }

    void enqueueRear(int x) {
        if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
            cout << "Deque Overflow\n";
            return;
        }

        if (rear == -1) {
            front = rear = 0;
        } else if (rear == MAX - 1) {
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = x;
        cout << x << " inserted at rear\n";
    }

    void dequeueFront() {
        if (front == -1) {
            cout << "Deque Underflow\n";
            return;
        }

        cout << arr[front] << " removed from front\n";

        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    void dequeueRear() {
        if (rear == -1) {
            cout << "Deque Underflow\n";
            return;
        }

        cout << arr[rear] << " removed from rear\n";

        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX - 1;
        } else {
            rear--;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Deque elements: ";
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
            cout << "Deque is empty\n";
            return;
        }

        cout << "Front index: " << front << endl;
        cout << "Rear index: " << rear << endl;
    }
};

int main() {
    Deque dq;
    int choice, value;

    while (true) {
        cout << "1. Enqueue Front\n";
        cout << "2. Enqueue Rear\n";
        cout << "3. Dequeue Front\n";
        cout << "4. Dequeue Rear\n";
        cout << "5. Display\n";
        cout << "6. Show Front & Rear\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            dq.enqueueFront(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            dq.enqueueRear(value);
            break;

        case 3:
            dq.dequeueFront();
            break;

        case 4:
            dq.dequeueRear();
            break;

        case 5:
            dq.display();
            break;

        case 6:
            dq.showPointers();
            break;

        case 7:
            return 0;

        default:
            cout << "Invalid choice\n";
        }
    }
}


