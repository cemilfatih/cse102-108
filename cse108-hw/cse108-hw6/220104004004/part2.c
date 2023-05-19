#include <stdio.h>
#define MAX_SIZE 100



int main(){

  int age[ MAX_SIZE];
  char occupation[MAX_SIZE];
  float salary[MAX_SIZE];
  char team[MAX_SIZE];
  int n;
  char choice;
  int total_salary;
  int i;
  int j;
  
  FILE *fp;
  
  fp = fopen("db.txt", "r");
  
  fscanf(fp , "%d", &n);
  
  for(i=0 ; i<n ; i++ ){
    fscanf(fp, "%d %c %f %c", &age[i], &occupation[i], &salary[i], &team[i]);
  }
  
  printf("\n Please select a team: ");
  scanf("%c", &choice);
  
  for(j=0 ; j<n ; j++){
    if(choice == team[j] ){
        total_salary = total_salary+salary[j];
        
    }

    
    }
    
        
    if(total_salary == 0){
      printf("\nThere is no such a team\n");
    }else{
      printf("\n%d",total_salary);
    }

  
  
  
  

  return 0;
}
