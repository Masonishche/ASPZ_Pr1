#include <stdio.h>
#include <stdint.h>

// Function to print binary representation of a byte
void printBinary(uint8_t num) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

// Function to invert bits in a given range
void invertBits(uint8_t x, uint8_t *y, int start, int end) {
    *y = x; // Initialize y with x
    for (int i = start; i <= end; i++) {
        *y ^= (1 << i); // Invert bit at position i
    }
}

int main() {
    uint8_t x = 0xAA; // Example input: 10101010 in binary
    uint8_t y;
    int start, end;

    // Print original value
    printf("Original x = ");
    printBinary(x);
    printf(" (decimal: %d)\n", x);

    // Invert all bits (default range 0 to 7)
    invertBits(x, &y, 0, 7);
    printf("Inverted all bits y = ");
    printBinary(y);
    printf(" (decimal: %d)\n", y);

    // Get range from user for partial inversion
    printf("Enter start bit position (0-7): ");
    scanf("%d", &start);
    printf("Enter end bit position (0-7): ");
    scanf("%d", &end);

    // Validate range
    if (start < 0 || end > 7 || start > end) {
        printf("Invalid range! Use 0-7 with start <= end.\n");
        return 1;
    }

    // Invert bits in the specified range
    invertBits(x, &y, start, end);
    printf("Inverted bits from %d to %d, y = ", start, end);
    printBinary(y);
    printf(" (decimal: %d)\n", y);

    return 0;
}
