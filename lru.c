#include <stdio.h>

int main() {
    int pages[] = {1, 3, 0, 3, 5, 6, 3};
    int n = 7, frames = 3;
    int frame[3], time[3];
    int i, j, k, flag, faults = 0, counter = 0;

    for(i = 0; i < frames; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++) {
        flag = 0;

        for(j = 0; j < frames; j++) {
            if(frame[j] == pages[i]) {
                counter++;
                time[j] = counter;
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            int min = time[0], pos = 0;

            for(j = 1; j < frames; j++) {
                if(time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }

            frame[pos] = pages[i];
            counter++;
            time[pos] = counter;
            faults++;
        }
    }

    printf("LRU Page Faults = %d\n", faults);
    return 0;
}