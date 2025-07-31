#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue() {
    int item;
    if ((rear + 1) % MAX == front) {
        printf("Overflow: Queue is full\n");
        return;
    }
    printf("Enter item to insert: ");
    scanf("%d", &item);

    if (front == -1) { // queue was empty
        front = 0;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = item;
    printf("Inserted: %d\n", item);
}


void dequeue() {
    if (front == -1) {
        printf("Underflow: Queue is empty\n");
        return;
    }
    printf("Deleted: %d\n", queue[front]);
    if (front == rear) {
        
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

e
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; ; i = (i + 1) % MAX) {
        printf("%d ", queue[i]);
        if (i == rear) break;
    }
    printf("\n");
}


int main() {
    int choice;

    do {
        printf("\n 1. Enqueue\n 2. Dequeue\n 3 . Display\n 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
