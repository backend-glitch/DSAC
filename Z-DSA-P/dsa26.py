stack = []

while True:
    print("\n1. Push\n2. Pop\n3. Display\n4. Exit")
    ch = int(input("Enter choice: "))
    if ch == 1:
        val = input("Enter value: ")
        stack.append(val)
    elif ch == 2:
        if stack:
            print("Popped:", stack.pop())
        else:
            print("Stack Empty")
    elif ch == 3:
        print("Stack:", stack)
    else:
        break


queue = []

while True:
    print("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit")
    ch = int(input("Enter choice: "))
    if ch == 1:
        val = input("Enter value: ")
        queue.append(val)
    elif ch == 2:
        if queue:
            print("Dequeued:", queue.pop(0))
        else:
            print("Queue Empty")
    elif ch == 3:
        print("Queue:", queue)
    else:
        break
