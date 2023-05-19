#include <stdio.h>

int main(){

  int a;
  int b;
  int c;
  int ref;
  
  printf(">>>PART1<<<\n");
  printf("First Input: ");
  scanf("%d", &a);
  
  printf("\nSecond Input: ");
  scanf("%d", &b);
  
  printf("\nThird Input: ");
  scanf("%d", &c);

  if(b>a){
    ref =a;
    a=b;
    b=ref;
  }
  if(c>a){
    ref = a;
    a=c;
    c=ref;
  }
  if(c>b){
    ref = b;
    b=c;
    c=ref;
  }
  printf("\nmedian: ");
  printf("%d \n" , b);
  
  return 0;
  
}
