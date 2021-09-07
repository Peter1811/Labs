#include <stdio.h>
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
	return (2 - sin(1/x));
}

bool condition (double x)
{
	return (fabs((cos(1/x))/(x*x)) < 1.0);
}




int main()
{
	double a = 1.2;
	double b = 2;
	bool NOT = 0;
	for (double i = a; i <= b; i = i + (b - a) / 100.0)
{
	if (!condition(i))
	{
		NOT = 1	;
		break;
	}
}
if (NOT)
{
	printf ("Newton Method is wrong\n");
}
else
{
	double x = (a + b) / 2.0;
	double answer = 1.3077;
	double e = macheps ();
	int t = 0;
printf("Step: %d. Value: %lf. Module of difference: %lf\n", t, x, fabs(x - answer));
t++;
do
{
		x = MyFunction(x);
		printf("Step: %d. Value: %lf. Module of difference: %lf\n", t, x, fabs(x - answer));
		t++;
}
while (fabs(x - answer) > pow(10, 12) * e);
printf("On step %d we calculated an approximate value: %lf.\nModule of difference is %lf\n", t - 1, x, fabs(x - answer));
}
	return 0;
}
		
