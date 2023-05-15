//Лабораторная работа 6
//Создать текстовый файл с записями следующего вида :
//Иванов Петр Сергеевич 1975
//Сидоров Николай Андреевич 1981
//….
//Воробьянинов Ипполит Матвеевич 1978
//
//Прочитать данные из этого файла и записать в другой только те строки, которые относятся к родившимся позднее 1980 года.

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
    
    system("close");
    return 0;
}