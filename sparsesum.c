#include <stdio.h>
#define MAX 10
void convertToSparseMatrix(int mat[MAX][MAX], int rows, int cols, int sparse[MAX][3], int *count) {
    *count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                sparse[*count][0] = i;            // Row index
                sparse[*count][1] = j;            // Column index
                sparse[*count][2] = mat[i][j];    // Value
                (*count)++;
            }
        }
    }
}

void displaySparseMatrix(int sparse[MAX][3], int count) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

void addSparseMatrices(int sparse1[MAX][3], int count1, int sparse2[MAX][3], int count2, int rows, int cols, int resultSparse[MAX][3], int *resultCount) {
    int i = 0, j = 0, k = 0;

    // Traverse both sparse matrices and add corresponding elements
    while (i < count1 && j < count2) {
        if (sparse1[i][0] < sparse2[j][0] || (sparse1[i][0] == sparse2[j][0] && sparse1[i][1] < sparse2[j][1])) {
            resultSparse[k][0] = sparse1[i][0];
            resultSparse[k][1] = sparse1[i][1];
            resultSparse[k][2] = sparse1[i][2];
            i++;
            k++;
        }
        else if (sparse1[i][0] > sparse2[j][0] || (sparse1[i][0] == sparse2[j][0] && sparse1[i][1] > sparse2[j][1])) {
            resultSparse[k][0] = sparse2[j][0];
            resultSparse[k][1] = sparse2[j][1];
            resultSparse[k][2] = sparse2[j][2];
            j++;
            k++;
        }
        else {  // Same position, add values
            resultSparse[k][0] = sparse1[i][0];
            resultSparse[k][1] = sparse1[i][1];
            resultSparse[k][2] = sparse1[i][2] + sparse2[j][2];
            i++;
            j++;
            k++;
        }
    }

    // Copy remaining elements from sparse1
    while (i < count1) {
        resultSparse[k][0] = sparse1[i][0];
        resultSparse[k][1] = sparse1[i][1];
        resultSparse[k][2] = sparse1[i][2];
        i++;
        k++;
    }

    // Copy remaining elements from sparse2
    while (j < count2) {
        resultSparse[k][0] = sparse2[j][0];
        resultSparse[k][1] = sparse2[j][1];
        resultSparse[k][2] = sparse2[j][2];
        j++;
        k++;
    }

    *resultCount = k;  // Resultant count of non-zero elements
}

int main() {
    int mat1[MAX][MAX], mat2[MAX][MAX], sparse1[MAX][3], sparse2[MAX][3], resultSparse[MAX][3];
    int rows, cols, count1, count2, resultCount;

    // Input matrix 1
    printf("Enter the number of rows and columns for matrices: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements of matrix 1:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    // Input matrix 2
    printf("Enter elements of matrix 2:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Convert matrix 1 to sparse matrix
    convertToSparseMatrix(mat1, rows, cols, sparse1, &count1);
    printf("Sparse Matrix 1:\n");
    displaySparseMatrix(sparse1, count1);

    // Convert matrix 2 to sparse matrix
    convertToSparseMatrix(mat2, rows, cols, sparse2, &count2);
    printf("Sparse Matrix 2:\n");
    displaySparseMatrix(sparse2, count2);

    // Add sparse matrices
    addSparseMatrices(sparse1, count1, sparse2, count2, rows, cols, resultSparse, &resultCount);
    printf("Resultant Sparse Matrix (Sum):\n");
    displaySparseMatrix(resultSparse, resultCount);

    return 0;
}
