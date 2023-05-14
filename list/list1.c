#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct Node Node;
struct Node {
	Data data;
	Node* next;
};

void print(Node* list);
int is_empty(Node* list);
void push(Node ** plist, Data d);
Data pop(Node** plist);

void print(Node* list) {
	for (Node* p = list; p != NULL; p = p->next) {
		printf("%d ", p->data);
	}
	printf("\n");
}

void push(Node** plist, Data d) {
	Node* p = malloc(sizeof(Node));
	p->data = d;
	p->next = *plist;
	*plist = p;
}

Data pop(Node** plist) {
	Node* p = *plist;
	Data res = p->data;
	*plist = p->next;
	free(p);
	return res;
}

int is_empty(Node* list) {
	return list == NULL;
}

int main() {
	Data test[] = { 21, 17, 3, 10 };
	Node* list = NULL;
	printf("Empty: %s\n", is_empty(list) ? "YES" : "NO");
	for (size_t i = 0; i < sizeof(test) / sizeof(test[0]); i++) {
		push(&list, test[i]);
		print(list);
	}
	printf("Empty: %s\n", is_empty(list) ? "YES" : "NO");

	while (!is_empty(list)) {
		Data d = pop(&list);
		printf("pop %d :", d);
		print(list);
	}
	printf("Empty: %s\n", is_empty(list) ? "YES" : "NO");

	return 0;
}

