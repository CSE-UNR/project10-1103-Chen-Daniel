//Author: Daniel Chen
//Date: 04/28/2025
//Project-10

#include<stdio.h>
#define ROWS 100
#define COLUMNS 5
#define FILE_IN "word.txt"


int main (){
	char array[5], input_array[ROWS][COLUMNS];
	FILE *fpin;
	fpin = fopen(FILE_IN, "r");
	if(fpin == NULL){
		printf("Error on open %s file", FILE_IN);
		}
	fscanf(fpin, "%s", &array);
	fclose(fpin);
		
	int num = 1; 
	int row;
	do{
		row = num - 1;
		printf("GUESS %d, Enter your guess:\n", num);
		scanf("%s", &input_array[row]);
		for(int i = 0; i < COLUMNS; i++){ 
			if(input_array[row][i] == array[i]){
				input_array[row][i] = input_array[row][i] + 32;
				}
			}
		printf("===============================\n");
		if(input_array[row] == array){
			printf("%s", input_array[row]);
			printf("You won in %d guesses\n", num);
			num =100;
			}
		else{
			for(int i = 0; i < num; i++){
				printf("%s", input_array[i]);
				printf("\n");
				}
			}

		num = num + 1;
	}while(num < 100);

	return 0;
}
