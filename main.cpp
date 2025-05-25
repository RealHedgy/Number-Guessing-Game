#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;


int generatenum()
{
    int num;    
    num = rand() % 101;

    return num;
}

void startgame()
{
    int num, chances = 0, difficulty = 0, guess = 0, attempts = 0;
    const int lvl1 = 10, lvl2 = 5, lvl3 = 3;
    string diff;
    bool valid = false, found = false;


    cout << "Welcome to the Number Guessing Game! \n\n";
    cout << "I'm thinking of a number between 0 and 100.\n";
    cout << "You have a certain number of chances to guess the correct number.\n\n";

    cout << "Please select the difficulty level: \n";
    cout << "1. Easy (10 chances)\n";
    cout << "2. Medium (5 chances)\n";
    cout << "3. Hard (3 chances)\n\n";

    
    while(valid == false)
    {
        cout << "Enter your choice: ";
        cin >> difficulty;

        if(difficulty == 1)
        {
            chances = 10;
            valid = true;
            diff = "Easy";
            difficulty = lvl1;
        }
        else if(difficulty == 2)
        {
            chances = 5;
            valid = true;
            diff = "Medium";
            difficulty = lvl2;
        }
        else if(difficulty == 3)
        {
            chances = 3;
            valid = true;
            diff = "Hard";
            difficulty = lvl3;
        }
        else
        {
            cout << "Invalid input.\n";
            valid = false;
        }

    }
    cout << endl;
    cout << "Great! You have selected the " << diff << " difficulty level.\nLet's start the game!\n\n\n";

    num = generatenum();
    
    
    while(found == false && attempts < difficulty)
    {
        auto start = std::chrono::high_resolution_clock::now();
        cout << "Enter your guess: ";
        cin >> guess;

        if(guess == num)
        {
            cout << "Congratulations! You guessed the correct number in " << attempts + 1 << " attempts.\n";
            found = true;
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            double seconds = duration.count();
            cout << "It took you " <<  seconds << " seconds" << endl << endl;
        }
        else if(guess > num)
        {
            cout << "Incorrect! The number is less than " << guess << endl << endl;
            found = false;
        }
        else if(guess < num)
        {
            cout << "Incorrect! The number is more than " << guess << endl << endl;
            found = false;
        }

        attempts++;
    }

    if(found == false)
    {
        cout << "You lose, the number is " << num << endl << endl;
    }
}


int main()
{
    srand(time(0));

    int num, chances = 0, difficulty = 0, guess = 0, attempts = 0, answ;
    const int lvl1 = 10, lvl2 = 5, lvl3 = 3;
    string diff;
    bool valid = false, found = false, restart = true;


    startgame();

    while(restart == true)
    {

    
        cout << "Do you wish to restart the game? \n";
        cout << "Press 1 to restart\n";
        cout << "Press 2 to exit\n";

        cin >> answ;

        if(answ == 1)
        {
            startgame();
            restart = true;
        }
        else if(answ == 2)
        {
            cout << "Thanks for playing!";
            restart = false;
        }
    }

}