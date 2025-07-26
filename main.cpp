#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> rows(3);
void print_table();

void init_table(){
    // Initialize the tic-tac-toe table
    
    // Create a 3x3 grid with empty cells
    for (int i = 0; i < 3; ++i) {
        rows[i]= vector<string>(3);
        for (int j = 0; j < 3; ++j){
            rows[i][j] = "|     |";
        }
    }
    print_table();
   
}
void print_table() {
    string floor="|_____||_____||_____|";
    // Print the initialized table
    cout <<"___1______2______3___"<< endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << rows[i][j];
                
        }
        cout << i+1 << endl;
        cout << floor << endl;  
    }
      
}


void player_move(int col, int row, string player) {
    // Update the table with the player's move
    row -= 1; // Adjust for 0-based index
    col -= 1; // Adjust for 0-based index
    if (3>row>= 0 && 3>col >= 0 && rows[row][col] == "|     |") {
        rows[row][col] = "|  " + player + "  |";
    } 
    else {
        cout << "Invalid move!" << endl;
    }
    // Print the updated table
    system("cls"); // Clear the console for better visibility
    print_table();
}


int main() {
    init_table();
    string playerX = "X";
    string playerO = "O";
    while (true) {
        int row, col;
        cout << "Player X, enter your move (column and row): ";
        cin >> row >> col;
        player_move(row, col, playerX);
        
        cout << "Player O, enter your move (column and row): ";
        cin >> row >> col;
        player_move(row, col, playerO);
    }

}