#pragma once
#include <stdbool.h>

typedef int Item; //�� �̷��� ��? : �̷��� �ϸ� �ٸ� �ڷ������� �� ���� ���ܵ� 'int'�� 'float'�� �ٲٸ� ��!
typedef struct stack_type *Stack;

Stack create();
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);
Item peek(Stack s);