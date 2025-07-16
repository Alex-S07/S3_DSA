#include <stdio.h>

struct polyn {
    int coeff;
    int expo;
} poly1[100], poly2[100], result[200];  // Arrays of polyn structs for two polynomials and the result

int main() {
    int n1, n2, i = 0, j = 0, k = 0;

    // Read first polynomial
    printf("Enter the number of terms in first polynomial: ");
    scanf("%d", &n1);
    for (i = 0; i < n1; i++) {
        printf("Enter the coefficient for term %d: ", i + 1);
        scanf("%d", &poly1[i].coeff);
        printf("Enter the exponent for term %d: ", i + 1);
        scanf("%d", &poly1[i].expo);
    }

    // Read second polynomial
    printf("Enter the number of terms in second polynomial: ");
    scanf("%d", &n2);
    for (i = 0; i < n2; i++) {
        printf("Enter the coefficient for term %d: ", i + 1);
        scanf("%d", &poly2[i].coeff);
        printf("Enter the exponent for term %d: ", i + 1);
        scanf("%d", &poly2[i].expo);
    }

    // Add polynomials - assuming terms are sorted by decreasing exponent
    i = 0; j = 0; k = 0;
    while (i < n1 && j < n2) {
        if (poly1[i].expo > poly2[j].expo) {
            result[k++] = poly1[i++];
        } else if (poly1[i].expo < poly2[j].expo) {
            result[k++] = poly2[j++];
        } else {
            // Same exponent, add coefficients
            int sumCoeff = poly1[i].coeff + poly2[j].coeff;
            if (sumCoeff != 0) {
                result[k].coeff = sumCoeff;
                result[k].expo = poly1[i].expo;
                k++;
            }
            i++;
            j++;
        }
    }

    // Copy remaining terms
    while (i < n1) {
        result[k++] = poly1[i++];
    }
    while (j < n2) {
        result[k++] = poly2[j++];
    }

    // Print the result
    printf("Resultant polynomial after addition:\n");
    for (i = 0; i < k; i++) {
        printf("%dx^%d", result[i].coeff, result[i].expo);
        if (i < k - 1)
            printf(" + ");
    }
    printf("\n");

    return 0;
}
