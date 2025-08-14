#include<stdio.h>

struct poly {
    int coeff;
    int exp;
} poly1[10], poly2[10], poly3[20];

int main() {
    int n1, n2, i, j, k;
    
    printf("enter the no.of terms of 1st poly:");
    scanf("%d", &n1);
    for (i = 0; i < n1; i++) {
        printf("enter the coefficent:");
        scanf("%d", &poly1[i].coeff);
        printf("enter the exponent:");
        scanf("%d", &poly1[i].exp);
    }
    
    printf("enter the no.of terms of 2nd poly:");
    scanf("%d", &n2);
    for (i = 0; i < n2; i++) {
        printf("enter the coefficent:");
        scanf("%d", &poly2[i].coeff);
        printf("enter the exponent:");
        scanf("%d", &poly2[i].exp);
    }
    
    i = j = k = 0;
    
    while (i < n1 && j < n2) {
        if (poly1[i].exp == poly2[j].exp) {
            poly3[k].coeff = poly1[i].coeff + poly2[j].coeff;
            poly3[k].exp = poly1[i].exp;
            i++;
            j++;
            k++;
        } else if (poly1[i].exp > poly2[j].exp) {
            poly3[k].coeff = poly1[i].coeff;
            poly3[k].exp = poly1[i].exp;
            i++;
            k++;
        } else {
            poly3[k].coeff = poly2[j].coeff;
            poly3[k].exp = poly2[j].exp;
            j++;
            k++;
        }
    }
    
    while (i < n1) {
        poly3[k].coeff = poly1[i].coeff;
        poly3[k].exp = poly1[i].exp;
        i++;
        k++;
    }
    
    while (j < n2) {
        poly3[k].coeff = poly2[j].coeff;
        poly3[k].exp = poly2[j].exp;
        j++;
        k++;
    }
    
   for(i=0;i<k-1;i++)
 			printf("%d(x)^%d + ",poly3[i].coeff,poly3[i].exp);
 	printf("%d(x)^%d",poly3[i].coeff,poly3[i].exp);
    
    return 0;
}
