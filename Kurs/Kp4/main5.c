#include <cstdio>
#include <cmath>

double macheps ()
{
	double e = 1.0;
	while (1.0 + e / 2.0 > 1.0)
	{
		e = e / 2.0;
	}
	return e;
}
double Function (double x)
{
	return sqrt(1 - x) - tan(x);
}
int main ()
{
	double a = 0;
	double b = 1;
	double x = (a + b) / 2.0;
	double answer = 0.5768;
double e = macheps ();
int t = 0;
printf("Step: %d. Current value: %lf. Module of difference: %lf\n", t, x, fabs(x - answer));
t++;

do
{
	if (Function(a) * Function(x) > 0)
	{
		a = (a + b) / 2.0;
	}
	else if (Function(b) * Function(x) > 0)
	{
		b = (a + b) / 2.0;
	}
	else if ((Function(a) * Function(x) == 0) || (Function(b) * Function(x) == 0))
	{	
			if (Function(a) == 0)
			{
				b = a;
			}
			else
			{
				a = b;
			}
			x = (a + b) / 2.0;
			break;
			}
		x = (a + b) / 2.0;
		printf("Step: %d. Current value: %lf. Module of difference: %lf\n", t, x, fabs(x - answer));
		t++;
	}
	while (fabs(a - b) > pow(10, 10) * e);
	printf("On step %d we calculated an approximate value: %lf. \nModule of difference is %lf\n", t - 1, x, fabs(x - answer));
	return 0;
}

