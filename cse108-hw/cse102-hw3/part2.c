#include <stdio.h>

int main(){
  int a;
  char gradea;
  char plusa;
  char gradeb;
  char plusb;
  char plusc;
  char gradec;
  int b;
  int c;
  int result;
  
  printf(">>>PART2<<< \n");
  printf("Enter Your Grades: ");
  
  scanf("%d %d %d", &a, &b ,&c );
  
  result = (a+b+c) /3;
  
  char switch_func(int a){
    
    switch( a/10){
    
    case 10:
      return 'A';
      break;
    case 9:
      return 'A';
      break;
    case 8:
      return 'A';
      break;
    case 7:
      return 'A';
      break;
    case 6:
      return 'B';
      break;
    case 5:
      return 'C';
      break;
    case 4:
      return 'D';
      break;
    }
  }
  
  char plus_func(int a){

  switch(a/10){
    case 10:
    case 9:
      return '+';
      break;
    case 7:
      return '+';
      break;
    default:
      return ' ';
      break;
  
  }
  
  }
  
  gradea = switch_func(a);
  plusa= plus_func(a);
  gradeb = switch_func(b);
  plusb= plus_func(b);
  gradec = switch_func(c);
    plusc= plus_func(c);
  
  
  printf("%c %c\n", gradea , plusa);
  printf("%c %c\n", gradeb , plusb);
  printf("%c %c\n", gradec , plusc);
      
  printf("%d" , result);


  return 0;
}
