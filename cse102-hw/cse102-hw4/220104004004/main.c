#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define S_DISCOUNT 0.125
#define TOTAL_DISCOUNT 0.1
#define TAX 0.18
#define kebap		75.99
#define lahmacun	21.50
#define pide		40.00
#define doner		55.60
#define iskender        65.00
#define durum           35.00
#define kola		15.00
#define su		 5.00
#define kunefe		60.00
#define sutlac	        32.50


int main(){
  
  print_menu();
  get_serve();
  
  game();
}

// Calcultaing the tax price 
  float tax( float price ){
    float price_with_tax = price + (price * TAX);
    return price_with_tax;
    
  } 
  
  //Calculating the discount if total price is greater than 150
  float over_discount(float total_price){
    float discount = 0;
    if(total_price >150){
      discount = total_price* TOTAL_DISCOUNT;
    }
    return discount;
  }
  
  //Calculating the student discount if user is student
  float student_discount(float total_price){
    char isStudent;
    float discount;
    int cycle;
    
    // keep asking if answer is not satisfied
      while(1){
    
    
        printf("\nAre you a student?");
        scanf(" %c" , &isStudent);
        
        
        switch(isStudent){
        
          case 'Y':
          case 'y':
          
            discount =  total_price * S_DISCOUNT ;
            cycle == 0;
            break;
          
          case 'n':
          case 'N':
          
            discount = 0;
            cycle == 0;
            break;
          
          default:
          break;
        }
        
      if(cycle == 0){
        break;
    } 
    }
    
    return discount;

    
    
  }

  // printing the menu in the first place
  int print_menu(){
  
  FILE *fp;
  //open file with read mode
  fp = fopen("menu.txt" , "r");
  
  //Get all the data of text file till reaching the end of file
  int c = fgetc(fp);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fp);
    }
    
    //close file at last
    fclose(fp);
  }
  
  //here is the serving part
  int get_serve(){
  
    FILE *fp;
    
    //open file with w if there are not such a file named recepit.txt it will cerate one
    fp = fopen("receipt.txt" , "w+");
    
    int cycle = 1;
    int choice;
    float amount;
    float total_price = 0;
    float s_discount;
    float o_discount;
    
    
    // This is how i get the date
    time_t now;
    struct tm *local;
    char str[100];
    now = time(NULL);
    local = localtime(&now);
    strftime(str, 100, "%d-%m-%Y %H:%M:%S", local);

  
  
    
    //This is the top of receipt
    fprintf(fp, "%s\t\t%s\n\n%s\n\n%s\t\t\t%s\n\n", "220104004004",str,"------------------------------------","Product","Price(TL)");
    
    
    while(1){
      
      printf("\nPlease choose a product: ");
      scanf("%d" , &choice);
      
      printf("\nHow many servings do you want?: ");
      scanf("%f" , &amount);
      
      //if amount is  0 it will stop asking
      if(amount == 0){
        break;
      }
      
      //I am not proud of this code but so far so good
      switch(choice){
        case 1:
        
        //Simply I am writing amount and food type to file
        //and adding them to total price
        //Same for all cases
          total_price = total_price +(amount*kebap);
          fprintf(fp,"%.0f%s\t\t\t%.2f\n\n",amount,"*Kebap",amount*kebap);
          break;
        case 2:
          total_price = total_price +(amount*lahmacun);
          fprintf(fp,"%.0f%s\t\t%.2f\n\n",amount,"*Lahmacun",amount*lahmacun);
          break;
        case 3:
          total_price = total_price+ (amount*pide);
          fprintf(fp,"%.0f%s\t\t\t%.2f\n\n",amount,"*Pide",amount*pide);
          break;
        case 4:
          total_price = total_price +(amount*doner);
          fprintf(fp,"%.0f%s\t\t\t%.2f\n\n",amount,"*Döner",amount*doner);
          break;
        case 5:
          total_price = total_price+ (amount*iskender);
          fprintf(fp,"%.0f%s\t\t%.2f\n\n",amount,"*İskender",amount*iskender);
          break;
        case 6:
          total_price = total_price +(amount*durum);
          fprintf(fp,"%.0f%s\t\t\t%.2f\n\n",amount,"*Dürüm",amount*durum);
          break;
        case 7:
          total_price = total_price +(amount*kola);
          fprintf(fp,"%.0f%s\t\t\t%.2f\n\n",amount,"*Kola",amount*kola);
          break;
        case 8:
          total_price = total_price +(amount*su);
          fprintf(fp,"%.0f%s\t\t\t%.2f\n\n",amount,"*Su",amount*su);
          break;
        case 9:
          total_price = total_price +(amount*kunefe);
          fprintf(fp,"%.0f%s\t\t\t%.2f\n\n",amount,"*Künefe",amount*kunefe);
          break;
        case 10:
          total_price = total_price +(amount*sutlac);
          fprintf(fp,"%.0f%s\t\t\t%.2f\n\n",amount,"*Sütlaç",amount*sutlac);
          break;
      }  
    }
    

    //There are my discount funcs
    s_discount = student_discount(total_price);
    o_discount = over_discount(total_price);
      // printing total price without any discount or tax
    fprintf(fp , "%s\t\t\t%.2f\n\n","Total:", total_price);
    
    // I am not printing discounts if there are not
    if (s_discount != 0){
      fprintf(fp, "%s\t%s%.2f\n\n", "Student Discount:","-", s_discount);
    }
    if(o_discount != 0){
      fprintf(fp, "%s\t\t%s%.2f\n\n", "+150 Discount:","-", o_discount);
    }
    
    fprintf(fp , "-----------------------------------\n\n");
    
    total_price = total_price - s_discount;
    total_price = total_price - o_discount;
    
    //printing the last versions of total price
    fprintf(fp , "%s\t\t\t%.2f\n\n" , "Price:", total_price);
    fprintf(fp , "%s\t\t%.2f\n\n" , "Price + VAT:", tax(total_price));
    
    fclose(fp);


  // lastly returning the receipe.txt content to user
  fp = fopen("receipt.txt", "r");
   int c = fgetc(fp);
   printf("\n\n");
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fp);
    }
  
    fclose(fp);
  }


