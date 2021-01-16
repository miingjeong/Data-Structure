#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

//p.16 예제
#define BUFFER_SIZE 100
#include <stdio.h>
#include <string.h>

int main() {

	char* words[100];
	int n = 0; // number of strings
	char buffer[BUFFER_SIZE];

	while (n < 4 && scanf("%s", buffer) != EOF) { //  scanf("%d",&a). 배열의 이름이 실제 그 배열의 주소를 저장하고 있는 포인트 변수이기 때문( &buffer 아닌이유)

		words[n] = strdup(buffer); //buffer로만 쓰면 안된다. 그럼 마지막 문자열만 4번 출력됨. 
		n++;

	}
	for (int i = 0; i < 4; i++)
		printf("%s\n", words[i]);

	return 0;
}