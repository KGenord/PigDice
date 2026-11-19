#ifndef PIGDICE_PDGAMEV2_H
#define PIGDICE_PDGAMEV2_H

#include "PDGame.h"
#include <string>

using namespace std;

class PDGameV2 : public PDGame {
private:
    string m_playerName;
public:
    PDGameV2(string playerName);
    string getPlayerName();
    void playGame();
    void displayRules();

};


#endif //PIGDICE_PDGAMEV2_H
