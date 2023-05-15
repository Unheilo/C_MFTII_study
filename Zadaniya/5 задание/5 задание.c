//Лабораторная работа 5

//Разместить в динамической памяти 2 массива – 2 матрицы размерностью n на n с элементами типа double
//(значения n и элементы массивов ввести с консоли).А также ввести с консоли знак операции : '+', '-' или '*'.Написать функцию, 
//вычисляющую сумму, разность или произведение данных матриц(их передать по указателю) и возвращающую указатель на массив - результат.
//Разместить эту функцию в отдельном модуле.Выдать на консоль значения полученного вектора.


#include <stdio.h>
#include <stdlib.h>
#include "5_module.h"

int main() {

    //Вводим значение n с консоли и выделить динамический массив a размерности 
    //n x n для первой матрицы и массив b размерности n x n для второй матрицы:

    int n;
    printf("Vvedite razmer matrixi n: ");
    scanf_s("%d", &n);

    double** a = malloc(n * sizeof(double*));
    double** b = malloc(n * sizeof(double*));

    for (int i = 0; i < n; i++) {
        a[i] = malloc(n * sizeof(double));
        b[i] = malloc(n * sizeof(double));
    }

    //Заполним массивы a и b значениями, введенными с консоли:

    printf("Vvedite elementi matrici A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf_s("%lf", &a[i][j]);
        }
    }

    printf("Vvedite elementi matrici B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf_s("%lf", &b[i][j]);
        }
    }

    //Введем знак операции с консоли:

    char operation;
    printf("Vvedite operaciu (+, -, *): ");
    scanf_s(" %c", &operation);

    //Вызываем функцию matrix_op с передачей ей параметров a, b, n и operation, 
    //сохраняем её результат в массив c и выводим его значения на консоль:

    double** c = matrix_op(a, b, n, operation);

    printf("Result:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", c[i][j]);
        }
        printf("\n");
    }

    //Освобождаем занятую память:

    for (int i = 0; i < n; i++) {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }

    free(a);
    free(b);
    free(c);

    system("pause");
    return 0;

}