#include "stack.h"
#include "stdlib.h"
#define MAX_CAPACITY 100

//배열을 이용한 stack 구현
/*
char stack[MAX_CAPACITY];
int top = -1;

void push(char ch) {
	if (is_full())
		return;
	top++;
	stack[top] = ch;
}

char pop() {
	char tmp = stack[top];
	top--;
	return tmp;
}

char peek() {
	return stack[top];
}

int is_empty() {
	return top == -1;
}

int is_full() {
	return top == MAX_CAPACITY - 1;
}
*/

//////////////////////////////////


//연결리스트를 통한 stack 구현
//add_first == push, remove_first == pop
struct node {
	char *data;
	struct node *next;
};

typedef struct node Node;

Node *top = NULL;

void push(char *item) {
	Node *p = (Node*)malloc(sizeof(Node));
	p->data = item;
	p->next = top;
	top = p;
}

char *pop() {
	if (is_empty())
		return NULL;
	char *result = top->data;
	top = top->next;
	return result;
}

char peek() {
	if (is_empty())
		return NULL;
	return top->data;
}

int is_empty() {
	return top == NULL;
}