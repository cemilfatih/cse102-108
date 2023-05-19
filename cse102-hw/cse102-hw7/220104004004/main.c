#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_SIZE 12
#define WORD_COUNT 20
#define MAX_NUM_WORDS 1002
#define THRESHOLD 26.0


void get_input_from_user(char words[WORD_COUNT][WORD_SIZE]);
int read_dict(const char * file_name, char dict[][WORD_SIZE]);
int  read_text(const char  * text_file, const char  * ignore_file, char words[WORD_COUNT][WORD_SIZE]);
int read_ignore_file(const char * ignore_file,char words[WORD_COUNT][WORD_SIZE] );
void assign_string(char dest[WORD_SIZE], const char src[WORD_SIZE]);
int read_dict(const char * file_name, char dict[][WORD_SIZE]);
double dissimilarity(char * w1, char * w2, char dict[][WORD_SIZE],char * dict_name, float threshold );
void histogram(const char words[][WORD_SIZE],const int text_count[]);


int main(){
  

  char words[WORD_COUNT][WORD_SIZE] = {{}};
  char text_file[WORD_SIZE], ignore_file[WORD_SIZE];
  //getting input from users as array
  get_input_from_user(words);
  
  //get the proper files from users
  printf("\n Print text file name you want to read: ");
  scanf("%s", text_file);
  
  printf("\n Print ignore file name you want to read: ");
  scanf("%s", ignore_file);  
  read_text(text_file, ignore_file, words);
  
}

//getting inputs from users. Limit is 20 words
void get_input_from_user(char words[WORD_COUNT][WORD_SIZE] ){

    int i =0;
    printf("Enter the words you r looking for: ");
  
    while (i < WORD_COUNT) {
    
            
        printf("Word %d: ", i+1);
        fgets(words[i], WORD_COUNT, stdin);

        // Remove any trailing newline character
        
        int len = 0;
        while (words[i][len] != '\0' && words[i][len] != '\n') {
            len++;
        }
        if (words[i][len] == '\n') {
            words[i][len] = '\0';
        }

        if (words[i][0] == '\0') {
            break;
        }
        
        i++;
    }
    
     for (int j = 0; j < i; j++) {
        printf("%d: %s\n", j+1, words[j]);
    }
    
}

int read_text(const char  * text_file, const char  * ignore_file, char words[WORD_COUNT][WORD_SIZE]){

  int i;
  
  FILE* fp;
  
  int counter=0;
  char closest_match[WORD_SIZE];
  char dict[MAX_NUM_WORDS][WORD_SIZE];
  char text[WORD_SIZE], ignore_text[WORD_COUNT][WORD_SIZE];
  int text_count[WORD_COUNT] = {0};
  
  i = read_ignore_file(ignore_file, ignore_text);
  read_dict("dictionary.txt", dict);
  
  fp = fopen(text_file, "r");
  
  if(fp== NULL){
    printf(" \n ERROR/ opening file \n");
    return 1;
  } 
  
  //we calculate how many inputs have given by user
   for (int x = 0; x<WORD_COUNT; x++){
    if(strcmp(words[x],"") != 0 && words[x] != NULL){
    counter ++;
    }
    }
  
//scanning the file
  while(fscanf(fp ,"%s" , text) == 1){
  
  
  //if the text is ignored we disable it
    for(int j = 0; j<i ; j++){
      if(strcmp(ignore_text[j], text) == 0){
        assign_string(text,"aaaaaaaaaaaa");
        }
      }


// if input is in file then we increment the count
    for (int n=0; n<counter ; n++){
        if(strcmp(text,words[n]) == 0){
          text_count[n] ++;
        }
      }
    }
    
    fclose(fp);
    
    fp = fopen(text_file, "r");
    for (int a=0; a<counter ; a++){

      if (text_count[a] == 0){
        //there are no such this text in ,input
        //dissimilarity
        
        dissimilarity(words[a],closest_match, dict, "dictionary.txt", THRESHOLD);
        
        assign_string(words[a],closest_match);
        char text2[WORD_SIZE];
        
        while(fscanf(fp, "%s", text2) ==1){
        
          if(strcmp(text2, closest_match) ==0){
          
          //This is the tricky point, if it's not in input.txt but closest one is; We increment the count by -1
            text_count[a]--;
        
         }

        }
      
    }
    }
    fclose(fp);
    
    histogram(words, text_count);

  
}



