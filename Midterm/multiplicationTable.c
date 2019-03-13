#include <stdio.h>

int main(void) {
	int input;
	int valid = 0;

	//Stays in the loop until its a number greater than 0.
	while(!valid){

		printf("Input a number greater than 0");
		scanf("%d", &input);
		if( input > 0){
			valid = 1;
		}
	}

	//prints the column headers.
	for(int i = 0; i < input + 1; i++){
		if(i == 0){
			printf("   \t");
		}else{
			printf("%d\t", i);
		}
	}

	for(int row = 0; row < input + 1; row++){
		for(int col = 0; col < input + 1; col++){
			//prints corner of table with spaces and a +
			if(row == 0 && col == 0){
				printf("\n  +");
			}
			//prints dashes for the entirety of row 0
			else if( row == 0){
				printf("--------");
			}
			//prints the headers for each row except for the row that contains dashes
			else if( col == 0 && row != 0){
				printf("%02d|\t", row);

			}
			//prints the table with the products
			else{
			int product = row * col;
			printf("%d\t" , product);
			}
		}
		printf("\n");
	}
}
