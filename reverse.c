#include <stdio.h>

int main() {
    int num, reverse = 0, remainder;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num != 0) {
        remainder = num % 10;        // Last digit
        reverse = reverse * 10 + remainder;
        num = num / 10;              // Remove last digit
    }

    printf("Reversed number: %d", reverse);

    return 0;
}
