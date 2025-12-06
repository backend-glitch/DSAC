## queue simple

MAX_SIZE = 5
queue = [0] * MAX_SIZE
front = -1
rear = -1

def isEmpty():
    return front == -1

def isFull():
    return rear == MAX_SIZE - 1

def enqueue(item):
    global front, rear
    if isFull():
        print("Queue is full! Cannot enqueue.")
    else:
        if isEmpty():
            front = 0
        rear += 1
        queue[rear] = item
        print(f"Enqueued: {item}")

def dequeue():
    global front, rear
    if isEmpty():
        print("Queue is empty! Cannot dequeue.")
    else:
        item = queue[front]
        print(f"Dequeued: {item}")
        if front == rear:
            # Queue becomes empty after removing last element
            front = rear = -1
        else:
            front += 1

def display():
    if isEmpty():
        print("Queue is empty.")
    else:
        print("Queue elements:", end=" ")
        for i in range(front, rear + 1):
            print(queue[i], end=" ")
        print()

# Example run
enqueue(10)
enqueue(20)
enqueue(30)
display()

dequeue()
display()

enqueue(40)
enqueue(50)
enqueue(60)  # should show full message
display()


## stack

MAX_SIZE = 5
stack = [0] * MAX_SIZE
top = -1

def isEmpty():
    return top == -1

def isFull():
    return top == MAX_SIZE - 1

def push(item):
    global top
    if isFull():
        print("Stack is full! Cannot push.")
    else:
        top += 1
        stack[top] = item
        print(f"Pushed: {item}")

def pop():
    global top
    if isEmpty():
        print("Stack is empty! Cannot pop.")
    else:
        item = stack[top]
        print(f"Popped: {item}")
        top -= 1

def peek():
    if isEmpty():
        print("Stack is empty!")
    else:
        print(f"Top element: {stack[top]}")

def display():
    if isEmpty():
        print("Stack is empty.")
    else:
        print("Stack elements (top → bottom): ", end="")
        for i in range(top, -1, -1):
            print(stack[i], end=" ")
        print()

# Example run
push(10)
push(20)
push(30)
display()

peek()

pop()
display()

push(40)
push(50)
push(60)  # should show full message
display()
