#include "pch.h"
#include "vjezba11.h"
#include <fstream>

double unesiBroj() {
	double n;
	std::cin >> n;
	if (std::cin.fail()) throw MissingNumber();
	return n;
}

char unesiOperator() {
	char o;
	std::cin >> o;
	if (o != '+' && o != '-' && o != '*' && o != '/') throw OperatorError();
	return o;
}

double rezultat(double a, double b, char o) {
	if (o == '/' && b == 0) throw ZeroDivide();
	switch (o) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	default:
		throw 0;
	}
}

void log_error(std::string e) {
	std::cout << e;
	std::ofstream fout;
	fout.open("errors.log", std::ios::out | std::ios::app);
	fout << e;
	fout.close();
}

