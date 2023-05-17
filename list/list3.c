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

int main()
{
	Node z, a = { 3 }, b = { 17 }, c = { 21 }, u = { 10 };
	Node * list = &z;

	z.data = 0;
	a.data = 3;
	b.data = 17;
	c.data = 21;
	u.data = 10;

	z.next = &a;
	z.prev = &c;
	a.next = &b;
	a.prev = &z;
	b.next = &c;
	b.prev = &a;
	c.next = &z;
	c.prev = &b;

	print(list);		// 3 17 21
	print_back(list);	// 21 17 3
	print_dbg(list);	// 3 17 21

	u.prev = &a;	// 1
	u.next = &b;	// 2
	a.next = &u;	// 3
	b.prev = &u;	// 4
	print(list);
	print_back(list);

	return 0;
}