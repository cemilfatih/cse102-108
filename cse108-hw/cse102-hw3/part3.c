#include <stdio.h>

int main(){

  char operation;
  int a,b,result, prediction;
  
  printf(">>>PART3<<< \n");
  printf("Select an Operation (+,-,/,*):");
  scanf("%c" , &operation);
  
  printf("\n Enter two integers");
  scanf( "%d %d", &a, &b);
  
  printf("\n prediction: ");
  scanf("%d", &prediction);
  
  if(operation =='+'){
    result = a+b;
  }
    if(operation =='*'){
    result = a*b;
  }
    if(operation =='-'){
    result = a-b;
  }
    if(operation =='/'){
    result = a/b;
  }
  
  if(result == prediction){
    printf("\n Bravo, Correct Answer! ");
  }else{
    printf("\n Wrong Answer, Try Again!");
  }
  
}
