/*														MyTicTacToe V3.2(Release)

Mode- Against Human Player and Against Computer(Easy)
Replay- Available
Round Match- Available, infinite matches
Score- Counts and updates
First Chance against Human- random
First Chance against Computer- random

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

#define WAIT 250

using std::cout;
using std::endl;
using std::cin;

int move=0, choice;
int player1Score=0, player2Score=0;

void resetScore() {
	player1Score=0;
	player2Score=0;
}

char Board[3][3]= {
	{' ', ' ', ' '},
	{' ', ' ', ' '},
	{' ', ' ', ' '}
};

void printGameVersion() {
	cout << "\n\a				Version 3.1";
	cout << "\n			Modes-Against Computer.\n			      Against Human Player.";
	cout << "\n			Replay- Available.\n			Round Match- Available.";
}

void printHeader() {

	cout << "+------------------------------------------------------------------------------+" << endl;
	cout << "|                                   Tic Tac Toe                                |" << endl;
	cout << "+------------------------------------------------------------------------------+" << endl;

}

void printHeaderWithScore() {

	cout << "+------------------------------------------------------------------------------+" << endl;
	cout << "|                                   Tic Tac Toe                                |" << endl;
	cout << "+------------------------------------------------------------------------------+" << endl;
	if(choice==1) {
		cout << "Player 1:"<< player1Score<< "							     Player 2:"<< player2Score;
	} else {
		cout << "Player:"<< player1Score<< "							     Computer:"<< player2Score;
	}
}

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

bool checkMove(int x, int y) {

	if(x<0 || x>3) return true;
	else if(y<0 || y>3) return true;
	else if (Board[x-1][y-1] != ' ') return true;
	else return false;
}

void updateMove(int x, int y, char z) {

	Board[--x][--y] = z;
}

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

void playHumanGame(int x, int y, int player, char tic) {

	printBoard();
	cout<< "			";
	cout<< "Player 1 -> X\tPlayer 2 -> O\n";
	
	player= rand()%2 +1;
	
	while(!checkWin() && move!=9) {

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
		move++;
	}

	player= player%2 +1;

	if(checkWin()) {
		cout<< "\n\a				  Player "<< player<< " wins!";
		if(player==1)player1Score++;
		else player2Score++;
	} else cout<< "\n\a				  *Draw*";

	cout<< "\n\n";
}

void playComputerGameWithChoice(int x, int y, int player, char tic) {
	//UNDER_CONSTRUCTION
}

void playComputerGameWithoutChoice(int x, int y, int player, char tic) {
	printBoard();

	cout<< "			";
	cout<< "Player 1 -> X\tComputer -> O\n";
	player= rand()%2 +1;

	while(!checkWin()) {
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
			move++;
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
			move++;
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

void resetBoard() {

	for(int i=0; i<3; ++i) for(int j=0; j<3; ++j) Board[i][j]= ' ';

	move= 0;

}

int main() {

	srand(time(NULL));

	int x, y;
	int player = 1;

	char tic, playAgain, playAnotherRound;
	printHeader();
	printGameVersion();
	Sleep(3000);
	system("cls");

	do {

		printHeader();
		cout<< "Press 1 To Play Against Human    -> :\nOr Play Against our Computer     -> :";
		cin >> choice;

		if(choice==1234) {
			system("cls");
			printHeader();
			cout<< "			";
			cout << "\n\n\t\t\t\tYou are my Creator. LOL\n\n\t\t\t\tThanks for making me.";
			Sleep(1500);
			return 0;
		}

		if (choice==1) {

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

			if(player1Score== player2Score) {
				cout<< "\n\n\t\t\t\t\t*Draw*\n";
			} else {
				(player1Score>player2Score)? cout<< "\n\n\t\t\t    Player 1 Wins with Score "<<player1Score<<"!\n" : 
					cout<< "\n\n\t\t\t    Player 2 Wins with Score "<< player2Score<<"!\n";
			}

		}

		else {

			system("cls");
			printHeader();
			cout<< "			";
			cout << "\n\n\t\t\tYou are playing against Computer!";
			Sleep(1500);
			do {
				playComputerGameWithoutChoice(x, y, player, tic);
				cout<< "Play Another Round?(Y/N):";
				cin >> playAnotherRound;
				resetBoard();
			} while(playAnotherRound=='y' || playAnotherRound== 'Y');
			
			if(player1Score== player2Score) {
				cout<< "\n\n\t\t\t\t\t*Draw*\n";
			} else {
				(player1Score>player2Score)? cout<< "\n\n\t\t\t    Player Wins with Score"<< player1Score<<"!\n" : 
					cout<< "\n\n\t\t\t    Computer Wins with Score"<< player2Score<<"!\n";
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
