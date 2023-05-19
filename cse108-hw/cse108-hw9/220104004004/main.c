#include <stdio.h>
#include <math.h>
#include <string.h>

#define STRING_SIZE 50
#define MAX_ITEMS 100


typedef struct{
  char name[STRING_SIZE];
  char color[STRING_SIZE];
  float price;
  int serial_number;
  int quantity;

} furniture;


int menu();
void write_database(furniture items[], int num_items);
int read_database(furniture items[]);
void reading(furniture items[MAX_ITEMS], int num_items);
void writing(furniture items[MAX_ITEMS], int num_items);
void removing(furniture items[MAX_ITEMS], int num_items);
void search_product(furniture items[], int num_items);
void search_furniture_by_name(furniture items[], int num_items, char *search_term);
void search_furniture_by_color(furniture items[], int num_items, char color[]);




int main(){


menu();

}

int menu(){

  int choice;
  
  furniture items[MAX_ITEMS];
  int num_items = read_database(items);

  
  do{
  printf("\n1-See all furnitures\n"
        "2-Add a new furniture\n"
        "3-Remove furniture\n"
        "4-Search furniture\n"
        "5- Exit\n");
        
  scanf("%d", &choice);
  
  switch(choice){
  
  case 1:
    reading(items, num_items);
    break;
  
  case 2:
    writing(items, num_items);
    break;
  
  case 3:
    removing(items, num_items);
    break;
    
  case 4:
    search_product(items, num_items);
    break;
    
  case 5:
    printf("exiting\n");
    break;
  
  default:
    printf("Invalid \n");
    choice = 5;
  }
  
  }while (choice != 5);
}


void reading(furniture items[MAX_ITEMS], int num_items){

  printf("Name\t\tColor\t\tPrice\t\tSerial\t\tQuantity\n");
  for (int i = 0; i < num_items; i++) {
  printf("%-12s\t%-8s\t%-8.2f\t%-8d\t%-8d\n", items[i].name, items[i].color, items[i].price, items[i].serial_number,items[i].quantity);
      
  }
  }

void writing(furniture items[MAX_ITEMS], int num_items){


    if (num_items >= MAX_ITEMS) {
        printf("Error: database is full.\n");

    }
    printf("Enter furniture name: ");
    scanf("%49s", items[num_items].name);
    printf("Enter furniture color: ");
    scanf("%19s", items[num_items].color);
    printf("Enter furniture price: ");
    scanf("%f", &items[num_items].price);
    printf("Enter furniture serial number (6 digits): ");
    scanf("%6d", &items[num_items].serial_number);
    printf("Enter furniture quantity: ");
    scanf("%d", &items[num_items].quantity);
    num_items++;
    write_database(items, num_items);
    printf("Furniture added.\n");
    

}

void removing(furniture items[MAX_ITEMS], int num_items){

      if (num_items == 0) {
        printf("Error: database is empty.\n");
    }
    printf("Enter serial number of furniture to remove: ");
    
    int serial_number;
    scanf("%6d", &serial_number);
    for (int i = 0; i < num_items; i++) {
        if (items[i].serial_number == serial_number) {
            for (int j = i; j < num_items - 1; j++) {
                items[j] = items[j + 1];
            }
            num_items--;
            write_database(items, num_items);
            printf("Furniture removed.\n");

        }
    }


}


void write_database(furniture items[], int num_items) {
    FILE *file = fopen("furniture_database.txt", "w+");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return;
    }

    for (int i = 0; i < num_items; i++) {
        fprintf(file, "%s %s %.2f %06d %d\n", items[i].name, 
                items[i].color, items[i].price, items[i].serial_number, 
                items[i].quantity);
    }

    fclose(file);
}

int read_database(furniture items[]) {
    FILE *file = fopen("furniture_database.txt", "r+");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 0;
    }

    int num_items = 0;
    while (fscanf(file, "%49s %19s %f %6d %d\n", 
            items[num_items].name, items[num_items].color, 
            &items[num_items].price, &items[num_items].serial_number, 
            &items[num_items].quantity) == 5) {
        num_items++;
        if (num_items >= MAX_ITEMS) {
            break;
        }
    }

    fclose(file);
    return num_items;
}


void search_product(furniture items[], int num_items){

int menuoption;
char search_term[50];
printf("Select a property to make search\n1-Name\n2-Color\n\n>");
scanf("%d",&menuoption);

switch (menuoption){

	case 1:
    	printf("Enter furniture name to search: ");
    	scanf("%s",search_term);
    	search_furniture_by_name(items, num_items, search_term);
    	break;

    case 2:
    	printf("Enter furniture color to search: ");
    	scanf("%s",search_term);
    	search_furniture_by_color(items, num_items, search_term);
    	break;

}

}

void search_furniture_by_name(furniture items[], int num_items, char *search_term) {
    int i, found = 0;
    for (i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, search_term) == 0) {
            printf("Name\t\tColor\t\tPrice\t\tSerial\t\tQuantity\n");
            printf("%-12s\t%-8s\t%-8.2f\t%-8d\t%-8d\n", items[i].name, items[i].color, items[i].price, items[i].serial_number, items[i].quantity);
            found = 1;
        }
    }
    if (!found) {
        printf("No furniture found with name %s\n", search_term);
    }
}

void search_furniture_by_color(furniture items[], int num_items, char color[]) {
    int found = 0;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].color, color) == 0) {
            if (found == 0) {
                printf("\nSearch results for color \"%s\":\n", color);
                printf("Name\t\tColor\t\tPrice\t\tSerial\t\tQuantity\n");
            }
            printf("%-12s\t%-8s\t%-8.2f\t%-8d\t%-8d\n", items[i].name, items[i].color, items[i].price, items[i].serial_number, items[i].quantity);
            found = 1;
        }
    }
    if (found == 0) {
        printf("No results found for color \"%s\".\n", color);
    }
}
