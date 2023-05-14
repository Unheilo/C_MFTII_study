#include <stdio.h>

typedef int Data;

typedef struct Node Node;
struct Node {
	Data data;
	Node* next;
};

void print(Node* list) {
	for (Node* p = list; p != NULL; p = p->next) {
		printf("%d ", p->data);
	}
	printf("\n");
}

int main() {
	struct Node* list = NULL;
	Node a = { 3 }, b = { 17 }, c = { 21 }, t = { 10 };
	list = &a;
	a.next = &b;
	b.next = &c;
	c.next = NULL;

	print(list);

	return 0;
}