// main.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "perceptron.h"

using namespace std;

struct object {
	int par;
	int rez_m = 0;
	int rez_n = 0;
	double rez_s;
};

object x[10];

double omega_one[10] = { 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5};
int porog_one = 10;
double si = 0.5;

double omega_two[10] = { 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8 };
int porog_two = 7;

double omega_three[10] = { 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3 };
int porog_three = 4;

perceptron neiron_one;
perceptron neiron_two;
perceptron neiron_three;

void print(object* y, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Object " << i + 1 << endl;
		cout << "P" << "  " << "M" << "  " << "N" << "  " << "S" << endl;
		cout << y[i].par << "  " << y[i].rez_m << "  " << y[i].rez_n << "  " << y[i].rez_s << endl;
	}
}

void initial(object* y, int n) {
	for (int i = 0; i < n; i++) {
		y[i].rez_m = 0;
		y[i].rez_n = 0;
		y[i].rez_s = 0;
		cout << "Object " << i + 1 << endl;
		cout << "P" << "  " << "M" << "  " << "N" << "  " << "S" << endl;
		cout << y[i].par << "  " << y[i].rez_m << "  " << y[i].rez_n << "  " << y[i].rez_s << endl;
	}
}

void manual(object* x, int n, int porog) {
	for (int i = 0; i < n; i++) {
		if (x[i].par > porog)
			x[i].rez_m = 1;
		else
			if (x[i].par < porog)
				x[i].rez_m = -1;
	}
}

void neiro(object* x, int n, perceptron neiron, double* omega, int porog) {
	for (int i = 0; i < n; i++) {
		neiron.ini(x[i].par, omega[i], porog, si);
		x[i].rez_n = neiron.fots();
	}

}

void func_sigm(object* x, int n, perceptron neiron, double* omega, int porog) {
	for (int i = 0; i < 10; i++) {
		neiron.ini(x[i].par, omega[i], porog, si);
		x[i].rez_s = neiron.sigmoida();
	}
}

void o_neiron(object* x, perceptron neiron, double* omega, int porog) {

	cout << "Initial data for first neiron" << endl;
	initial(x, 10);

	manual(x, 10, porog);

	neiro(x, 10, neiron, omega, porog);

	cout << "Data from first neiron after first iteration" << endl;
	print(x, 10);

	for (int i = 0; i < 10; i++) {
		while (x[i].rez_m != x[i].rez_n)
			if (x[i].rez_m != x[i].rez_n) {
				omega[i] = neiron.calibration(x[i].rez_m, x[i].rez_n, omega[i]);
				neiron.ini(x[i].par, omega[i], porog, si);
				x[i].rez_n = neiron.fots();
			}
	}

	neiro(x, 10, neiron, omega, porog);

	func_sigm(x, 10, neiron, omega, porog);

	cout << "Data from first neiron after calibration" << endl;
	print(x, 10);
}



int main()
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		x[i].par = 1 + rand() % 20;
	}

	o_neiron(x, neiron_one, omega_one, porog_one);

	o_neiron(x, neiron_two, omega_two, porog_two);

	o_neiron(x, neiron_three, omega_three, porog_three);

	system("pause");

    return 0;
}

