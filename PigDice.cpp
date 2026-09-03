#include <iostream>
#include <ctime>
#include <cstdlib>


// Build your solution starting from this code.

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
void turn_count(GameState &g)


void addScore(GameState &gs) {
    gs.game_score += 10;
}

int main() {
    GameState my_game; // instantiate a GameState object
    addScore(my_game);
    std::cout << "Game score is: " << my_game.game_score << std::endl;
   // display_rules(); // call the display_rules function
    // play_game([&]my_game); // call the play_game function and pass the GameState object
    return 0;
}
void take_turn(GameState &game) {
    g.turn_count++;
    std::cout << "TURN" << mg.turn_count << " - Game Score: " <<:
    while (!mg.turn_over) {
        std::cout << "roll or hold?  r/h): " << std::endl;
        std::cin >> g.choice;
        if (mg.choice == 'r') {
            roll([])
        }
    }
}


void play_game(GameState g) {
    while (!g.game_over) {
        take_turn([&]g);
        g.game_score += g.score_this_turn;
        if (g.game_score >= 20) {
            g.game_over = true;
        }
        else {
            g.turn_over = false;
            g.score_this_turn = 0;
        }
    }
}

std::cout << "You finsihed with a final score of ";
std::cout << g.game_score;
std::cout << " in " << g.turn_count << " turns "
std::cout << "\nThanks for playing PIG Dice!";

void roll(GameState &g) {
    srand(seed:(NULL));
    int die = rand() % 6 + 1;
    std::cout << "Die: " << die;
    if (die == 1) {
        std::cout << "\nTurn over. No score.";
        g.score_this_turn = 0;
        g.turn_over = true;
    }
    else {
        g.score_this_turn+=die;
        std::cout << "Running score this turn:    " <<g.score_this_turn
    }
}

void hold(GameState &g) {
    g.turn_over = true;

}
