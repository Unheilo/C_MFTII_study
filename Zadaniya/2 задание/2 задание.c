//Лабораторная работа 2
//Объявить массив данных типа double размером 3 на 3. Ввести с консоли его значения, вывести на консоль сумму его элементов, расположенных на главной диагонали и сумму элементов, расположенных на побочной диагонали.
//
//Объявить массив данных типа int размером 2 на 2. Ввести с консоли его значения, вывести на консоль квадрат данной матрицы(перемножение матрицы самой на себя).
//
//В программе должна быть предусмотрена возможность работы с матрицами любого размера.

#include <stdio.h>
#include <math.h>
#define N 100 //условно любая матрица

double a[N][N];
int b[N][N];
int c[N][N] = { 0 };

int main() {
    int v = 0;
    printf("Raschet summy elementov glavnoy diagonali i summy elementov pobochnoy diagonali.\n Vvedite razmer matritsy(tseloe polozhitel'noe chislo bolshe odnogo): \n");
    scanf_s("%d", &v);
    if (v <= 1) {
        printf("Nepravil'noe 4islo!\n");
        return 0;
    }

    printf("Vvedite matritsu:\n");

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf_s("%lf", &a[i][j]);
        }
    }

    printf("Rezul'tat:\n");

    double sum = 0;

    for (int i = 0; i < v; i++) {
        sum = sum + a[i][i];
    }

    double sum2 = 0;

    for (int i = 0; i < v; i++) {
        sum2 = sum2 + a[i][(v - 1) - i];
    }

    printf("Summa elementov glavnoy diagonali: %lf\n Summa elementov pobochnoy diagonali: %lf\n", sum, sum2);
    printf("\n");


    v = 0;
    printf("Raschet kvadrata matritsy.\n Vvedite razmer matritsy(tseloe polozhitel'noe chislo): \n");
    scanf_s("%d", &v);

    if (v <= 1) {
        printf("Nepравильное число!\n");
        return 0;
    }

    printf("Vvedite matritsu:\n");

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf_s("%d", &b[i][j]);
        }
    }

    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < v; k++)
                c[i][j] += b[i][k] * b[k][j];
        }

    printf("Rezul'tat:\n");

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }


    system("pause");
    return 0;
}