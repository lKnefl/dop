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

    int** arr = 0; // ������� ���������
    int i, j, rows;
    printf("������� ���������� ������ �����: ");
    scanf("%d", &rows);

    arr = (int**)malloc(rows * sizeof(int*));
    if (arr == NULL) {
        printf("�� ������� �������� ������!\n");
        return 1;
    }
    for (i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(rows * sizeof(int));
    }

    // ������������ ��������� �������� ��� ������� ���������
    for (i = 0; i < rows; i++) {
        for (j = i; j < rows; j++) {
            if (i == j) {
                arr[i][j] = 0; // �� ������� ��������� ����
            }
            else {
                arr[i][j] = (-1) + rand() % 3;
                arr[j][i] = -arr[i][j];
            }
        }
    }

    // �������� ������� ��������� �� �����
    printf("������� ��������� ��� �����:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < rows; j++) {
            printf("%-4d ", arr[i][j]);
        }
        printf("\n");
    }


    // ��������� ����������� � ��������������� �����
    reverseGraph(arr, rows);

    // ����� ���������� ������� ��������� �� �����
    printf("���������� ������� ���������:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < rows; j++) {
            printf("%-4d ", arr[i][j]);
        }
        printf("\n");
    }

    // ������������ ������
    for (i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
