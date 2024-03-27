/*
File: librarySystem2__struct.h
Created: 24-03-27(3파일 날짜)
Author: 이주원
*/

#ifndef LIBRARYSYSTEM2_STRUCT_H
#define LIBRARYSYSTEM2_STRUCT_H

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

headNode* createHeadNode();
void pre_addNode(headNode* pnode, char* title, char* author, int price, char* producer, char* isbn);
void rear_addNode(headNode* pnode, char* title, char* author, int price, char* producer, char* isbn);
void showAllNode(headNode* pnode);
void deleteNode(headNode* pnode, char* title);
void freeAllNode(headNode* pnode);
void searchPrint(Node* tnode);
void searchNode(headNode* pnode, char* keyword);
void login();

#endif
