#pragma once
#include <string>
using namespace std;

struct Ticket
{
	//Thong tin phieu muon/tra sach
	string	borrowerID;

	int		borrowDay,
			borrowMonth,
			borrowYear,

			expectedReturnDay,
			expectedReturnMonth,
			expectedReturnYear,
		/*
			tong so sach muon
			vi tri sach
		*/
			realReturnDay[100] = {0},
			realReturnMonth[100]= {0},
			realReturnYear[100] = { 0 };

	//Trang thai cua sach. 1 la dang muon, 2 la da tra dung han, 3 la tra qua han, 4 la mat
	int		bookStatus[100] = {0},
	//Phi cua sach do lam mat hoac tra tre han
			bookFee[100] = { 0 };
};

//Ham de nap du lieu phieu muon tu file txt
void loadTicket(int& totalTickets, Ticket ticket[]);

//Ham de luu du lieu phieu muon vao file txt
void saveTicket(int totalTickets, int totalBooks, Ticket ticket[]);

//Them phieu muon moi
void addNewBorrowTicket
(
	int& totalTickets,
	int		totalReaders,
	int		totalBooks,
	Ticket	ticket[],
	Reader	reader[],
	Book	book[]
);

//Tra sach hoac bao mat sach
void returnBook
(
	int		totalTickets,
	int		totalReaders,
	int		totalBooks,
	Ticket	ticket[],
	Reader	reader[],
	Book	book[]
);

//Ham dung de cap nhat trang thai sach va tien phat sach
void updateBookStatusAndFee(int posOfTicket, int posOfBook, Ticket ticket[], Book book[]);

//Hien thong tin 1 phieu muon thong qua vi tri trong mang
void displayABorrowTicketByPos(int pos, int totalTickets, int totalBooks, Ticket ticket[], Book book[]);

//Hien thi thong tin cua toan bo phieu muon
void displayAllTickets(int totalTickets, int totalBooks, Ticket ticket[], Book book[]);

//Ham dung de hien hang tieu de cua bang thong tin phieu muon
void displayTicketTableTitle();

//Hien Thi toan bo thong tin cua cac sach dang duoc muon va doc gia muon chung
void displayAllBorrowedBooks(int totalTickets, int totalBooks, Ticket ticket[], Book book[]);

//Hien thi thong tin cac doc gia tra sach tre han
void displayBorrowerReturnLate
(
	int		totalTickets,
	int		totalReaders,
	int		totalBooks,
	Ticket	ticket[],
	Reader	reader[],
	Book	book[]
);

//Ham kiem tra xem 1 doc gia da tung muon sach do hay chua? 
//Do moi doc gia chi duoc muon 1 cuon
bool alreadyBorrowed(int totalTickets, Ticket ticket[], Ticket currentTicket, int posOfBook);

//Kiem tra date 1 co nam o sau date 2 khong ?
bool isDayLater(int d1, int m1, int y1, int d2, int m2, int y2);

//Tim ngay tiep theo ngay nhap vao
void tomorow(int& day, int& month, int& year);

//Tinh khoang cach 2 ngay voi date 1 nam o sau date 2
int distanceBetweenTwoDates(int d1, int m1, int y1, int d2, int m2, int y2);

//Ham kiem tra xem 1 phieu muon con sach dang muon hay khong?
bool aTicketOutOfBorrowedBooks(int posOfTicket, int totalBooks, Ticket ticket[]);

//Ham kiem tra toan bo phieu muon con sach dang muon hay khong?
bool allTicketsOutOfBorrowedBooks(int totalTickets, int totalBooks, Ticket ticket[]);

//Ham kiem tra 1 phieu muon co sach nao tra qua han hay khong?
bool aTicketNoReturnLate(int posOfTicket, int totalBooks, Ticket ticket[]);

//Ham kiem tra toan bo phieu muon co sach nao tra qua han hay khong?
bool allTicketsNoReturnLate(int totalTickets, int totalBooks, Ticket ticket[]);

//Ham kiem tra xem 1 quyen sach con doc gia dang muon hay khong?
bool aBookOutOfBorrowers(int posOfBook, int totalTickets, Ticket ticket[]);

//Ham de dem so luong nguoi muon cua 1 cuon sach
int countBorrowersOfABook(int posOfBook, int totalTickets, Ticket ticket[]);

