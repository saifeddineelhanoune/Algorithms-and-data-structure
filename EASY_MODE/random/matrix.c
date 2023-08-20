#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix of integers
int** allocateMatrix(int rows, int cols) 
{
    int **matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
        matrix[i] = (int*)malloc(cols * sizeof(int));
    return matrix;
}

// Function to initialize a matrix with values
void initializeMatrix(int** matrix, int rows, int cols) 
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = i * cols + j;
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
void freeMatrix(int** matrix, int rows) 
{
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
}

int main() 
{

    // Declare a triple pointer to hold a double pointer
    int*** triplePointer;

    /* Allocate memory for the double pointer
    triplePointer = (int***) malloc(sizeof(int**));
    */

    /* Allocate memory for the matrix using the double pointer
    *triplePointer = allocateMatrix(/*rows, cols);
    */

    /* Initialize the matrix with values
    initializeMatrix(*triplePointer, rows, cols);
    */

    /* Print the matrix
    printf("Matrix:\n");
    printMatrix(*triplePointer, rows, cols);
    */

    /* Free the memory allocated for the matrix
    freeMatrix(*triplePointer, rows);
    */

    /* Free the memory allocated for the double pointer
    free(triplePointer);
    */



    return 0;
}

