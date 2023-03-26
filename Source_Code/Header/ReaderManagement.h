#pragma once
#include <string>
using namespace std;

struct Reader
{
	string	readerID,
			name,
			nationalID,
			email,
			address;

	int		gender, //Gioi tinh cua doc gia. 1 la Nam, 2 la Nu

			//Ngay sinh
			dayOfBirth,
			monthOfBirth,
			yearOfBirth,

			//Ngay Lap The
			dayOfStartCard,
			monthOfStartCard,
			yearOfStartCard,

			//Ngay het han the
			dayOfEndCard,
			monthOfEndCard,
			yearOfEndCard;
};

//Ham dung de nap du lieu doc gia tu file txt
void loadReader(int& totalReaders, Reader reader[]);

//Ham de luu du lieu doc gia vao file txt
void saveReader(int totalReaders, Reader reader[]);

//Ham dung de them thong tin doc gia moi.
void addReader(int& totalReaders, Reader reader[]);

//Ham dung de thay doi thong tin 1 doc gia
void changeReaderInfo(int totalReaders, Reader reader[]);

//Dung de xoa thong tin 1 doc gia
void deleteReaderInfo(int& totalReaders, Reader reader[]);

//Ham dung de hien thi thong tin 1 doc gia thong qua Vi tri o trong mang
void displayAReaderByPos(int pos, Reader reader[]);

//Ham dung de hien thi thong tin cua toan bo doc gia
void displayAllReaders(int totalReaders, Reader reader[]);

//Ham dung de hien thi thong tin 1 doc gia thong qua CMND
void displayAReaderByNID(int totalReaders, Reader reader[]);

//Ham dung de hien thi thong tin 1 doc gia thong qua ho ten
//Neu co nhieu doc gia trung ten thi hien thi toan bo nhung doc gia do
void displayAReaderByName(int totalReaders, Reader reader[]);

//Ham dung de hien hang tieu de cua bang thong tin doc gia
void displayReaderTableTitle();

//Thong ke so luong doc gia theo gioi tinh
void statisticizeReadersByGender(int totalReaders, Reader reader[]);

//Dem so luong doc gia theo gioi tinh
int countReadersByGender(int totalReaders, Reader reader[], int _gender);

//Ham dung de tim kiem vi tri cua 1 doc gia thong qua Ma Doc Gia
int findPosOfAReaderByRID(
	int totalReaders,
	Reader reader[],
	string currentRID
);

//Ham dung de tim kiem vi tri cua 1 doc gia thong qua CMND
int findPosOfAReaderByNID(
	int totalReaders,
	Reader reader[],
	string currentNID
);

//Ham dung de tim kiem vi tri cua 1 doc gia thong qua ho ten
int findPosOfAReaderByName(
	int totalReaders,
	Reader reader[],
	string currentName
);

//Ham kiem tra nam nhuan
bool isLeapYear(int year);

//Ham de tinh so ngay trong 1 thang cu the. 
int daysOfMonth(int month, int year);

//Ham kiem tra xem 1 ngay co hop le hay khong?
bool isValidDate(int day, int month, int year);