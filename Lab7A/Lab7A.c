#include <stdio.h>//Підключаємо необхідні для роботи бібліотеки
#include <stdlib.h>
#include <math.h>

void AbsElem(double** A, int n, int m) {
    double maxElement = fabs(A[0][0]); //Початково вважаємо перший елемент найбільшим за модулем

    //Знаходимо найбільший елемент за модулем
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (fabs(A[i][j]) > maxElement) {
                maxElement = fabs(A[i][j]);
            }
        }
    }

    //Ділимо кожен елемент на найбільший елемент за модулем
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] /= maxElement;
        }
    }
}

int main() {
    int n, m;

    printf("Введіть розмірність матриці (n × m): ");
    scanf_s("%d %d", &n, &m);

    //Ініціалізуємо дійсну матрицю A
    double** A = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        A[i] = (double*)malloc(m * sizeof(double));
    }

    //Вводимо значення для матриці A
    printf("Введіть значення для матриці A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf_s("%lf", &A[i][j]);
        }
    }

    //Знаходимо найбільше число в матриці
    double maxElement = A[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] > maxElement) {
                maxElement = A[i][j];
            }
        }
    }

    //Виводимо задану матрицю з виділенням найбільшого числа червоним кольором
    printf("Задана матриця:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == maxElement) {
                printf("\033[0;31m%.2f\033[0m ", A[i][j]); // Виділення червоним кольором
            }
            else {
                printf("%.2f ", A[i][j]);
            }
        }
        printf("\n");
    }

    //Викликаємо функцію AbsElem для матриці A
    AbsElem(A, n, m);

    //Виводимо отриману матрицю
    printf("Отримана матриця:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.2f ", A[i][j]);
        }
        printf("\n");
    }

    //Звільняємо пам'ять
    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);

    return 0;//Кінець програми)
}













