#include <stdio.h>

int main() {
    int pages[] = {1, 3, 0, 3, 5, 6, 3};
    int n = 7, frames = 3;
    int frame[3], i, j, k, flag, faults = 0;

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    int index = 0;

    for(i = 0; i < n; i++) {
        flag = 0;

        for(j = 0; j < frames; j++) {
            if(frame[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            frame[index] = pages[i];
            index = (index + 1) % frames;
            faults++;
        }
    }

    printf("FIFO Page Faults = %d\n", faults);
    return 0;
}