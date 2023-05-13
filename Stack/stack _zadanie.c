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

//void stack_init(Stack* s); -необходимые действия для создания и инициализации стека. (Когда мы создаем локальную переменную, то она не инициализируется 0, т.е.в поле n может лежать любое число.)

//void stack_init(Stack* s) 
//{
//    s->n == 0;
//}
//
//void stack_push(Stack* s, Data x)
//{
//    s->a[s->n] = x;
//    s->n++;
//
//}
//
//Data stack_pop(Stack* s)
//{
//    Data res = s->a[s->n - 1];
//    s->n--;
//    return res;
//}
//
//Data stack_get(Stack* s)
//{
//    Data res = s->a[s->n - 1];
//    return res;
//}
//
//void stack_clear(Stack* s)
//{
//    while(s->n != 0)    {
//        s->n--;
//    }
//}
//
//void stack_print(Stack* s)
//{
//    for (unsigned int i = 0; i < s->n; i++)
//        printf("%d ", s->a[i]);
//    printf("\n");
//}
//
//int stack_size(Stack* s) {
//    return s->n * sizeof(s->a[0]);
//}
//
//int stack_is_empty(Stack* s) {
//    return s->n == 0;
//}
//
//int stack_is_full(Stack* s) {
//    return s->n == sizeof(s->a) / sizeof(s->a[0]);
//}

void stack_init(Stack* s) {
    s->n = 0;
}

void stack_push(Stack* s, Data x) {
    if (stack_is_full(s)) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->a[s->n++] = x;
}

Data stack_pop(Stack* s) {
    if (stack_is_empty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->a[--s->n];
}

Data stack_get(Stack* s) {
    if (stack_is_empty(s)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->a[s->n - 1];
}

void stack_clear(Stack* s) {
    s->n = 0;
}

void stack_print(Stack* s) {
    for (int i = 0; i < s->n; i++) {
        printf("%d ", s->a[i]);
    }
    printf("\n");
}

int stack_size(Stack* s) {
    return s->n;
}

int stack_is_empty(Stack* s) {
    return s->n == 0;
}

int stack_is_full(Stack* s) {
    return s->n == N;
}






//void stack_push(Stack * s, Data x); -кладет число х в стек;
//Data stack_pop(Stack* s); -достает одно число из стека и возвращает его
//Data stack_get(Stack * s); -возвращает число, лежащее на верхушке стека, не изменяя состояния стека;
//void stack_clear(Stack* s); -очищает стек(функция stack_is_empty должна вернуть 1).
//void stack_print(Stack * s); -распечатывает через пробел числа, лежащие в стеке.С самого первого до верхнего.В конце переводит строку.
//int stack_size(Stack* s); -возвращает количество элементов, лежащих в стеке
//int stack_is_empty(Stack* s); -возвращает 1 если стек пуст, иначе возвращает 0.
//int stack_is_full(Stack * s); -возвращает 1 если стек полон(в него нельзя добавлять данные, это приведет к переполнению), иначе возвращает 0.

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
