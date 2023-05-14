#include<iostream>
#include<conio.h>
#include<ctime>
#include<string>
#include<stdlib.h>
using namespace std;

int TheNumberOfGame(string Message)
{
    int Number;
    do
    {
        cout << Message;
        cin >> Number;
    } while( Number<=0 || Number>10 );
    return Number;
}
int RandomNumber(int From, int To)
{
    return rand()%(To-From+1)+From;
}
int GetGameChoice()
{
    int Choice;
    cout << "\nYour Choice: Stone:[1]  Paper:[2]  Scissors:[3] ? ";
    cin >> Choice;
    return Choice;
}
string Tab(int NumberOfTab)
{
    string Tabs="";
    for(int i=0; i<NumberOfTab; i++)
        Tabs += "-";
    return Tabs;
}
string CheckToEquelChoices(int Player1, int Computer)
{
    return (Player1==1) ? "Stone" : ((Player1==2) ? "Paper":"Scissors");
}
string CheckToPlayerChoice(int Player1)
{
    return (Player1==1) ? "Stone" : ((Player1==2) ? "Paper":"Scissors");
}
string CheckToComputerChoice(int Computer)
{
    return (Computer==1) ? "Stone" : ((Computer==2) ? "Paper":"Scissors");
}
void PrintRoundsResult(string Player1Choice, string ComputerChoice, int Round)
{
    cout << "\n";
    cout << Tab(20) << " Round [" << Round+1 << "] " << Tab(20) << "\n\n"; 
    cout << "Player1 choice :: " << Player1Choice << endl;
    cout << "Computer choice :: " << ComputerChoice << endl;
    cout << Tab(51) << endl;
}
void GameOver(int Player1Counter, int ComputerCounter, int GameRounds)
{
    cout << "\n\n";
    cout << "\t\t\t" << Tab(44) << "\n";  
    cout << "\t\t\t\t\t" << "G a m e  O v e r \n";
    cout << "\t\t\t" << Tab(44) << "\n";  
    cout << "\t\t\t" << Tab(14) << "[ Game Result ]" << Tab(15) << "\n";  
    cout << "\t\t\t" << "Game Rounds        : " << GameRounds << endl;
    cout << "\t\t\t" << "Player1 won times  : " << Player1Counter << endl;
    cout << "\t\t\t" << "Computer won times : " << ComputerCounter << endl;
    string Winner = (Player1Counter>ComputerCounter) ? "[Player1]" : (ComputerCounter>Player1Counter) ? "[Computer]" : "[No Winner]";
    cout << "\t\t\t" << "Final Winner       : " << Winner << endl;
    cout << "\t\t\t" << Tab(44) << endl;
    
}
void GameConditions(int NumberOfGame, int &Player1Counter, int &ComputerCounter)
{
    // Stone=1, Paper=2, Scissors=3
    for(int i=0; i<NumberOfGame; i++)
    {
        cout << "\nRound[" << i+1 << "] beigns";
        int Player1 = GetGameChoice();
        int Computer = RandomNumber(1, 3);
        if(Player1==1 && Computer==2)
        {
            cout << "\a";
            system("color 4F");
            ComputerCounter++;
            PrintRoundsResult(CheckToPlayerChoice(Player1), CheckToComputerChoice(Computer), i);
        }
        else if(Player1==1 && Computer==3)
        {
            // Player1
            system("color 1F");
            Player1Counter++;
            PrintRoundsResult(CheckToPlayerChoice(Player1), CheckToComputerChoice(Computer), i);
        }
        else if(Player1==2 && Computer==1)
        {
            // Player1
            system("color 1F");
            Player1Counter++;
            PrintRoundsResult(CheckToPlayerChoice(Player1), CheckToComputerChoice(Computer), i);
        }
        else if(Player1==2 && Computer==3)
        {
            cout << "\a";
            system("color 4F");
            ComputerCounter++;
            PrintRoundsResult(CheckToPlayerChoice(Player1), CheckToComputerChoice(Computer), i);
        }
        else if(Player1==3 && Computer==1)
        {
            cout << "\a";
            system("color 4F");
            ComputerCounter++;
            PrintRoundsResult(CheckToPlayerChoice(Player1), CheckToComputerChoice(Computer), i);
        }
        else if(Player1==3 && Computer==2)
        {
            // Player1
            system("color 1F");
            Player1Counter++;
            PrintRoundsResult(CheckToPlayerChoice(Player1), CheckToComputerChoice(Computer), i);
        }
        else
        {
            system("color 6F");
            PrintRoundsResult(CheckToEquelChoices(Player1, Computer), CheckToEquelChoices(Player1, Computer), i);

        }
    }
    GameOver(Player1Counter, ComputerCounter, NumberOfGame);
}
int main()
{
    srand((unsigned)time(NULL));
    int NumberOfGame, ComputerCounter=0, Player1Counter=0;
    NumberOfGame = TheNumberOfGame("How Many Rounds 1 to 10 ? ");
    GameConditions(NumberOfGame, Player1Counter, ComputerCounter);
}

