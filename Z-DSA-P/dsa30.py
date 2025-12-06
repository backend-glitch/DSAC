# stacks

MAX_SIZE = 5
stack = [0] * MAX_SIZE
top = -1

def push(value):
    global top
    if top == MAX_SIZE - 1:
        print("Shelf is full. Cannot add more books.")
        return
    top += 1
    stack[top] = value
    print(f"Book {value} is added to the shelf")

def pop():
    global top
    if top == -1:
        print("No books on the shelf")
        return
    element = stack[top]
    top -= 1
    print(f"Book {element} is removed from the shelf")

def displayStack():
    if top == -1:
        print("Shelf is empty")
        return
    print("Books on the shelf:", end=" ")
    for i in range(top, -1, -1):
        print(stack[i], end=" ")
    print()

def peek():
    if top == -1:
        print("Shelf is empty")
    else:
        print(f"Top book on the shelf: {stack[top]}")