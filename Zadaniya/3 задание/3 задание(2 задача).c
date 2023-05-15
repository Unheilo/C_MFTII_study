//Лабораторная работа 3 (задача 2)
//Объявить массив данных типа int размером 3 на 3. Ввести с консоли его значения, вывести на консоль сумму его элементов, расположенных на главной диагонали и сумму элементов, 
//расположенных на  побочной диагонали.Проверить, является ли матрица «магическим квадратом»(в «магическом квадрате» суммы элементов по вертикали, горизонтали и диагонали равны).
#include <stdio.h>

#define N 100 //условно любая матрица

int a[N][N];

int sum_row(int a[N][N], int irow, int v);
int sum_col(int a[N][N], int icol, int v);
int sum_diag(int a[N][N], int v);
int sum_diag2(int a[N][N], int v);

int main() {

	int v = 0;
	printf("Rasschet magi4eskogo kvadrata i vivod summi elementov glavnoy diagonali i summi elementov pobochnoy diagonali.\nVvedite razmer matrici: ");
	scanf_s("%d", &v);
	printf("Vvedite matricy:\n");
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			scanf_s("%d", &a[i][j]);
		}
	}

	int result0 = 0;
	int result1 = 0;
	printf("Summa elementov glavnoy diagonali: %d\n", sum_diag(a, v));
	printf("Summa elementov pobochnoy duiagonali: %d\n", sum_diag2(a, v));
	printf("Proverka na magi4eski kvadrat ");
	result0 = sum_diag(a, v);
	result1 = sum_diag(a, v);

	for (int i = 0; i < v; i++) {

		result1 = sum_row(a, i, v);

		if (result0 != result1) {
			printf("NO\n");
			system("pause");
			return 0;
		}

		result1 = sum_col(a, i, v);

		if (result0 != result1) {
			printf("NO\n");
			system("pause");
			return 0;
		}

	}

	result1 = sum_diag2(a, v);

	if (result0 != result1) {
		printf("NO\n");
		system("pause");
		return 0;
	}

	printf("MAGIC\n");
	system("pause");
	return 0;


}

int sum_row(int a[N][N], int irow, int v) {

	int sum = 0;

	for (int j = 0; j < v; j++) {
		sum += a[irow][j];
	}



	return sum;
}

int sum_col(int a[N][N], int icol, int v) {

	int sum = 0;

	for (int j = 0; j < v; j++) {
		sum += a[j][icol];
	}

	return sum;

}

int sum_diag(int a[N][N], int v) {

	int sum = 0;

	for (int i = 0; i < v; i++) {
		sum = sum + a[i][i];
	}

	return sum;
}

int sum_diag2(int a[N][N], int v) {


	int sum2 = 0;

	for (int i = 0; i < v; i++) {
		sum2 = sum2 + a[i][(v - 1) - i];
	}


	return sum2;

}


