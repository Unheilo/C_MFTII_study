#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define N 4

typedef struct {
    char firstname[MAX_NAME_LEN];
    char lastname[MAX_NAME_LEN];
    int birth_year;
    char gender;
    float height;
} person;

//typedef struct {
//    int* fields;
//    int num_fields;
//} compare_args;

global_fields[N]; // для передачи значений в compare 
int global_num_fields;

int compare(a, b)
const void* a;
const void* b;
{
    int fields[N];

    person person_a = *(person*)a;
    person person_b = *(person*)b;

    int num_fields = global_num_fields;
    for (int i = 0; i < num_fields; i++) {
        fields[i] = global_fields[i];
    }

  /*  printf("Comp. Num_fields: %d\n", num_fields);
    for (int i = 0; i < num_fields; i++) {
        printf("Comp. Fields: %d\n", fields[i]);
    }*/

    int result = 0;

    for (int i = 0; i < num_fields; i++) {

        int field = fields[i];
        switch (field) {
        case 0:
            result = (person_a.birth_year > person_b.birth_year) - (person_a.birth_year < person_b.birth_year);
            break;
        case 1:
            result = strcmp(person_a.firstname, person_b.firstname);
            if (result == 0) result = strcmp(person_a.lastname, person_b.lastname);
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
        printf("Oshibka otkritiya faila %s\n", filename);
        return 1;
    }

    int num_persons = 0;
    char buffer[1024];
    while (fgets(buffer, 1024, fp) != NULL) {
        person p;
        sscanf(buffer, "%s %s %d %c %f", p.firstname, p.lastname, &p.birth_year, &p.gender, &p.height);
        //print_person(p);
        num_persons++;
    }

    //printf("Number of persons in file %s: %d\n", filename, num_persons);

    fclose(fp);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Oshibka otkritiya faila! %s\n", filename);
        return 1;
    }

    person* persons = (person*)malloc(num_persons * sizeof(person));
    if (persons == NULL) {
        printf("Oshibka videleniya pamyati.\n");
        return 1;
    }

    int i;
    for (i = 0; i < num_persons; i++) {
        fscanf(fp, "%s %s %d %c %f\n", persons[i].firstname, persons[i].lastname, &persons[i].birth_year, &persons[i].gender, &persons[i].height);
    }

    int num_fields = 0;
    printf("Vvedite koli4estvo poley dlya sortirovki (1-4): ");
    scanf("%d", &num_fields);

    int* fields = (int*)malloc(num_fields * sizeof(int));
    if (fields == NULL) {
        printf("Oshibka videleniya pamyati.\n");
        return 1;
    }

    printf("Vvedite polya dlya sortirovki(0-data rojdeniya, 1-imya/familiya, 2-pol, 3-rost):\n");
    for (i = 0; i < num_fields; i++) {
        scanf_s("%d", &fields[i]);
        global_fields[i] = fields[i];
    }

    //for (int i = 0; i < num_fields; i++) {
    //    printf("%d : %d ",i, fields[i]);
    //}

    //printf("\n");

    //for (i = 0; i < num_persons; i++) {
    //    print_person(persons[i]);
    //}
    //printf("\n");

    //compare_args args = { fields, num_fields };

    global_num_fields = num_fields;
    qsort(persons, num_persons, sizeof(person), compare);
 
    for (i = 0; i < num_persons; i++) {
        print_person(persons[i]);
    }

    free(persons);
    free(fields);
    fclose(fp);

    system("pause");
    return 0;
}