#include <stdio.h>
int front = -1, rear = -1;  

void enqueue(int queue[], int max_size, int value) {
    if (rear == max_size - 1) {
        printf("QUEUE OVERFLOW\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = value;
        printf("%d enqueued to queue\n", value);
    } 
    else {
        rear++;
        queue[rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}
void dequeue(int queue[]) {
    if (front == -1 || front > rear) {
        printf("QUEUE UNDERFLOW\n");
    } else {
        printf("Dequeued element: %d\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1; 
        }
    }
}

void display(int queue[]) {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int max_size;
    printf("Enter the maximum size of the queue:\n");
    scanf("%d", &max_size);

    int queue[max_size];  

    int value;
    printf("Enter %d queue elements:\n", max_size);
    for (int i = 0; i < max_size; i++) {
        scanf("%d", &value);
        enqueue(queue, max_size, value);
    }
    display(queue);
    enqueue(queue, max_size, 99);
    dequeue(queue);
    display(queue);
    return 0;
}
        
	
