#include <stdio.h>
#include <stdlib.h>

// Structure for player's info and lottery numbers
typedef struct KnightsBallLottoPlayer
{
    char firstName[20];
    char lastName[20];
    int numbers[6];
} KBLottoPlayer;

int main() {

    FILE *fp; // file pointer
    int i, j, n, k;
    int match;

    // Open input file
    fp = fopen("KnightsBall.in", "r");
    // If file cannot be opened, it will end program
    if (fp == NULL) {
        printf("The input file cannot be opened. \n");
        return 0;
    }
    // Reads the first line of single integer showing the number of tickets bought
    fscanf(fp, "%d", &n);

    // Reserve enough memory by the number of tickets and read the lotto player names and numbers into the array
    KBLottoPlayer *players = (KBLottoPlayer *)malloc(n*sizeof(KBLottoPlayer));
    for (i=0; i<n; i++) {
        fscanf(fp, "%s %s", players[i].firstName, players[i].lastName); // Reads the player's first and last name from input file and puts into array from struct
    for (j=0; j<6; j++)
        fscanf(fp, "%d", &players[i].numbers[j]); // Reads the player's lottery numbers from input file and puts into array from struct
    }
    fclose(fp); //Close input file

    // Reserve memory and read the winning numbers into array
    int *winningNums = (int *)malloc(6*sizeof(int));
        printf("Enter the winning Lottery numbers:\n"); // Ask user the winning lottery numbers
        for (i=0; i<6; i++) {
            scanf("%d", &winningNums[i]); // Winning lottery numbers are put into an array
            if (winningNums[i] >= 54) { // If user inputs a number greater than 53 it will end program
                printf("Please enter a number less than or equal to 53.\n");
                return 0;
            }
        }
        //Creates output file of lottery results
        fp = fopen("KnightsBall.out", "w");
        for (i=0; i<n; i++) { // Loop to go through all lottery players
        match = 0; // Starts matched count at 0
            for (j=0; j<6; j++) { // Loop through all the player's lottery numbers
                for (k=0; k<6; k++) { // Loop through to check players lottery numbers match with winning numbers
                    if (players[i].numbers[j] == winningNums[k])
                        match++; // Match count increases when player's lottery number matches with winning number
                    }
                }

        // Match lottery number cases and prints to the output file
        if(match<=2) // if match is less than 3 numbers it will continue the program
        continue;

        // Match count is equal to 3 player wins $10
        if(match==3)
        fprintf(fp, "%s %s matched %d numbers and won $10. \n", players[i].lastName, players[i].firstName, match);

        // Match count is equal to 4 player wins $100
        else if(match==4)
        fprintf(fp, "%s %s matched %d numbers and won $100. \n", players[i].lastName, players[i].firstName, match);

        // Match count is equal to 5 player wins $10000
        else if(match==5)
        fprintf(fp, "%s %s matched %d numbers and won $10000. \n", players[i].lastName, players[i].firstName, match);

        // Match count is equal to 6 player wins $1000000
        else if(match==6)
        fprintf(fp, "%s %s matched %d numbers and won $1000000. \n", players[i].lastName, players[i].firstName, match);
        }

    return 0; // Ends program
}
