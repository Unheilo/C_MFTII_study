#include "4_module.h"

double perimeter(double a, double b, double c) {

	return a + b + c;

}

double square(double p, double a, double b, double c) {

	p = p / 2;

	return sqrt(p * (p - a) * (p - b) * (p - c));

}