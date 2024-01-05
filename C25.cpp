#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} Triple;

typedef struct {
    Triple* data;
    int rows;
    int cols;
    int count;
} SparseMatrix;

SparseMatrix createSparseMatrix(int rows, int cols) {
    SparseMatrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.count = 0;
    matrix.data = (Triple*)malloc(sizeof(Triple) * (rows * cols));
    return matrix;
}

void setElement(SparseMatrix* matrix, int row, int col, int value) {
    if (row >= matrix->rows || col >= matrix->cols) {
        printf("元素下标越界\n");
        return;
    }
    
    if (value == 0) {
        // 不存储值为 0 的元素
        return;
    }
    
    int index = matrix->count;
    matrix->data[index].row = row;
    matrix->data[index].col = col;
    matrix->data[index].value = value;
    matrix->count++;
}

int getElement(SparseMatrix matrix, int row, int col) {
    for (int i = 0; i < matrix.count; i++) {
        if (matrix.data[i].row == row && matrix.data[i].col == col) {
            return matrix.data[i].value;
        }
    }
    return 0;
}

SparseMatrix addSparseMatrix(SparseMatrix matrix1, SparseMatrix matrix2) {
    if (matrix1.rows != matrix2.rows || matrix1.cols != matrix2.cols) {
        printf("矩阵维度不匹配\n");
        exit(1);
    }
    
    SparseMatrix result = createSparseMatrix(matrix1.rows, matrix1.cols);
    
    int i = 0, j = 0;
    while (i < matrix1.count && j < matrix2.count) {
        if (matrix1.data[i].row < matrix2.data[j].row ||
            (matrix1.data[i].row == matrix2.data[j].row && matrix1.data[i].col < matrix2.data[j].col)) {
            setElement(&result, matrix1.data[i].row, matrix1.data[i].col, matrix1.data[i].value);
            i++;
        } else if (matrix1.data[i].row > matrix2.data[j].row ||
                   (matrix1.data[i].row == matrix2.data[j].row && matrix1.data[i].col > matrix2.data[j].col)) {
            setElement(&result, matrix2.data[j].row, matrix2.data[j].col, matrix2.data[j].value);
            j++;
        } else {
            int sum = matrix1.data[i].value + matrix2.data[j].value;
            setElement(&result, matrix1.data[i].row, matrix1.data[i].col, sum);
            i++;
            j++;
        }
    }
    
    while (i < matrix1.count) {
        setElement(&result, matrix1.data[i].row, matrix1.data[i].col, matrix1.data[i].value);
        i++;
    }
    
    while (j < matrix2.count) {
        setElement(&result, matrix2.data[j].row, matrix2.data[j].col, matrix2.data[j].value);
        j++;
    }
    
    return result;
}

SparseMatrix multiplySparseMatrix(SparseMatrix matrix1, SparseMatrix matrix2) {
    if (matrix1.cols != matrix2.rows) {
        printf("矩阵维度不匹配\n");
        exit(1);
    }
    
    SparseMatrix result = createSparseMatrix(matrix1.rows, matrix2.cols);
    
    for (int i = 0; i < matrix1.rows; i++) {
        for (int j = 0; j < matrix2.cols; j++) {
            int sum = 0;
            for (int k = 0; k < matrix1.cols; k++) {
                sum += getElement(matrix1, i, k) * getElement(matrix2, k, j);
            }
            setElement(&result, i, j, sum);
        }
    }
    
    return result;
}

void printSparseMatrix(SparseMatrix matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            printf("%d ", getElement(matrix, i, j));
        }
        printf("\n");
    }
}

int main() {
    int rows1, cols1;
    printf("输入第一个矩阵的行数和列数：");
    scanf("%d %d", &rows1, &cols1);
    SparseMatrix matrix1 = createSparseMatrix(rows1, cols1);
    printf("输入第一个矩阵的元素：\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            int value;
            scanf("%d", &value);
            setElement(&matrix1, i, j, value);
        }
    }
    
    int rows2, cols2;
    printf("输入第二个矩阵的行数和列数：");
    scanf("%d %d", &rows2, &cols2);
    SparseMatrix matrix2 = createSparseMatrix(rows2, cols2);
    printf("输入第二个矩阵的元素：\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            int value;
            scanf("%d", &value);
            setElement(&matrix2, i, j, value);
        }
    }
    
    SparseMatrix sum = addSparseMatrix(matrix1, matrix2);
    printf("矩阵相加结果:\n");
    printSparseMatrix(sum);
    
    SparseMatrix product = multiplySparseMatrix(matrix1, matrix2);
    printf("矩阵相乘结果:\n");
    printSparseMatrix(product);
    
    return 0;
}
