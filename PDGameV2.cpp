#include "PDGameV2.h"
#include <iostream>
using namespace std;

// constructor
PDGameV2::PDGameV2(string playerName) {
    m_playerName = playerName;
}

string PDGameV2::getPlayerName() {
    return m_playerName;
}

void PDGameV2::playGame() {
    m_myTurn.setParentGame(this);
    m_myTurn.takeTurn();
    m_gameScore += m_myTurn.getScoreThisTurn();
    m_myTurn.resetTurnOver();
    m_myTurn.resetScoreThisTurn();
}

void PDGameV2::displayRules() {
    cout << "\nGAME RULES:" << endl;
    cout << "See which player will reach 50 points in the fewest turns." << endl;
    cout << "Turn ends when you hold or roll a 1" << endl;
    cout << "If you roll a 1, you lose all points for this turn" << endl;
    cout << "If you hold, you save all points for this turn." << endl;
}
