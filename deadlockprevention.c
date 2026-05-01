#include <stdio.h>

int main() {
    int resourceA = 1, resourceB = 1;

    // Process wants both resources together
    if (resourceA && resourceB) {
        resourceA = 0;
        resourceB = 0;

        printf("Process got both resources\n");

        // Release after use
        resourceA = 1;
        resourceB = 1;
    } else {
        printf("Wait until all resources available\n");
    }

    return 0;
}