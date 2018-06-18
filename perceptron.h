#pragma once
class perceptron {
public:
	void ini(int, double, int, double);
	perceptron();
	~perceptron();
	int fots();
	int sigmoida();
	double calibration(int, int, double);

private:
	int func(int, double, int);
	double sigm();
	int x;
	double w;
	int t;
	double a;
};