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



	t = push_front(list, 21);
	print(list); // 21
	printf("pushed: %d\n", t->data);
	printf("Empty %s\n", is_empty(list) ? "YES" : "NO");
}

int main() {
	//test();
	test_alloc();
	return 0;
}