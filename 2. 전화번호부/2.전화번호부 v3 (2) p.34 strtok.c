//전화번호부 v3 (2) p.34
//strtok을 이용한 문자열 짜르기 (tokenizing)
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

    char str[] = "now # is the time # to start preparing ### for the exam#";
    char delims[] = "#";
    char* token;
    char* tokens[100];
    int i=0;

    printf("Before:%s\n", str);
    token = strtok(str, delims);

    while (token != NULL) {
        printf("next token is: %s:%d\n", token, strlen(token));
        token = strtok(NULL, delims);
        tokens[i++] = token;
    }
    printf("Before:%s\n", str);
    return 0;
}