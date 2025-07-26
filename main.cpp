#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> rows(3);

// Function declarations
void print_table();
void player_win(string move_player);

bool con = true; // Control variable for the game loop
bool draw = false; // Variable to check if the game is a draw


void init_table(){
    system("cls"); // Clear the console for better visibility
    draw = true; // Reset draw status for a new game
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
    string floor=" |_____||_____||_____|";
    // Print the initialized table
    cout <<" ___1______2______3___"<< endl;
    for (int i = 0; i < 3; ++i) {
        cout << i+1 ;
        for (int j = 0; j < 3; ++j) {
            cout << rows[i][j];
        }
        cout << endl;
        cout << floor << endl;  
    }  
}

void player_move(int row, int col, string player) {
    // Update the table with the player's move
    rows[row][col] =player;
 
    // Print the updated table
    system("cls"); // Clear the console for better visibility
    print_table();
    player_win(player);
}

void player_win(string move_player){
    // Check if the player has won
    vector<bool> win_conditions = {
        // Horizontal
        rows[0][0] == rows[0][1] && rows[0][0] == rows[0][2] && rows[0][0] !="|     |",
        rows[1][0] == rows[1][1] && rows[1][0] ==rows[1][2] && rows[1][0] !="|     |",
        rows[2][0] == rows[2][1] && rows[2][0] ==rows[2][2] && rows[2][0] !="|     |",
        // Vertical
        rows[0][0] == rows[1][0] && rows[0][0] ==rows[2][0] && rows[0][0] !="|     |",
        rows[0][1] == rows[1][1] && rows[0][1] ==rows[2][1] && rows[0][1] !="|     |",
        rows[0][2] == rows[1][2] && rows[0][2] ==rows[2][2] && rows[0][2] !="|     |",
        // Diagonal
        rows[0][0] == rows[1][1] && rows[0][0] ==rows[2][2] && rows[0][0] !="|     |",
        rows[0][2] == rows[1][1] && rows[0][2] ==rows[2][0] && rows[0][2] !="|     |"
    };
    // Check if any win condition is met
    for (int i = 0; i < win_conditions.size(); ++i) {
        if (win_conditions[i]) {
            // If a win condition is met, announce the winner
            cout << "Player " << move_player << " wins!" << endl;
            cout << "Do you want play again? (Y/N)" << endl;
            string choice;
            cin >> choice;
            if (choice == "Y" || choice == "y") {
                init_table(); // Reset the game
            } else if (choice == "N" || choice == "n") {
                con = false; // End the game
                cout << "Thanks for playing!" << endl;
            }
            else {
                cout << "Invalid choice! Exiting the game." << endl;
                con = false; // End the game
            }                       
        }
    }
    // Check for a draw condition
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (rows[i][j] == "|     |") {
                draw=false;
                // If there's an empty cell, the game continues
            }
        }
    }
    // If no empty cells are found and no player has won, it's a draw
    if (draw) {
        cout << "It's a draw!" << endl;
        cout << "Do you want to play again? (Y/N)" << endl;
        string choice;
        cin >> choice;
        if (choice == "Y" || choice == "y") {
            init_table(); // Reset the game
        } else if (choice == "N" || choice == "n") {
            con = false; // End the game
            cout << "Thanks for playing!" << endl;
        } else {
            cout << "Invalid choice! Exiting the game." << endl;
            con = false; // End the game
        }
    }
    

}

void give_move(string player) {
    int row, col;
    cout << "Player " + player + ", enter your move (row and column): ";
    cin >> row >> col;

    // 0-tabanlı indeks
    int r = row - 1;
    int c = col - 1;

    if (row < 1 || row > 3 || col < 1 || col > 3 || rows[r][c] != "|     |") {
        cout << "Invalid move! Please enter a valid and empty cell (1 to 3)." << endl;
        return give_move(player); // Tekrar dene
    }

    player_move(r, c, player);
}




int main() {
    // Initialize the game table
    init_table();
    // Define player symbols
    string playerX = "|  X  |";
    string playerO = "|  O  |";
    // Game loop
    while (con) {
        
        // Player X's turn
        give_move(playerX);
        // Check if the game is still ongoing
        if (con == false) {
            break; // Exit if the game is over
        }
        // Player O's turn
        give_move(playerO);
    }

}