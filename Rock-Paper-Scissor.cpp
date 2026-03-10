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

string winnerName(enWinner winner) {
    string arrWinnerName[3] = { "Player1", "Computer", "Draw" };
    return arrWinnerName[winner - 1];
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

string choiceName(enGameChoice choice) {
    string arrGameChoices[3] = { "Rock", "Paper", "Scissor" };
    return arrGameChoices[choice - 1];
}

void setWinnerScreenColor(enWinner winner) {
    switch (winner) {

    case enWinner::Player:
        system("color 2F"); // green color
        break;
    case enWinner::Computer:
        system("color 4F"); // red color
        cout << "\a";
        break;
    default:
        system("color 6F"); // yellow color
        break;
    }
}

void PrintRoundResults(stRoundInfo roundInfo)
{
    cout << "\n____________ Round [" << roundInfo.roundNumber << "] ____________\n\n";
    cout << "Player1 Choice: " << choiceName(roundInfo.player1Choice) << endl;
    cout << "Computer Choice: " << choiceName(roundInfo.computerChoice) << endl;
    cout << "Round Winner   : [" << roundInfo.winnerName << "]\n";
    cout << "_________________________________________\n" << endl;

    setWinnerScreenColor(roundInfo.winner);
}

enWinner whoWonTheGame(short player1WinTimes, short computerWinTimes) {
    if (player1WinTimes > computerWinTimes) return enWinner::Player;
    else if (computerWinTimes > player1WinTimes) return enWinner::Computer;
    else return enWinner::Draw;
}

stGameResults fillGameResults(int gameRounds, short player1WinTimes, short computerWinTimes, short drawTimes) {
    stGameResults gameResults;

    gameResults.gameRound = gameRounds;
    gameResults.player1WinTimes = player1WinTimes;
    gameResults.computerWinTimes = computerWinTimes;
    gameResults.drawTimes = drawTimes;
    gameResults.gameWinner = whoWonTheGame(player1WinTimes, computerWinTimes);
    gameResults.winnerName = winnerName(gameResults.gameWinner);

    return gameResults;
}

enGameChoice readPlayer1Choice() {
    short choice;

    do {
        cout << "\nYour choice: [1]Rock, [2]Paper, [3]Scissor? ";
        cin >> choice;

    } while (choice < 1 || choice > 3);
    return (enGameChoice)choice;
}

enGameChoice getComputerChoice() {
    return (enGameChoice)randomNumber(1, 3);
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

    return  fillGameResults(howManyRounds, player1WinTimes, computerWinTimes, drawTimes);
}

string tabs(short numberOfTabs) {
    string t = "";

    for (int i = 1; i < numberOfTabs; i++) {
        t = t + "\t";
        cout << t;
    }
    return t;
}

void showGameOverScreen() {
    cout << tabs(2) << "---------------------------------------------------------------\n\n";
    cout << tabs(2) << "                +++ G a m e  O v e r +++\n";
    cout << tabs(2) << "---------------------------------------------------------------\n\n";
}

void showFinalGameResults(stGameResults gameResult) {
    cout << tabs(2) << "------------------ [Game Results] ------------\n\n";
    cout << tabs(2) << "Game Rounds        : " << gameResult.gameRound << endl;
    cout << tabs(2) << "Player 1 won times : " << gameResult.player1WinTimes << endl;
    cout << tabs(2) << "Computer won times : " << gameResult.computerWinTimes << endl;
    cout << tabs(2) << "Draw times         : " << gameResult.drawTimes << endl;
    cout << tabs(2) << "Final winner       : " << gameResult.winnerName << endl;
    cout << tabs(2) << "----------------------------------------------\n\n";

    setWinnerScreenColor(gameResult.gameWinner);
}

short readHowManyRounds() {
    short gameRounds = 1;

    do {
        cout << "How many round 1 to 10 ? \n";
        cin >> gameRounds;

    } while (gameRounds < 1 || gameRounds > 10);
    return gameRounds;
}

void resetScreen() {
    system("cls");
    system("color 0F"); // back to black color
}

void startGame() {
    char playAgain = 'Y';

    do {
        resetScreen();
        stGameResults gameResult = playGame(readHowManyRounds());
        showGameOverScreen();
        showFinalGameResults(gameResult);

        cout << endl << tabs(3) << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');

}

int main() {
    srand((unsigned)time(NULL)); 
    startGame(); 
    return 0;  
}

