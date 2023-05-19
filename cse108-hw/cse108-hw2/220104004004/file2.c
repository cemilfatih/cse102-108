#include <stdio.h>


int main(){


	float boy;
	float kilo;

	int bmi;


	printf("kilo:");
	scanf("%f" , &kilo);

	printf("boy");
	scanf("%f" , &boy);


	bmi = kilo/(boy*boy);

	if(bmi<18.5){
	
		printf("underweight \n");
	};
	if( bmi > 18.5 && bmi <22.5){
	
		printf("average wieght \n");
	}if(bmi>25 && bmi <29){
	
		printf("over weigth");
	}if(bmi>30){
	
		printf("obese");
	}

}
