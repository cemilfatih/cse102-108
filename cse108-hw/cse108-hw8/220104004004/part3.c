#include <stdio.h>
#include <math.h>

typedef struct {
    double a;
    double b;
    double c;
    double d;
} third_order_polynomial;

typedef struct {
    double a;
    double b;
    double c;
    double d;
    char constant;
    double value;
} polynomial;

polynomial get_integral(third_order_polynomial p1, third_order_polynomial p2, int a, int b);

int main(){

  int a,b;
  third_order_polynomial p1,p2;
  
  printf("Enter the coefficients of the first polynomial (a, b, c, d): ");
  scanf("%lf %lf %lf %lf", &p1.a, &p1.b, &p1.c, &p1.d);

  printf("Enter the coefficients of the second polynomial (a, b, c, d): ");
  scanf("%lf %lf %lf %lf", &p2.a, &p2.b, &p2.c, &p2.d);

  printf("Enter the interval values (a, b): ");
  scanf("%d %d", &a, &b);

  polynomial p = get_integral(p1, p2, a, b);

  printf("Integrated Polynomial: %fx^3 + %fx^2 + %fx + %f + %c = %f\n", p.a, p.b, p.c, p.d, p.constant, p.value);
  
}

polynomial get_integral(third_order_polynomial p1, third_order_polynomial p2, int a, int b){

double integral_a = 0, integral_b = 0;

    double a1 = p1.a * p2.a / 4.0;
    double b1 = p1.a * p2.b / 3.0 + p1.b * p2.a / 3.0;
    double c1 = p1.a * p2.c / 2.0 + p1.b * p2.b / 2.0 + p1.c * p2.a / 2.0;
    double d1 = p1.a * p2.d + p1.b * p2.c + p1.c * p2.b + p1.d * p2.a;
   
    integral_b = a1 * b * b * b * b + b1 * b * b * b + c1 * b * b + d1 * b;
    integral_a = a1 * a * a * a + b1 * a * a * a + c1 * a * a + d1 * a;

    double value = integral_b - integral_a;

    polynomial p = {a1, b1, c1, d1, 'C', value};

    return p;
}
