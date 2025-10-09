#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char url[100];
    struct Node* prev;
    struct Node* next;
};

int main() {
    struct Node* current = NULL;
    int choice;
    char url[100];
        printf("\nBrowser Navigation Menu:\n");
        printf("1. New Page\n");
        printf("2. Go Back\n");
        printf("3. Go Forward\n");
        printf("4. Exit\n");
        do{
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Enter URL to visit: ");
                fgets(url, sizeof(url), stdin);
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                strcpy(newNode->url, url);
                newNode->prev = current;
                newNode->next = NULL;
                if (current != NULL) {
                    current->next = newNode;
                }
                current = newNode;
                printf("Visited: %s\n", url);
                break;
            case 2:
                if (current == NULL || current->prev == NULL) {
                    printf("Cannot go back.\n");
                } else {
                    current = current->prev;
                    printf("Moved back to: %s\n", current->url);
                }
                break;
            case 3:
                if (current == NULL || current->next == NULL) {
                    printf("Cannot go forward.\n");
                } else {
                    current = current->next;
                    printf("Moved forward to: %s\n", current->url);
                }
                break;
            case 5:
                if (current == NULL) {
                    printf("No page visited yet.\n");
                } else {
                    printf("Current Page: %s\n", current->url);
                }
                break;
            case 4:
                   printf("Exiting....");
                   exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }}
        while(choice<=4);
    return 0;
    }
