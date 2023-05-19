#include <stdio.h>

int main() {

    int num, final = 0, digit_count = 0;
    printf("Enter a (3-5) digit integer: ");
    scanf("%d", &num);

    // Count number of digits in the input number
    int temp = num;
    while (temp != 0) {
        digit_count++;
        temp /= 10;
    }

    // Check if number of digits is valid
    if (digit_count < 3 || digit_count > 5) {
        printf("Invalid input.\n");
        return 1;
    }

    // Reverse the digits of the input number
    while (num != 0) {
        final = final * 10 + num % 10;
        num /= 10;
    }

    printf("Reversed number: %d\n", final);
    return 0;
}
