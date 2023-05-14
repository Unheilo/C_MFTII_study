#include <stdio.h>

typedef int Data;

typedef struct Node Node;

struct Node {
	Data data;
	Node* next;
};

int main() {
	struct Node* list = NULL;
	return 0;
}