#include <stdlib.h>
#include <stdio.h>

int draw_triangle(int rows)
{
    int i, j;




    for(i=1; i<=rows; i++)
    {

        for(j=i; j<rows; j++)
        {
            printf("  ");
        }


        for(j=1; j<=(2*i-1); j++)
        {
            if(i==rows || j==1 || j==(2*i-1))
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }


        printf("\n");
    }

    return 0;
}




int draw_rectangle(int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i==1 || i==n || j==1 || j==n)            
                printf("* ");  

            else
                printf("  ");            
        }
        printf("\n");
    }
  return 0;
  
}



void write_shapes_to_file() {
    char shape_type;
    int size;
    

    FILE *file = fopen("shapes.txt", "w");
    if (file == NULL) {
        printf("Can not open file.\n");
        exit(1);
    }
    

    while (1) {
        printf("Enter shape type (s for square, t for triangle, e to end): ");
        scanf(" %c", &shape_type);
        
        if (shape_type == 'e') {
            break;
        }
        
        printf("Enter size (3-10): ");
        scanf("%d", &size);
        
        if (size < 3 || size > 10) {
            printf("Input should be in between 3-10\n");
            continue;
        }
        
        if (shape_type == 's') {

            fprintf(file, "s,%d\n", size);
        } else if (shape_type == 't') {

            fprintf(file, "t,%d\n", size);
        } else {
            printf("Invalid shape type. Please enter s, t or e.\n");
            continue;
        }
    }
    
    // Close file
    fclose(file);
}




void read_shapes_from_file() {
    // Open file for reading
    FILE *file = fopen("shapes.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    
    // Read shapes from file and print them to the console
    char shape_type;
    int size;
    
    while (fscanf(file, "%c,%d\n", &shape_type, &size) != EOF) {
        if (shape_type == 's') {
            printf("Square with size %d\n", size);
            draw_rectangle(size);
        } else if (shape_type == 't') {
            printf("Triangle with size %d\n", size);
            draw_triangle(size);
        } else {
            printf("Invalid shape type in file.\n");
            exit(1);
        }
    }
    

    fclose(file);
}

  

int main(){

    
    //write_shapes_to_file();
    //read_shapes_from_file();
    int cycle=0;
    int choice;
    while (choice != 3){
    
    


      printf("Welcome to Shape Reader! Please make your choice to continue:\n");
      printf("1-) Generate a shape file\n");
      printf("2-) Read and Draw a Shape File\n");
      printf("3-) Terminate the Program\n");
  
      scanf("%d", &choice);
      
      if(cycle ==0 && choice ==2){
        printf("You can not choose '2' without create file\n");
        choice =4;
      }
      cycle = cycle +1;
      menu(choice);
    }

    return 0;
}

int menu(int choice){

  
  switch(choice){
  case 1:
    write_shapes_to_file();
    read_shapes_from_file();
    break;
  case 2:
    read_shapes_from_file();
    break;
  case 3:
    break;
  case 4:
    break;
  }
  
  return 0;
}
