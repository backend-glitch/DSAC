# queues

def isFull():
    return rear == MAX_CUSTOMERS - 1

def isEmpty():
    return front == -1

def addCustomer(customerID):
    global front, rear
    if isFull():
        return 0
    else:
        rear += 1
        customerIDs[rear] = customerID
        if front == -1:
            front = 0
        return 1

def processCustomer():
    global front, rear
    if isEmpty():
        customerID = -1
        return customerID, 0
    else:
        customerID = customerIDs[front]
        front += 1
        if front > rear:
            initializeQueue()
        return customerID, 1

def displayQueue():
    if isEmpty():
        print("Checkout queue is empty.")
    else:
        print("Customers waiting in the checkout queue: ", end="")
        for i in range(front, rear + 1):
            print(customerIDs[i], end=" ")
        print()