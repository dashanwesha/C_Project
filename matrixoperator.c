#include <stdio.h>
#include <stdlib.h>

void readMatrix(int rows, int cols, double matrix[][cols])
{
    printf("Enter the %dx%d matrix:\n", rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void displayMatrix(int rows, int cols, double matrix[][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void addMatrices(int rows, int cols, double matrix1[][cols], double matrix2[][cols], double result[][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int rows, int cols, double matrix1[][cols], double matrix2[][cols], double result[][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyScalar(int rows, int cols, double matrix[][cols], double scalar, double result[][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
}

void multiplyMatrices(int rows1, int cols1, int cols2, double matrix1[][cols1], double matrix2[][cols2], double result[][cols2])
{
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            result[i][j] = 0.0;
            for (int k = 0; k < cols1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void transposeMatrix(int rows, int cols, double matrix[][cols], double result[][rows])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
}

int main()
{
    int rows, cols, choice;
    double scalar;
    int cols2;

    printf("Matrix Operations Program\n");
    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &rows);
    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &cols);

    double matrix1[rows][cols], matrix2[rows][cols], result[rows][cols];

    readMatrix(rows, cols, matrix1);

    printf("Choose the matrix operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication with a scalar\n");
    printf("4. Multiplication with another matrix\n");
    printf("5. Transpose of the matrix\n");
    printf("Enter the corresponding number (1-5): ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        readMatrix(rows, cols, matrix2);
        addMatrices(rows, cols, matrix1, matrix2, result);
        printf("\nResultant Matrix:\n");
        displayMatrix(rows, cols, result);
        break;

    case 2:
        readMatrix(rows, cols, matrix2);
        subtractMatrices(rows, cols, matrix1, matrix2, result);
        printf("\nResultant Matrix:\n");
        displayMatrix(rows, cols, result);
        break;

    case 3:
        printf("Enter the scalar value: ");
        scanf("%lf", &scalar);
        multiplyScalar(rows, cols, matrix1, scalar, result);
        printf("\nResultant Matrix:\n");
        displayMatrix(rows, cols, result);
        break;

    case 4:
        printf("Enter the number of columns in the second matrix: ");
        scanf("%d", &cols2);
        if (cols != cols2)
        {
            printf("Matrix dimensions are not compatible for multiplication.\n");
        }
        else
        {
            double matrix2[cols][cols2];
            readMatrix(cols, cols2, matrix2);
            multiplyMatrices(rows, cols, cols2, matrix1, matrix2, result);
            printf("\nResultant Matrix:\n");
            displayMatrix(rows, cols2, result);
        }
        break;

    case 5:
        transposeMatrix(rows, cols, matrix1, result);
        printf("\nResultant Matrix:\n");
        displayMatrix(cols, rows, result);
        break;

    default:
        printf("Invalid choice. Please select a number from 1 to 5.\n");
    }

    return 0;
}