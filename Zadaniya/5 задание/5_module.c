#include "5_module.h"

double** matrix_op(double** a, double** b, int n, char op) {

    //������� ������� ��� ���������� �����, �������� ��� ������������ ������ ������, ������� 
    //��������� � �������� ���������� ��������� �� ������� - ������� a � b, ����������� n, 
    //���� �������� op, ��������� ��������� � ���������� ��������� �� ������ - ��������� c :

    double** c = malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        c[i] = malloc(n * sizeof(double));
    }

    switch (op) {
    case '+': {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c[i][j] = a[i][j] + b[i][j];
            }
        }
        break;
    }
    case '-': {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c[i][j] = a[i][j] - b[i][j];
            }
        }
        break;
    }
    case '*': {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        break;
    }
    }

    return c;
}
