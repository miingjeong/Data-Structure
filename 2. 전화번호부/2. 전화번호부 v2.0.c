#include<stdio.h>
#include <string.h>

#define CAPACITY 100
#define BUFFER_SIZE 20

char* names[CAPACITY];       //names
char* numbers[CAPACITY];    // phone numbers 051-2352-3235 숫자도 char로.맨앞 0 뺴먹을 수도있고 '-' 사용하기위해
int n = 0; //number of people in phone directory

void add();
void find();
int search(char* name);
void status();
void remover();
void load();
void save();


int main() {
	char buffer[BUFFER_SIZE];
	while (1) {
		printf("$ ");
		scanf("%s", buffer);

		//strcmp함수는 두 문자열이 동일하면 0을 반환한다.
		if (strcmp(buffer, "read") == 0)
			load();
		else if (strcmp(buffer, "add") == 0)
			add();
		else if (strcmp(buffer, "find") == 0)
			find();
		else if (strcmp(buffer, "status") == 0)
			status();
		else if (strcmp(buffer, "delete") == 0)
			remover();
		else if (strcmp(buffer, "save") == 0)
			save();
		else if (strcmp(buffer, "exit") == 0)
			break;

	}
	return 0;

}

void load() {
	char fileName[BUFFER_SIZE];
	char buf1[BUFFER_SIZE];
	char buf2[BUFFER_SIZE];

	scanf("%s", fileName); //파일 이름 입력받기

	FILE* fp = fopen(fileName, "r"); //파일 접근하기 위해 먼저 파일 열기
	if (fp == NULL) {
		printf("Open failed.\n");
		return;
	}

	while ((fscanf(fp, "%s", buf1) != EOF)) { //파일 끝 도달할 때 까지 이름과 전화번호 읽어서 배열에 저장
		fscanf(fp, "%s", buf2);
		names[n] = strdup(buf1);
		numbers[n] = strdup(buf2);
		n++;
	}
	fclose(fp); //볼일 끝난 파일은 반드시 닫아야함.
}

void save() {
	int i;
	char fileName[BUFFER_SIZE];
	char tmp[BUFFER_SIZE];

	scanf("%s", tmp);
	scanf("%s", fileName);

	FILE* fp = fopen(fileName, 'w');
	if (fp == NULL) {
		printf("Open failed.\n");
		return;
	}
	for (i = 0; i < n; i++) {
		fprintf(fp, "%s %s\n", names[i], numbers[i]);
	}
	fclose(fp);

}

void add() {
	char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
	scanf("%s", buf1);
	scanf("%s", buf2);

	int i = n - 1;
	while (i > 0 && strcmp(names[i], buf1) > 0) { //사전식 순서로 나보다 큰 항목 모두 뒤로 한칸씩 이동
		names[i + 1] = names[i]; // 처음으로 나보다 작은 항목이 나오면 그것 바로 뒤에 삽입
		numbers[i + 1] = numbers[i];
		i--;
	}
	names[i + 1] = strdup(buf1);
	numbers[i + 1] = strdup(buf2);

	n++;
	printf("%s was added successfully.\n", buf1);
}

void find() {
	char buf[BUFFER_SIZE];
	scanf("%s", buf);

	int index = search(buf);
	if (index == -1)
		printf("No person named %s exists.\n", buf);
	else
		printf("%s\n", numbers[index]);
}

int search(char* name) {
	int i;
	for (i = 0; i < n; i++) {
		if (strcmp(name, names[i]) == 0) {
			return i;
		}
	}
	return -1;

}


void status() {
	int i;
	for (i = 0; i < n; i++)
		printf("%s %s\n", names[i], numbers[i]);
	printf("Total %d person.\n", n);
}

//remove라는 같은 이름의 함수가 존재하여 remover로 수정하니 잘 된다.
void remover() {
	char buf[BUFFER_SIZE];
	scanf("%s", buf);

	int index = search(buf);
	if (index == -1) {
		printf("No person named %s exists.\n", buf);
		return;
	}
	int j = index;
	for (; j < n - 1; j++) {
		names[j] = names[j + 1];
		numbers[j] = numbers[j + 1];
	}
	n--;
	printf("%s was deleted successfully.\n", buf);
}