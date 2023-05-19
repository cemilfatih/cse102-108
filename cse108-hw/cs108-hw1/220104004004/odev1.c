#include <stdio.h>

int main() {
    
	
    int num;
 
    printf("Enter an integer value between 1 and 100: ");
    scanf("%d", &num);

    while(num>100 || num<0){
     
        printf("kurallara uygun sayı gir");
    	scanf("%d", &num);
	
    }

    void isBuzz(int num){
    
	    if(num<=50 && num>= 5){
	    	printf("Buzz\n");
	    }
    }
    void isFizz(int num){
    	
	    if( num % 3 == 0){
	    	printf("Fizz");
	    }
    }
            isFizz(num);
        isBuzz(num);







}
