/*******************************************************************************************************
											MyTicTacToe V3.5/V4.0 (Construction)
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

VERSION 3.4
	Commented Code, No Such So Updates

VERSION 3.410/VERSION 4.0, *Under construction*
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

//Defining global variables, so as not to pass them in the functions
int choice;
int player1Score=0, player2Score=0;
char playerTic, computerTic, player2Tic;

char Board[3][3]= {
	{' ', ' ', ' '},
	{' ', ' ', ' '},
	{' ', ' ', ' '}
};

//Print Game Version and the updates Available
void printGameVersion() {
	cout << "\n\n\n\a				    Version 3.5(Closer to 4.0)";
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
void printBoard() {

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
bool checkMove(int x, int y) {

	if(x<1 || x>3) return true;
	else if(y<1 || y>3) return true;
	else if (Board[x-1][y-1] != ' ') return true;
	else return false;
}

//Updates Player Move
void updateMove(int x, int y, char z) {

	Board[x-1][y-1] = z;
}

//Checks if the player Won or not
bool checkWin() {

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
void playHumanGame(int x, int y, int player, char tic) {

	printBoard();
	int moves=0;
	cout<< "			";
	cout<< "Player 1 -> X\tPlayer 2 -> O\n";
	
	player= rand()%2 +1;
	
	while(!checkWin() && moves!=9) {

		player=(player%2)?1:2;

		cout<< "\nPlayer "<< player<<  " give your move coordinates:";
		cout<< "	";

		cin >> x >> y;
		if(player%2==0) tic='O';
		else tic= 'X';
		if(checkMove(x,y)) {
			cout<< "Invalid Points!\n";
			continue;
		}
		updateMove(x,y,tic);
		printBoard();
		player++;
		moves++;
	}

	player= player%2 +1;

	if(checkWin()) {
		cout<< "\n\a				  Player "<< player<< " wins!";
		if(player==1)player1Score++;
		else player2Score++;
	} else cout<< "\n\a				  *Draw*";

	cout<< "\n\n";
}

//Game Function for playing Against Computer with player character set as default to "X"
void playComputerGameWithoutChoice(int x, int y, int player, char tic) {
	printBoard();
	int moves=0;
	cout<< "			";
	cout<< "Player 1 -> X\tComputer -> O\n";
	player= rand()%2 +1;

	while(!checkWin() && moves!=9) {
		player=(player%2)?1:2;

		if(player==1) {

			tic= 'X';
			cout<< "\nPlayer "<< player<<  " give your move coordinates:";
			cout<< "	";

			cin >> x >> y;

			if(checkMove(x,y)) {
				cout<< "Invalid Points!\n";
				continue;
			}

			updateMove(x,y,tic);
			printBoard();
			player++;
			moves++;
			if(checkWin()) break;
		} else {

			cout<< "Computer Playing.";
			Sleep(WAIT); cout<< "."; Sleep(WAIT); cout<< "."; Sleep(WAIT); cout<<  "\b\b\b   \b\b\b";
			Sleep(WAIT); cout<< "."; Sleep(WAIT); cout<< "."; Sleep(WAIT); cout<< ".";
			Sleep(800);

			tic= 'O';

			do {
			
				x = rand()%3 + 1;
				y = rand()%3 + 1;
			} while(checkMove(x,y));

			updateMove(x,y,tic);
			printBoard();
			player++;
			moves++;
		}

	}

	player= player%2 +1;
	if(checkWin()) {
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

//Game Function for playing Against Computer with player character as chosen by Player
void playComputerGameWithChoice(int x, int y, int player, char tic) {
	
	printBoard();
	int moves=0;
	cout<< "			";
	cout<< "Player 1 Choose X/O:";
	cin>> playerTic;
	computerTic= (playerTic== 'X')? 'O': 'X';
	player= rand()%2 +1;

	while(!checkWin() && moves!=9) {
		player=(player%2)?1:2;

		if(player==1) {

			tic= playerTic;
			cout<< "\nPlayer "<< player<<  " give your move coordinates:";
			cout<< "	";

			cin >> x >> y;

			if(checkMove(x,y)) {
				cout<< "Invalid Points!\n";
				continue;
			}

			updateMove(x,y,tic);
			printBoard();
			player++;
			moves++;
			if(checkWin()) break;
		} else {

			cout<< "Computer Playing.";
			Sleep(WAIT); cout<< "."; Sleep(WAIT); cout<< "."; Sleep(WAIT); cout<<  "\b\b\b   \b\b\b";
			Sleep(WAIT); cout<< "."; Sleep(WAIT); cout<< "."; Sleep(WAIT); cout<< ".";
			Sleep(800);

			tic= computerTic;

			do {
			
				x = rand()%3 + 1;
				y = rand()%3 + 1;
			} while(checkMove(x,y));

			updateMove(x,y,tic);
			printBoard();
			player++;
			moves++;
		}

	}

	player= player%2 +1;
	if(checkWin()) {
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

//AI Mode
void playComputerGameHardMode(int x, int y, int player, char tic){
	
	
}

//Resets Board and number of Moves for the next move
void resetBoard() {

	for(int i=0; i<3; ++i) for(int j=0; j<3; ++j) Board[i][j]= ' ';

}

//Main Function for Playing Game
int main() {

	srand(time(NULL));

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
		
		//This is just a cheat lol, ignore this
		if(choice==1234) {
			system("cls");
			printHeader();
			cout<< "			";
			cout << "\n\n\t\t\t\tYou are my Creator. LOL\n\n\t\t\t\tThanks for making me.";
			Sleep(1500);
			return 0;
		}
		
		//AI mode
		if(choice==100){
			
			system("cls");
			printHeader();
			cout<< "			";
			cout << "\n\n\t\t\tYou are playing against AI Computer!!!!";
			Sleep(1500);
			do {
				playComputerGameHardMode(x, y, player, tic);
				cout<< "Play Another Round?(Y/N):";
				cin >> playAnotherRound;
				resetBoard();
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
		
		
		//Choice 2 is for Two Players Match
		if (choice==2) {

			system("cls");
			printHeader();
			cout<< "			";
			cout << "\n\n\t\t\tYou are playing against another player!";
			Sleep(1500);
			do {
				playHumanGame(x, y, player, tic);
				cout<< "Play Another Round?(Y/N):";
				cin >> playAnotherRound;
				resetBoard();
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
				playComputerGameWithChoice(x, y, player, tic);
				cout<< "Play Another Round?(Y/N):";
				cin >> playAnotherRound;
				resetBoard();
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
		resetBoard();
		resetScore();
		system("cls");

	} while(playAgain=='y' || playAgain== 'Y');

	cout << "					Bye-Bye!\n";
	
	system("pause");
	return 0;
}
