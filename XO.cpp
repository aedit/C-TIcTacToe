#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int userChoice = 0;

int comChoice = 1 - userChoice;

int Board[3][3] = {
    {-1, -1, -1},
    {-1, -1, -1},
    {-1, -1, -1}
};


char getx_o(int a) {
    switch (a) {
        case -1: return ' ';
        case 0: return 'O';
        case 1: return 'X';
    }
    return 'n';
}

bool checkWin() {


    for (int i = 0; i < 3; i++) {
        if (Board[i][0] == Board[i][1] && Board[i][0] == Board[i][2] && Board[i][0] != -1){
            cout<< getx_o(Board[i][0])<<" Wins.";
            return true;
        }
        if (Board[0][i] == Board[1][i] && Board[0][i] == Board[2][i] && Board[0][i] != -1){ 
            cout<< getx_o(Board[0][i])<<" Wins.";
            return true;
        }
    }

    if (Board[0][0] == Board[1][1] && Board[0][0] == Board[2][2] && Board[0][0] != -1){
            cout<< getx_o(Board[0][0])<<" Wins.";
            return true;
    }

    if (Board[0][2] == Board[1][1] && Board[0][2] == Board[2][1] && Board[0][2] != -1){
            cout<< getx_o(Board[0][2])<<" Wins.";
            return true;
    }

    return false;
}

void printBoard() {
    cout << endl;
    cout << "				     |     |     " << endl;
    cout << "				  " << getx_o(Board[0][0]) << "  |  " << getx_o(Board[0][1]) << "  |  " << getx_o(Board[0][2]) << "  " << endl;
    cout << "				     |     |     " << endl;
    cout << "				-----+-----+-----" << endl;
    cout << "				     |     |     " << endl;
    cout << "				  " << getx_o(Board[1][0]) << "  |  " << getx_o(Board[1][1]) << "  |  " << getx_o(Board[1][2]) << "  " << endl;
    cout << "				     |     |     " << endl;
    cout << "				-----+-----+-----" << endl;
    cout << "				     |     |     " << endl;
    cout << "				  " << getx_o(Board[2][0]) << "  |  " << getx_o(Board[2][1]) << "  |  " << getx_o(Board[2][2]) << "  " << endl;
    cout << "				     |     |     " << endl;

}

void updateMove(int x, int y, int z) {

    Board[x][y] = z;

}

int checkBoard(int x, int y, int a, int b) {

    if ((x >= 0)&&(x < 3)&&(y >= 0)&&(y < 3)) {
        if (Board[x][y] == -1) {
            updateMove(x, y, userChoice);
            printBoard();
            
            if(checkWin())exit(0);
        }else{
            
            return 10;
            
        }
        if (Board[a][b] == -1) {
            updateMove(a, b, comChoice);
            printBoard();
            
            if(checkWin())exit(0);
        }else{
            
            return 20;
            
        }
        
    }else{
        
        return 10;
        
    }
}

int main() {

    srand(time(NULL));
    cout << "+------------------------------------------------------------------------------+" << endl;
    cout << "|                                   Tic Tac Toe                                |" << endl;
    cout << "+------------------------------------------------------------------------------+" << endl;

    cout << "Enter 0 -> O\n      1 -> X\n(Default : O) : ";
    cin>>userChoice;
    comChoice = 1 - userChoice;
    int ux = 0, uy = 0;
    int cx = -1, cy = -1;
    bool takeInp = true;
    
    while (!checkWin()) {

        while (true) {
            userIP:
            if (takeInp) {
                cout << "Enter your move (x,y) : ";
                cin >> ux>>uy;
            }
            comIP:
            cx = rand() % 3;
            cy = rand() % 3;
            switch(checkBoard(ux, uy, cx, cy)){
                
                case 10 : goto userIP;
                break;
                case 20: goto comIP;
                break;
                
            }
            break;
        }
    }
    return 0;

}