// If its zero there are no matches if its more than zero there are exact matches if its negative there are close matches
void histogram(const char words[][WORD_SIZE],const int text_count[WORD_COUNT]){

  int counter = 0;

    
   for (int x = 0; x<WORD_COUNT; x++){
    if(strcmp(words[x],"") != 0 && words[x] != NULL){
    counter ++;
      }
    }
  
  int temp[WORD_COUNT];
  for (int i = 0; i<WORD_SIZE; i++) {
    temp[i]=text_count[i];
  }
  
  for (int i = 0; i<WORD_SIZE; i++) {
      if(temp[i]<0) temp[i]*(-1);
  }
  int max_occurrence = 0;
      for (int i = 0; i<WORD_SIZE; i++) {
          if (temp[i] > max_occurrence) {
              max_occurrence = temp[i];
          }
      }
  int scale= (max_occurrence/20)+1;
  
  printf("Scale: %d\n", scale);
  
  for (int a=0; a<counter; a++){
    printf("%s: ", words[a]);
    if(text_count[a]>0){

      for (int c=0; c<text_count[a]/scale; c++ ){
        printf("*");
      }
    }else if(text_count[a]<0){
      int operation = text_count[a]*-1;
      for(int x=0; x<operation/scale; x++){
        printf("+");
      }
    } else{
      printf("No matches\n");
      }
  printf("\n");
  }
  
  
}



// reading ignore file and putting them in array
int read_ignore_file(const char * ignore_file, char ignore_text_arr[WORD_COUNT][WORD_SIZE]){

  FILE* fp;
  char ignore_text[WORD_SIZE];
  int i = 0;
  
  
  fp = fopen(ignore_file, "r");
  
  if(fp== NULL){
    printf(" \n ERROR/ opening file \n");
  } 
  
  while( fscanf(fp,"%s", ignore_text) == 1){
    assign_string(ignore_text_arr[i],ignore_text );
    i ++; 
    }
    
  fclose(fp);
  return i;
}

//simple function for assigning string
void assign_string(char dest[WORD_SIZE], const char src[WORD_SIZE]) {
    int i = 0;
    while (src[i] != '\0' && i < WORD_SIZE - 1) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

//reading the dict put it in an array
int read_dict(const char * file_name, char dict[][WORD_SIZE]){

    FILE *fp;
    char word[WORD_SIZE];
    int count = 0,num_words, vector_size;
    char line[100];

    fp = fopen(file_name, "r");
    
    if (fp == NULL) {
        return -1;
    }
    
    fgets(line,100,fp );
    sscanf(line, "num_word=%d, vector_size=%d", &num_words, &vector_size);

    while (!feof(fp)) {
    
    fscanf(fp,"%[^ ] %*[^\n]\n",word);
          
        
        if (count == num_words) {
            break;
        }

        assign_string(dict[count], word);
        count++;
    }
    
    fclose(fp);

    return count;

}

// calculating the distance and catching the smallest one
double dissimilarity(char * w1, char * w2, char dict[][WORD_SIZE],char * dict_name, float threshold){  
  
  FILE *fp;

  char line[100];
  int index=-1;
  int num_words,vector_size;
  
  fp = fopen(dict_name,"r");
  fgets(line,100,fp );
  sscanf(line, "num_word=%d, vector_size=%d", &num_words, &vector_size);
  
  float vectors[num_words][vector_size];
  fgets(line, 100, fp);
  
  char word[WORD_SIZE];
      for (int i = 0; i < num_words; i++) {
          fscanf(fp, "%s", word);
          for (int j = 0; j < vector_size; j++) {
              fscanf(fp, "%f", &vectors[i][j]);
              //printf("%f \n", vectors[i][j]);
          }
      }
      


  for (int text= 0; text<num_words; text++ ){
    if(strcmp(dict[text],w1) == 0){
      index = text;
    }
  }
  
  


  float min=100;
  int flag = 0;
  int min_index = 0;
  for(int j=0; j<num_words; j++){
  
    float diss = 0;
    for (int i=0; i<vector_size; i++){
  
      diss += pow(vectors[index][i]-vectors[j][i],2);
    }

 
//It should be under threshold also 
 
    if(diss != 0 && min>diss && diss<THRESHOLD){
      min = diss;
      flag =1;
      min_index = j;
    }


      }

  assign_string(w2, dict[min_index]);
  fclose(fp);
  
  
  
}

