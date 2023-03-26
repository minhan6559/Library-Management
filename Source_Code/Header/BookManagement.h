#pragma once
#include <string>
using namespace std;

struct Book
{
	//Thong Tin Sach
	string	bookID,
			bookName,
			author,
			publisher,
			category;
	int		publishYear,
			bookPrice,
			bookQuantity;
};

//Ham de nap du lieu sach tu file txt
void loadBook(int& totalBooks, Book book[]);

//Ham de luu du lieu sach vao file txt
void saveBook(int totalBooks, Book book[]);

//Ham dung de them thong tin sach moi.
void addBook(int& totalBooks, Book book[]);

//Ham dung de thay doi thong tin 1 sach
void changeBookInfo(int totalBooks, Book book[]);

//Ham de xoa thong tin 1 sach
void deleteBookInfo(int& totalBooks, Book book[]);

//Ham dung de hien thi thong tin cua toan bo sach
void displayAllBooks(int totalBooks, Book book[]);

//Ham dung de hien thi thong tin 1 sach thong qua Vi tri o trong mang
void displayABookByPos(int pos, Book book[]);

//Ham dung de hien thi thong tin 1 doc gia thong qua ma ISBN
void displayABookByISBN(int totalBooks, Book book[]);

//Ham dung de hien thi thong tin 1 quyen sach thong qua ten sach
//Neu co nhieu quyen sach trung ten thi hien thi toan bo nhung quyen sach do
void displayABookByName(int totalBooks, Book book[]);

//Ham dung de hien hang tieu de cua bang thong tin sach
void displayBookTableTitle();

//Ham dung de tim kiem vi tri cua 1 sach thong qua ma ISBN
int findPosOfABookByISBN(int totalBooks, Book book[], string currentISBN);

//Ham dung de tim kiem vi tri cua 1 sach thong qua ten
int findPosOfABookByName(int totalBooks, Book book[], string currentBookName);

//Kiem tra sach da duoc muon het hay chua?
//Tra ve 1 thi con sach, tra ve 0 thi toan bo sach da duoc muon het
bool bookAvailable(int totalBooks, Book book[]);

//Ham de dem so sach con lai trong thu vien
int countBooks(int totalBooks, Book book[]);

//Them 1 The loai sach vao tap hop (Moi the loai chi duoc them 1 lan)
void addCategoryToSet(string categorySet[], int& number, string _category);

//Thong ke so luong sach theo the loai
void statisticizeBookByCategory(int totalBooks, Book book[]);

//Dem so luong sach theo the loai
int countBooksByCategory(int totalBooks, Book book[], string _category);