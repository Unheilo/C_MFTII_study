#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    FILE *f, *f_new;
    char str[MAX_LEN];
    char *name, *surname, *patronymic;
    int year;

    f = fopen("names.txt", "r");
    f_new = fopen("names_new.txt", "w");

    if (!f) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(str, MAX_LEN, f)) {
        surname = strtok(str, " ");
        name = strtok(NULL, " ");
        patronymic = strtok(NULL, " ");
        year = atoi(strtok(NULL, " "));

        if (year > 1980) {
            fprintf(f_new, "%s %s %s %d\n", surname, name, patronymic, year);
        }
    }

    fclose(f);
    fclose(f_new);

    return 0;
}