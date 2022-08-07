
#define ROUNDS 5
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void greeting(void); //display welcome message to user
void playRound(int round); //play one round
int pickOne(void); //retrieve the user's guess
int computerPick(void); //computer makes its pick
int battle(int player1, int player2); //battle rock...paper...scissor
void result(int player1, int player2); //overall winner of round

int main()
{
    greeting(); //display greeting message

    //setup random generator
    int seed;
    printf("Before we start, pick a number to determine how random I will be.\n");
    scanf("%d", &seed);
    srand(seed);
    printf("All set now!\n");

    // For 5 rounds, the game will continue looping.
    for(int x = 0; x < ROUNDS; ++x)
    {
        playRound(x + 1); //function call
    }


    printf("********************************************************\n");
    printf("Thank you for playing!\n");
    return 0;
}

// Player greeting that starts the game off before the looping starts.
void greeting()
{
    printf("********************************************************\n");
    printf("Welcome to rock paper scissor game!\n");
    printf("Here are the rules.\n");
    printf("You and I will  get to choose rock, paper, or scissor.\n");
    printf("After we made a decision we will reveal it and determine the winner based on these rules.\n");
    printf("Rock beats Scissor!\n");
    printf("Paper beats Rock!\n");
    printf("Scissor beats Paper!\n");
    printf("If we both pick the same option, then it is a tie.\n");
    printf("Ready to play?...Here we go!\n");
    printf("********************************************************\n");

}

// Each round of rock, paper, scissor is played and decided each time
void playRound(int round)
{
    printf("Welcome to a new round %d!\n", round);
    printf("Best out of three...Let's go!\n");

    // Declaration of variables
    int p1wins = 0;
    int p2wins = 0;
    int player1;
    int player2;
    int winner;

    //loop that keeps track of wins until respective player reaches 3. we will learn about conditional loops soon :)
    while(p1wins != 3 && p2wins != 3)
    {
        //place code inside this control structure that you want to repeat until someone wins best out of 3
        printf("********************************************************\n");
        printf("Player 1 has won %d time(s).\n", p1wins);
        printf("Player 2 has won %d time(s).\n", p2wins);

        // Function calls
        player1 = pickOne();
        player2 = computerPick();
        winner = battle(player1, player2);

        // Determines if winner is player1 or player2.
        if (winner == 1)
            p1wins++;
        else if (winner == 2)
            p2wins++;

        printf("********************************************************\n");
    }

    // player1 and player1 are declared winner or not
    player1 = p1wins;
    player2 = p2wins;

    result(player1, player2); //function call
}

// User picks rock, paper, or scissor
int pickOne()
{
    int p1;

    printf("1---Rock\n");
    printf("2---Paper\n");
    printf("3---Scissor\n");

    printf("Make your selection: ");
    scanf("%d", &p1);

    // Number corresponds to their selection
    switch (p1)
    {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break;
        default:
            printf("Someone made an invalid choice.\n");
            break;
    }

    return 0;
}

// Player2 (computer) makes a random rock, paper, scissor pick
int computerPick()
{
    int p2 = rand() % (3) + 1;

    // Number corresponds to their selection
    switch (p2)
    {
        case 1:
            printf("I'm making my decision now.\n");
            return 1;
            break;
        case 2:
            printf("I'm making my decision now.\n");
            return 2;
        case 3:
            printf("I'm making my decision now.\n");
            return 3;
        default:
            break;
    }

    return 0;
}

// Decision about who won the round based on selections
int battle(int player1, int player2)
{
    int flag1 = 1; //player1
    int flag2 = 2; //player2

    if (player1 == 1 && player2 == 3)
    {
        printf("Player 1 used Rock and Player 2 used Scissor!\n");
        printf("Rock beats Scissor!\n");
        return flag1;
    }
    else if (player1 == 3 && player2 == 2)
    {
        printf("Player 1 used Scissor and Player 2 used Paper!\n");
        printf("Scissor beats Paper!\n");
        return flag1;
    }
    else if (player1 == 2 && player2 == 1)
    {
        printf("Player 1 used Paper and Player 2 used Rock!\n");
        printf("Paper beats Rock!\n");
        return flag1;
    }
    else if (player1 == 3 && player2 == 1)
    {
        printf("Player 1 used Scissor and Player 2 used Rock!\n");
        printf("Rock beats Scissor!\n");
        return flag2;
    }
    else if (player1 == 2 && player2 == 3)
    {
        printf("Player 1 used Paper and Player 2 used Scissor!\n");
        printf("Paper beats Rock!\n");
        return flag2;
    }
    else if (player1 == 1 && player2 == 2)
    {
        printf("Player 1 used Rock and Player 2 used Paper!\n");
        printf("Paper beats Rock!\n");
        return flag2;
    }
    else if (player1 == 1 && player2 == 1)
    {
        printf("Player1 and Player2 both used Rock!\n");
        printf("Draw!\n");
        return 0;
    }
    else if (player1 == 2 && player2 == 2)
    {
        printf("Player1 and Player2 both used Paper!\n");
        printf("Draw!\n");
        return 0;
    }
    else if (player1 == 3 && player2 == 3)
    {
        printf("Player1 and Player2 both used Scissor!\n");
        printf("Draw!\n");
        return 0;
    }

    return 0;
}

// Based off the player1 and player2 wins, a message is displayed
void result(int player1, int player2)
{
    if (player1 == 3)
        printf("You won! I'll let you have this one.\n");
    else
        printf("I won! Haha better luck next time!\n");

}
