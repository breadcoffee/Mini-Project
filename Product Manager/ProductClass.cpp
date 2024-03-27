/*
File: ProductClass.cpp
Created: 24-03-11(1파일 날짜)
Author: 이주원
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Product {
private:
	char id[50];
	int price;
	char producer[50];
public:
	Product(const char* id, int price, const char* producer) : price(price) {
		//id = new char[(strlen(id) + 1)];
		strcpy(this->id, id);
		//producer = new char[(strlen(producer) + 1)];
		strcpy(this->producer, producer);
	}
	void ShowProductInfo() {
		cout << "상품 ID : " << id << endl;
		cout << "상품 가격 : " << price << endl;
		cout << "상품 제작사 : " << producer << endl;
	}
	void addProduct() {
		
		//addBookProduct();
	}
	~Product() {

	}  
};

class Book : public Product{
private:
	char ISBN[50];
	char author[50];
	char title[50];
public:
	Book(const char* id, int price, const char* producer, const char* ISBN, const char* author, const char* title) : Product(id, price, producer) {
		strcpy(this->ISBN, ISBN);
		strcpy(this->author, author);
		strcpy(this->title, title);
	}
	void addBookProduct() {
		cout << "책 ISBN 입력 : ";
		cin >> ISBN;
		cout << "책 작가 입력 : ";
		cin >> author;
		cout << "책 제목 입력 : ";
		cin >> title;
		cout << "책이 추가 되었습니다" << endl;
	}
	void ShowBookInfo() {
		ShowProductInfo();
		cout << "책 ISBN : " << ISBN << endl;
		cout << "책 작가 : " << author << endl;
		cout << "책 제목 : " << title << endl;
	}
	void SearchBook(const char* title) {
		if(this->title == title){
			cout << "찾으시는 책 : " << title << "있습니다" << endl;
		}
	}
	~Book(){}
};

class ProductHandler {
private:
	Product* product[100];
	int proNum;
public:
	ProductHandler() : proNum(0) {}
	void AddProduct(Product* pro) {
		product[proNum++] = pro;
	}
	void ShowAllProductInfo() const {
		for (int i = 0; i < proNum; i++)
			product[i]->ShowProductInfo();
	}
	//void SearchProductInfo(const char* id) const {
	//	for (int i = 0; i < proNum; i++)
	//		if (product[i].id == id) {

	//		}
	//}
	~ProductHandler() {
		for (int i = 0; i < proNum; i++)
			delete product[i];
	}
};

int main(){
	int menu, choice;
	char id[50];
	int price;
	char producer[50];
	char ISBN[50];
	char author[50];
	char title[50];
	ProductHandler handler;

	do {
		cout << "----상품관리 프로그램----" << endl;
		cout << "1. 상품추가  2. 상품출력  3. 상품검색  0. 종료" << endl;
		cout << "-> ";
		cin >> menu;

		cout << "1. 책  2. 핸드폰  3. 컴퓨터 중 고르시오" << endl;
		cout << "-> ";
		cin >> choice;

		if (menu == 1) {
			cout << "상품 ID 입력 : ";
			cin >> id;
			cout << "상품 가격 입력 : ";
			cin >> price;
			cout << "상품 제작사 입력 : ";
			cin >> producer;
			if (choice == 1) {
				cout << "책 ISBN 입력 : ";
				cin >> ISBN;
				cout << "책 작가 입력 : ";
				cin >> author;
				cout << "책 제목 입력 : ";
				cin >> title;
				handler.AddProduct(new Book(id, price, producer, ISBN, author, title));
				continue;
			}

			continue;
		}
		else if (menu == 2) {
			handler.ShowAllProductInfo();
			continue;
		}
		else if (menu == 3) {
			continue;
		}
		else if (menu == 0) {
			exit(0);
		}
	} while (menu);

	return 0;
}