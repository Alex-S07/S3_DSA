#include <stdio.h>
#include <stdlib.h>

// Node structure for a term in the polynomial
typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into the polynomial in descending order of exponents
void insertTerm(Node** poly, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
    if (*poly == NULL || (*poly)->exp < exp) {
        newNode->next = *poly;
        *poly = newNode;
    } else {
        Node* current = *poly;
        while (current->next != NULL && current->next->exp > exp) {
            current = current->next;
        }
        if (current->next != NULL && current->next->exp == exp) {
            current->next->coeff += coeff; // Combine like terms
            free(newNode);
        } else {
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}

// Function to input a polynomial from user
Node* inputPolynomial() {
    int n, coeff, exp;
    Node* poly = NULL;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d%d", &coeff, &exp);
        insertTerm(&poly, coeff, exp);
    }
    return poly;
}

// Function to add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* p1 = poly1;
    Node* p2 = poly2;
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            insertTerm(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            insertTerm(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0) {
                insertTerm(&result, sum, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        insertTerm(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insertTerm(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return result;
}

// Function to print a polynomial
void printPolynomial(Node* poly) {
    if (!poly) {
        printf("0\n");
        return;
    }
    while (poly != NULL) {
        if (poly->coeff > 0 && poly != NULL)
            printf(poly == NULL ? "%d" : "%d", poly->coeff);
        else
            printf("%d", poly->coeff);
        if (poly->exp != 0)
            printf("x^%d", poly->exp);
        if (poly->next != NULL && poly->next->coeff > 0)
            printf(" + ");
        else if (poly->next != NULL && poly->next->coeff < 0)
            printf(" ");
        poly = poly->next;
    }
    printf("\n");
}

// Function to free memory
void freePolynomial(Node* poly) {
    Node* tmp;
    while (poly != NULL) {
        tmp = poly;
        poly = poly->next;
        free(tmp);
    }
}

int main() {
    printf("Enter first polynomial:\n");
    Node* poly1 = inputPolynomial();

    printf("Enter second polynomial:\n");
    Node* poly2 = inputPolynomial();

    Node* sum = addPolynomials(poly1, poly2);

    printf("First Polynomial: ");
    printPolynomial(poly1);

    printf("Second Polynomial: ");
    printPolynomial(poly2);

    printf("Sum: ");
    printPolynomial(sum);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(sum);
    return 0;
}
