#include "stdafx.h"
#include "perceptron.h"

void perceptron::ini(int xt, double wt, int teta, double alfa) {
	x = xt;
	w = wt;
	t = teta;
	a = alfa;
}

perceptron::perceptron() {

}

perceptron::~perceptron() {

}

int perceptron::func(int xi, double wi, int ti) {
	double summ = 0;
		summ = summ + xi * wi;
	return summ - ti;
}

int perceptron::fots() {
	int z = perceptron::func(perceptron::x, perceptron::w, perceptron::t);
	if (z > 0)
		return 1;
	else
		if (z == 0)
			return 0;
		else
			return -1;
}

double perceptron::sigm() {
	double sigma = 1 / (1 + exp(-perceptron::a * (perceptron::func(perceptron::x, perceptron::w, perceptron::t))));
	return sigma;
}

int perceptron::sigmoida() {
	double s = perceptron::sigm();
	if (s > 0.5)
		return 1;
	else
		return -1;
}

double perceptron::calibration(int rez1, int rez2, double omeg) {
	double weight = omeg;
		if (rez1 != rez2)
			if (rez1 == 1)
				weight = weight + 0.1;
			else
				if (rez1 == -1)
					weight = weight - 0.1;
	return weight;		
}