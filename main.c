#include <stdio.h>
//The header file stdio.h stands for Standard Input Output.It has the information related to
// input/output functions like printf(), scanf() etc.

// it is global array.
//in this array each value represent the position of the in the 3*3 square.
char square[10]= {'o','1', '2', '3', '4', '5', '6', '7', '8', '9'};

// this function is used to check the winnner of the game.
int checkwin();

// this function is used to make board.
// Declare THE BOARD FUNCTION
void board();

// 1st phase==In this phase we have to make the board on which the tic tac toe game is being played.
// in this phase we are using only printf function to print the board.
//\nis used for printing line to the next line.

    //==== this is created  by JITENDER GOYAL=======
    // DEFINE THE BOARD FUNCTION
void board()
{
    printf("\n\n==================================\n");
    printf("\t  Tic Tac Toe");
    printf("\n ==================================\n");

    printf(" Player 1 (X)  -  Player 2 (O)\n");
    printf("====================================\n");

    printf("\t|     |     |     |\n");
    printf("\t|__%c__|__%c__|__%c__|\n", square[1], square[2], square[3]);

    printf("\t|     |     |     |\n");
    printf("\t|__%c__|__%c__|__%c__|\n", square[4], square[5], square[6]);

    printf("\t|     |     |     |\n");
    printf("\t|__%c__|__%c__|__%c__|\n", square[7], square[8], square[9]);
    printf("\t|     |     |     |\n");

    printf("\n==================================");
}

//2nd phase == in this phase  we are asking from user to give the value as per his/her choice.
// in this phase we are using do while loop to check whether it is player 1 or player 2.
//in this phase we are also using else if ladder in loop for marking the choice to their correct places.
//in this phase we are also tracking whether any player win or game draw by using else if statements.

    //==== this phase created by shubham shrivastav==========
int main()
{
    //choice == it means positon that is being taken by any of the two player.
    //1== it is the 1st player.
    //i==it keeps track of the game whether the game is in progess.
    int player = 1, i, choice;

    //mark can be X or 0.
    char mark;
    do
    {
        board();
        //if player value is divisible by 2 that means it is player 2.
        //if player value is not divisible by 2 that means it is player 1.
        //player value comes out to be 0 that means it is false or we can say that it is player 2.
        //if it comes out to be 1 it is true or we can say that it is player 1.

        player = (player % 2) ? 1 : 2;

        // we are asking from user to give the value as per his/her choice.
        printf("\nPlayer %d, enter a number:  ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;

        else if (choice == 2 && square[2] == '2')
            square[2] = mark;

        else if (choice == 3 && square[3] == '3')
            square[3] = mark;

        else if (choice == 4 && square[4] == '4')
            square[4] = mark;

        else if (choice == 5 && square[5] == '5')
            square[5] = mark;

        else if (choice == 6 && square[6] == '6')
            square[6] = mark;

        else if (choice == 7 && square[7] == '7')
            square[7] = mark;

        else if (choice == 8 && square[8] == '8')
            square[8] = mark;

        else if (choice == 9 && square[9] == '9')
            square[9] = mark;

        else
        {
            // if the player makes a wrong choice or enter the number which is  not mentioned above in the code
            //then he or she will get a second chance.
            printf("   Invalid move ");
            player--;
            
        }
        i = checkwin();

        player++;
    } while (i == -1);

    board();

    if (i == 1)
    {
        printf("   ==>\aPlayer %d win ", --player);
    }
    else
    {
        printf("   ==>\aGame draw");
        
    }
    

    return 0;
}

// 3rd phase == In this phase we have to check whether the player 1 is winner or player 2 is winner of the game.
//in this phase we are using else if ladder for checking the combinations.

    //this phase is created by ayush sahoo
int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}
