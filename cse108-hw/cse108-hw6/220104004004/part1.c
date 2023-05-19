#include <stdio.h>
#define MAX_SIZE 10

int main(){

  int values[MAX_SIZE];
  int labeled_values[MAX_SIZE];

  void take_values(int values[]){
    
    int counter = 0;
    while(1){
    
      printf("\n Please enter your values: (-100 for exit)");
      scanf("%d" , &values[counter]);
      
      if(values[counter] == -100){
        break;
      }
      
      ++counter;
    }

  }
  
  void label_func(int values[], int labeled_values[]){
    

    int counter = 0;
    
    while(1){
      
      
      if(values[counter] % 2 == 0){
        
        labeled_values[counter] = 'e';
      }else{
        labeled_values[counter] = 'o';
      }
      
      ++counter;
      
      if(values[counter] == -100){
        break;
      }
    }
    
  }
  
  void print_results(int values[] , int labels[]){
    
    int counter = 0;
    while(1){
      
      printf("\n%d\t%c\n",values[counter] , labels[counter]);
      
      ++counter;
      if(values[counter] == -100){
        break;
      }
    }
  }

  take_values(values);
  label_func(values , labeled_values);
  print_results(values , labeled_values);
  return 0;
}
