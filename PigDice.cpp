#include <iostream>
#include <ctime>
#include <cstdlib>

// Build your solution starting from this code

struct GameState {
    char choice;
    int turn_count = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;
};


void play_game(GameState &g);
void take_turn(GameState &g);
void roll(GameState &g);
void hold(GameState &g);


int main() {
    GameState my_game; // instantiate a GameState object addScore(my_game);
    //display_rules(); // call the display_rules function
    play_game(my_game); // call the play_game function and pass the GameState object
    return 0;
}



void play_game(GameState &g) {
    while (!g.game_over) {
        take_turn((g));
        g.game_score += g.score_this_turn;
        if (g.game_score >= 20) {
            g.game_over = true;
        }
        else {
            g.turn_over = false;
            g.score_this_turn = 0;
        }
    }
    std::cout << "You finished with a final score of ";
    std::cout << g.game_score;
    std::cout << " in " << g.turn_count << " turns ";
    std::cout << "\nThanks for playing PIG Dice!";
}
void take_turn(GameState &g) {
    g.turn_count++;
    std::cout << "TURN " << g.turn_count;
    std::cout << " - Game Score: " << g.game_score;
    while (!g.turn_over) {
        std::cout << "roll or hold? (r/h): ";
        std::cin >> g.choice;
        if (g.choice == 'r') {
            roll(g);
        }
        else if (g.choice == 'h') {
            hold(g);
        }
        else {
            std::cout << "Invalid Choice!";
        }
    }
    std::cout << "Score Banked This Turn: " << g.score_this_turn;
}


void roll(GameState &g) {
    srand(time(NULL));
    int die = rand() % 6 + 1;
    std::cout << "Die: " << die;
    if (die == 1) {
        std::cout << "\nTurn over. No Score.";
        g.score_this_turn = 0;
        g.turn_over = true;
    }
    else {
        g.score_this_turn+=die;
        std::cout << " Running score this turn: " << g.score_this_turn;
    }
}


void hold(GameState &g) {
    g.turn_over = true;
}
