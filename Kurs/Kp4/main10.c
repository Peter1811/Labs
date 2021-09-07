#include <cstdio>
#include <math.h>

double macheps ()
{
	double e = 1.0;
	while (1.0 + e / 2.0 > 1.0)
	{
		e = e / 2.0;
	}
	return e;
}
double MyFunction (double x)
{
	return ((2*x*sin(x) - cos(x)) / (2*x*cos(x) + 3*sin(x))) ;
}
bool condition (double x)
{
	return ((2*x*sin(x) - cos(x))*(2*sin(x) + 2*x*cos(x) + sin(x)) < pow(2*sin(x) + 2*x*cos(x) + sin(x), 2));
}


int main ()
{
	double a = 0.4;
	double b = 1;
	bool NOT = 0;
	for (double i = a; i <=b; i = i + (b - a) / 1000.0)
	{
		if(!condition(i))
		{
			NOT = 1;
			break;
		}
	}
	if (NOT)
	{
		printf("Newton's method is wrong\n");
	}
	else
	{
		double x = (a + b) / 2.0;
		double answer = 0.6533;
		double e = macheps();
		int t = 0;
		printf("Step: %d. Current value: %lf. Module of difference: %lf\n", t, x, fabs(x - answer));
		t++;
		do
		{
			x = x - MyFunction(x);
			printf("Step: %d. Current value: %lf. Module of difference: %lf\n", t, x, fabs(x - answer));
			t++;

		if (t > 1000)
		{
			break;
		}
	}
	while (fabs(x - answer) > pow(10, 12) * e);
	printf("On step %d we calculated an approximate value: %lf.\nModule of difference is %lf\n", t-1, x, fabs(x - answer));
	}
	return 0;
}
