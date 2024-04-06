#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

// Function to check if a file has .sh extension
int is_sh_file(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if (dot && !strcmp(dot, ".sh"))
        return 1;
    return 0;
}

// Function to delete a file
void delete_file(const char *filename) {
    if (remove(filename) == 0)
        printf("Deleted file: %s\n", filename);
    else
        fprintf(stderr, "Failed to delete file: %s\n", filename);
}

// Function to list files and directories in a directory
void list_files_and_directories(const char *dirname) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_info;

    if ((dir = opendir(dirname)) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            char path[1024];
            snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);

            if (stat(path, &file_info) == 0) {
                printf("%s: ", S_ISDIR(file_info.st_mode) ? "Directory" : "File");
                printf("%s, Size: %ld bytes\n", entry->d_name, (long)file_info.st_size);

                // Delete file if its size is zero or if it's a .sh file
                if (S_ISREG(file_info.st_mode) && (file_info.st_size == 0 || is_sh_file(entry->d_name))) {
                    delete_file(path);
                }
            }
        }
        closedir(dir);
    } else {
        fprintf(stderr, "Failed to open directory: %s\n", dirname);
    }
}

int main() {
    const char *dirname = "summative";
    list_files_and_directories(dirname);
    return 0;
}
