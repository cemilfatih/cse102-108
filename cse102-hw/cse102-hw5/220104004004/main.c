#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ALPHABET_SIZE 26

int main(){

  part1();
  part2();
  part3();
  
  return 0;
}

int part1(){
 //changing upper case to lower case using ASCII
  int to_lower_case(char chr) {
  
        if( chr>=65 && chr <= 90){
            chr = chr + 32;
        }
        
        return chr;
  }
  
  // Count occurrences of each letter in the English alphabet (case-insensitive)
  void count_letters(FILE *fp, int *counts){
      char c;

      while (!feof(fp)) {
              c=fgetc(fp);

              if (c == EOF){
                break;
              }
              
              c = to_lower_case(c);
              
              //magic is here, ı m beein able to submit every letter sufficiently
              counts[c - 'a']++;
      }
  }
  
  // Print the counts in a tabular format
  void print_counts(int *counts)
  {
      printf("Letter\tFrequency\n");
      printf("----------------\n");
      for (int i = 0; i < ALPHABET_SIZE; i++) {
        if(counts[i] != 0){
          printf("%c%c\t%d\n", 'a' + i,':', counts[i]); 
        }

      }
  }
  //This is for file name which is example.txt
    char str[50];
    char chr;
    
    printf("Welcome to count letters program \n");
    scanf("%s", str);
    // Open input file
    FILE *fp;
    fp = fopen(str, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Putting alphabet size of zeros
    int counts[ALPHABET_SIZE] = {0};

    count_letters(fp,counts);

    // Print results
    print_counts(counts);

    // Close input file
    fclose(fp);

    return 0;
}


// for generic code
static float color_values[][3] = {
  {1,0,0},
  {0,1,0},
  {0,0,1},
  {0.5,0.5,0},
  {0.5,0.4,0.2}
  };
  
//here is my enum
typedef enum
    {RED,GREEN,BLUE,YELLOW, ORANGE}
  Color;
  
int part2(){


  void color_mixer(Color color1 , Color color2 , void (*func)(Color,Color,Color*, int*)){
  
    Color mixed_color;
    int index;
    
    // THis returns mixed color and index of it in static array
    (*func)(color1,color2, &mixed_color , &index);
    
        //for printing the results
    switch(index){
    
    case 0:
      printf("RED ");
      break;
    
    case 1:
      printf("GREEN ");
      break;
    
    case 2:
      printf("BLUE ");
      break;
      
    case 3:
      printf("YELLOW ");
      break;
    
    case 4:
      printf("ORANGE ");
      break;
    }
  
  //for printing values of result
    printf("%.1f %.1f %.1f", color_values[mixed_color][0],color_values[mixed_color][1],color_values[mixed_color][2]);
    
  }
  
  //this is my pointed func
  void get_mixed(Color color1, Color color2, Color *mixed_color, int *color_index){
    
    float r1,g1,b1, r2,g2,b2, r3,g3,b3;
    
    r1= color_values[color1][0];
    g1= color_values[color1][1];
    b1= color_values[color1][2];
    
    r2= color_values[color2][0];
    g2= color_values[color2][1];
    b2= color_values[color2][2];
    
    //mixed color's values
    r3= (r1+r2)/2;
    g3= (g1+g2)/2;
    b3= (b1+b2)/2;
    
    //for generic code
    float mixed[3] = {r3, g3 , b3};
    
    int i,j;
    int index;
    float c1,c2,c3;
    
    // I set 100 because old one should bu greater than new one in the first place
    float old_distance = 100;
    float new_distance;

    
    for (i=0; i<5; i++){
    
      //ı took every value of static array in order to compare them
      c1 = color_values[i][0];
      c2 = color_values[i][1];
      c3 = color_values[i][2];
      
      // array for generic code
      float temp_arr[3] = {c1,c2,c3};
      
      // I reset the dew distance in every turn
      new_distance=0;
      
      
      // get the squared distance of every value
      for (j=0; j<3; j++){
        float distance = mixed[j]-temp_arr[j];
        
        //add them to new distance
        new_distance = new_distance + pow(distance,2);
      }
    
      //if old one is greater than new one, this one should be my new distance.
      if (new_distance < old_distance){

        old_distance = new_distance;
        
        // get the result's index
        index = i;
      }
    

    }
    
    //outputs
    *color_index = index;
    
    switch(index){
    
    case 0:
      *mixed_color = RED;
      break;
    
    case 1:
      *mixed_color = GREEN;
      break;
    
    case 2:
      *mixed_color = BLUE;
      break;
      
    case 3:
      *mixed_color = YELLOW;
      break;
    
    case 4:
      *mixed_color = ORANGE;
      break;
    }
    
    
  }

  void assign_color(char chr, Color *color){
  
  
  //convert them to my enum
    switch(chr){
    
    case 'r':
      *color = RED;
      break;
    
    case 'g':
      *color = GREEN;
      break;
    
    case 'b':
      *color = BLUE;
      break;
      
    case 'y':
      *color = YELLOW;
      break;
    
    case 'o':
      *color = ORANGE;
      break;
    }
    
  }
  

 
  //my main codes
  char c1;
  char c2;
  
  printf("\nEnter color1:(r,g,b,o,y) ");
  scanf(" %c" , &c1);
  
  printf("\nEnter color2:(r,g,b,o,y) ");
  scanf(" %c" , &c2);
  
  Color color1;
  Color color2;
  
  assign_color(c1, &color1);
  assign_color(c2, &color2);
  
  color_mixer(color1, color2 , get_mixed);



}


//tic-tac-toe
int part3()
{

    
    char board[3][3];
    char player1 = '1';
    char player2 = '2';
    char x = 'X';
    char o = 'O';
    char current_char = x;
    
    //current player for setting the who's round is this.
    char current_player = player1;
    int row, col;
    int game_over = 0;
    int play_again = 1;
    int num_moves = 0;


// if play again false stop the game
    while (play_again) {
    
        //resest the board
        init_board(board);
        num_moves = 0;
        game_over = 0;

        // I checked game status with two case, one of them is; is there a winner and other one of them is; is number of moves equals 9
        while (!game_over && num_moves < 9) {
            print_board(board);

            printf("Player %c's turn (%c)\n", current_player,current_char);
            printf("Enter row (1-3): ");
            scanf("%d", &row);
            printf("Enter column (1-3): ");
            scanf("%d", &col);

            // Check if move is valid
            if (!is_valid_move(board, row-1, col-1)) {
                printf("Invalid move, try again\n");
                continue;
            }

            // Update board in every step
            board[row-1][col-1] = current_char;
            num_moves++;

            // Check for win
            if (check_win(board, current_char)) {
                printf("Player %c wins!\n", current_player);
                game_over = 1;
            }

            // change the current player
            if (current_player == player1) {
                current_player = player2;
                current_char = o;
            } else {
                current_player = player1;
                current_char = x;
            }
        }

        // Check for draw
        if (!game_over) {
            printf("It's a draw!\n");
        }

        // Ask to play again
        printf("Do you want to play again? (Y/N): ");
        char answer;
        scanf(" %c", &answer);
        if (answer == 'Y' || answer == 'y') {
            play_again = 1;
        } else {
            play_again = 0;
        }
    }

    printf("Thanks for playing!\n");

    return 0;
}

// Initialize the board
void init_board(char board[3][3])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Print the board
void print_board(char board[3][3])
{
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c", board[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("- - -\n");
        }}}
   
   int is_valid_move(char board[3][3], int row, int col)
{
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return 0;
    }
    if (board[row][col] != ' ') {
        return 0;
    }
    return 1;
    }


  // Check if the current player has won
int check_win(char board[3][3], char player[])
{
    // Checking the rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Checking the columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }

    // Checking the diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    // No win keep going
    return 0;
}

