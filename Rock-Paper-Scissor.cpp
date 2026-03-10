#include <iostream>
#include <cstdlib>    
#include <ctime>      

using namespace std;

enum enGameChoice {Rock = 1, Paper = 2, Scissor = 3};
enum enWinner {Player = 1, Computer = 2, Draw = 3 };

struct stRoundInfo {
    short roundNumber = 0;
    enGameChoice player1Choice;
    enGameChoice computerChoice;
    enWinner winner;
    string winnerName;
};

struct stGameResults {
    short gameRound = 0;
    short player1WinTimes = 0;
    short computerWinTimes = 0;
    short drawTimes = 0;
    enWinner gameWinner;
    string winnerName = "";
};

int randomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

enGameChoice getComputerChoice() {
    return (enGameChoice) randomNumber(1, 3);
}

enWinner whoWonTheRound(stRoundInfo roundInfo) {
    if (roundInfo.player1Choice == roundInfo.computerChoice) {
        return enWinner::Draw;
    }

    switch (roundInfo.player1Choice) {
    case enGameChoice::Rock:
        return (roundInfo.computerChoice == enGameChoice::Paper) ? enWinner::Computer : enWinner::Player;
    case enGameChoice::Paper:
        return (roundInfo.computerChoice == enGameChoice::Scissor) ? enWinner::Computer : enWinner::Player;
    case enGameChoice::Scissor:
        return (roundInfo.computerChoice == enGameChoice::Rock) ? enWinner::Computer : enWinner::Player;
    }
}

enWinner whoWonTheGame(short player1WinTimes, short computerWinTimes) {
    if (player1WinTimes > computerWinTimes) return enWinner::Player;
    else if (computerWinTimes > player1WinTimes) return enWinner::Computer;
    else return enWinner::Draw;
}

string choiceName(enGameChoice choice) {
    string arrGameChoices[3] = {"Rock", "Paper", "Scissor"};
    return arrGameChoices[choice - 1];
}

string winnerName(enWinner winner) {
    string arrWinnerName[3] = {"Player1", "Computer", "Draw"};
    return arrWinnerName[winner - 1];
}





void startGame() {


}

int main() {
    srand((unsigned)time(NULL)); 
    startGame(); 
    return 0;  
}

