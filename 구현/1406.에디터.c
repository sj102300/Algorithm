//[실버2] 1406.에디터 https://www.acmicpc.net/problem/1406
//이중 연결 리스트 이용, 큐 구현

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[100002];

typedef struct _node {
	struct _node* prev;
	struct _node* next;
	char data;
}Node;

typedef struct _queue {
	Node* head;
	Node* tail;
	Node* cursor;
}Queue;

Node* create_node(char data) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->prev = NULL;
	tmp->next = NULL;
	tmp->data = data;
	return tmp;
}

void goNext(Queue* q) {
	if (q->cursor == q->tail)
		return;
	q->cursor = q->cursor->next;
	return;
}

void goPrev(Queue* q) {
	if (q->cursor->prev == q->head)
		return;
	q->cursor = q->cursor->prev;
	return;
}

void deletePrev(Queue* q) {
	if (q->cursor->prev == q->head)
		return;
	Node* target = q->cursor->prev;
	target->prev->next = q->cursor;
	q->cursor->prev = target->prev;
	free(target);
	return;
}

void appendPrev(Queue* q, Node* newnode) {
	newnode->next = q->cursor;
	newnode->prev = q->cursor->prev;
	q->cursor->prev->next = newnode;
	q->cursor->prev = newnode;
	return;
}

Queue* makeQueue() {
	Queue* tmp = (Queue*)malloc(sizeof(Queue));
	tmp->head = create_node(0);
	tmp->tail = create_node(0);
	tmp->head->next = tmp->tail;
	tmp->tail->prev = tmp->head;
	tmp->cursor = tmp->tail;
	return tmp;
}

void printQueue(Queue* q) {
	for (Node* cur = q->head->next; cur != q->tail; cur = cur->next) {
		printf("%c", cur->data);
	}
}

int main(void) {
	int opNum;
	char op;
	char ch;

	Queue* q = makeQueue();

	(void)scanf("%s", str);
	(void)getchar();

	for (int i = 0;i < strlen(str);++i) {
		appendPrev(q, create_node(str[i]));
	}

	(void)scanf("%d", &opNum);
	(void)getchar();

	for (int _ = 0;_ < opNum;_++) {
		(void)scanf("%c", &op);
		(void)getchar();

		switch (op) {
		case'L':
			goPrev(q);
			break;
		case'D':
			goNext(q);
			break;
		case'B':
			deletePrev(q);
			break;
		case'P':
			(void)scanf("%c", &ch);
			(void)getchar();
			appendPrev(q, create_node(ch));
			break;
		}
	}

	printQueue(q);
	return 0;

}