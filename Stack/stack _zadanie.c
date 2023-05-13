#include <stdio.h>
#include <assert.h>
#define N 8

typedef int Data;
typedef struct {
    Data a[N]; // данные
    unsigned int n; // сколько элементов хранится в стеке
} Stack;

void print(Stack* st)
{
    for (unsigned int i = 0; i < st->n; i++)
        printf("%d ", st->a[i]);
    printf("\n");
}

void init(Stack* st) {
    st->n = 0;
}

void push(Stack* st, Data data)
{
    st->a[st->n] = data;
    st->n++;
}

Data pop(Stack* st)
{
    Data res = st->a[st->n - 1];
    st->n--;
    return res;
}

int is_empty(Stack* st) {
    return st->n == 0;
}

int is_full(Stack* st) {
    return st->n == sizeof(st->a) / sizeof(st->a[0]);
}

int main()
{
    Data test[N] = { 5, 17, -3, 0, 1, 2, 3, 4 };
    


    Stack stack;            // создаем стек
    Stack* st = &stack;    // указатель на созданный стек

    init(st);
    printf("empty: %s\n", is_empty(st) ? "YES" : "NO"); // YES
    printf("full: %s\n", is_full(st) ? "YES" : "NO");   // NO
    print(st);              // ничего не печатается

    Data d;
    for (int i = 0; i < N; i++) {
        d = test[i];
        printf("push %d :", d);
        push(st, d);
        print(st);  // 5
        printf("empty: %s\n", is_empty(st) ? "YES" : "NO"); // NO
    }

    printf("full: %s\n", is_full(st) ? "YES" : "NO");   // YES

    while (!is_empty(st)) {
        d = pop(st);
        printf("pop %d: ", d);
        print(st);
    }

    printf("empty: %s\n", is_empty(st) ? "YES" : "NO"); // YES

    assert(sizeof(test) == sizeof(st->a));

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
