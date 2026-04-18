#include <stdio.h>

int main() {
    int total_memory, process, i;
    int memory_required;

    printf("Enter total memory available (in KB): ");
    scanf("%d", &total_memory);

    printf("Enter number of processes: ");
    scanf("%d", &process);

    for(i = 1; i <= process; i++) {
        printf("\nEnter memory required for process %d: ", i);
        scanf("%d", &memory_required);

        if(memory_required <= total_memory) {
            printf("Process %d is allocated memory.\n", i);
            total_memory = total_memory - memory_required;
            printf("Remaining memory: %d KB\n", total_memory);
        } else {
            printf("Process %d cannot be allocated memory (Not enough memory).\n", i);
        }
    }

    return 0;
}