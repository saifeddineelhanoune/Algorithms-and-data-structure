#include <stdio.h>
#include <stdbool.h>

bool isValidCombination(int combination[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (combination[i] >= combination[i + 1]) {
            return false;
        }
    }
    return true;
}

bool hasDuplicate(int combination[], int index) {
    for (int i = 0; i < index; i++) {
        if (combination[i] == combination[index]) {
            return true;
        }
    }
    return false;
}

void displayCombination(int combination[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", combination[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf(" ");
}

void generateCombinations(int combination[], int index, int n, int currentDigit) {
    if (index == n) {
        if (isValidCombination(combination, n)) {
            displayCombination(combination, n);
        }
        return;
    }

    for (int digit = currentDigit; digit <= 9; digit++) {
        combination[index] = digit;
        if (!hasDuplicate(combination, index)) {
            generateCombinations(combination, index + 1, n, digit + 1);
        }
    }
}

void ft_print_combn(int n) {
    if (n <= 0 || n >= 10) {
        printf("Invalid input. n should be between 1 and 9.\n");
        return;
    }
  
    int combination[n];
    generateCombinations(combination, 0, n, 0);
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    ft_print_combn(n);
    return 0;
}
