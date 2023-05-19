#include <stdio.h>
#include "util.h"
#include <math.h>


//I wrote a simple factorial function
int factorial(int number){

// Multiplied by fact every step
 int i,fact=1;     
    for(i=1;i<=number;i++){    
      fact=fact*i;    
  }    
    
return fact;  


}
void part1(){
  int year;
  
  printf("Please enter a year: ");
  scanf("%d" , &year);
  
  // if it can divide by 400 then no problem but it can not be divided by 400 and can be divided by 100 then its not a leap year
  if(year % 400 ==0){
  //such as 1600
    printf("\n%d%s" , year ," is leap year");
  }else if(year %100 == 0){
//such as 1900
    printf("\n%d%s" , year ," is not leap year");
    
    //after statements above if it can be divided by 2 then its leap year
  }else if(year%4 == 0){
    printf("\n%d%s" , year ," is leap year");
    
    // if none of them is true then its not a leap year
  }else{
    printf("\n%d%s" , year ," is not leap year");
  }
  


}

void part2(){

  char type;//calculation type
  int n1;
  int n2;
  double result; //make sure that result is double
  char operation; //operation type
  int m;
  int n;
  

  printf("Enter the type of calculation you want S/I: ");
  scanf(" %c" , &type);
  

    
  if(type == 'S'){
    printf("\nPlease enter m value and n value (n should not be greater than m): ");
    scanf("%d %d", &m, &n);
    
    while(n>m){
    //it can not be n>m 
      printf("\nPlease enter m value and n value again (n should not be greater than m): ");
      scanf("%d %d", &m, &n);
    }
    
    
  }
  
  printf("\nPlease enter operation type + , - , * , / , ! , ^ , % ");
  scanf(" %c", &operation);
  
  printf("\nPlease enter first number: ");
  scanf("%d", &n1);
  
  
  //if operation type is factorial then there is no need for second input
  if(operation !='!'){
    printf("\nPlease enter second number: ");
    scanf("%d", &n2);

  }

  

  switch(operation){
  case '+':
    result = n1 +n2;
    break;
  case '-':
    result = n1-n2;
    break;
  case '*':
    result =  n1*n2;
    break;
  case '/':
    result = n1/n2;
    break;
  case '!':
    result = factorial(n1);
    break;
  case '^':
    result = pow(n1,n2);
    break;
  case '%':
    result = n1%n2;
    break;
  default:
  
  //if input is none of them then there must be an error
    printf("\nInvalid Operation Error");
    break;
  }
  

  if(type == 'I'){
    printf("\n%.0f\n", result);
  }else if(type == 'S'){
    
    //First I want to divide the result by n+1 in order to reach a proper value
    result = result / pow(10, n+1);
    printf("\n");
    // Zero stands for filling the space in left, stars stands for digit counts and f stands for float of course
    printf("%0*.*f",m+1,n,result);
    //I added 'e' with our division count
    printf("%c%d",'e',n+1);

  }
  

}


void part3(){
  
  int e1;
  int e2;
  int e3;
  int a1;
  int a2;
  double final;
  //make sure that final value is double
  
  printf("Please enter your 3 exams: ");
  scanf("%d %d %d", &e1 , &e2 , &e3);
  
  printf("\nPlease enter your 2 assignments: ");
  scanf("%d %d", &a1 , &a2);
  
  //this is the basic operation
  final = ((e1+e2+e3)/3)*0.6 + ((a1+a2)/2)*0.4;
  
  
// I want just one digit after decimal 
  printf("Final Grade: %.1f " , final);
  
  if(final >60){
    printf("Passed");
  } else{
    printf("Failed");
  }
  

}

