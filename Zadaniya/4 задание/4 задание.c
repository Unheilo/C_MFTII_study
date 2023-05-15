//Лабораторная работа 4
//Написать функции, вычисляющие периметр и площадь треугольника по значениям длин трёх его сторон.Разместить их в отдельном модуле(отличном от того, где располагается функция main()).Ввести с консоли значения длин сторон треугольника(с проверкой на корректность неравенства треугольника) 
//и выдать на консоль вычисленные с помощью написанных функций значения его периметра и площади.
#include <stdio.h>
#include <math.h>
#include "4_module.h"

int main() {

	double a, b, c, p;
	printf(" Rasschet perimetra i ploshadi treygolnika po trem storonam. \nVvedite storoni treygolnika: ");
	scanf_s("%lf %lf %lf", &a, &b, &c);
	if ((a + b <= c) || (b + c <= a) || (a + c <= b)) {

		printf("Takogo treygolnika ne shyshetvyet!\n");
		system("pause");
		return 0;

	}

	p = perimeter(a, b, c);

	printf("Ploshad': %.3lf\n", p);
	printf("Perimetr: %.3lf\n", square( p, a, b, c));

	system("pause");
	return 0;

}

//double perimeter(double a, double b, double c) {
//
//	return a + b + c;
//
//}
//
//double square(double p, double a, double b, double c) {
//
//	p = p / 2;
//
//	return sqrt(p * (p - a) * (p - b) * (p - c));
//
//}