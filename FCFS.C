#include <stdio.h>

int main()
{
    int at[20], bt[20], wt[20], tat[20], ct[20], p[20];
    int i, j, n, temp;

    float wtavg = 0, tatavg = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input
    for(i = 0; i < n; i++)
    {
        p[i] = i;  // Process number
        printf("\nProcess %d\n", i);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
    }

    // Sort according to Arrival Time (Bubble Sort)
    for(i = 0; i < n-1; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(at[i] > at[j])
            {
                // Swap Arrival Time
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                // Swap Burst Time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap Process number
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // First Process
    ct[0] = at[0] + bt[0];
    wt[0] = 0;
    tat[0] = ct[0] - at[0];

    wtavg += wt[0];
    tatavg += tat[0];

    // Remaining Processes
    for(i = 1; i < n; i++)
    {
        if(ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];  // CPU Idle
        else
            ct[i] = ct[i-1] + bt[i];

        wt[i] = ct[i] - at[i] - bt[i];
        tat[i] = ct[i] - at[i];

        wtavg += wt[i];
        tatavg += tat[i];
    }

    // Output Table
    printf("\nP\tAT\tBT\tCT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", wtavg/n);
    printf("\nAverage Turnaround Time = %.2f\n", tatavg/n);

    // Gantt Chart
    printf("\nGantt Chart:\n|");
    for(i = 0; i < n; i++)
        printf(" P%d |", p[i]);

    printf("\n%d", at[0]);
    for(i = 0; i < n; i++)
        printf("    %d", ct[i]);

    return 0;
}