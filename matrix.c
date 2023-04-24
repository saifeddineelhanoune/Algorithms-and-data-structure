#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_COLS 20
// Function to allocate memory for a matrix of integers
int** allocateMatrix(int rows, int cols) 
{
    int** matrix = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
        matrix[i] = (int*) malloc(cols * sizeof(int));
    return matrix;
}

// Function to initialize a matrix with values
void initializeMatrix(int** matrix, int rows, int cols) 
{
    char c =  'a';
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = c++;
}

// Function to print the contents of a matrix
void printMatrix(int** matrix, int rows, int cols) 
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            write(1, &matrix[i][j], 1);
    write(1, "\n", 1);
}

// Function to free the memory allocated for a matrix
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
}

int main(int ac, char *av[])
{
    int **matrice;
    matrice = allocateMatrix(10, MAX_COLS);
    initializeMatrix(matrice, 10, MAX_COLS);
    printMatrix(matrice, 10, MAX_COLS);
    freeMatrix(matrice, 10);
    return 0;
}

