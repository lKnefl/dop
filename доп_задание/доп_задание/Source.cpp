#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void reverseGraph(int** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < i; j++) {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));

    int** arr = 0; // матрица смежности
    int i, j, rows;
    printf("Введите количество вершин графа: ");
    scanf("%d", &rows);

    arr = (int**)malloc(rows * sizeof(int*));
    if (arr == NULL) {
        printf("Не удалось выделить память!\n");
        return 1;
    }
    for (i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(rows * sizeof(int));
    }

    // генерировать случайные значения для матрицы смежности
    for (i = 0; i < rows; i++) {
        for (j = i; j < rows; j++) {
            if (i == j) {
                arr[i][j] = 0; // на главной диагонали нули
            }
            else {
                arr[i][j] = (-1) + rand() % 3;
                arr[j][i] = -arr[i][j];
            }
        }
    }

    // выводить матрицу смежности на экран
    printf("Матрица смежности для графа:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < rows; j++) {
            printf("%-4d ", arr[i][j]);
        }
        printf("\n");
    }


    // Изменение направлений в ориентированном графе
    reverseGraph(arr, rows);

    // Вывод обращенной матрицы смежности на экран
    printf("Обращенная матрица смежности:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < rows; j++) {
            printf("%-4d ", arr[i][j]);
        }
        printf("\n");
    }

    // Освобождение памяти
    for (i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
