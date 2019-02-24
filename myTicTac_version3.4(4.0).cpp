/*******************************************************************************************************
											MyTicTacToe V3.4/V4.0 (Construction)
	Author: Aedit
	Date: 13 Nov 2016
	
######################################
BETTER PLAYING AI UNDERCONSTRUCTION
######################################


VERSION 3.2
		Mode- Against Human Player and Against Computer(Easy)
		Replay- Available
		Round Match- Available, infinite matches with Final Win on the basis of score
		Score- Counts and updates after every match in the round; Resets when new round started.
		First Chance - randomized

VERSION 3.3
		X or O Player choice while playing against Computer

VERSION 3.4/VERSION 4.0
		AI under construction, using minimax algorithm
		LEVEL- EASY/ HARD
*/

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <windows.h>

#define WAIT 250

using std::cout;
using std::endl;
using std::cin;
using std::max;
using std::min;

//Defining global variables, so as not to pass them in the functions
int move=0, choice;
int player1Score=0, player2Score=0;
char playerTic='X', computerTic='O';

//For taking care of the best move from maxmin theorem
struct Move
{
    int row, col;
}compMove;

// This function returns true if there are moves
// remaining on the board. It returns false if
// there are no moves left to play.
bool isMovesLeft(char board[3][3])
{
    for (int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            if (board[i][j]==' ')
                return true;
    return false;
}

//Print Game Version and the updates Available
void printGameVersion() {
	cout << "\n\n\n\a				    Version 3.4/4.0";
		  cout << "\n				*Under Construction*";
	cout << "\n			Modes-Against Computer.\n			      Against Human Player.";
	cout << "\n			//Level- Easy/Hard";
	cout << "\n			Replay- Available.";
	cout << "\n			Round Match- Available with infinite matches.";
	cout << "\n			First Chance- Randomized.";
	cout << "\n			X or O Choice- On Player.";
}

//Print Header for the game
void printHeader() {

	cout << "+------------------------------------------------------------------------------+" << endl;
	cout << "|                                   Tic Tac Toe                                |" << endl;
	cout << "+------------------------------------------------------------------------------+" << endl;

}

//Print Header with Score games
void printHeaderWithScore() {

	printHeader();
	if(choice==2) {
		cout << "Player 1:"<< player1Score<< "							     Player 2:"<< player2Score;
	} else {
		cout << "Player:"<< player1Score<< "							     Computer:"<< player2Score;
	}
}

// Reset Scores for Player1 and Player2(Also Computer)
void resetScore() {
	player1Score=0;
	player2Score=0;
}

//Print Game Board with Score Card and Header on the top
void printBoard(char Board[3][3]) {

	system("cls");
	printHeaderWithScore();

	cout << endl;
	cout<< "				";
	cout << "     |     |     " << endl;
	cout<< "				";
	cout << "  " << Board[0][0] << "  |  " << Board[0][1] << "  |  " << Board[0][2]<< "  " << endl;
	cout<< "				";
	cout << "     |     |     " << endl;
	cout<< "				";
	cout << "-----+-----+-----" << endl;
	cout<< "				";
	cout << "     |     |     " << endl;
	cout<< "				";
	cout << "  " << Board[1][0] << "  |  " << Board[1][1] << "  |  " << Board[1][2] << "  " << endl;
	cout<< "				";
	cout << "     |     |     " << endl;
	cout<< "				";
	cout << "-----+-----+-----" << endl;
	cout<< "				";
	cout << "     |     |     " << endl;
	cout<< "				";
	cout << "  " << Board[2][0] << "  |  " << Board[2][1] << "  |  " <<Board[2][2] << "  " << endl;
	cout<< "				";
	cout << "     |     |     " << endl;

}

//Checks for Moves Available
bool checkMove(int x, int y, char Board[3][3]) {

	if(x<0 || x>3) return true;
	else if(y<0 || y>3) return true;
	else if (Board[x-1][y-1] != ' ') return true;
	else return false;
}

//Updates Player Move
void updateMove(int x, int y, char z, char Board[3][3]) {

	Board[--x][--y] = z;
}

void updateComputerMove(int x, int y, char z, char Board[3][3]) {

	Board[x+1][y+1] = z;
}

//Checks if the player Won or not
bool checkWin(char Board[3][3]) {

	for (int i = 0; i < 3; i++) {
		if (Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2] && Board[i][0] != ' ') return true;
	}

	for (int i = 0; i < 3; i++) {
		if (Board[0][i] == Board[1][i] && Board[1][i] == Board[2][i] && Board[0][i] != ' ') return true;
	}

	if (Board[0][0] == Board[1][1] && Board[0][0] == Board[2][2] && Board[0][0] != ' ') return true;
	if (Board[0][2] == Board[1][1] && Board[0][2] == Board[2][0] && Board[0][2] != ' ') return true;

	return false;
}

