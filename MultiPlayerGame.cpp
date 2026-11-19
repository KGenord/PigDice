#include "MultiPlayerGame.h"
#include <iostream>
#include <string>

using namespace std;

MultiPlayer::MultiPlayer(string gameName) {
    m_gameOver = false;
    int numberOfPlayers;
    cout << "How many people are playing? ";
    cin >> numberOfPlayers;
    cin.ignore(1000, '\n');
    for (int i = 0; i < numberOfPlayers; i++) {
        string playerName;
        cout << "Enter player " << i + 1 << " name: ";
        getline(cin, playerName);
        if (playerName.empty()) {
            playerName = "Anonymous Player " + to_string(i + 1);
        }
        m_players.emplace_back(playerName);
    }
}
    void MultiPlayer::mpPlayGame() {
        if (m_players.empty()) {
            cout << "No players found." << endl;
            return;
        }
        cout << "\nLets Play Pig Dice!" << endl;
        m_players[0].displayRules();
        int turnNumber = 1;
        while (!m_gameOver) {
            for (int i = 0; i < m_players.size(); i++) {
                cout << "\n" << m_players[i].getPlayerName();
                cout << "(Score: " << m_players[i].gameScore();
                cout << ") - Turn" << turnNumber << endl;

                m_players[i].playGame();
                displayScoreBoard();
                checkForWinner();
                if (m_gameOver) {
                    break;
                }
            }
            turnNumber++;
    }
}

void MultiPlayer::displayScoreBoard() {
    cout << endl;
    for (int i = 0; i < m_players.size(); i++) {
        cout << m_players[i].getPlayerName();
        cout << "Score: " << m_players[i].gameScore();
        cout << ") | ";
        cout << endl;
    }
}

void MultiPlayer::checkForWinner() {
    for (int i = 0; i < m_players.size(); i++) {
        if (m_players[i].gameScore() >=50) {
            m_gameOver = true;
            cout << "\nCongratulations!";
            cout << m_players[i].getPlayerName();
            cout << " you win with a score of ";
            cout << m_players[i].gameScore();
            cout << endl;

            break;
        }
    }
}
