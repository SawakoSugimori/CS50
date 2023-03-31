// This is a program of a plurality election
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
            i--;
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    bool validation = false;
    int invalid = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        // See if the candidate name exists
        if (strcmp(candidates[i].name, name) == 0)
        {
            validation = true;
            candidates[i].votes++;
            invalid++;
            return validation;
        }
    }

    // In the case the input name didn't match any candidates
    if (invalid == 0)
    {
        // The invalid vote won't be counted
        validation = false;
        return validation;
    }
    return validation;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    string winner = candidates[0].name;
    candidate n;

    // Sort in decending order
    int swap_counter = 1;
    int size = candidate_count - 1;

    // Repeat until the swap counter is 0
    while (swap_counter != 0)
    {
        swap_counter = 0;

        for (int i = 0; i < size; i++)
        {
            if (candidates[i].votes < candidates[i + 1].votes)
            {
                n = candidates[i];
                candidates[i] = candidates[i + 1];
                candidates[i + 1] = n;

                swap_counter++;
            }
        }
        size--;
    }

    // Count the number of candidates who have max votes
    int winners = 1;
    for (int j = 1; j < candidate_count; j++)
    {
        if (candidates[0].votes == candidates[j].votes)
        {
            winners++;
        }
    }

    // Print winners
    for (int j = 0; j < winners; j++)
    {
        printf("%s\n", candidates[j].name);
    }
    return;
}