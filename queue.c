#include <stdio.h>
#define size 5

int queue[size];
int front = -1;
int rear = -1;

void insertion() {
    if (rear == size - 1) {
        printf("Overflow\n");
        return;
    }

    int value;
    printf("Enter the number: ");
    scanf("%d", &value);

    if (front == -1) { // Queue was empty
        front = 0;
    }
    rear++;
    queue[rear] = value;
}

void deletion() {
    if (front == -1 || front > rear) {
        printf("Underflow\n");
    }
    else {
        printf("Deleted element is %d\n", queue[front]);
        
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front++; 
        }
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    }
    else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n 1. Insertion\n 2. Deletion\n 3. Display\n 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertion();
                break;
            case 2:
                deletion();
                break;
            case 3:
                display();
                break; 
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
