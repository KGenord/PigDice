#ifndef PIGDICE_MULTIPLAYERGAME_H
#define PIGDICE_MULTIPLAYERGAME_H
#include "PDGameV2.h"
#include <vector>
#include <string>

using namespace std;

class MultiPlayer {
private:
    vector<PDGameV2> m_players;
    bool m_gameOver;
    void checkForWinner();
    void displayScoreBoard();
public:
    MultiPlayer(string gameName);
    void mpPlayGame();
};


#endif //PIGDICE_MULTIPLAYERGAME_H
