#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int deque[MAX];
int front = -1, rear = -1;

void insertFront(int val) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque is full!\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = val;
    printf("Inserted %d at front.\n", val);
}

void insertRear(int val) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque is full!\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = val;
    printf("Inserted %d at rear.\n", val);
}

void deleteFront() {
    if (front == -1) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deleted %d from front.\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

void deleteRear() {
    if (front == -1) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deleted %d from rear.\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque elements: ");
    i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n---DEQUEUE MENU---\n");
        printf("1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &val);
                insertFront(val);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &val);
                insertRear(val);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
