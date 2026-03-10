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

enGameChoice readPlayer1Choice() {
    short choice;

    do {
        cout << "\nYour choice: [1]Rock, [2]Paper, [3]Scissor? ";
        cin >> choice;

    } while (choice < 1 || choice > 3);
    return (enGameChoice) choice;
}

void PrintRoundResults(stRoundInfo RoundInfo)
{
    cout << "\n____________ Round [" << RoundInfo.roundNumber << "] ____________\n\n";
    cout << "Player1 Choice: " << choiceName(RoundInfo.player1Choice) << endl;
    cout << "Computer Choice: " << choiceName(RoundInfo.computerChoice) << endl;
    cout << "Round Winner   : [" << RoundInfo.winnerName << "]\n";
    cout << "_________________________________________\n" << endl;
}

stGameResults playGame(short howManyRounds) {
    stRoundInfo roundInfo;

    short player1WinTimes = 0, computerWinTimes = 0, drawTimes = 0;

    for (short gameRound = 1;gameRound <= howManyRounds; gameRound++) {
        cout << "\nRound [" << gameRound << "] begins: \n";
        roundInfo.roundNumber = gameRound;
        roundInfo.player1Choice = readPlayer1Choice();
        roundInfo.computerChoice = getComputerChoice();
        roundInfo.winner = whoWonTheRound(roundInfo);
        roundInfo.winnerName = winnerName(roundInfo.winner);

        if (roundInfo.winner == enWinner::Player)
            player1WinTimes++;
        else if (roundInfo.winner == enWinner::Computer)
            computerWinTimes++;
        else drawTimes++;

        PrintRoundResults(roundInfo);
    }

    return  {howManyRounds, player1WinTimes, computerWinTimes, drawTimes, whoWonTheGame(player1WinTimes, computerWinTimes), winnerName(whoWonTheGame(player1WinTimes, computerWinTimes))};
}



void startGame() {
    char playAgain = 'Y';

    do {
        system("cls");
        stGameResults gameResult = playGame(3);
        cout << "\nGame over! Winner: " << gameResult.winnerName << endl;

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');

}

int main() {
    srand((unsigned)time(NULL)); 
    startGame(); 
    return 0;  
}

