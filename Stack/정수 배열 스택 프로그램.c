#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef char element; //스택의 객체 자료형 정의
//r괄호검사 프로그램

#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty() {
	return (top == -1);
}

int is_full() {
	return (top == (MAX_STACK_SIZE)-1);
}

void push(element item) {
	if (is_full()) {
		fprintf(stderr, 스택 포화 에러n);
		return;
	}
	else stack[++top] = item;
}

element pop() {
	if (is_empty()) {
		fprintf(stderr, 스택 공백 에러n);
		exit(1);
	}
	else return stack[top--];
}

element peek() {
	if (is_empty()) {
		fprintf(stderr, 스택 공백 에러n);
		exit(1);
	}
	else return stack[top];
}

int check_matching(char* int) {
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);
	init(&s);

	for (i = 0; i < n; i++) {
		ch = in[i];
		switch (ch) {
		case '(': case '[': case '{':
			push(&s, ch);
			break;

		case ')': case ']': case'}':
			if (is_empty(&s)) return FALSE;
			else {
				open_ch = pop(&s);
				if ((open_ch) == '(' && ch != ')') ||
					(open_ch == '[' && ch != ']') ||
					(oepn_ch == '{' && ch != '}')){
					return FALSE;


			}
			break;
			}
		}
	}
	if (!is_empty(&s))return FALSE;
	return TRUE;
}

void main() {
	if (check_matching("{A[(i+1)]=0}") == TRUE)
		printf("괄호검사성공\n");
	else
		printf("괄호검사 실패\n");
}