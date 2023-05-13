#include <stdio.h>
#define N 8

typedef int Data;
typedef struct {
    Data a[N]; // данные
    unsigned int n; // сколько элементов хранится в стеке
} Stack;

void print(Stack * st)
{
    for (unsigned int i = 0; i < st->n; i++)
        printf("%d ", st->a[i]);
    printf("\n");
}

void init(Stack * st) {
    st->n = 0;
}

void push(Stack * st, Data data)
{
    st->a[st->n] = data;
    st->n ++;
}

Data pop(Stack * st)
{
    Data res = st->a[st->n - 1];
    st->n --;
    return res;
}

int is_empty(Stack * st) {
    return st->n == 0;
}

int is_full(Stack * st) {
    return st->n == sizeof(st->a) / sizeof(st->a[0]);
}

int main()
{
    Stack stack;            // создаем стек
    Stack * st = &stack;    // указатель на созданный стек

    init(st);
    printf("empty: %s\n", is_empty(st) ? "YES" : "NO"); // YES
    printf("full: %s\n", is_full(st) ? "YES" : "NO");   // NO
    print(st);              // ничего не печатается

    // тесты для push
    push(st, 5);
    print(st);      // 5
    push(st, 17);
    print(st);      // 5 17
    push(st, -3);
    print(st);      // 5 17 -3

    printf("empty: %s\n", is_empty(st) ? "YES" : "NO"); // NO
    printf("full: %s\n", is_full(st) ? "YES" : "NO");   // YES

    // тесты для pop
    Data d;
    d = pop(st);    // pop -3: 5 17
    printf("pop %d: ", d);
    print(st);

    d = pop(st);    // pop 17: 5
    printf("pop %d: ", d);
    print(st);

    d = pop(st);    // pop 5:
    printf("pop %d: ", d);
    print(st);

    printf("empty: %s\n", is_empty(st) ? "YES" : "NO"); // YES
    printf("full: %s\n", is_full(st) ? "YES" : "NO");   // NO

    return 0;
    
}

//typedef int Data;
//typedef struct {
//    Data a[N]; // храним данные в системе
//    int n; // сколько данных в стеке
//} Stack;
//
//Stack st;   push(&st, 5)
//
//void push(Stack * s, Data x);
//Data pop(Stack *s); // top
//void init(Stack *s);
//void print(Stack *s);
//int is_empty(Stack *s); // int is_full(Stack *s)
