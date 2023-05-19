#include <stdio.h>
#include "util.h"


    void part1(){
    

                int a,b;

                printf("input first number:");
                scanf("%d" , &a);
                printf("input second number:");
                scanf("%d" , &b);

                //default gcd is 1 
                int remainder = 1;


                //There are several steps in order to reach remainder = 0;
                while (remainder != 0){
                        
                        // This is cycle that runs till remainder = 0;
                        remainder = a % b;
                        a=b;
                        b=remainder;

                }
                
                //when algorithm is done a is gcd
                printf("%d\n" , a);
                }


        void part2(){

                int a;
                int b;
                int c;

                // I want to work with 4 digits numbers
                printf("input first number:");
                scanf("%4d" , &a);
                printf("input second number:");
                scanf("%4d" , &b);
                printf("\n");
                
                // I want to set 7 digits in order to see numbers accurate
                printf("%7d" , a);
                printf("\n");
                printf("%7d" , b);
                printf("\n");
                printf("+");
                printf("\n");
                printf("-------");
                printf("\n");

                c=a+b;
                printf("%7d" , c);
                printf("\n");

        }

        void part3(){
        
      int a ;
      int b;
      int line1;
      int line2;
      int line3;
      int b1;
      int b2;
      int b3;
      int result;
      
      
      printf(" \n first number:");
      scanf("%3d" , &a);
      
      printf(" \n second number:");
      scanf("%3d" , &b);
      

      

      
       // I separate the number into digits
      b3 = (b /100) %10;
      b2 = (b /10) %10;
      b1 = b%10;
      
      
      // Calculate every line of multiply operation
      line1 = b1 *a;
      line2 = b2 *a;
      line3 = b3 *a;
      
      
      // print 10 digits in order to see properly the multiply operation
      printf("%10d \n", a);
      printf("%10d \n", b);
      printf("* \n");
      printf("---------- \n");
      

      printf("%10d \n", line1);
    
    
    // I don't want to add meanless zero if my inputs 1 or 2 digits numbers
      if(line2 != 0){
          printf("%9d \n", line2);
      }
      if(line3 != 0){
          printf("%8d \n", line3);
      }
      
      printf("+ \n");
      printf("---------- \n");
      
      result = a*b;
      printf("%10d \n", result);


	}
	
    
      void part4(){
      
      int a;
        printf(">>>>> 1-10 PART<<<<< \n");
        
        printf("Please enter a number in between 1-10 \n");
        
        scanf("%d" , &a);
        
        
        // I think the instructions says greater than and less than 10 so I did it that way
        if(a>5 && a <=10 ){
          printf("The integer you entered is greater than 5");
        
        }else if(a <= 5 && a >= 0 ){
          printf("The integer you entered is less than or equal to 5");
        
        }else{
          printf("Invalid input");
        }
        }




