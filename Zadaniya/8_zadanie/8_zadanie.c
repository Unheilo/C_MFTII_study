#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_SORT_FIELDS 4


typedef struct {
    char firstname[MAX_NAME_LEN];
    char lastname[MAX_NAME_LEN];
    int birth_year;
    char gender;
    float height;
} person;

int compare(a, b, fields, num_fields)
const void* a;
const void* b;
int* fields;
int num_fields;
{
    person person_a = *(person*)a;
    person person_b = *(person*)b;
    int result = 0;

    int i;

    printf("fields: ");
    for (i = 0; i < num_fields; i++) {
        int field = fields[i];
        printf("%d ",field);
    }

    printf("\n");

    for (i = 0; i < num_fields; i++) {

        int field = fields[i];
        switch (field) {
        case 0:
            result = (person_a.birth_year > person_b.birth_year) - (person_a.birth_year < person_b.birth_year);
            break;
        case 1:
            result = strcmp(person_a.firstname, person_b.firstname);
            if (result == 0) {
                result = strcmp(person_a.lastname, person_b.lastname);
            }
            break;
        case 2:
            result = person_a.gender - person_b.gender;
            break;
        case 3:
            result = (person_a.height > person_b.height) - (person_a.height < person_b.height);
            break;
        default:
            break;
        }
        if (result != 0) return result;
    }

    return 0;
}

void print_person(p)
person p;
{
    printf("%s %s %d %c %.2f\n", p.firstname, p.lastname, p.birth_year, p.gender, p.height);
}

int main() {

    FILE* fp;
    char filename[] = "persons.txt";
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    int num_persons = 0;
    char buffer[1024];
    while (fgets(buffer, 1024, fp) != NULL) {
        person p;
        sscanf(buffer, "%s %s %d %c %f", p.firstname, p.lastname, &p.birth_year, &p.gender, &p.height);
        print_person(p);
        num_persons++;
    }

    printf("Number of persons in file %s: %d\n", filename, num_persons);

    fclose(fp);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    person* persons = (person*)malloc(num_persons * sizeof(person));
    if (persons == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    int i;
    for (i = 0; i < num_persons; i++) {
        fscanf(fp, "%s %s %d %c %f\n", persons[i].firstname, persons[i].lastname, &persons[i].birth_year, &persons[i].gender, &persons[i].height);
    }

    int num_fields;
    printf("Enter the number of fields to sort by (1-4): ");
    scanf("%d", &num_fields);

    int* fields = (int*)malloc(num_fields * sizeof(int));
    if (fields == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    printf("Enter the fields to sort by (0-birth year, 1-name, 2-gender, 3-height):\n");
    for (i = 0; i < num_fields; i++) {
        scanf_s("%d", &fields[i]);
    }

    for (int i = 0; i < num_fields; i++) {
        printf("%d : %d ",i, fields[i]);
    }

    printf("\n");

    qsort(persons, num_persons, sizeof(person), (void*)compare, fields, num_fields);

    for (i = 0; i < num_persons; i++) {
        print_person(persons[i]);
    }

    free(persons);
    free(fields);

    fclose(fp);

    return 0;
}