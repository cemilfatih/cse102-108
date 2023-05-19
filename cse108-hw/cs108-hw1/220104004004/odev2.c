
#include <stdio.h>

int main(){

	float num1;
	float num2;
	float num3;
	float result;

	printf("num1:\n");
	scanf("%f" , &num1);
	printf("num2:\n" , &num2);
	scanf("%f" , &num2);

	num3 =  num1 - num2;
	

	if(num3 >0){
	
		result = (num1/num2) + num1/(num1 + num2);
	}else{
              	result = (num1/num2) + num2/(num1 + num2);


	}

	printf("%f", result);

}