//Game Function for Playing against Another Human PLayer
void playHumanGame(int x, int y, int player, char tic, char Board[3][3]) {

	printBoard(Board);
	cout<< "			";
	cout<< "Player 1 -> X\tPlayer 2 -> O\n";
	
	player= rand()%2 +1;
	
	while(!checkWin(Board) && move!=9) {

		player=(player%2)?1:2;

		cout<< "\nPlayer "<< player<<  " give your move coordinates:";
		cout<< "	";

		cin >> x >> y;
		if(player%2==0) tic='O';
		else tic= 'X';
		if(checkMove(x, y, Board)) {
			cout<< "Invalid Points!\n";
			continue;
		}
		updateMove(x, y, tic, Board);
		printBoard(Board);
		player++;
		move++;
	}

	player= player%2 +1;

	if(checkWin(Board)) {
		cout<< "\n\a				  Player "<< player<< " wins!";
		if(player==1)player1Score++;
		else player2Score++;
	} else cout<< "\n\a				  *Draw*";

	cout<< "\n\n";
}

//Game Function for playing Against Computer with player character set as default to "X"
void playComputerGameWithoutChoice(int x, int y, int player, char tic, char Board[3][3]) {
	printBoard(Board);

	cout<< "			";
	cout<< "Player 1 -> X\tComputer -> O\n";
	player= rand()%2 +1;

	while(!checkWin(Board)) {
		player=(player%2)?1:2;

		if(player==1) {

			tic= 'X';
			cout<< "\nPlayer "<< player<<  " give your move coordinates:";
			cout<< "	";

			cin >> x >> y;

			if(checkMove(x, y, Board)) {
				cout<< "Invalid Points!\n";
				continue;
			}

			updateMove(x, y, tic, Board);
			printBoard(Board);
			player++;
			move++;
			if(checkWin(Board)) break;
		} else {

			cout<< "Computer Playing.";
			Sleep(WAIT); cout<< "."; Sleep(WAIT); cout<< "."; Sleep(WAIT); cout<<  "\b\b\b   \b\b\b";
			Sleep(WAIT); cout<< "."; Sleep(WAIT); cout<< "."; Sleep(WAIT); cout<< ".";
			Sleep(800);

			tic= 'O';

			do {
			
				x = rand()%3 + 1;
				y = rand()%3 + 1;
			} while(checkMove(x, y, Board));

			updateMove(x, y, tic, Board);
			printBoard(Board);
			player++;
			move++;
		}

	}

	player= player%2 +1;
	if(checkWin(Board)) {
		if(player==1) {
			cout<< "\n\a			Our Computer played dumb! You win!";
			player1Score++;
		}

		else {
			cout<< "\n\a				 Computer wins!";
			player2Score++;
		}
	}

	else cout<< "\n				  	*Draw*";
	cout<<"\n\n";
}

// This is the evaluation function as discussed
// in the previous article ( http://goo.gl/sJgv68 )
int evaluate(char b[3][3])
{
    // Checking for Rows for X or O victory.
    for (int row = 0; row<3; row++)
    {
        if (b[row][0]==b[row][1] &&
            b[row][1]==b[row][2])
        {
            if (b[row][0]==computerTic)
                return +10;
            else if (b[row][0]==playerTic)
                return -10;
        }
    }
 
    // Checking for Columns for X or O victory.
    for (int col = 0; col<3; col++)
    {
        if (b[0][col]==b[1][col] &&
            b[1][col]==b[2][col])
        {
            if (b[0][col]==computerTic)
                return +10;
 
            else if (b[0][col]==playerTic)
                return -10;
        }
    }
 
    // Checking for Diagonals for X or O victory.
    if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
    {
        if (b[0][0]==computerTic)
            return +10;
        else if (b[0][0]==playerTic)
            return -10;
    }
 
    if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
    {
        if (b[0][2]==computerTic)
            return +10;
        else if (b[0][2]==playerTic)
            return -10;
    }
 
    // Else if none of them have won then return 0
    return 0;
}

