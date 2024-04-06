#include <stdio.h>
#include <string.h>
#include <math.h> // Include math.h for sqrt function

int main() {
    char pin[6]; // 5 digits + '\0'
    printf("Enter PIN to test: ");
    scanf("%5s", pin);

    FILE *file = fopen("generated_passwords.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int totalPins = 0;
    int matchedPins = 0;
    char buffer[6];
    while (fscanf(file, "%5s", buffer) != EOF) {
        totalPins++;
        if (strcmp(buffer, pin) == 0) {
            matchedPins++;
        }
    }
    fclose(file);

    if (totalPins == 0) {
        printf("No PINs found in the file.\n");
    } else {
        // Adjusting the probability calculation as per the new requirement
        double adjustedProbability = (double)matchedPins / sqrt(totalPins);
        printf("Adjusted probability of finding PIN %s: %.10f\n", pin, adjustedProbability);
    }

    return 0;
}