#include <stdio.h>
#include "util.h"


int main() {

    /* A fractional number: 13/7 */
    int num1 = 13, den1 = 7;
    /* A second fractional number: 13/11 */
    int num2 = 30, den2 = 11;
    /* An unitilized fractional number */
    int num3, den3;

    printf("First number: ");
    fraction_print(num1, den1);
    printf("\n");

    printf("Second number: ");
    fraction_print(num2, den2);
    printf("\n");

    printf("Addition: ");
    fraction_add(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Subtraction: ");
    fraction_sub(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Multiplication: ");
    fraction_mul(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Division: ");
    fraction_div(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

	//We tested, our algorithm works with given integers. Let's test it with scanf function. 

    // These are my integers.
    int n1 , d1 , n2 , d2 , n3 , d3;
	
    // We will get our input values separately.
    printf(">>> Not It's Your Turn! <<<\n");
    printf("type the nominator of first fractional number \n");
    scanf("%d" , &n1);

    printf("type the denominator of first fractional number \n");
    scanf("%d" , &d1);


    printf("type the nominator of second fractional number \n");
    scanf("%d" , &n2);

    printf("type the denominator of second fractional number \n");
    scanf("%d" , &d2);

    // We will calculate multiplication and division operations as we told.
    printf("----------\n");
    printf("multiplication:\n");
    fraction_mul(n1 ,d1 , n2 , d2, &n3 , &d3);
    fraction_print(n3 , d3);
    printf("\n"),


    printf("----------\n");
    printf("division:");
    fraction_div(n1 ,d1 ,n2 ,d2 ,&n3 ,&d3);
    fraction_print(n3,d3);
    printf("\n");

    printf(">>> Program has been completed <<<");




    return(0);
}
