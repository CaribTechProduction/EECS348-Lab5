#include <stdio.h>

// Define the number of different plays
#define NUM_PLAYS 5

// Define a struct for a play
struct Play
{
    char *name; // Name of the play
    int value; // Value of the play
    int count; // Count of the play
};

// Array of scoring plays with their values
struct Play scoring_plays[NUM_PLAYS] = {
    {"TD + 2pt", 8, 0},
    {"TD + 1pt FG", 7, 0},
    {"TD", 6, 0},
    {"FG", 3, 0},
    {"Safety", 2, 0}
};

// Function to find combinations of plays for a given score
void find_combinations(int score, struct Play *plays, int index)
{
    if (score == 0)
    {
        // Print the combinations of plays that add up to the score
        for (int i = 0; i < NUM_PLAYS; i++)
        {
            if (plays[i].count >= 0)
            {
                printf("%d %s, ", plays[i].count, plays[i].name);
            }
        }
        printf("\n"); // Move to a new line
        return;
    }

    if (index == NUM_PLAYS)
    {
        return; // Exit if index exceeds the number of plays
    }

    // Iterate through the plays to find combinations
    for (int i = 0; i <= score / plays[index].value; i++)
    {
        plays[index].count = i; // Update the count of plays
        find_combinations(score - i * plays[index].value, plays, index + 1); // Recursively call to find more combinations
    }
}

// Main function
int main()
{
    printf("Enter 0 or 1 to STOP\n"); // Prompt the user to enter 0 or 1 to stop
    int score;
    while (1)
    {
        printf("Enter the NFL score: "); // Ask for the NFL score
        scanf("%d", &score); // Read the score
        if (score <= 1)
        {
            break; // Break the loop if score is less than or equal to 1
        }
        printf("Possible combinations of scoring plays:\n");
        struct Play plays[NUM_PLAYS];
        for (int i = 0; i < NUM_PLAYS; i++)
        {
            plays[i] = scoring_plays[i]; // Initialize plays with scoring_plays
        }
        find_combinations(score, plays, 0); // Find combinations for the given score
    }
    return 0; // Exit the program
}