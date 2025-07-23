#include <stdio.h>

int front = -1, rear = -1;

void enqueue(int queue[], int max_size, int value) {
    if ((rear + 1) % max_size == front) {
        printf("QUEUE OVERFLOW\n");
        return;
    }
    if (front == -1&&rear== -1) {
        front = rear = 0;
        queue[rear] = value;
    } else {
        rear = (rear + 1) % max_size;
        queue[rear] = value;
    }
    printf("%d enqueued to queue\n", value);
}

void dequeue(int queue[], int max_size) {
    if (front == -1) {
        printf("QUEUE UNDERFLOW\n");
        return;
    }
    printf("Dequeued element: %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % max_size;
    }
}

void display(int queue[], int max_size) {
    if (front == -1&& rear== -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % max_size;
    }
    printf("\n");
}

int main() {
    int max_size;
    printf("Enter the maximum size of the queue:\n");
    scanf("%d", &max_size);

    int queue[max_size];

    int value;
    printf("Enter elements to enqueue (max %d elements):\n", max_size);
    for (int i = 0; i < max_size; i++) {
        scanf("%d", &value);
        enqueue(queue, max_size, value);
    }

    display(queue, max_size);
    enqueue(queue, max_size, 99);
    dequeue(queue, max_size);
    dequeue(queue, max_size);
    display(queue, max_size);
    enqueue(queue, max_size, 77);
    enqueue(queue, max_size, 88);

    display(queue, max_size);

    return 0;
}