// This is the minimax function. It considers all
// the possible ways the game can go and returns
// the value of the board
int minimax(char board[3][3], int depth, bool isMax)
{
    int score = evaluate(board);
 
    // If Maximizer has won the game return his/her
    // evaluated score
    if (score == 10)
        return score;
 
    // If Minimizer has won the game return his/her
    // evaluated score
    if (score == -10)
        return score;
 
    // If there are no more moves and no winner then
    // it is a tie
    if (isMovesLeft(board)==false)
        return 0;
 
    // If this maximizer's move
    if (isMax)
    {
        int best = -1000;
 
        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (board[i][j]==' ')
                {
                    // Make the move
                    board[i][j] = 'O';
 
                    // Call minimax recursively and choose
                    // the maximum value
                    best = max( best,
                        minimax(board, depth+1, !isMax) );
 
                    // Undo the move
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
 
    // If this minimizer's move
    else
    {
        int best = 1000;
 
        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (board[i][j]==' ')
                {
                    // Make the move
                    board[i][j] = 'X';
 
                    // Call minimax recursively and choose
                    // the minimum value
                    best = min(best,
                           minimax(board, depth+1, !isMax));
 
                    // Undo the move
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
}
 
// This will return the best possible move for the player
Move findBestMove(char board[3][3])
{
    int bestVal = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;
 
    // Traverse all cells, evalutae minimax function for
    // all empty cells. And return the cell with optimal
    // value.
    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            // Check if celll is empty
            if (board[i][j]==' ')
            {
                // Make the move
                board[i][j] = 'O';
 
                // compute evaluation function for this
                // move.
                int moveVal = minimax(board, 0, false);
 
                // Undo the move
                board[i][j] = ' ';
 
                // If the value of the current move is
                // more than the best value, then update
                // best/
                if (moveVal > bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }
 
    return bestMove;
}

//Game Function for playing Against Computer with player character as chosen by Player
void playComputerGameWithChoice(int x, int y, int player, char tic, char Board[3][3]) {
	
	printBoard(Board);
	
	cout<< "			";
	cout<< "Player 1 Choose X/O:";
	cin>> playerTic;
	computerTic= (playerTic== 'X')? 'O': 'X';
	player= rand()%2 +1;
	

	while(!checkWin(Board)) {
		player=(player%2)?1:2;

		if(player==1) {

			tic= playerTic;
			cout<< "\nPlayer "<< player<<  " give your move coordinates:";
			cout<< "	";

			cin >> x >> y;

			if(checkMove(x, y, Board)) {
				cout<< "Invalid Points!\n";
				continue;
			}

			updateMove(x, y, tic, Board);
			printBoard(Board);
			player++;
			move++;
			if(checkWin(Board)) break;
		} else {

			cout<< "Computer Playing.";
			Sleep(WAIT); cout<< "."; Sleep(WAIT); cout<< "."; Sleep(WAIT); cout<<  "\b\b\b   \b\b\b";
			Sleep(WAIT); cout<< "."; Sleep(WAIT); cout<< "."; Sleep(WAIT); cout<< ".";
			Sleep(800);

			tic= computerTic;
			
			do {
			
				x = rand()%3 + 1;
				y = rand()%3 + 1;
			} while(checkMove(x, y, Board));

			updateMove(x, y, tic, Board);
			printBoard(Board);
			player++;
			move++;
		}

	}

	player= player%2 +1;
	if(checkWin(Board)) {
		if(player==1) {
			cout<< "\n\a			Our Computer played dumb! You win!";
			player1Score++;
		}

		else {
			cout<< "\n\a				 Computer wins!";
			player2Score++;
		}
	}

	else cout<< "\n				  	*Draw*";
	cout<<"\n\n";
	
}

//Resets Board and number of Moves for the next move
void resetBoard(char Board[3][3]) {

	for(int i=0; i<3; ++i) for(int j=0; j<3; ++j) Board[i][j]= ' ';

	move= 0;

}

void playComputerGameHarder(int x, int y, int player, char tic, char Board[3][3]){
	
	printBoard(Board);
	
	cout<< "			";
	cout<< "Player 1 -> X\tComputer -> O\n";
	player= rand()%2 +1;

	while(!checkWin(Board)) {
		player=(player%2)?1:2;

		if(player==1) {

			tic= 'X';
			cout<< "\nPlayer "<< player<<  " give your move coordinates:";
			cout<< "	";

			cin >> x >> y;

			if(checkMove(x, y, Board)) {
				cout<< "Invalid Points!\n";
				continue;
			}

			updateMove(x, y, tic, Board);
			printBoard(Board);
			player++;
			move++;
			if(checkWin(Board)) break;
		} else {

			cout<< "Computer Playing.";
			Sleep(WAIT); cout<< "."; Sleep(WAIT); cout<< "."; Sleep(WAIT); cout<<  "\b\b\b   \b\b\b";
			Sleep(WAIT); cout<< "."; Sleep(WAIT); cout<< "."; Sleep(WAIT); cout<< ".";
			Sleep(800);

			tic= 'O';
			compMove = findBestMove(Board);
			cout<< compMove.row<<" "<< compMove.col;
			cout<< "    Hello";
			Sleep(1000);
			Board[compMove.row+1][compMove.col+1]= tic;
			printBoard(Board);
			player++;
			move++;
		}

	}

	player= player%2 +1;
	if(checkWin(Board)) {
		if(player==1) {
			cout<< "\n\a			Our Computer played dumb! You win!";
			player1Score++;
		}

		else {
			cout<< "\n\a				 Computer wins!";
			player2Score++;
		}
	}

	else cout<< "\n				  	*Draw*";
	cout<<"\n\n";
	
}


//Main Function for Playing Game
int main() {

	srand(time(NULL));
	
	char Board[3][3]= {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
	};

	int x, y;
	int player = 1;

	char tic, playAgain, playAnotherRound;
	printHeader();
	printGameVersion();
	Sleep(3500);
	system("cls");

	do {

		printHeader();
		cout<< "Press 1 for One Player Game    -> :\nPress 2 for Two Player Game    -> :";
		cin >> choice;
		
		//This is just a cheat lol, ignore this function
		if(choice==1234) {
			system("cls");
			printHeader();
			cout<< "			";
			cout << "\n\n\t\t\t\tYou are my Creator. LOL\n\n\t\t\t\tThanks for making me.";
			Sleep(1500);
			return 0;
		}
		
		
		if(choice==100) {
			system("cls");
			printHeader();
			cout<< "			";
			cout << "\n\n\t\t\t\tYou are my Creator. LOL\n\n\t\t\t\tThanks for making me.";
			
			do {
				playComputerGameHarder(x, y, player, tic, Board);
				cout<< "Play Another Round?(Y/N):";
				cin >> playAnotherRound;
				resetBoard(Board);
			} while(playAnotherRound=='y' || playAnotherRound== 'Y');
			
			system("cls");
			printHeaderWithScore();
			
			if(player1Score== player2Score) {
				cout<< "\n\n\t\t\t\t\t*Draw*\n";
			} else {
				(player1Score>player2Score)? cout<< "\n\n\t\t\t    Player 1 Wins with Score "<<player1Score<<"!\n" : 
					cout<< "\n\n\t\t\t    Player 2 Wins with Score "<< player2Score<<"!\n";
			}
		}
		
		
		//Choice 2 is for Two Players Match
		else if (choice==2) {

			system("cls");
			printHeader();
			cout<< "			";
			cout << "\n\n\t\t\tYou are playing against another player!";
			Sleep(1500);
			do {
				playHumanGame(x, y, player, tic, Board);
				cout<< "Play Another Round?(Y/N):";
				cin >> playAnotherRound;
				resetBoard(Board);
			} while(playAnotherRound=='y' || playAnotherRound== 'Y');
			
			system("cls");
			printHeaderWithScore();
			
			if(player1Score== player2Score) {
				cout<< "\n\n\t\t\t\t\t*Draw*\n";
			} else {
				(player1Score>player2Score)? cout<< "\n\n\t\t\t    Player 1 Wins with Score "<<player1Score<<"!\n" : 
					cout<< "\n\n\t\t\t    Player 2 Wins with Score "<< player2Score<<"!\n";
			}

		}
		
		//Choice 1 or default choice is for One Player Match (Against Computer)
		else {

			system("cls");
			printHeader();
			cout<< "			";
			cout << "\n\n\t\t\tYou are playing against Computer!";
			Sleep(1500);
			do {
				playComputerGameWithChoice(x, y, player, tic, Board);
				cout<< "Play Another Round?(Y/N):";
				cin >> playAnotherRound;
				resetBoard(Board);
			} while(playAnotherRound=='y' || playAnotherRound== 'Y');
			
			system("cls");
			printHeaderWithScore();
			
			if(player1Score== player2Score) {
				cout<< "\n\n\t\t\t\t\t*Draw*\n";
			} else {
				(player1Score>player2Score)? cout<< "\n\n\t\t\t    Player Wins with Score "<< player1Score<<"!\n" : 
					cout<< "\n\n\t\t\t    Computer Wins with Score "<< player2Score<<"!\n";
			}
				
		}

		cout<< "			    	Thanks for playing.\n";
		cout<< "Play again? (Y/N):";
		cin >> playAgain;
		resetBoard(Board);
		resetScore();
		system("cls");

	} while(playAgain=='y' || playAgain== 'Y');

	cout << "					Bye-Bye!\n";
	
	system("pause");
	return 0;
}
