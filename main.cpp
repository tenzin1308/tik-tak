//
//  main.cpp
//  tic tak
//
//  Created by Tenzin Tashi on 1/31/19.
//  Copyright B) 2019 Tenzin Tashi. All rights reserved.
//

#include <iostream>
using namespace std;
char input;
char table[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn = 'X';
int row, col;
bool draw = false;
void display_board()
{
 //it ffor menu
    cout << "\t\tTic Tac Game\n";
    cout << "\nPlayer 1 [X]\nPlayer 2 [O]\n\n";
    cout << "     |     |     "<<endl;
    cout << "  "<<table[0][0]<<"  |  "<<table[0][1]<<"  |  "<<table[0][2]<<"  "<<endl;
    cout << "_____|_____|_____"<<endl;
    cout << "     |     |     "<<endl;
    cout << "  "<<table[1][0]<<"  |  "<<table[1][1]<<"  |  "<<table[1][2]<<"  "<<endl;
    cout << "_____|_____|_____"<<endl;
    cout << "     |     |     "<<endl;
    cout << "  "<<table[2][0]<<"  |  "<<table[2][1]<<"  |  "<<table[2][2]<<"  "<<endl;
    cout << "     |     |     "<<endl;
    
    
}

void player_turn()
{
    if (turn == 'X'){
        cout << "\nPlayer 1 [X] turn: ";
    }else{
        cout << "\nPlayer 2 [O] turn: ";
    }
    cin >> input;
    switch (input) {
        case '1': row = 0; col = 0;
            break;
        case '2': row = 0; col = 1;
            break;
        case '3': row = 0; col = 2;
            break;
        case '4': row = 1; col = 0;
            break;
        case '5': row = 1; col = 1;
            break;
        case '6': row = 1; col = 2;
            break;
        case '7': row = 2; col = 0;
            break;
        case '8': row = 2; col = 1;
            break;
        case '9': row = 2; col = 2;
            break;
        default:
            cout << "Invalid input!!!"<<endl;
            break;
    }
    if (turn == 'X' && table[row][col] != 'X' && table[row][col] != 'O'){
        table[row][col]=turn;
        turn = 'O';
    }else if(turn == 'O' && table[row][col] != 'X' && table[row][col] != 'O') {
        table[row][col]=turn;
        turn = 'X';
    }else{
        cout << "Box already filled! \nTry again!!\n";
        player_turn();
    }
    
}

bool check_gameover()
{
    
    for(int i = 0; i <3;i++)
        if ((table[i][0] == table[i][1] && table[i][0] == table[i][2]) || (table[0][i] == table[1][i] && table[0][i] == table[2][i]) || (table[0][0] == table[1][1] && table[0][0] == table[2][2]) || (table[0][2] == table[1][1] && table[0][2] == table[2][0]))
            
            return false;
    
    for(int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (table[i][j] != 'X' && table[i][j] != 'O')
                return true;
    
    draw = true;
    return false;
}

int main(int argc, const char * argv[]) {
    
    while (check_gameover()) {
        display_board();
        
        player_turn();
        check_gameover();
        display_board();
        
    }
    if (turn == 'X' && draw == false){
        cout << "Player 2 [O] Wins! \nCongratulation\n";
    }else if(turn == 'O' && draw == false){
        cout << "Player 1 [X] Wins! \nCongratulation\n";
    }else{
        cout << "Game Draw"<<endl;
    }
    
}