int game()
{

  printf("\n\n Welcome to My Game! \n");
//keep playing till it stops
  int game_again = 1;
  while(1){
  
      int player_choice, computer_choice;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get the player's choice
    printf("Enter your choice (1 for rock, 2 for paper, 3 for scissors): ");
    scanf("%d", &player_choice);

    // generate computer choice
    computer_choice = rand() % 3 + 1;

    //convert choices to strings for better understanding
    printf("You chose ");
    switch (player_choice) {
        case 1:
            printf("rock.\n");
            break;
        case 2:
            printf("paper.\n");
            break;
        case 3:
            printf("scissors.\n");
            break;
        default:
            printf("an invalid option.\n");
            return 1;
    }
    //Same here
    printf("The computer chose ");
    switch (computer_choice) {
        case 1:
            printf("rock.\n");
            break;
        case 2:
            printf("paper.\n");
            break;
        case 3:
            printf("scissors.\n");
            break;
        default:
            printf("an invalid option.\n");
            return 1;
    }

    // Check the winner
    if (player_choice == computer_choice) {
        printf("It's a tie!\n");
    } else if ((player_choice == 1 && computer_choice == 3) ||
               (player_choice == 2 && computer_choice == 1) ||
               (player_choice == 3 && computer_choice == 2)) {
        printf("You win!\n");
    } else {
        printf("The computer wins!\n");
    }

//If user says no game will stop
    char choice;
    printf("Want to play again? (y/N)\n");
    scanf(" %c", &choice);
    
    if(choice == 'n' || choice == 'N'){
      break;
    }
  
  }

}



  

