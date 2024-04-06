#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 5
#define MAX_DIGIT_VALUE 9
#define MIN_DIGIT_VALUE 0

int main() {
    char pin[6]; // 5 digits + '\0'
    printf("Enter PIN to test: ");
    scanf("%5s", pin);

    FILE *file = fopen("generated_passwords.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Calculate total combinations
    int totalCombinations = 1;
    for (int i = 0; i < MAX_DIGITS; i++) {
        totalCombinations *= (MAX_DIGIT_VALUE - MIN_DIGIT_VALUE + 1);
    }

    int position = 0;
    int found = 0;
    char buffer[6];
    while (fscanf(file, "%5s", buffer) != EOF && !found) {
        position++;
        if (strcmp(buffer, pin) == 0) {
            found = 1; // Stop searching after the first match
        }
    }
    fclose(file);

    if (!found) {
        printf("PIN not found in the file.\n");
    } else {
        double probability = (double)(totalCombinations - position) / totalCombinations;
        printf("Position: %d\n", position);
        printf("Probability of finding PIN %s based on its position: %.10f\n", pin, probability);
    }

    return 0;
}