#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <fstream> // Add the fstream library for file handling, game record file will made on your desktop.
using namespace std;

int main()
{
    cout << "Welcome to Tic Tac Toe game, made by Tayyab Babar" << endl;
    string board[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    int turn = 1;
    int player;
    int choice;
    string mark;
    string player1_name, player2_name;
    string game_result;
    int game_duration;
    string active_dates;
    string game_history;

    // player names
    cout << "Enter Player 1 name: ";
    cin >> player1_name;
    cout << "Enter Player 2 name: ";
    cin >> player2_name;

    // current date and time
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "The date and time today is: " << dt << endl;

    auto start = chrono::high_resolution_clock::now();

    while (true)
    {
        // Display the game board
        cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
        cout << "---+---+---" << endl;
        cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
        cout << "---+---+---" << endl;
        cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;

        if (turn % 2 == 1)
        {
            player = 1;
        }
        else
        {
            player = 2;
        }

        // take player's choice
        cout << player1_name << " (X) vs " << player2_name << " (O)" << endl;
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> choice;

        // Make sure the player's choice is valid
        if (choice < 1 || choice > 9 || board[choice - 1] == "X" || board[choice - 1] == "O")
        {
            cout << "Invalid move, try again." << endl;
            continue;
        }

        // Update the game board with the player's choice
        if (player == 1)
        {
            mark = "X";
        }
        else
        {
            mark = "O";
        }
        board[choice - 1] = mark;

        // Check if the game is over
        if ((board[0] == board[1] && board[1] == board[2]) ||
            (board[3] == board[4] && board[4] == board[5]) ||
            (board[6] == board[7] && board[7] == board[8]) ||
            (board[0] == board[3] && board[3] == board[6]) ||
            (board[1] == board[4] && board[4] == board[7]) ||
            (board[2] == board[5] && board[5] == board[8]) ||
            (board[0] == board[4] && board[4] == board[8]) ||
            (board[2] == board[4] && board[4] == board[6]))
{
cout << "Player " << player << " (" << mark << ") wins!" << endl;
auto end = chrono::high_resolution_clock::now(); // stop the timer
auto duration = chrono::duration_cast<chrono::seconds>(end - start); // calculate the duration

cout << "Total duration: " << duration.count() << " seconds" << endl; // output the duration
        // Store the game data into a file
        ofstream gameFile("games.txt", ios::app); // Open the file
        if (gameFile.is_open())
        {
            // Write the game data to the file
            gameFile << "Date: " << dt << endl;
            gameFile << "Player 1: " << player1_name << endl;
            gameFile << "Player 2: " << player2_name << endl;
            gameFile << "Winner: Player " << player << " (" << mark << ")" << endl;
            gameFile << "Duration: " << duration.count() << " seconds" << endl;
            
            gameFile << endl; // Add a newline to separate each game in the file

            gameFile.close(); // Close the file
        }
        else
        {
            cout << "Error: Unable to open file." << endl;
        }

        break;
    }

    if (turn == 9)
    {
        cout << "Draw." << endl;
        auto end = chrono::high_resolution_clock::now(); // stop the timer
        auto duration = chrono::duration_cast<chrono::seconds>(end - start); // calculate the duration
        cout << "Total duration: " << duration.count() << " seconds" << endl; // output the duration

        // Store the game data into a file
        ofstream gameFile("games.txt", ios::app); // Open the file in append mode
        if (gameFile.is_open())
        {
            // Write the game data to the file
            gameFile << "Date: " << dt << endl;
            gameFile << "Player 1: " << player1_name << endl;
            gameFile << "Player 2: " << player2_name << endl;
            gameFile << "Result: Draw" << endl;
            gameFile << "Duration: " << duration.count() << " seconds" << endl;
            gameFile << "Active Dates: TODO" << endl;
            gameFile << "Games: TODO" << endl;
            gameFile << endl; // Add a newline to separate each game in the file

            gameFile.close(); // Close the file
        }
        else
        {
            cout << "Error: Unable to open file." << endl;
        }

        break;
    }

    turn++;
}

return 0;
}
