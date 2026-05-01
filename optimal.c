#include <stdio.h>

int main() {
    int pages[] = {1, 3, 0, 3, 5, 6, 3};
    int n = 7, frames = 3;
    int frame[3];
    int i, j, k, faults = 0, flag;

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    for(i = 0; i < n; i++) {
        flag = 0;

        for(j = 0; j < frames; j++) {
            if(frame[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            int pos = -1, farthest = i + 1;

            for(j = 0; j < frames; j++) {
                int k;
                for(k = i + 1; k < n; k++) {
                    if(frame[j] == pages[k]) {
                        if(k > farthest) {
                            farthest = k;
                            pos = j;
                        }
                        break;
                    }
                }

                if(k == n) {
                    pos = j;
                    break;
                }
            }

            if(pos == -1)
                pos = 0;

            frame[pos] = pages[i];
            faults++;
        }
    }

    printf("Optimal Page Faults = %d\n", faults);
    return 0;
}