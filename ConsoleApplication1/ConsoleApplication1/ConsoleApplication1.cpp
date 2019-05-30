#include "pch.h"
#include <vector>
#include <algorithm>
#include "vjezba11.h"

int main() {
	std::vector<double> rezultati;
	try {
		while (true) {
			double a = unesiBroj();
			char o = unesiOperator();
			double b = unesiBroj();
			double res = rezultat(a, b, o);
			std::cout << "Result: " << res << std::endl;
			rezultati.push_back(res);
		}
	}
	catch (MathError& e) {
		log_error(e.Error());
	}
	catch (...) {
		log_error("Unknown exception\n");
	}

	
	return 0;
}