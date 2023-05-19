#include <stdio.h>
#include <math.h>

#define PI 3.14

int main(){

int a;
float s_a;
float v_a;

int b;
int b1;
int b2;
float s_b;
float v_b;

int c;
float s_c;
float v_c;

int d;
int d1;
float s_d;
float v_d;




//a cube
printf("Enter the edge length for cube:  ");
scanf("%d" , &a);

s_a = 6*a*a;
v_a = a*a*a;

printf("surface area:");
printf("%f",s_a);
printf("     volume");
printf("%f", v_a);


//b prism
printf("Enter side length for rectangular prism:");
scanf("%d", &b);

printf("Enter Side Width");
scanf("%d" , &b1);

printf("Enter Side Length");
scanf("%d" , &b2);

s_b = 2*(b*b1 + b*b2 + b1*b2);
v_b = b*b1*b2;

printf("surface area:");
printf("%f",s_b);
printf("     volume");
printf("%f" , v_b);


//c sphere
printf("Enter the radius for sphere: ");
scanf("%d", &c);

v_c = (PI*c*c*c*4)/3;
s_c = (4*PI*c*c);

printf("surface area:");
printf("%f",s_c);
printf("     volume");
printf("%f",v_c);

//d cone

printf("Enter the radius for cone: ");
scanf("%d", &d);
printf("Enter the height");
scanf("%d", &d1);

int x;

x = sqrt(d1*d1 + d*d);


v_d = (PI*d*d*d1)/3;
s_d = PI*d*(x+d);

printf("surface area:");
printf("%f",s_d);
printf("     volume");
printf("%f",v_d);

}
