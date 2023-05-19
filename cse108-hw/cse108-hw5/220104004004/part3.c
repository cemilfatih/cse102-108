#include <stdio.h>

int main() {

    
    int operate(int number, int choice){
    
    int  temp, remainder;
    int binary = 0, octal = 0;
    int i = 1, j = 1;
    
    if(choice == 1){
        printf("Decimal equivalent: %d\n",number);
    }


    else if(choice == 2){
        temp = number;
    
    while (temp != 0) {
        remainder = temp % 2;
        binary += remainder * i;
        i *= 10;
        temp /= 2;
    }
    printf("Binary: %d\n", binary);

    }
    else if(choice == 3){
          temp = number;
    while (temp != 0) {
        remainder = temp % 8;
        octal += remainder * j;
        j *= 10;
        temp /= 8;
    }
    printf("Octal: %d\n", octal);
    
      
    }
    

    
    else if(choice == 4){
        printf("Hexadecimal: %x\n", number);
    }else{
      printf("\nInvalid Input");
    }


    return 0;
    }
    
    

    int menu(){
      int choice;
      int number;
      
      printf("Convert a number to decimal, binary, octal, and hexadecimal\n");
      printf("Exit \n");
      
      printf("enter your choice: ");
      scanf("%d" , &choice);
      
      printf("Enter a number: ");
      scanf("%d" , &number);
      
      operate(number , choice);
      return 0;
      
    }
    
    menu();

}
