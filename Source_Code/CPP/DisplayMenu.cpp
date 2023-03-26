#include "DisplayMenu.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

void manageReader(int &totalReaders, Reader reader[])
{
	while (true)
	{
		cout << setfill('-');
		cout << setw(60) << "-" << endl;
		cout << setfill(' ');

		cout << setw(23) << ' ' << "MENU DOC GIA" << endl;

		cout << "1. Xem danh sach doc gia" << '\n'
			<< "2. Them doc gia" << '\n'
			<< "3. Chinh sua thong tin 1 doc gia" << '\n'
			<< "4. Xoa thong tin 1 doc gia" << '\n'
			<< "5. Tim kiem doc gia theo CMND \n"
			<< "6. Tim kiem doc gia theo ho ten \n"
			<< "0. Quay lai MAIN MENU" << '\n';

		cout << "\nNhap lua chon cua ban: ";
		int chosen;
		cin >> chosen;
		cout << '\n';

		system("cls");

		switch (chosen)
		{
		case 1:
			displayAllReaders(totalReaders, reader);
			break;
		case 2:
			addReader(totalReaders, reader);
			break;
		case 3:
			changeReaderInfo(totalReaders, reader);
			break;
		case 4:
			deleteReaderInfo(totalReaders, reader);
			break;
		case 5:
			displayAReaderByNID(totalReaders, reader);
			break;
		case 6:
			displayAReaderByName(totalReaders, reader);
			break;
		case 0:
			return;
		default:
			cout << "Lua chon khong hop le! Vui long nhap lai!\n";
			break;
		}
		system("pause");
		system("cls");
	}
}

void manageBook(int& totalBooks, Book book[])
{
	while (true)
	{
		cout << setfill('-');
		cout << setw(60) << "-" << endl;
		cout << setfill(' ');

		cout << setw(25) << ' ' << "MENU SACH" << endl;

		cout << "1. Xem danh sach cac sach trong thu vien" << '\n'
			<< "2. Them sach" << '\n'
			<< "3. Chinh sua thong tin 1 quyen sach" << '\n'
			<< "4. Xoa thong tin 1 quyen sach" << '\n'
			<< "5. Tim kiem sach theo ISBN\n"
			<< "6. Tim kiem sach theo ten sach\n"
			<< "0. Quay lai MAIN MENU" << '\n';

		cout << "\nNhap lua chon cua ban: ";
		int chosen;
		cin >> chosen;
		cout << '\n';

		system("cls");

		switch (chosen)
		{
		case 1:
			displayAllBooks(totalBooks, book);
			break;
		case 2:
			addBook(totalBooks, book);
			break;
		case 3:
			changeBookInfo(totalBooks, book);
			break;
		case 4:
			deleteBookInfo(totalBooks, book);
			break;
		case 5:
			displayABookByISBN(totalBooks, book);
			break;
		case 6:
			displayABookByName(totalBooks, book);
			break;
		case 0:
			return;
		default:
			cout << "Lua chon khong hop le! Vui long nhap lai!\n";
			break;
		}
		system("pause");
		system("cls");
	}
}

void manageTicket
(
	int&	totalTickets,
	int		totalReaders,
	int		totalBooks,
	Ticket	ticket[],
	Reader	reader[],
	Book	book[]
)
{
	while (true)
	{
		cout << setfill('-');
		cout << setw(60) << "-" << endl;
		cout << setfill(' ');

		cout << setw(20) << ' ' << "MENU MUON/TRA SACH" << endl;

		cout << "1. Lap phieu muon sach\n"
			<< "2. Xem tinh trang tat ca phieu muon\n"
			<< "3. Lam thu tuc tra sach\n"
			<< "0. Quay lai MAIN MENU" << '\n';

		cout << "\nNhap lua chon cua ban: ";
		int chosen;
		cin >> chosen;
		cout << '\n';

		system("cls");

		switch (chosen)
		{
		case 1:
			addNewBorrowTicket(totalTickets, totalReaders, totalBooks, ticket, reader, book);
			break;
		case 2:
			displayAllTickets(totalTickets, totalBooks, ticket, book);
			break;
		case 3:
			returnBook(totalTickets, totalReaders, totalBooks, ticket, reader, book);
			saveTicket(totalTickets, totalBooks, ticket);
			break;
		case 0:
			return;
		default:
			cout << "Lua chon khong hop le! Vui long nhap lai!\n";
			break;
		}
		system("pause");
		system("cls");
	}
}

void manageStatics
(
	int		totalTickets,
	int		totalReaders,
	int		totalBooks,
	Ticket	ticket[],
	Reader	reader[],
	Book	book[]
)
{
	while (true)
	{
		cout << setfill('-');
		cout << setw(60) << "-" << endl;
		cout << setfill(' ');

		cout << setw(23) << ' ' << "MENU THONG KE" << endl;

		cout << "1. Thong ke so luong sach trong thu vien\n"
			<< "2. Thong ke so luong sach theo the loai\n"
			<< "3. Thong ke so luong doc gia\n"
			<< "4. Thong ke so luong doc gia theo gioi tinh\n"
			<< "5. Thong ke so sach dang duoc muon\n"
			<< "6. Thong ke danh sach doc gia bi tre han\n"
			<< "0. Quay lai MAIN MENU" << '\n';

		cout << "\nNhap lua chon cua ban: ";
		int chosen;
		cin >> chosen;
		cout << '\n';

		system("cls");

		switch (chosen)
		{
		case 1:
			displayAllBooks(totalBooks, book);
			cout << "\nSo luong sach hien co trong thu vien la " << countBooks(totalBooks, book) << " quyen sach\n";
			break;
		case 2:
			statisticizeBookByCategory(totalBooks, book);
			break;
		case 3:
			displayAllReaders(totalReaders, reader);
			cout << "\nSo luong doc gia hien tai la " << totalReaders << endl;
			break;
		case 4:
			statisticizeReadersByGender(totalReaders, reader);
			break;
		case 5:
			displayAllBorrowedBooks(totalTickets, totalBooks, ticket, book);
			break;
		case 6:
			displayBorrowerReturnLate(totalTickets, totalReaders, totalBooks, ticket, reader, book);
			break;
		case 0:
			return;
		default:
			cout << "Lua chon khong hop le! Vui long nhap lai!\n";
			break;
		}
		system("pause");
		system("cls");
	}
}