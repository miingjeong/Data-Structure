#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*일반적인 배열 스택 프로그램
* 탑과 스택 배열을 하나의 구조체로 결합시켜 이 구조체의 포인터를 함수의 매게변수로 전달한다.
* stackType이라는 새로운 구조체 타입을 만들고 여기에 stack배열과 top을 넣는다.
* */

#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;

}StackType ;

//스택 초기화 함수
void init(StackType* s) {
	s->top = -1;
}
//공백 상태 검사 함수
int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE)-1);
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, 스택 포화 에러n);
		return;
	}
	else s->stack[s->(++top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, 스택 공백 에러n);
		exit(1);
	}
	else return s->stack[s->(top)--];
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, 스택 공백 에러n);
		exit(1);
	}
	else return s->stack[s->top];
}

void main() {
	StackType s;

	init(&s);
	push(&s,1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", is_empty(&s));
}