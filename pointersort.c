#include <stdio.h>

int main() {
    int arr[100], n, i, j, temp;
    FILE *fp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", (arr + i)); 
    }

   
    fp = fopen("array.txt", "w");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(fp, "Unsorted array:\n");
    for(i = 0; i < n; i++) {
        fprintf(fp, "%d ", *(arr + i)); 
    }
    fprintf(fp, "\n");

    
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(*(arr + j) > *(arr + j + 1)) {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }


    fprintf(fp, "Sorted array:\n");
    for(i = 0; i < n; i++) {
        fprintf(fp, "%d ", *(arr + i));
    }
    fprintf(fp, "\n");
    fclose(fp);

    
    printf("Sorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    printf("Arrays written to file 'array.txt'.\n");
    return 0;
}
