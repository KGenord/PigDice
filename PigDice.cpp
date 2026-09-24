#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>

// Build your solution starting from this code


struct GameState {
    char choice;
    int turn_count = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;
};
class Die {
private:
    int m_value;
    int m_numberOfSides;
public:
    Die() {
        m_numberOfSides = 6;
        setValue();
    }

    void set_numOfSides(int numOfSides) {
        switch (numOfSides) {
            case 4:
                m_numberOfSides = 4;
                break;
            case 6:
                m_numberOfSides = 6;
                break;
            case 8:
                m_numberOfSides = 8;
                break;
            default:
                m_numberOfSides = 6;
        }
    }
int getNumOfSides() {
        return m_numberOfSides;
    }

    void setValue() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(1, m_numberOfSides);
        m_value = dist(gen);
    }
    int getValue() {
        return m_value;
    }
};



void play_game(GameState &g);
void take_turn(GameState &g);
void roll(GameState &g);
void hold(GameState &g);


int main() {
    GameState my_game; // instantiate a GameState object addScore(my_game);
   // display_rules(); // call the display_rules function
    std::cout << "Welcome to PigDice!" << std::endl;
    std::cout << "\nGAME RULES:" << std::endl;
    std::cout << "\nSee how many turns it takes you to get to 20 points.";
    std::cout << "\nTurn ends when you hold or roll a 1.";
    std::cout << "\nIf you roll a 1, you lose all points for the turn.";
    std::cout << "\nIf you hold, you bank all points for the turn to the game score";

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
    std::cout << "\nTURN " << g.turn_count;
    std::cout << " - Game Score: " << g.game_score;
    while (!g.turn_over) {
        std::cout << "\nroll or hold? (r/h): ";
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
    std::cout << "\nScore Banked This Turn: " << g.score_this_turn;
}


void roll(GameState &g) {
    /*srand(time(NULL));
    int die = rand() % 6 + 1;*/
    Die myDie;  // calls the default constructor
    myDie.setValue();  // calling the public function to roll the die
    std::cout << "Die: " << myDie.getValue();
    if (myDie.getValue() == 1) {
        std::cout << "\nTurn over. No Score.";
        g.score_this_turn = 0;
        g.turn_over = true;
    }
    else {
        g.score_this_turn+=myDie.getValue();
        std::cout << " \nRunning score this turn: " << g.score_this_turn;
    }
}


void hold(GameState &g) {
    g.turn_over = true;
}