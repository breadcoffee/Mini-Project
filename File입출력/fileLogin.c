/*
File: fileLogin.c
Created: 24-03-21(2파일 날짜)
Author: 이주원
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void main() {
    char msg[50];
    char id[20];
    char pw[20];
    int failCount = 3;
    FILE* fp;

    while (failCount) {
        // 로그인 입력
        printf("ID 입력 : ");
        scanf("%s", id);
        printf("PassWord 입력 : ");
        scanf("%s", pw);

        // 아이디 비번 체크(ID=test, PW=1234)
        if (strcmp(id, "test") == 0 && strcmp(pw, "1234") == 0) {
            printf("\n");
            printf("로그인 성공!!\n");
            if ((fp = fopen("myinfo.txt", "r")) == NULL) {
                fprintf(stderr, "ERROR");
                exit(1);
            }
            fscanf(fp, "%s", msg);
            printf("%s\n", msg);

            fclose(fp);
            exit(0);
        }
        else {
            printf("로그인에 실패했습니다\n");
            if (failCount != 1)
                printf("기회 %d번 남았습니다.\n", (failCount - 1));
            failCount--;
        }
    }
}