#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

//�迭 stackADT
/*
#define INIT_CAPACITY 100

void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
Item pop(Stack s);
Item peek(Stack s);
void reallocate(Stack s);

struct stack_type {
	Item *contents; //stack ������ �� �迭
	int top; //contents�� top ����
	int size; //contents�� size
};

static void terminate(const char *message) {//���� ó�� �Լ�
	printf("%s\n", message);
	exit(1);
}

Stack create() { //Stack ��ü ����
	Stack s = (Stack)malloc(sizeof(struct stack_type));

	if (s == NULL)
		terminate("Error in create: stack could not be created");

	s->contents = (Item*)malloc(sizeof(Item) * INIT_CAPACITY);

	if (s->contents == NULL) {
		free(s);
		terminate("Error in create: stack could not be created.");
	}
	s->top = -1;
	s->size = INIT_CAPACITY;

	return s;
}

void destroy(Stack s) { //Stack ��ü ����
	free(s->contents);
	free(s);
}

void make_empty(Stack s) { //Stack �ʱ�ȭ
	s->top = -1;
}

bool is_empty(Stack s) { //empty ���� Ȯ��
	return s->top == -1;
}

void push(Stack s, Item i) { //push
	if (is_full(s))
		reallocate(s);
	s->top++;
	s->contents[s->top] = i;
}

Item pop(Stack s) { //pop
	if (is_empty(s))
		terminate("Error in pop: stack is empty.");
	s->top--;

	return s->contents[s->top + 1];
}

Item peek(Stack s) { //peek
	if (is_empty(s))
		terminate("Error in peek: stack is empty.");

	return s->contents[s->top];
}

void reallocate(Stack s) {
	Item *tmp = (Item*)malloc(sizeof(Item) * 2 * s->size);

	if(tmp == NULL)
		terminate("Error in create: stack could not be created.");

	for (int i = 0; i < s->size; i++)
		tmp[i] = s->contents[i];

	free(s->contents);

	s->contents = tmp;
	s->size *= 2;
}
*/


//////////


//���Ḯ��Ʈ stackADT
struct node {
	Item data;
	struct node *next;
};

struct stack_type { //���� ù ��� �ּҸ� �����ϴ� top
	struct node *top;
};

static void terminate(const char *message) {//���� ó�� �Լ�
	printf("%s\n", message);
	exit(1);
}

Stack create() { //Stack ��ü ����
	Stack s = (Stack)malloc(sizeof(struct stack_type));

	if (s == NULL)
		terminate("Error in create: stack could not be created");

	s->top = NULL;

	return s;
}

void destroy(Stack s) { //Stack top ����
	make_empty(s);
	free(s);
}

void make_empty(Stack s) { //Stack ��ü ����
	while (!is_empty(s))
		pop(s);
}

bool is_empty(Stack s) { //empty ���� Ȯ��
	return s->top == NULL;
}

void push(Stack s, Item i) { //push
	struct node *new_node = malloc(sizeof(struct node));

	if (new_node == NULL)
		terminate("Error in push: stack is full");

	new_node->data = i;
	new_node->next = s->top;
	s->top = new_node;
}

Item pop(Stack s) { //pop
	struct node *old_top;
	Item i;

	if (is_empty(s))
		terminate("Error in pop: stack is empty.");
	
	old_top = s->top;
	i = old_top->data;
	s->top = old_top->next;
	free(old_top);

	return i;
}

Item peek(Stack s) { //peek
	if (is_empty(s))
		terminate("Error in peek: stack is empty.");

	return s->top->data;
}