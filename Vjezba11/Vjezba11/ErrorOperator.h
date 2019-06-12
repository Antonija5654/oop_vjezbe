#ifndef ERROROPERATOR_H
#define ERROROPERATOR_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class  ErrorOperator: public XError
{
public:
	void ispisi(ofstream& dat)
	{
		cout << "Unesen je krivi operand" << endl;
		time_t t = time(NULL);
		string time = ctime(&t);
		dat << "Unesen je krivi operand  " << time << endl;
	}
};

#endif