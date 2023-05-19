#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//defining the directions
#define UP 'w'
#define DOWN 's'
#define RIGHT 'd'
#define LEFT 'a'



void main() {

  //If my character is trying to outside of the matrix throw a warning and get it back to where it was. (this is for vertical moves)
  int is_hit_wall_y(int matrix_size, int y_c){

    if( y_c<1 ){
      y_c = 1;
      printf("\n WARNING: You can not break through walls \n");
      
    }else if(y_c > matrix_size){
      y_c = matrix_size;
      printf("\n WARNING: You can not break through walls \n");
    }
    return y_c ;
  
  }
  
    //If my character is trying to outside of the matrix throw a warning and get it back to where it was. (this is for horizontal moves)
    int is_hit_wall_x(int matrix_size, int x_c ){
    
      if( x_c<0 ){
        x_c = 0;
        printf("\n WARNING You can not break through walls \n");
        
      }else if(x_c>matrix_size -1 ){
        x_c = matrix_size -1;
        printf("\n WARNING You can not break through walls \n");
      }
      return x_c;
  
  }
  void drawing_game_room(int matrix_size , int x_d , int y_d , int x_c , int y_c){
  
    int column, flat ;
    
    
    // I  increased matrix_size for better view
    for (flat = 0 ; flat <= matrix_size +1 ; ++flat){
    

      for (column = 0 ; column <= matrix_size ; ++column){
      

        //There must be -- at the top and bottom of my matrix.
        if(flat ==0 || flat == matrix_size +1  ){
          printf("--");

        }else{
        
        //We are writing our D and C but D is first of course because if they are in same place I want to show D
          if(flat == x_d && column ==y_d){
          
            if(column == y_c -1 ){
              printf("|D");
              
            }else{
              printf("|D| ");
              ++column;            
            }

          //if they are side by side I deleted the extra space for better view
        
          }else if(flat == x_c && column == y_c){
          
            if(column == y_d -1 ){
              printf("|C");
              
            }else{
              printf("|C| ");
              ++column;            
            }

          }else{
          
            printf("| ");
          }
         }
        }
        
        printf("\n");
      }
    }
    
  
  //ınformations for game
  void info(){
    printf("Instructions:\n");
    printf("You are controlling C character in order to catch D\n");
    printf("You can control C character by (a,s,d,w)\n");
    printf("Enjoy!\n");
  }
  
  // Func returns 1 if C and D coordinates match if not 0
  int check_game_status( int x_d ,int  y_d ,int  x_c , int y_c){
  
    if(x_d == y_c && y_d == x_c){
      return 1;
    }
    return 0;
  }
  
  
  //this is the game playing 
  void game_play(int matrix_size){
    
    int score = 0;
    char choice;

    
    srand(time(0));
    int x_d = 0;
    int y_d = 1;
    int x_c = 2;
    int y_c = 3;
    
    // Taking the random numbers in matrix sizes
    x_d = (rand() % matrix_size) +1;
    x_c = (rand() % matrix_size) ;
    
    y_d = rand() % matrix_size;
    y_c = (rand() % matrix_size) +1;
    
    
    // The game is on going if my check func returns 0 which means C and D are not in the same coordinates
    while (check_game_status(x_d , y_d , x_c, y_c) == 0){
      
      // I have a counter for steps
      ++score;

      // I am checking hitting walls also every step
      y_c =  is_hit_wall_y(matrix_size , y_c);
      x_c = is_hit_wall_x(matrix_size , x_c);
      
      // I am drawing the matrix before every step
      drawing_game_room(matrix_size , x_d , y_d , y_c , x_c);
      printf("\n enter your move:");
      scanf(" %c" , &choice);
      char a;
      a= getchar();
      
      while(a !='\n'){
        a = getchar();
        printf("You can not input two char");

      }
      
      // Switch is the best options for running the code block for any choice
      switch(choice){
      
      
      // I defined directions at the top my code
      case UP:
        y_c = y_c -1;
        break;
        
      case DOWN:
        y_c = y_c +1;
        break;
        
      case LEFT:
        x_c = x_c -1;
        break;
      
      case RIGHT:
        x_c = x_c +1;
        break;
        
      }
      
      // Writing the score every step also
      printf("\n SCORE: %d \n", score );

    }
    
    // if while cycle is done write the final score and finish the game 
    printf(" \n >>> CONGRATS MY FRIEND \n");
    printf(">>>Your score is: %d <<<\n", score);
  }
  

  // I wrote a func for checking the user input about matrix size
  int set_matrix_size(){
      int matrix_size = 0;
  
      while(matrix_size<5 || matrix_size>10){
    
      printf("Please input the size of matrix (5-10)\n");
      scanf("%d", &matrix_size);
     } 
     
     return matrix_size;
  }
  
  // This is my func for welcomming the user
  void game_menu(){
  
    int choice;
    int matrix_size;
    
    printf(">>> Welcome to my 2D Game <<<\n");
    printf("1- Start a New Game\n");
    printf("2- Help\n");
    printf("3- Exit\n");
    
    scanf(" %d" , &choice);
    
    
    switch(choice){
      case 1:
      matrix_size = set_matrix_size();
      game_play(matrix_size);
      break;
      
      case 2:
      info();
      game_menu();
      break;
      
      case 3:
      printf("\n >>> Closing the game.. \n");
      break;
      
      default:
      break;

    }
  }
  
//Here is my call
  game_menu();

}
