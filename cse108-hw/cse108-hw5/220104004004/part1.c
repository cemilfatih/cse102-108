#include <stdio.h>

void menu();
void conversion(int choice);

int main(){

menu();

}

void menu(){

int choice;

while(choice!=3){

printf("Temperature Conversion Menu\n");
printf("\n1. Convert Celsius to Fahrenheit\n");
printf("\n2. Convert Fahrenheit to Celsius\n");
printf("\n3. Quit\n");
printf("\nEnter your choice (1-3): ");
scanf("%d",&choice);

switch (choice){
	
	case 1:
	case 2:
	 convert(choice);
	 break;
	
	case 3:
	 break; 
	
	default:
	 printf("Invalid input\n"); 
	 break;
}

}

}

void convert(int choice){

float temp,final;

printf("Enter the temperature value to convert: ");
scanf("%f",&temp);

switch (choice){
	
	case 1:
	 final =(9 * temp / 5 ) + 32;
	 printf(" %.2f Celsius = %.2f Fahrenheit\n",temp,final);
	 break;
	
	case 2:
	 final = 5 * ( temp - 32) / 9;
	 printf(" %.2f Fahrenheit =  %.2f Celsius\n",temp,final);
	 break;

}

}
