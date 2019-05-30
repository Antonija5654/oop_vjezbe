#pragma once
#include <iostream>
#include <string>

class MathError {
public:
	virtual std::string Error() = 0;



};

class MissingNumber : public MathError {
public:
	std::string Error() {
		return "Number not entered!\n";
	}
};

class OperatorError : public MathError {
public:
	std::string Error() {
		return "Operator not supported!\n";
	}
};

class ZeroDivide : public MathError {
public:
	std::string Error() {
		return "Zero division not allowed!\n";
	}
};

double unesiBroj();

char unesiOperator();

double rezultat(double a, double b, char o);

void log_error(std::string e);

