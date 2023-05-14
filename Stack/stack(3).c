#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100000

typedef struct {
	char* data;
	int top;
} Stack;

void init(Stack* s) {
	s->data = (char*)malloc(MAX_STACK_SIZE * sizeof(char));
	s->top = -1;
}

void push(Stack* s, char c) {
	s->top++;
	s->data[s->top] = c;
}

char pop(Stack* s) {
	char c = s->data[s->top];
	s->top--;
	return c;
}

int is_empty(Stack* s) {
	return s->top == -1;
}

int is_full(Stack* s) {
	return s->top == MAX_STACK_SIZE - 1;
}

void destroy(Stack* s) {
	free(s->data);
}

int is_pair(char open, char close) {
	return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}') || (open == '<' && close == '>');
}

int is_balanced(char* str) {
	Stack s;
	init(&s);


	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{' || str[i] == '<') {
			push(&s, str[i]);
		}
		else if (str[i] == ')' || str[i] == ']' || str[i] == '}' || str[i] == '>') {
			if (is_empty(&s) || !is_pair(pop(&s), str[i])) {
				destroy(&s);
				return 0;
			}
		}

		int result = is_empty(&s);
		destroy(&s);
		return result;
	}
}

int main() {
		char str[MAX_STACK_SIZE];
		scanf("%s", str);

		if (is_balanced(str)) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}

		return 0;
}

//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>
//#define N 10    // на сколько будет изменяться размер стека в штуках
//
//typedef int Data;
//typedef struct {
//    unsigned int n; // сколько элементов хранится в стеке
//    size_t size; // для скольки элементов выделена память
//    Data* a; // данные
//} Stack;
//
//void print(Stack* st)
//{
//    for (unsigned int i = 0; i < st->n; i++)
//        printf("%d ", st->a[i]);
//    printf("\n");
//}
//
//int is_empty(Stack* st) {
//    return st->n == 0;
//}
//
//int is_full(Stack* st) {
//    return st->n == st->size;
//}
//
//Stack* create() {
//    Stack* st = malloc(sizeof(Stack));
//    st->size = N;
//    st->n = 0;
//    st->a = malloc(N * sizeof(Data));
//    return st;
//}
//
//void destroy(Stack* st) {
//    free(st->a);
//    free(st);
//}
//
//void push(Stack** pst, Data data)
//{
//    Stack* st = *pst;
//    if (is_full(st)) {
//        st->size += N;
//        st->a = realloc(st->a, st->size * sizeof(Data));
//    }
//
//    st->a[st->n] = data;
//    st->n++;
//}
//
//Data pop(Stack* st)
//{
//    Data res = st->a[st->n - 1];
//    st->n--;
//    return res;
//}
//
//int main()
//{
//    Data test[N] = { 5, 17, -3, 0, 1, 2, 3, 4 };
//
//    Stack* st = create();    // указатель на созданный стек
//
//    printf("empty: %s\n", is_empty(st) ? "YES" : "NO"); // YES
//    printf("full: %s\n", is_full(st) ? "YES" : "NO");   // NO
//    print(st);              // ничего не печатается
//
//    Data d;
//    for (int i = 0; i < N; i++) {
//        d = test[i];
//        printf("push %d :", d);
//        push(&st, d);
//        print(st);  // 5
//        printf("empty: %s\n", is_empty(st) ? "YES" : "NO"); // NO
//    }
//
//    printf("full: %s\n", is_full(st) ? "YES" : "NO");   // YES
//
//    while (!is_empty(st)) {
//        d = pop(st);
//        printf("pop %d: ", d);
//        print(st);
//    }
//
//    printf("empty: %s\n", is_empty(st) ? "YES" : "NO"); // YES
//
//    //assert(sizeof(test) == sizeof(st->a));
//
//    destroy(st);
//
//    return 0;
//}

///


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
