#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct {
    char firstname[MAX_NAME_LEN];
    char lastname[MAX_NAME_LEN];
    int birth_year;
    char gender;
    float height;
} person;

int compare(const void* a, const void* b, int* fields, int num_fields) {
  person person_a = *(person*)a;
  person person_b = *(person*)b;
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

void print_person(person p) {
  printf("%s %s, %d, %c, %.2f\n", p.firstname, p.lastname, p.birth_year, p.gender, p.height);
}

int main() {
  int num_fields;
  int fields[4];

  printf("Введите количество полей для сортировки (от 1 до 4): ");
  scanf("%d", &num_fields);
  if (num_fields <= 0 || num_fields > 4) {
    printf("Ошибка ввода!\n");
    return 1;
  }

  printf("Выберите поля для сортировки (введите от 0 до 3):\n");
  printf("0 - Год рождения\n");
  printf("1 - Имя и фамилия\n");
  printf("2 - Пол\n");
  printf("3 - Рост\n");
  for (int i = 0; i < num_fields; i++) {
    printf("Введите поле %d: ", i+1);
    scanf("%d", fields+i);
    if (fields[i] < 0 || fields[i] > 3) {
      printf("Ошибка ввода!\n");
      return 1;
    }
  }

  FILE* f = fopen("persons.txt", "r");
  if (!f) {
    printf("Ошибка чтения файла!\n");
    return 1;
  }

  // считываем количество элементов в файле
  int num_persons = 0;
  char line[MAX_NAME_LEN*2 + 17];
  while (fgets(line, MAX_NAME_LEN*2+17, f) != NULL) num_persons++;

  // выделяем память под элементы
  person* persons = malloc(num_persons * sizeof(person));
  if (!persons) {
    printf("Ошибка выделения памяти!\n");
    return 1;
  }

  // переводим курсор на начало файла
  rewind(f);

  // считываем данные из файла в массив 
  for (int i = 0; i < num_persons; i++) {
    fscanf(f, "%s %s %d %c %f\n", persons[i].firstname, persons[i].lastname, &persons[i].birth_year, &persons[i].gender, &persons[i].height);
  }

  fclose(f);

  // сортируем данные
  qsort(persons, num_persons, sizeof(person), 
        (int (*) (const void *, const void *)) 
             compare, fields, num_fields);

  // печатаем упорядоченные записи
  printf("%s %s, %s, %s\n", 
     "Имя", "Фамилия", "Год рождения", "Пол", "Рост");
  for (int i = 0; i < num_persons; i++) {
    print_person(persons[i]);
  }
  free(persons);
  return 0;
}