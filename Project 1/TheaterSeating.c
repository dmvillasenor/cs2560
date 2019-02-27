#include <stdio.h>

char board[16][31] = {
		{' ','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9','0'},
		{'1','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
		{'2','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
		{'3','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
		{'4','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
		{'5','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
		{'6','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
		{'7','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
		{'8','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
		{'9','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
		{'0','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
		{'1','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
		{'2','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
		{'3','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
		{'4','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
		{'5','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
};
double prices[16];
double profit = 0;
double seatsSold = 0;

void printBoard(){
	for(int row = 0; row < 16; row++){
		for(int column = 0; column < 31; column++){
			printf("%c ", board[row][column]);
		}//end inside for
		printf("\n");
	}// end outside for
}//end printBoard

void assignPrice(){
	for(int i = 1; i < 16; i++){
		printf("What do you want the price for Row %d?", i);
		scanf("%lf", &prices[i]);
	}
}
int seatAvailable(int row, int column){
	if( board[row][column] == '#'){
		return 1;
	}
	else{
		return 0;
	}
}

int yesNo( char response){
	int yesNo = 0;
	if(response == 'Y' || response == 'y'){
		yesNo = 1;
	}//end if

	else if(response == 'N' || response == 'n'){
		yesNo = 0;
	}//end else if

	else{
		yesNo = 0;
	}//end else
	return yesNo;
}
void ticketPurchase(){

	//Total for their purchase
	double individualTotal = 0;
	//Number of seats they purchased.
	int seatsPurchased = 0;

	//Whether they want to keep buying seats.
	int moreTicket = 1;

	//Row and Seat person chooses
	int row;
	int seat;


	while(moreTicket){

		//Whether the seat they got is open
		int isValid = 0;

		while(!isValid){
			printf("Input Row:\n");
			scanf("%d", &row);
			printf("Input Seat:\n");
			scanf("%d", &seat);
			if( row <= 15 && row > 0 && seat <= 30 && seat > 0 && seatAvailable(row, seat)){
				isValid = 1;
				board[row][seat] = '*';

				//Profit overall
				profit += prices[row];

				//Profit of this purchase
				individualTotal += prices[row];

				//Seats just for this purchase
				seatsPurchased++;
				//Seats overall
				seatsSold++;

			}//end if
			else{
				printf("Enter a valid open seat\n");
			}//end else
		}//end Valid While

		//Asking if they want another ticket
		char another;
		printf("Do you want to another seat Y/N");
		scanf("%s", &another);
		moreTicket = yesNo(another);
	}
	printf("\nNumber of Seats Purchased: %d", seatsPurchased);
	printf("\nPurchase Total: $%.2lf\n", individualTotal);
}
/*
void printPrice(){
	for(int row = 0; row < 16; row++){
		printf("Row %d: %f", row, prices[row]);
	}// end for
}*/
int seatsAvailableRow(int row){
	int numAvailable = 0;
	for( int i = 1; i <= 30; i++){
		if(board[row][i] == '#'){
			numAvailable++;
		}
	}
	return numAvailable;
}
int main(void) {
	assignPrice();
	//printPrice();
	printBoard();
	ticketPurchase();

	char response;
	printf("Would you like to see the profit for today?\n Y / N \n");
	scanf("%s", &response);
	int theyDo = yesNo(response);
	if(theyDo){
		printf("Total: $%.2lf\n\n", profit);
	}

	printf("Would you like to see how many seats have been sold,"
			"\nhow many seats are available in each row, "
			"\nand how many seats are available in the entire auditorium"
			"\nY / N");
	scanf("%s", &response);
	theyDo = yesNo(response);
	if(theyDo){
		printBoard();
		int freeSeats = 0;
		for(int row = 1; row <= 15; row++){
			freeSeats += seatsAvailableRow(row);
			printf("Available seats in Row %d: %d\n", row, seatsAvailableRow(row));
		}
		printf("Total Seats Available: %d", freeSeats);
	}
}
