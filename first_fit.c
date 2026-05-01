#include <stdio.h>

int main() {
    int blocks[] = {100, 500, 200, 300, 600};
    int processes[] = {212, 417, 112, 426};
    
    int nb = 5, np = 4;
    int allocation[np];

    for(int i = 0; i < np; i++)
        allocation[i] = -1;

    for(int i = 0; i < np; i++) {
        for(int j = 0; j < nb; j++) {
            if(blocks[j] >= processes[i]) {
                allocation[i] = j;
                blocks[j] -= processes[i];
                break;
            }
        }
    }

    printf("\nFirst Fit Allocation:\n");
    for(int i = 0; i < np; i++) {
        if(allocation[i] != -1)
            printf("Process %d -> Block %d\n", i+1, allocation[i]+1);
        else
            printf("Process %d -> Not Allocated\n", i+1);
    }

    return 0;
}