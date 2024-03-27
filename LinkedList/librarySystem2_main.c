/*
File: librarySystem2_main.c
Created: 24-03-27(3파일 날짜)
Author: 이주원
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "librarySystem2_struct.h"

void main() {
    headNode* newhead = createHeadNode();
    int num = 0;
    char title[20];
    char author[20];
    int price = 0;
    char producer[20];
    char isbn[20];
    char keyword[20];

    // 로그인
    login();
    while (true) {
        printf("**** 메뉴 ****\n 1. 도서등록\n 2. 도서검색\n 3. 도서삭제\n 4. 도서출력\n 0. 종료\n 입력-> ");
        scanf("%d", &num);
        // 도서 등록
        if (num == 1) {
            printf("\n");
            printf("< 도서 등록 >\n");
            printf("책 제목 입력: ");
            scanf("%s", title);
            printf("책 작가 입력: ");
            scanf("%s", author);
            printf("책 출판사 입력: ");
            scanf("%s", producer);
            printf("책 ISBN 입력: ");
            scanf("%s", isbn);
            printf("책 가격 입력: ");
            scanf("%d", &price);
            rear_addNode(newhead, title, author, price, producer, isbn);
        }
        // 도서검색
        else if (num == 2) {
            printf("검색할 키워드 입력: ");
            scanf("%s", keyword);
            searchNode(newhead, keyword);
        }
        // 도서삭제
        else if (num == 3) {
            printf("\n");
            printf("1. 개별삭제, 2. 전체삭제: ");
            scanf("%d", &num);
            if (num == 1) {
                printf("삭제할 책제목 입력: ");
                scanf("%s", title);
                deleteNode(newhead, title);
            }
            else if (num == 2) {
                freeAllNode(newhead);
            }
        }
        else if (num == 4) {
            showAllNode(newhead);
        }
        else if (num == 0) {
            break;
        }
        printf("\n");
    }
    freeAllNode(newhead);
    free(newhead);
}