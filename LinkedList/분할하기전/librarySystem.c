#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct NODE{
  char title[20];
  char author[20];
  int price;
  char rent[20];
  char producer[20];
  char isbn[20];
  struct NODE* next;
}Node;

typedef struct{
  Node* head;
}headNode;

headNode* createHeadNode(){
  headNode* head = (headNode*)malloc(sizeof(headNode));
  if(head != NULL){
    return head;
  }
}

// 새로운 노드가 맨 앞으로
void pre_addNode(headNode* pnode, char* title, char* author, int price, char* producer, char* isbn){
  Node* tnode = (Node*)malloc(sizeof(Node));
  if(tnode != NULL){
    strcpy(tnode->title, title);
    strcpy(tnode->author, author);
    tnode->price = price;
    tnode->next = pnode->head;
    strcpy(tnode->producer, producer);
    strcpy(tnode->isbn, isbn);
    strcpy(tnode->rent, "대여 가능");

    pnode->head = tnode;
  }
}

// 새로운 노드가 맨 뒤로
void rear_addNode(headNode* pnode, char* title, char* author, int price, char* producer, char* isbn){
  Node* tnode1 = (Node*)malloc(sizeof(Node));
  if(tnode1 != NULL){
    strcpy(tnode1->title, title);
    strcpy(tnode1->author, author);
    tnode1->price = price;
    strcpy(tnode1->producer, producer);
    strcpy(tnode1->isbn, isbn);
    strcpy(tnode1->rent, "대여 가능");
    tnode1->next = NULL;

    if(pnode->head == NULL) pnode->head = tnode1;
    else{
      Node* tnode2 = pnode->head;
      while(tnode2->next != NULL){
        tnode2 = tnode2->next;
      }
      tnode2->next = tnode1;
    }
  }
}

// 노드 출력
void showAllNode(headNode* pnode){
  Node* tnode = pnode->head;
  int count=0;

  if(tnode != NULL){
    printf("\n");
    printf("< 모든 도서 출력 >\n");

    while(tnode != NULL){
      count++;
      printf("\n");
      printf("%d 번째 책\n", count);
      printf("책 제목 : %s\n", tnode->title);
      printf("책 작가 : %s\n", tnode->author);
      printf("책 출판사 : %s\n", tnode->producer);
      printf("책 ISBN : %s\n", tnode->isbn);
      printf("책 가격 : %d\n", tnode->price);
      printf("대여 유무 : %s\n", tnode->rent);

      tnode = tnode->next;
    }
  }
  else{
    printf("책이 없습니다\n");
  }
}

// 노드 하나 삭제
void deleteNode(headNode* pnode, char* title){
  Node* tnode = pnode->head;
  if(tnode == NULL){// 노드가 없다면
    printf("일치하는 책이 없습니다\n");
    return;
  }
  else if(strcmp(tnode->title, title) == 0){ // 첫노드 삭제시
    printf("< 책 %s 삭제 완료 >\n", tnode->title);
    pnode->head = tnode->next;
    return;
  }
  else {
    while(tnode->next != NULL){
      if(strcmp(tnode->next->title, title) == 0){
        printf("\n");
        printf("< 책 %s 삭제 완료 >\n", tnode->next->title);
        tnode->next = tnode->next->next;
        return;
      }
      tnode = tnode->next;
    }
  }
  printf("일치하는 책이 없습니다\n");
}

// 모든 메모리영역 해제
void freeAllNode(headNode* pnode){
  Node* tnode = pnode->head;
  while(tnode != NULL){
    pnode->head = tnode->next;
    free(tnode);
    tnode = pnode->head;
  }
  printf("모든 책 삭제 완료!!\n");
}

// 노드 검색 출력함수
void searchPrint(Node* tnode){
  int num;

  printf("\n");
  printf("< 검색완료!!! >\n");
  printf("책 제목 : %s\n", tnode->title);
  printf("책 작가 : %s\n", tnode->author);
  printf("책 출판사 : %s\n", tnode->producer);
  printf("책 ISBN : %s\n", tnode->isbn);
  printf("책 가격 : %d\n", tnode->price);
  printf("대여 유무 : %s\n", tnode->rent);
  if(strcmp(tnode->rent, "대여 가능") == 0){
    printf("책을 대여하시겠습니까? 대여(y) 종료(other) : ");
    scanf("%d", &num);
    if(num == 1){
      strcpy(tnode->rent, "대여 중");
    }
  }
}

// 노드 검색
void searchNode(headNode* pnode, char* keyword){
  Node* tnode = pnode->head;

  while(tnode != NULL){
    if(strcmp(tnode->title, keyword) == 0){
      searchPrint(tnode);
      return;
    }
    else if(strcmp(tnode->author, keyword) == 0){
      searchPrint(tnode);
      return;
    }
    else if(strcmp(tnode->producer, keyword) == 0){
      searchPrint(tnode);
      return;
    }
    else if(strcmp(tnode->isbn, keyword) == 0){
      searchPrint(tnode);
      return;
    }
    tnode = tnode->next;
  }
  printf("검색되는 책이 없습니다\n");
}

// 로그인 함수
void login(){
  char id[20];
  char pw[20];
  int failCount=3;
  FILE* fp;

  while(failCount){// 로그인 기회 3번
    // 로그인 입력
    printf("ID 입력 : ");
    scanf("%s", id);
    printf("PassWord 입력 : ");
    scanf("%s", pw);

    // 아이디 비번 체크(ID=test, PW=1234)
    if(strcmp(id, "test")==0 && strcmp(pw, "1234")==0){
      printf("\n");
      printf("로그인 성공!!\n");
      return;
    }
    else{
      printf("로그인 실패\n");
      if(failCount != 1)
        printf("기회 %d번 남았습니다.\n", (failCount-1));
        failCount--;
    }
  }
  exit(0);
}

void main(){
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
  while(true){
    printf("**** 메뉴 ****\n 1. 도서등록\n 2. 도서검색\n 3. 도서삭제\n 4. 도서출력\n 0. 종료\n 입력-> ");
    scanf("%d", &num);
    // 도서 등록
    if(num == 1){
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
    else if(num == 2){
      printf("검색할 키워드 입력: ");
      scanf("%s", keyword);
      searchNode(newhead, keyword);
    }
    // 도서삭제
    else if(num == 3){
      printf("\n");
      printf("1. 개별삭제, 2. 전체삭제: ");
      scanf("%d", &num);
      if(num == 1){
        printf("삭제할 책제목 입력: ");
        scanf("%s", title);
        deleteNode(newhead, title);
      }
      else if(num == 2){
        freeAllNode(newhead);
      }
    }
    else if(num == 4){
      showAllNode(newhead);
    }
    else if(num == 0){
      break;
    }
    printf("\n");
  }
  freeAllNode(newhead);
  free(newhead);
}
