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
	for (Node* p = list->next; p != list; p = p->next) {
		printf("%d prey=%p p% next=%p\n", p->data, p->prev, p, p->next);
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
	Node z, a = { 3 }, b = { 17 }, c = { 21 };
	Node * list = &z;
	z.next = &a;
	z.prev = &c;
	a.next = &b;
	a.prev = &z;
	b.next = &c;
	b.prev = &a;
	c.next = &z;
	c.prev = &b;

	print(list);
	print_back(list);
	print_dbg(list);


	return 0;
}