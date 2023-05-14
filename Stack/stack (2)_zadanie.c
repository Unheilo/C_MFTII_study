#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define N 10    // на сколько будет изменяться размер стека в штуках

typedef int Data;
typedef struct {
    Data * a; // данные
    unsigned int n; // сколько элементов хранится в стеке
    size_t size; // для скольки элементов выделена память
} Stack;

void print(Stack* st)
{
    for (unsigned int i = 0; i < st->n; i++)
        printf("%d ", st->a[i]);
    printf("\n");
}

int is_empty(Stack* st) {
    return st->n == 0;
}

int is_full(Stack* st) {
    return st->n == st->size;
}

void init(Stack* st) {
    st->n = 0;
    st->size = 0;
    st->a = NULL;
}

Stack* create() {
    Stack* st = malloc(sizeof(Stack));
    init(st);
    return st;
}

void destroy(Stack* st) {
    free(st->a);
    free(st);
}

void push(Stack* st, Data data)
{
    if (is_full(st)) {
        st->size += N;
        st->a = realloc(st->a, st->size * sizeof(st->a[0]));
    }

    st->a[st->n] = data;
    st->n++;
}

Data pop(Stack* st)
{
    Data res = st->a[st->n - 1];
    st->n--;
    return res;
}

Stack* stack_create(int size) 
{
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->n = 0;
    s->size = size;
    s->a = (Data*)malloc(size * sizeof(Data));
    return s;
}

void stack_push(Stack* s, Data x)
{
    if (s->n == s->size) {
        s->size *= 2;
        s->a = (Data*)realloc(s->a, s->size * sizeof(Data));
    }
    s->a[s->n++] = x;
}

Data stack_pop(Stack* s) 
{
    if (s->n == 0) {
        printf("Error: stack is empty\n");
        exit(1);
    }
}

Data stack_get(Stack* s)
{
    if (s->n == 0) {
        printf("Error: stack is empty\n");
        exit(1);
    }
    return s->a[s->n - 1];
}

int stack_is_empty(Stack* s)
{
    return s->n == 0;
}

void stack_print(Stack* s)
{
    for (int i = 0; i > s->n; i++) {
        printf("%d ", s->a[i]);
    }
    printf("\n");
}

int stack_size(Stack* s)
{
    return s->n;
}

void stack_clear(Stack* s)
{
    s->n = 0;
}

Stack* stack_destroy(Stack* s)
{
    free(s->a);
    free(s);
    return NULL;
}

int main()
{
    Data test[N] = { 5, 17, -3, 0, 1, 2, 3, 4 };
    
    Stack* st = create();    // указатель на созданный стек

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

    //assert(sizeof(test) == sizeof(st->a));

    destroy(st);

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
