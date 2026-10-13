#include <iostream>
#include "Turn.h"
#include "PDGame.h"


Turn::Turn() {
    m_turnCount = 0;
    m_scoreThisTurn = 0;
    m_turnOver = false;
    m_choice = '\0';
}
void Turn::setParentGame(PDGame* parentGame){
    m_parentGame = parentGame; // 6.
}
void Turn::takeTurn() {
    m_turnCount++;
    std::cout << "\nTURN " << m_turnCount;
    // ISSUE: Turn object "part" needs access to m_gameScore in "whole" (PDGame)
    std::cout << " - Game Score: " << m_parentGame->gameScore(); // 9.
    while (!m_turnOver) {
        std::cout << "\nroll or hold? (r/h): ";
        std::cin >> m_choice;
        if (m_choice == 'r') {
            roll();
        }
        else if (m_choice == 'h') {
            m_turnOver = true;
        }
        else {
            std::cout << "Invalid Choice!";
        }
    }
    std::cout << "\nScore Banked This Turn: " << m_scoreThisTurn;

}
int Turn::getScoreThisTurn() const {
    return m_scoreThisTurn;
}
void Turn::resetTurnOver() {
    m_turnOver = false;
}
int Turn::getTurnCount() {
    return m_turnCount;
}
void Turn::resetScoreThisTurn() {
    m_scoreThisTurn = 0;
}
void Turn::roll() {
    m_myDie.rollDie();
    std::cout << "Die: " << m_myDie.getDieValue();
    if (m_myDie.getDieValue() == 1) {
        std::cout << "\nTurn Over. No Score. \n";
        m_scoreThisTurn = 0;
        m_turnOver = true;
    }
    else {
        m_scoreThisTurn+=m_myDie.getDieValue();
        std::cout << " - Running score this turn: " << m_scoreThisTurn;
    }
}
