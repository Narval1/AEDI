#include <stdio.h>
#include <stdlib.h>

void *girarMatriz(int **matrix) {
  
}

int **createMatrix(int NumberOfColumns, int NumberOfLines) {
  int **matrix = malloc(sizeof(int *) * NumberOfLines);
  for (int i = 0; i < NumberOfLines; i++) matrix[i] = malloc(sizeof(int) * NumberOfColumns);

  for (int i = 0; i < NumberOfLines; i++) {
    for (int j = 0; j < NumberOfColumns; j++) matrix[i][j] = rand() % 3;
  }

  return matrix;
}

void printMatrix(int **matrix, int NumberOfLines, int NumberOfColumns) {
  for (int i = 0; i < NumberOfLines; i++) {
    for (int j = 0; j < NumberOfColumns; j++) printf("%d ", matrix[i][j]);
    printf("\n");
  }
}

void freeMatrix(int **matrix, int NumberOfLines) {
  for (int i = 0; i < NumberOfLines; i++) free(matrix[i]);
  free(matrix);
}

int **turnClockwise(int **matrix, int NumberOfLines, int NumberOfColumns) {
  int **newMatrix = createMatrix(NumberOfLines, NumberOfColumns);
  //serve como auxiliar pra trocar as linhas da matrix de entrada durante o loop
  int k = 0;

  //o loop começa em j pra fixar a coluna, corremos de tras pra frente.
  //vou esquecer como funciona daqui 10min.
  for (int j = NumberOfColumns - 1; j >= 0; j--) {
    //serve pra trocar as linhas na nova matrix durante o loop
    int p = 0;
    for (int i = 0; i < NumberOfLines; i++) {
      newMatrix[p++][j] = matrix[k][i];
    }
    k++;
  }
  return newMatrix;
}

int main() {
  int **matrix = NULL;

  matrix = createMatrix(4, 4);
  printMatrix(matrix, 4, 4);
  printf("\n");

  matrix = turnClockwise(matrix, 4, 4);
  printMatrix(matrix, 4, 4);

  freeMatrix(matrix, 4);

  return 0;
}