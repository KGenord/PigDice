#include "PDGame.h"

#include <iostream>

PDGame::PDGame() {
    m_gamOver = false;
    m_gameScore = 0;
    m_myTurn.setParentGame(this); // 7.
    displayRules();
    playGame();
}
int PDGame::gameScore() const {
    return m_gameScore; // 2.
}
void PDGame::displayRules() {
    std::cout << "Welcome to PigDice!" << std::endl;
    std::cout << "\nGAME RULES:" << std::endl;
    std::cout << "\nSee how many turns it takes you to get to 20 points.";
    std::cout << "\nTurn ends when you hold or roll a 1.";
    std::cout << "\nIf you roll a 1, you lose all points for the turn.";
    std::cout << "\nIf you hold, you bank all points for the turn to the game score";
}
void PDGame::playGame() {
    while (!m_gamOver) {
        m_myTurn.takeTurn();
        m_gameScore += m_myTurn.getScoreThisTurn();
        if (m_gameScore >= 20) {
            m_gamOver = true;
        }
        else {
            m_myTurn.resetTurnOver();
            m_myTurn.resetScoreThisTurn();
        }
    }
    std::cout << "You finished with a final score of ";
    std::cout << m_gameScore;
    std::cout << " in " << m_myTurn.getTurnCount() << " turns ";
    std::cout << "\nThanks for playing PIG Dice!";
}