#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

struct CandidateInfo
{
    char fullName[50];
    int votesReceived;
};

struct VoterInfo
{
    char fullName[50];
    char address[100];
    int identification;
    int hasVoted;
};

void clearConsole()
{
    system("clear || cls");
}

void displayCandidates(struct CandidateInfo candidates[], int totalCandidates)
{
    printf("Candidates:\n");
    for (int i = 0; i < totalCandidates; i++)
    {
        printf("%d. %s\n", i + 1, candidates[i].fullName);
    }
}

int main()
{
    struct CandidateInfo candidates[MAX_CANDIDATES];
    int totalCandidates = 0;

    struct VoterInfo voters[MAX_VOTERS];
    int totalVoters = 0;

    int voteCount[MAX_CANDIDATES] = {0};

    int userChoice;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add Candidate\n");
        printf("2. Add Voter\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);

        switch (userChoice)
        {
        case 1:
            if (totalCandidates < MAX_CANDIDATES)
            {
                printf("Enter candidate's full name: ");
                scanf("%s", candidates[totalCandidates].fullName);
                candidates[totalCandidates].votesReceived = 0;
                totalCandidates++;
                printf("Candidate added successfully!\n");
            }
            else
            {
                printf("Maximum candidate limit reached.\n");
            }
            break;

        case 2:
            if (totalVoters < MAX_VOTERS)
            {
                printf("Enter voter's full name: ");
                scanf("%s", voters[totalVoters].fullName);
                printf("Enter voter's address: ");
                scanf("%s", voters[totalVoters].address);
                printf("Enter voter's identification: ");
                scanf("%d", &voters[totalVoters].identification);
                voters[totalVoters].hasVoted = 0;
                totalVoters++;
                printf("Voter added successfully!\n");
            }
            else
            {
                printf("Maximum voter limit reached.\n");
            }
            break;

        case 3:
            clearConsole();
            if (totalCandidates > 0 && totalVoters > 0)
            {
                printf("Enter voter's full name: ");
                char voterFullName[50];
                scanf("%s", voterFullName);

                int candidateChoice = 0;
                int voterIndex = -1;

                for (int i = 0; i < totalVoters; i++)
                {
                    if (strcmp(voters[i].fullName, voterFullName) == 0)
                    {
                        voterIndex = i;
                        break;
                    }
                }

                if (voterIndex != -1 && !voters[voterIndex].hasVoted)
                {
                    displayCandidates(candidates, totalCandidates);
                    printf("Choose a candidate (1-%d) or enter 0 for NOTA: ", totalCandidates);
                    scanf("%d", &candidateChoice);

                    if (candidateChoice >= 0 && candidateChoice <= totalCandidates)
                    {
                        voteCount[candidateChoice - 1]++;
                        candidates[candidateChoice - 1].votesReceived++;
                        voters[voterIndex].hasVoted = 1;
                        printf("Vote cast successfully!\n");
                    }
                    else
                    {
                        printf("Invalid candidate choice.\n");
                    }
                }
                else
                {
                    printf("Invalid voter name or voter has already voted.\n");
                }
            }
            else
            {
                printf("No candidates or voters available.\n");
            }
            break;

        case 4:
            clearConsole();
            printf("Election Results:\n");
            int maxVotes = -1;
            for (int i = 0; i < totalCandidates; i++)
            {
                if (candidates[i].votesReceived > maxVotes)
                {
                    maxVotes = candidates[i].votesReceived;
                }
            }

            if (maxVotes > 0)
            {
                printf("Candidates with maximum votes:\n");
                for (int i = 0; i < totalCandidates; i++)
                {
                    if (candidates[i].votesReceived == maxVotes)
                    {
                        printf("%s\n", candidates[i].fullName);
                    }
                }
            }
            else
            {
                printf("No votes were cast.\n");
            }

            printf("\n");
            break;

        case 5:
            printf("Exiting the program.\n");
            exit(0);
            break;

        default:
            printf("Invalid choice. Please select a valid option.\n");
            break;
        }
    }

         return 0;
}