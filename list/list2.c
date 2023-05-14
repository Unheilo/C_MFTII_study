#include <stdio.h>

typedef int Data;
struct Node {
	Data val;               // данные, которые хранятся в одном элементе
	struct Node* next;     // указатель на следующий элемент списка
};
typedef struct Node* List;

List list_create() {
	return NULL;
}

void list_push(List* plist, Data x) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->val = x;
	new_node->next = *plist;
	*plist = new_node;
}

Data list_pop(List* plist) {
	if (*plist == NULL) {
		return 0;
	}
	struct Node* temp = *plist;
	Data x = temp->val;
	*plist = temp->next;
	free(temp);
	return x;
}

void list_print(List list) {
	while (list != NULL) {
		printf("%d ", list->val);
		list = list->next;
	}
	printf("\n");
}

int list_size(List list) {
	int size = 0;
	while (list != NULL) {
		size++;
		list = list->next;
	}
	return size;
}

int list_is_empty(List list) {
	return list == NULL;
}

void list_clear(List* plist) {
	while (*plist != NULL) {
		struct Node* temp = *plist;
		*plist = temp->next;
		free(temp);
	}
}
