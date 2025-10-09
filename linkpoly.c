#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Insert node in descending order of exponent
void insertTerm(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*head == NULL || (*head)->exp < exp) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL && temp->next->exp > exp) {
            temp = temp->next;
        }
        // If exponent is same, add coefficients
        if (temp->next != NULL && temp->next->exp == exp) {
            temp->next->coeff += coeff;
            free(newNode);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

// Function to print polynomial
void printPoly(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d(x)^%d", temp->coeff, temp->exp);
        if (temp->next != NULL) printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two polynomials and return the result linked list
struct Node* addPoly(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;
    struct Node *temp1 = p1, *temp2 = p2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exp == temp2->exp) {
            insertTerm(&result, temp1->coeff + temp2->coeff, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->exp > temp2->exp) {
            insertTerm(&result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        } else {
            insertTerm(&result, temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
    }

    // Add remaining terms from p1
    while (temp1 != NULL) {
        insertTerm(&result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    // Add remaining terms from p2
    while (temp2 != NULL) {
        insertTerm(&result, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }

    return result;
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *sum = NULL;
    int n1, n2, coeff, exp;

    printf("Enter the number of terms in first polynomial: ");
    scanf("%d", &n1);

    for (int i = 0; i < n1; i++) {
        printf("Enter coefficient for term %d: ", i + 1);
        scanf("%d", &coeff);
        printf("Enter exponent for term %d: ", i + 1);
        scanf("%d", &exp);
        insertTerm(&poly1, coeff, exp);
    }

    printf("Enter the number of terms in second polynomial: ");
    scanf("%d", &n2);

    for (int i = 0; i < n2; i++) {
        printf("Enter coefficient for term %d: ", i + 1);
        scanf("%d", &coeff);
        printf("Enter exponent for term %d: ", i + 1);
        scanf("%d", &exp);
        insertTerm(&poly2, coeff, exp);
    }

    printf("\nFirst polynomial: ");
    printPoly(poly1);

    printf("Second polynomial: ");
    printPoly(poly2);

    sum = addPoly(poly1, poly2);

    printf("\nSum of polynomials: ");
    printPoly(sum);

    return 0;
}
