#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct Node
{
	Data data;
	struct Node* next;
	struct Node* prev;
} Node;

void print(Node* list) {
	for (Node* p = list->next; p != list; p = p->next) {
		printf("%d ", p->data);
	}
	printf("\n");
}

void print_dbg(Node* list) {
	Node* p = list;
	printf("-------\n");
	printf("list: prey=%p %p next=%p\n", p->prev, p, p->next);
	for (Node* p = list->next; p != list; p = p->next) {
		printf("%d prey=%p %p next=%p\n", p->data, p->prev, p, p->next);
	}
	printf("\n");
}

void print_back(Node* list) {
	for (Node* p = list->prev; p != list; p = p->prev) {
		printf("%d ", p->data);
	}
	printf("\n");
}

void insert(Node* p, Node* t) {
	Node* q = p->next;
	t->prev = p;	// 1
	t->next = q;	// 2
	p->next = t;	// 3
	q->prev = t;	// 4
}

void insert_before(Node* q, Node* t) {
	insert(q->prev, t);
}

void list_remove(Node* t) {
	Node* p = t->prev;
	Node* q = t->next;
	p->next = q;
	q->prev = p;
}

void init(Node* list) {
	list->next = list;
	list->prev = list;
}

int is_empty(Node* list) {
	return list->prev == list && list->next == list;
}

void test() {
	Node z, a, b, c, u, w;
	Node* list = &z;
	z.data = 0;
	a.data = 3;
	b.data = 17;
	c.data = 21;
	u.data = 10;
	w.data = 8;

	init(list);
	printf("Empty %s\n", is_empty(list) ? "YES" : "NO");
	insert(list, &c);
	print(list);		// 21
	printf("Empty %s\n", is_empty(list) ? "YES" : "NO");

	insert(list, &b);
	print(list);		// 17 21

	insert(list, &a);
	print(list);		// 3 17 21

	print(list);		// 3 17 21
	print_back(list);	// 21 17 3
	print_dbg(list);	// 3 17 21
	
	insert(&a, &u);
	print(list);		// 3 10 17 21
	print_back(list);	// 21 17 10 3

	insert_before(&u, &w);
	print(list);		// 3 8 10 17 21
	print_back(list);	// 21 17 10 8 3

	list_remove(&u);
	print(list);		// 3 8 17 21
	print_back(list);	// 21 17 8 3

	list_remove(&w);
	print(list);		// 3  17 21
	print_back(list);	// 21 17  3

}

Node* push_front(Node* list, Data d) {
	Node* p = malloc(sizeof(Node));
	p->data = d;
	insert(list, p);
	return p;
}

Node* push_back(Node* list, Data d) {
	return push_front(list->prev, d);
}

Data list_delete(Node* t) {
	list_remove(t);
	Data d = t->data;
	free(t);
	return d;
}

Data pop_front(Node* list) {
	return list_delete(list->next);
}

Data pop_back(Node* list) {
	return list_delete(list->prev);
}

void clear(Node* list) {
	while (!is_empty(list))
		pop_front(list);
}

void test_alloc() {
	Node z;
	Node* list = &z;

	Data test_data1[] = { 21, 17, 3 };
	Data test_data2[] = { 10, 8 };

	init(list);
	printf("Empty %s\n", is_empty(list) ? "YES" : "NO");

	Node* t;
	for (size_t i = 0; i < sizeof(test_data1) / sizeof(test_data1[0]); i++) {
		t = push_front(list, test_data1[i]);
		print(list);
		printf("pushed: %d\n", t->data);
	}
	// 3 17 21
	for (size_t i = 0; i < sizeof(test_data2) / sizeof(test_data2[0]); i++) {
		t = push_back(list, test_data2[i]);
		print(list);
		printf("pushed_back: %d\n", t->data);
	}
	// 3 17 21 10 8
	printf("Empty %s\n", is_empty(list) ? "YES" : "NO");

	t = list->next->next; //17
	Data res;

	res = list_delete(t);
	print(list);		// 3 21 10 8
	printf("deleted: %d\n", res);

	res = pop_front(list);
	print(list);		// 21 10 8
	printf("pop front: %d\n", res);	// 3

	res = pop_back(list);
	print(list);		// 21 10 
	printf("pop back: %d\n", res);	// 8

	clear(list);

	printf("Empty %s\n", is_empty(list) ? "YES" : "NO");

}

void print_it(Data d, void * arg) {
	fprintf((FILE*)arg,"%d ", d);
}

void sum_all(Node* list, Data * res) {
	*res = 0;
	for (Node* p = list->next; p != list; p = p->next) {
		res = res + p->data;
	}
	return res;
}

void sum_it(Data d, void* a) {
	Data* res = (Data*)a;
	*res = *res + d;
}

void foreach(Node* list, void (*func)(Data d, void * a), void * arg) {
	for (Node* p = list->next; p != list; p = p->next) {
		func(p->data, arg);
	}

}
void print1(Node* list, FILE * fout) {
	foreach(list, print_it, fout);
	fprintf(fout, "\n");

}

void test_foreach() {
	Node z;
	Node* list = &z;

	Data test_data1[] = { 8, 10, 21, 17, 3 };

	init(list);
	for (size_t i = 0; i < sizeof(test_data1) / sizeof(test_data1[0]); i++)
		push_front(list, test_data1[i]);
	print(list); // 3 17 21 10 8
	printf("to stdout\n");
	print1(list, stdout); // 3 17 21 10 8
	printf("to stderr\n");
	print1(list, stderr); // 3 17 21 10 8

	Data sum = 0;
	foreach(list, sum_it, &sum); 
	printf("sum is %d\n", sum);	// 59
	clear(list);

}

int main() {
	printf("---test------------------------------\n");
	test();
	printf("---test_alloc------------------------\n");
	test_alloc();
	printf("---test_foreach----------------------\n");
	test_foreach();
	return 0;
}