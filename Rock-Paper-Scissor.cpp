#include <iostream>
#include <cstdlib>    
#include <ctime>      

using namespace std;

enum enGameChoice {Rock = 1, Paper = 2, Scissor = 3};
enum enWinner {Player = 1, Computer = 2, Draw = 3 };



void startGame() {


}

int main() {
    srand((unsigned)time(NULL)); 
    startGame(); 
    return 0;  
}

