#include <stdio.h>
#include <string.h>

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
        double probability = (double)matchedPins / totalPins;
        printf("Probability of finding PIN %s: %.10f\n", pin, probability);
    }

    return 0;
}
