#include <stdio.h>

#define NB 5
#define NP 4

void firstFit(int blocks[], int processes[]) {
    int allocation[NP];
    
    for(int i = 0; i < NP; i++)
        allocation[i] = -1;

    for(int i = 0; i < NP; i++) {
        for(int j = 0; j < NB; j++) {
            if(blocks[j] >= processes[i]) {
                allocation[i] = j;
                blocks[j] -= processes[i];
                break;
            }
        }
    }

    printf("\nFirst Fit:\n");
    for(int i = 0; i < NP; i++) {
        if(allocation[i] != -1)
            printf("P%d -> Block %d\n", i+1, allocation[i]+1);
        else
            printf("P%d -> Not Allocated\n", i+1);
    }
}

void bestFit(int blocks[], int processes[]) {
    int allocation[NP];

    for(int i = 0; i < NP; i++)
        allocation[i] = -1;

    for(int i = 0; i < NP; i++) {
        int bestIndex = -1;

        for(int j = 0; j < NB; j++) {
            if(blocks[j] >= processes[i]) {
                if(bestIndex == -1 || blocks[j] < blocks[bestIndex]) {
                    bestIndex = j;
                }
            }
        }

        if(bestIndex != -1) {
            allocation[i] = bestIndex;
            blocks[bestIndex] -= processes[i];
        }
    }

    printf("\nBest Fit:\n");
    for(int i = 0; i < NP; i++) {
        if(allocation[i] != -1)
            printf("P%d -> Block %d\n", i+1, allocation[i]+1);
        else
            printf("P%d -> Not Allocated\n", i+1);
    }
}

void worstFit(int blocks[], int processes[]) {
    int allocation[NP];

    for(int i = 0; i < NP; i++)
        allocation[i] = -1;

    for(int i = 0; i < NP; i++) {
        int worstIndex = -1;

        for(int j = 0; j < NB; j++) {
            if(blocks[j] >= processes[i]) {
                if(worstIndex == -1 || blocks[j] > blocks[worstIndex]) {
                    worstIndex = j;
                }
            }
        }

        if(worstIndex != -1) {
            allocation[i] = worstIndex;
            blocks[worstIndex] -= processes[i];
        }
    }

    printf("\nWorst Fit:\n");
    for(int i = 0; i < NP; i++) {
        if(allocation[i] != -1)
            printf("P%d -> Block %d\n", i+1, allocation[i]+1);
        else
            printf("P%d -> Not Allocated\n", i+1);
    }
}

int main() {
    int blocks[NB] = {100, 500, 200, 300, 600};
    int processes[NP] = {212, 417, 112, 426};

    int b1[NB], b2[NB], b3[NB];

    // Copy original blocks (important)
    for(int i = 0; i < NB; i++) {
        b1[i] = blocks[i];
        b2[i] = blocks[i];
        b3[i] = blocks[i];
    }

    firstFit(b1, processes);
    bestFit(b2, processes);
    worstFit(b3, processes);

    return 0;
}