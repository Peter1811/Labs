//Вариант 8
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double meps(){
        double e =1.0;
        while (1.0 + e / 2.0 > 1.0)
                e /= 2.0;
        return e;
}
struct Point{
        double x;
        double y;

};
double taylor(unsigned p, double x){
        double y = 0.;
	//double q = -1/5;
        for(unsigned i = 1; i <= p; ++i){
                y += (-1)*pow(2, i-1)*pow(x, i-1)/pow(5,i);
	}
        return y;
}

double f(double x){
        return 1/(2*x-5);
}

void solve( unsigned count, double a, double b, double (*taylor)(unsigned, double), double (*f)(double)){
        double step = (b - a) / count;
        struct Point* points = (struct Point*)malloc(sizeof(struct Point) * count);
        double eps = meps();
	//printf();
        double x = a;
        for(unsigned i = 0; i < count; ++i, x += step){
                unsigned p = 0;
                while(fabs(f(x) - taylor(p, x)) > 100*eps){
                        points[i].x = x;
                        points[i].y = taylor(p, x);
                        ++p;
                        if(p >= 100){
                                break;
                        }
                }
                printf("%d| %lf %lf %lf\n", i, x, f(x), points[i].y);
        }
        free(points);
}

int main(){
        unsigned n;
        double a = 0.;
        double b = 0.5;
        scanf("%u", &n);
        solve(n, a, b, taylor, f);

}
