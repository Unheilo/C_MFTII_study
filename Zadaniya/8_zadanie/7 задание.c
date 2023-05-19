//Ћабораторна€ работа 7
//ќбъ€вить тип - структуру humen, включающую им€ человека, фамилию и год рождени€.ќбъ€вить два массива из четырЄх элементов типа humen.
//¬вести с консоли или из файла элементы одного массива и построить на их основе другой, упор€дочив элементы по годам рождени€.¬ывести результат.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20

typedef struct {
    char firstname[MAX_NAME_LEN];
    char secondname[MAX_NAME_LEN];
    int birth_year;
} human;

int compare_years(const void* a, const void* b) {
    return (*(human*)a).birth_year - (*(human*)b).birth_year;
}

int main() {
    human arr1[4], arr2[4];
    FILE *f;
    f = fopen("data.txt", "r");

    if (f == NULL) {
        printf("Cannot open file \n");
        return 0;
    }

    for (int i = 0; i < 4; i++) {
        fscanf(f, "%s %s %d", arr1[i].firstname, arr1[i].secondname, &arr1[i].birth_year);
    }

    qsort(arr1, 4, sizeof(human), compare_years);

    for (int i = 0; i < 4; i++) {
        printf("%s %s - %d \n", arr1[i].firstname, arr1[i].secondname, arr1[i].birth_year);
    }

    system("pause");
    return 0;
}