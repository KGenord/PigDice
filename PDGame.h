#ifndef PIGDICE_PBGAME_H
#define PIGDICE_PBGAME_H
#include "Turn.h"

class PDGame {
private:
    Turn m_myTurn;
    bool m_gamOver;
    int m_gameScore;
public:
    PDGame();
    int gameScore() const;  // 1. review document for steps details


private:
    void displayRules();
    void playGame();
};


#endif //PIGDICE_PBGAME_H