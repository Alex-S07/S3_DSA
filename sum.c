#include <stdio.h>

struct polyn {
    int coeff;
    int expo;
} poly1[100], poly2[100], poly3[100]; 

int main() {
    int n1, n2, i, k = 0;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    for (i = 0; i < n1; i++) {
        printf("Enter the coefficient for term %d: ", i + 1);
        scanf("%d", &poly1[i].coeff);
        printf("Enter the exponent for term %d: ", i + 1);
        scanf("%d", &poly1[i].expo);
    }

   
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);
    for (i = 0; i < n2; i++) {
        printf("Enter the coefficient for term %d: ", i + 1);
        scanf("%d", &poly2[i].coeff);
        printf("Enter the exponent for term %d: ", i + 1);
        scanf("%d", &poly2[i].expo);
    }



    for (i = 0; i < n1; i++) {
        if (poly1[i].expo != poly2[i].expo) {
            printf("Error: The exponents of the polynomials do not match at term %d.\n", i + 1);
            return 1;  
        }
     
        poly3[i].coeff = poly1[i].coeff + poly2[i].coeff;
        poly3[i].expo = poly1[i].expo;  
    }

    
    printf("Resultant polynomial after addition:\n");
    for (i = 0; i < n1; i++) {
        printf("%dx^%d", poly3[i].coeff, poly3[i].expo);
        if (i < n1 - 1)
            printf(" + ");
    }
    printf("\n");

    return 0;
}
