#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *input_file = fopen("summative/candidates.txt", "r");
    FILE *output_file = NULL;
    FILE *pipe_stream = NULL;

    if (input_file == NULL) {
        fprintf(stderr, "Failed to open input file.\n");
        return 1;
    }

    // Open pipe for redirection
    pipe_stream = popen("cat > unique_candidates.txt", "w");
    if (pipe_stream == NULL) {
        fprintf(stderr, "Failed to open pipe for redirection.\n");
        fclose(input_file);
        return 1;
    }

    char candidate[100][100]; // assuming each candidate's name is less than 100 characters
    int count = 0;

    // Read candidates from file and remove duplicates
    while (fgets(candidate[count], sizeof(candidate[count]), input_file) != NULL) {
        int duplicate = 0;
        candidate[count][strcspn(candidate[count], "\n")] = '\0'; // remove newline character

        // Check for duplicates
        for (int i = 0; i < count; i++) {
            if (strcmp(candidate[count], candidate[i]) == 0) {
                duplicate = 1;
                break;
            }
        }

        // If not a duplicate, write to pipe for redirection
        if (!duplicate) {
            fprintf(pipe_stream, "%s\n", candidate[count]);
            count++;
        }
    }

    fclose(input_file);
    pclose(pipe_stream);

    printf("Unique candidates saved to unique_candidates.txt\n");

    return 0;
}
