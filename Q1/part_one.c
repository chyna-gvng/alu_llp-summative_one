#include <stdio.h>

void generatePINs(FILE *file) {
    int i, j, k, l, m;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            for (k = 0; k < 10; k++) {
                for (l = 0; l < 10; l++) {
                    for (m = 0; m < 10; m++) {
                        fprintf(file, "%d%d%d%d%d\n", i, j, k, l, m);
                    }
                }
            }
        }
    }
}

int main() {
    FILE *file = fopen("generated_passwords.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    generatePINs(file);
    fclose(file);
    printf("Generated all PINs and saved to generated_passwords.txt\n");
    return 0;
}
