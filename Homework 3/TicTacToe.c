#include <stdio.h>

//Create Tic-Tac-Toe board
char board[4][4] = {{' ','1','2','3'},{'1','*','*','*'},{'2','*','*','*'},{'3','*','*','*'}};

//Prints the board out
void printBoard(){
	for(int row = 0; row < 4; row++){
		for(int column = 0; column < 4; column++){
			printf("%c ", board[row][column]);
		}//end inside for
		printf("\n");
	}// end outside for
}//end printBoard

//Ensures the selected space is not already taken
int moveAvailable(int row, int column){
	if( board[row][column] == 'X' || board[row][column] == 'O'){
		return 0;
	}
	else{
		return 1;
	}
}

//Assigns the space with X or O depending on whose turn it is
void assignSpace(int row, int column, int player){
	char tictac;
	if( player == 0){
		tictac = 'X';
	}
	else if(player == 1){
		tictac = 'O';
	}

	board[row][column] = tictac;
}
void playerMove(int player){
	int validMove = 0;
	int row;
	int column;
	//Keeps asking player for a space until its a valid choice.
	while(!validMove){

		printf("Input Row:\n");
		scanf("%d", &row);
		printf("Input Column:\n");
		scanf("%d", &column);

		//Checks if the move is valid and only ends the loops and assigns it if it is.
		if( row <= 3 && row > 0 && column <= 3 && column > 0 && moveAvailable(row, column)){
			validMove = 1;
			assignSpace(row, column, player);
		}//end if
		else{
			printf("Enter a valid available space\n");

		}//end else
	}//end while
}
int boardFull(){
	//printf("boardfull is running\n");
	int boardFull = 0;
	int containStar = 0;

	//Checks for any stars left on the board.
	for(int row = 1; row < 4; row++){
		for(int column = 1; column < 4; column++){
			if(board[row][column] == '*'){
				containStar = 1;
				//printf("contains a star\n");
			}
		}//end inside for
	}// end outside for

	if(containStar){
		//printf("boardfull returning 0");
		return 0;
	}//end if
	else{
		//printf("boardfull returning 1");
		return 1;

	}//end else
}//end boardFull()

int rowWin(){
	int winner = 1;

	//Row Wins
	for(int row = 1; row < 4; row++){
		if(board[row][1] == board[row][2] && board[row][2] == board[row][3] && board[row][1] != '*'){
			winner = 0;
		}
	}

	//Column Wins
	for(int column = 1; column < 4; column++){

		if(board[1][column] == board[2][column] && board[2][column] == board[3][column] && board[1][column] != '*' ){
			winner = 0;
		}
	}

	//Diagonal Wins
	if(board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[1][1] != '*'){
		winner = 0;
	}
	if(board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[1][3] != '*'){
		winner = 0;
	}

	//printf("rowWin Returning: %d", winner);
	return winner;
}

int checkWinner(int player){
	//Determines if the games over
	int gameOver = 0;

	//Determine who is winner:
	// 0 = tie, 1 & 2 = players 1 or 2.
	int winner =  0;

	int rowWinner = rowWin();

	//Checkers if board the board is full
	//rowWinner outputs true if there is no winner.
	if(boardFull() && rowWinner){
		gameOver = 1;
		printf("Game is a tie");
	}

	if(!rowWinner){
		gameOver = 1;
		winner = player;
		printf("Player %d Wins", winner);
	}

	return gameOver;
}
int main(void) {

	int gameOver = 0;
	printBoard();
	while(!gameOver){

		printf("Player 1's turn ( X )\n");
		playerMove(0);

		printBoard();

		gameOver = checkWinner(1);
		//printf("Gameover = %d\n", gameOver);

		//Ensures Player 2 does not take turn if game is over.
		if(gameOver){
			break;
		}

		printf("Player 2's turn ( O )\n");
		playerMove(1);

		printBoard();
		gameOver = checkWinner(2);
	}
}
