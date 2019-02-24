/*														MyTicTacToe V2.0

Mode- Against Human and Against Computer(Easy)
Replay- Not Available
Score- Does not Count

*/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

#define WAIT 250

using std::cout;
using std::endl;
using std::cin;

int move=0;

char Board[3][3]= {
	{' ', ' ', ' '},
	{' ', ' ', ' '},
	{' ', ' ', ' '}
};

void printHeader(){
	
	cout << "+------------------------------------------------------------------------------+" << endl;
    cout << "|                                   Tic Tac Toe                                |" << endl;
    cout << "+------------------------------------------------------------------------------+" << endl;
	
}

void printBoard() {
	
	system("cls");
	printHeader();	
	
    cout << endl;
    cout<< "				"; cout << "     |     |     " << endl;
    cout<< "				"; cout << "  " << Board[0][0] << "  |  " << Board[0][1] << "  |  " << Board[0][2]<< "  " << endl;
    cout<< "				"; cout << "     |     |     " << endl;
    cout<< "				"; cout << "-----+-----+-----" << endl;
    cout<< "				"; cout << "     |     |     " << endl;
    cout<< "				"; cout << "  " << Board[1][0] << "  |  " << Board[1][1] << "  |  " << Board[1][2] << "  " << endl;
    cout<< "				"; cout << "     |     |     " << endl;
    cout<< "				"; cout << "-----+-----+-----" << endl;
    cout<< "				"; cout << "     |     |     " << endl;
    cout<< "				"; cout << "  " << Board[2][0] << "  |  " << Board[2][1] << "  |  " <<Board[2][2] << "  " << endl;
    cout<< "				"; cout << "     |     |     " << endl;

}

bool checkMove(int x, int y){
	
	if(x<0 || x>3) return true;
	else if(y<0 || y>3) return true;
	else if (Board[x-1][y-1] != ' ') return true;
	else return false;
}

void updateMove(int x, int y, char z) {
    
	Board[--x][--y] = z;
}

bool checkWin(){
	
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

void playHumanGame(int x, int y, int player, char tic){
	
	printBoard();
	cout<< "			";cout<< "Player 1 -> X\tPlayer 2 -> O\n";
	
	while(!checkWin() && move!=9){
		
		player=(player%2)?1:2;
		
		cout<< "\nPlayer "<< player<<  " give your move coordinates:";cout<< "	";
		
		cin >> x >> y;
		if(player%2==0) tic='O';
		else tic= 'X';
		if(checkMove(x,y)){
			cout<< "Invalid Points!\n";
			continue;
		}
		updateMove(x,y,tic);
		printBoard();
		player++;
		move++;
	}
	
	player= player%2 +1; 
	
	if(checkWin()) cout<< "\n\a				  Player "<< player<< " wins!";
	else cout<< "\n\a				  *Draw*";
	
	cout<< "\n\n";
}

void playComputerGameWithChoice(int x, int y, int player, char tic){
	//UNDER_CONSTRUCTION
	}

void playComputerGameWithoutChoice(int x, int y, int player, char tic){
	printBoard();
	
	cout<< "			";cout<< "Player 1 -> X\tComputer -> O\n";
	player= rand()%2 +1;
	
	while(!checkWin()){
		player=(player%2)?1:2;
		
		if(player==1){
			
			tic= 'X';
			cout<< "\nPlayer "<< player<<  " give your move coordinates:";cout<< "	";
		
			cin >> x >> y;
			
			if(checkMove(x,y)){
				cout<< "Invalid Points!\n";
				continue;
			}
			
			updateMove(x,y,tic);
			printBoard();
			player++;
			move++;
			if(checkWin()) break;
		}
		else{
			
			cout<< "Computer Playing."; Sleep(WAIT); cout<< "."; Sleep(WAIT); cout<< "."; Sleep(WAIT);
				cout<<  "\b\b\b   \b\b\b"; Sleep(WAIT); cout<< "."; Sleep(WAIT); cout<< "."; Sleep(WAIT); cout<< ".";
			Sleep(1000);
			
			tic= 'O';
			
			do{
				x = rand()%3 + 1;
				y = rand()%3 + 1;
				
			}while(checkMove(x,y));
			
			updateMove(x,y,tic);
			printBoard();
			player++;
			move++;
		}
		
	}
	
	player= player%2 +1; 
	if(checkWin()) {
		if(player==1) cout<< "\n\a			Our Computer played dumb! You win!";
		else cout<< "\n\a				 Computer wins!";
	}
	
	else cout<< "\n				  *Draw*";
	cout<<"\n\n";
}


int main(){
	
	srand(time(NULL));
	
	int x, y, choice;
	int player = 1;
	
	char tic, playAgain;
	

	printHeader();
	cout<< "Press 1 To Play Against Human    -> :\nOr Play Against our Computer     -> :";
	cin >> choice;
	
	if (choice==1) {
		
		system("cls");
		printHeader();
		cout<< "			";cout << "\n\n\t\t\tYou are playing against another player!";
		Sleep(1500);
		playHumanGame(x, y, player, tic);
	}
	
	else {
		//cout<< "SORRY, Under Construction!\n";
		
		
		system("cls");
		printHeader();
		cout<< "			";cout << "\n\n\t\t\tYou are playing against Computer!";
		Sleep(1500);
		playComputerGameWithoutChoice(x, y, player, tic);
		
	}
	
	cout<< "			    Thanks for playing. Bye-Bye!\n";
	system("pause");
	return 0;
}
