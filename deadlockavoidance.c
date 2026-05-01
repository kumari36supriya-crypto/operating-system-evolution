#include <stdio.h>

#define P 5  // Number of processes
#define R 3  // Number of resources

int main() {
    int i, j, k;

    int allocation[P][R] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    int max[P][R] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    int available[R] = {3, 3, 2};

    int need[P][R];
    int finish[P] = {0};
    int safeSeq[P];

    // Calculate Need matrix
    for (i = 0; i < P; i++) {
        for (j = 0; j < R; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int count = 0;

    while (count < P) {
        int found = 0;
        for (i = 0; i < P; i++) {
            if (finish[i] == 0) {
                for (j = 0; j < R; j++) {
                    if (need[i][j] > available[j])
                        break;
                }

                if (j == R) {
                    for (k = 0; k < R; k++) {
                        available[k] += allocation[i][k];
                    }

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0) {
            printf("System is NOT in safe state (Deadlock possible)\n");
            return 0;
        }
    }

    printf("System is in SAFE state\nSafe sequence: ");
    for (i = 0; i < P; i++) {
        printf("P%d ", safeSeq[i]);
    }
    printf("\n");

    return 0;
}