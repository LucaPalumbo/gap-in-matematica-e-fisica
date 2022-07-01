#include <stdio.h>
#include <math.h>
// funzione matematica da integrare
double f(double x){
    if(x == 0 || x == 1)
        return 0;
    return pow(x,3)/( pow(1.-x,5)*(exp(x/(1.-x))-1.) );
}
// metodo dei trapezi
double integral(double (*function)(double), double a, double b, int n){
    double surface = 0.;
    double step = (b-a)/n;
    for (int i = 1; i < n; i++) {
      surface += (*function)(a+i*step);
    }
    surface*=step;
    return surface;
}
int main() {
    double surface = integral(f, 0., 1., 1600);
    printf("%.15lf\n", surface);
    return 0;
}
