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



void startGame() {


}

int main() {
    srand((unsigned)time(NULL)); 
    startGame(); 
    return 0;  
}

