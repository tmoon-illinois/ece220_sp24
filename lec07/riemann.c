#include <stdio.h>
#include <math.h>

double f(double x);

double rieman(double a, double b, int n);

int main(){
    double a,b;
    int n;

    printf("Enter a,b,n: ");
    scanf("%lf %lf %d", &a, &b, &n);
    printf("Result is %lf\n", rieman(a,b,n) ); 
}
double f(double x){
    return cos(x); // any function
//    return x;
}

double rieman(double a, double b, int n){

    double dx = (b-a)/n;

    double result = 0;
    double x, y;
    int i;
    for(i=0 ; i <n ;i++){
        x = a + i*dx;
        y = f(x);

        result = result + dx*y;
    }
    return result;
}


