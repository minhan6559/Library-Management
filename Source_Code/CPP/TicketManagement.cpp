#include "ReaderManagement.h"
#include "BookManagement.h"
#include "TicketManagement.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
using namespace std;

void loadTicket(int& totalTickets, Ticket ticket[])
{
	ifstream fp("Source_Code\\Data\\Ticket.txt");

	fp >> totalTickets;

	fp.ignore();

	for (int i = 0; i < totalTickets; i++)
	{
		getline(fp, ticket[i].borrowerID);
		fp >> ticket[i].borrowDay;
		fp >> ticket[i].borrowMonth;
		fp >> ticket[i].borrowYear;
		fp >> ticket[i].expectedReturnDay;
		fp >> ticket[i].expectedReturnMonth;
		fp >> ticket[i].expectedReturnYear;

		int totalBorrow;
		fp >> totalBorrow;

		for (int j = 0; j < totalBorrow; j++)
		{
			int pos;
			fp >> pos;

			fp >> ticket[i].realReturnDay[pos];
			fp >> ticket[i].realReturnMonth[pos];
			fp >> ticket[i].realReturnYear[pos];

			fp >> ticket[i].bookStatus[pos];
			fp >> ticket[i].bookFee[pos];
		}
		fp.ignore();
	}
	fp.close();
}

void saveTicket(int totalTickets, int totalBooks ,Ticket ticket[])
{
	ofstream fp("Source_Code\\Data\\Ticket.txt");

	fp << totalTickets << '\n';

	for (int i = 0; i < totalTickets; i++)
	{
		fp << ticket[i].borrowerID << '\n';
		fp << ticket[i].borrowDay << '\n';
		fp << ticket[i].borrowMonth << '\n';
		fp << ticket[i].borrowYear << '\n';
		fp << ticket[i].expectedReturnDay << '\n';
		fp << ticket[i].expectedReturnMonth << '\n';
		fp << ticket[i].expectedReturnYear << '\n';

		int count = 0;
		for (int j = 0; j < totalBooks; j++)
		{
			if (ticket[i].bookStatus[j] != 0) count++;
		}

		fp << count << '\n';

		for (int j = 0; j < totalBooks; j++)
		{
			if (ticket[i].bookStatus[j] != 0)
			{
				fp << j << '\n';
				fp << ticket[i].realReturnDay[j] << '\n';
				fp << ticket[i].realReturnMonth[j] << '\n';
				fp << ticket[i].realReturnYear[j] << '\n';
				fp << ticket[i].bookStatus[j] << '\n';
				fp << ticket[i].bookFee[j] << '\n';
			}
		}
	}

	fp.close();
}

void addNewBorrowTicket
(
	int&	totalTickets,
	int		totalReaders,
	int		totalBooks,
	Ticket	ticket[],
	Reader	reader[],
	Book	book[]
)
{
	Ticket	temp;

	int		chosen, posOfReader;
	if (totalReaders == 0)
	{
		cout << "Chua co doc gia nao duoc nhap! Vui long them thong tin doc gia!\n";
		return;
	}

	if (totalBooks == 0)
	{
		cout << "Chua co sach nao duoc nhap! Vui long them thong tin sach!\n";
		return;
	}

	if (bookAvailable(totalBooks, book) == 0)
	{
		cout << "Hien sach dang tam thoi duoc muon het! Vui long quay lai sau!\n";
		return;
	}

	while (true)
	{
		cout << setfill('-');
		cout << setw(60) << "-" << endl;
		cout << setfill(' ');

		cout << "1. Nhap Ma Doc Gia de dang ky phieu muon\n"
			<< "2. Xuat thong tin toan bo doc gia\n"
			<< "0. Huy thay doi! Quay lai Menu Muon/Tra sach\n";

		cout << "\nNhap lua chon cua ban: ";
		cin >> chosen;

		cin.ignore();

		switch (chosen)
		{
		case 1:
			cout << setw(20) << left << "\nNhap ma doc gia: ";
			getline(cin, temp.borrowerID);

			posOfReader = findPosOfAReaderByRID(totalReaders, reader, temp.borrowerID);

			if (temp.borrowerID.empty())
			{
				cout << "\nKhong duoc de trong! Vui long thuc hien lai! \n";
				continue;
			}
			if (posOfReader == -1)
			{
				cout << "\nKhong tim thay thong tin doc gia! Vui long thuc hien lai! \n ";
				continue;
			}
			cout << "\nNhap Ma Doc Gia thanh cong! Bam nut bat ki de tiep tuc!\n";
			system("pause");
			system("cls");
			break;
		case 2:
			cout << '\n';
			displayAllReaders(totalReaders, reader);
			cout << '\n';
			continue;
		case 0:
			return;
		default:
			cout << "\nLua chon khong hop le! Vui long thuc hien lai!\n";
			system("pause");
			system("cls");
			continue;
		}
		break;
	}

	while (true)
	{
		cout << "Nhap ngay muon: \n"
			<< setw(15) << left << " Nhap ngay: ";
		cin >> temp.borrowDay;

		cout << setw(15) << left << " Nhap thang: ";
		cin >> temp.borrowMonth;

		cout << setw(15) << left << " Nhap nam: ";
		cin >> temp.borrowYear;

		if (isValidDate(temp.borrowDay, temp.borrowMonth, temp.borrowYear) == 0)
		{
			cout << "\nNgay khong hop le! Vui long nhap lai! \n\n";
			continue;
		}

		if (isDayLater(reader[posOfReader].dayOfEndCard, reader[posOfReader].monthOfEndCard, reader[posOfReader].yearOfEndCard,
				temp.borrowDay, temp.borrowMonth, temp.borrowYear) == 0
			|| isDayLater(temp.borrowDay, temp.borrowMonth, temp.borrowYear, 
				reader[posOfReader].dayOfStartCard, reader[posOfReader].monthOfStartCard, reader[posOfReader].yearOfStartCard) == 0)
		{
			cout << "\nKhong the muon ngay nay do khong nam trong han su dung the thu vien cua doc gia nay!"
				<< "\nVui long cap nhat hoac lam lai the thu vien moi!\n\n";
			return;
		}

		break;
	}

	temp.expectedReturnDay = temp.borrowDay;
	temp.expectedReturnMonth = temp.borrowMonth;
	temp.expectedReturnYear = temp.borrowYear;

	for (int i = 1; i <= 7; i++)
	{
		tomorow(temp.expectedReturnDay, temp.expectedReturnMonth, temp.expectedReturnYear);
	}

	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');

	cout << "Ngay tra du kien la: " << temp.expectedReturnDay << "/" << temp.expectedReturnMonth << "/" << temp.expectedReturnYear << '\n';
	cout << "\nNhap phim bat ky de tiep tuc them thong tin!\n";

	system("pause");
	system("cls");

	int dem = 0;
	while (true)
	{
		cout << setfill('-');
		cout << setw(60) << "-" << endl;
		cout << setfill(' ');

		if (dem == 0)
		{
			cout << "1. Nhap ma ISBN de muon sach\n"
				<< "2. Xuat thong tin toan bo sach\n"
				<< "0. Huy thay doi! Quay lai Menu Muon/Tra sach\n";
		}
		else
		{
			cout << "1. Nhap ma ISBN de muon them sach\n"
				<< "2. Xuat thong tin toan bo sach\n"
				<< "0. Hoan tat muon sach!\n";
		}

		cout << "\nNhap lua chon cua ban: ";
		cin >> chosen;

		int posOfBook;
		string _borrowedBookID;
		cin.ignore();

		switch (chosen)
		{
		case 1:
			cout << setw(20) << left << "\nNhap ma ISBN: ";
			getline(cin, _borrowedBookID);


			posOfBook = findPosOfABookByISBN(totalBooks, book, _borrowedBookID);

			if (_borrowedBookID.empty())
			{
				cout << "\nKhong duoc de trong! Vui long thuc hien lai! \n";
				continue;
			}
			if (posOfBook == -1)
			{
				cout << "\nKhong tim thay thong tin sach! Vui long thuc hien lai! \n ";
				continue;
			}
			if (book[posOfBook].bookQuantity == 0)
			{
				cout << "\nSach nay dang tam thoi het! Vui long thuc hien lai!\n";
				continue;
			}
			if (alreadyBorrowed(totalTickets, ticket, temp, posOfBook))
			{
				cout << "\nBan da muon sach nay roi! Vui long thuc hien lai!\n";
				continue;
			}

			temp.bookStatus[posOfBook] = 1;
			book[posOfBook].bookQuantity--;
			dem++;

			cout << "\nMuon sach thanh cong! Bam phim bat ki de tiep tuc!\n";
			system("pause");
			system("cls");
			continue;
		case 2:
			cout << endl;
			displayAllBooks(totalBooks, book);
			cout << endl;
			continue;
		case 0:
			if (dem == 0)
			{
				return;
			}
			else
			{
				break;
			}
		default:
			cout << "\nLua chon khong hop le! Vui long nhap lai!\n\n";
			system("pause");
			system("cls");
			continue;
		}
		break;
	}

	ticket[totalTickets] = temp;

	totalTickets++;


	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');

	cout << "Thong tin phieu muon da duoc them!\n";
	saveTicket(totalTickets, totalBooks, ticket);
}

void returnBook
(
	int		totalTickets,
	int		totalReaders,
	int		totalBooks,
	Ticket	ticket[],
	Reader	reader[],
	Book	book[]
)
{
	if (totalTickets == 0)
	{
		cout << "Chua co phieu muon nao duoc lap! Vui long them phieu muon!\n";
		return;
	}

	if (allTicketsOutOfBorrowedBooks(totalTickets, totalBooks, ticket))
	{
		cout << "Toan bo phieu muon hien khong con sach can tra lai! Vui long thuc hien lai sau!\n";
		return;
	}

	displayAllTickets(totalTickets, totalBooks, ticket, book);

	int		chosen;
	string	_bookID;
	int		_realReturnDay,
			_realReturnMonth,
			_realReturnYear;
	int		posOfBook, posOfTicket;


	cout << "\n1. Chon phieu muon de tra sach\n"
		<< "0. Quay ve Menu Muon/Tra sach\n";
	cout << "\nNhap lua chon cua ban: ";

	cin >> chosen;

	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');

	switch (chosen)
	{
	case 1:
		while (true)
		{
			cout << "Nhap STT cua 1 phieu o tren: ";
			cin >> posOfTicket;

			if (posOfTicket >= totalTickets || posOfTicket < 0)
			{
				cout << "\nSTT khong hop le! Vui long nhap lai!\n\n";
				continue;
			}

			if (aTicketOutOfBorrowedBooks(posOfTicket, totalBooks, ticket))
			{
				cout << "\nPhieu muon nay khong con sach can tra lai! Vui long nhap lai\n\n";
				continue;
			}

			break;
		}

		system("cls");

		cout << "Thong tin cua phieu duoc chon la:\n\n";
		displayTicketTableTitle();
		displayABorrowTicketByPos(posOfTicket, totalTickets, totalBooks, ticket, book);

		cout << "\n1. Tra sach\n"
			<< "2. Bao mat sach\n"
			<< "0. Quay ve Menu Muon/Tra sach\n";

		cout << "\nNhap lua chon cua ban: ";
		cin >> chosen;

		cout << setfill('-');
		cout << setw(60) << "-" << endl;
		cout << setfill(' ');

		cin.ignore();

		switch (chosen)
		{
		case 1:
			while (true)
			{
				cout << "Nhap ma ISBN cua sach muon tra: ";
				getline(cin, _bookID);

				posOfBook = findPosOfABookByISBN(totalBooks, book, _bookID);

				if (_bookID.empty())
				{
					cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
					continue;
				}
				if (ticket[posOfTicket].bookStatus[posOfBook] != 1)
				{
					cout << "\nBan chi duoc chon sach dang muon trong phieu muon nay! Vui long nhap lai!\n\n";
					continue;
				}
				break;
			}

			cout << setfill('-');
			cout << setw(60) << "-" << endl;
			cout << setfill(' ');

			while (true)
			{
				cout << "Nhap ngay tra sach: \n"
					<< setw(20) << left << " Nhap ngay: ";
				cin >> _realReturnDay;

				cout << setw(20) << left << " Nhap thang: ";
				cin >> _realReturnMonth;

				cout << setw(20) << left << " Nhap nam: ";
				cin >> _realReturnYear;

				if (isValidDate(_realReturnDay, _realReturnMonth, _realReturnYear) == 0)
				{
					cout << "\nNgay khong hop le! Vui long nhap lai! \n\n";
					continue;
				}

				if (isDayLater(_realReturnDay, _realReturnMonth, _realReturnYear,
					ticket[posOfTicket].borrowDay, ticket[posOfTicket].borrowMonth, ticket[posOfTicket].borrowYear) == 0)
				{
					cout << "\nNgay tra khong duoc nhap o truoc ngay muon sach! Vui long nhap lai!\n\n";
					continue;
				}
				break;
			}

			ticket[posOfTicket].realReturnDay[posOfBook] = _realReturnDay;
			ticket[posOfTicket].realReturnMonth[posOfBook] = _realReturnMonth;
			ticket[posOfTicket].realReturnYear[posOfBook] = _realReturnYear;

			updateBookStatusAndFee(posOfTicket, posOfBook, ticket, book);
			if (ticket[posOfTicket].bookStatus[posOfBook] == 2)
			{
				cout << "\nCam on ban da tra sach dung han!\n";
			}
			else if (ticket[posOfTicket].bookStatus[posOfBook] == 3)
			{
				cout << "\nBan da tra sach qua han!"
					<< "\nSo tien bi phat do tra sach qua han la: " << ticket[posOfTicket].bookFee[posOfBook];
				cout << endl;
			}
			break;
		case 2:
			while (true)
			{
				cout << "Nhap ma ISBN cua sach muon bao mat: ";
				getline(cin, _bookID);

				posOfBook = findPosOfABookByISBN(totalBooks, book, _bookID);

				if (_bookID.empty())
				{
					cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
					continue;
				}
				if (ticket[posOfTicket].bookStatus[posOfBook] != 1)
				{
					cout << "\nBan chi duoc chon sach dang muon trong phieu nay! Vui long nhap lai!\n\n";
					continue;
				}
				break;
			}

			cout << setfill('-');
			cout << setw(60) << "-" << endl;
			cout << setfill(' ');

			while (true)
			{
				cout << "Nhap ngay bao mat sach: \n"
					<< setw(20) << left << " Nhap ngay: ";
				cin >> _realReturnDay;

				cout << setw(20) << left << " Nhap thang: ";
				cin >> _realReturnMonth;

				cout << setw(20) << left << " Nhap nam: ";
				cin >> _realReturnYear;

				if (isValidDate(_realReturnDay, _realReturnMonth, _realReturnYear) == 0)
				{
					cout << "\nNgay khong hop le! Vui long nhap lai! \n\n";
					continue;
				}

				if (isDayLater(_realReturnDay, _realReturnMonth, _realReturnYear,
					ticket[posOfTicket].borrowDay, ticket[posOfTicket].borrowMonth, ticket[posOfTicket].borrowYear) == 0)
				{
					cout << "\nNgay bao mat khong duoc nhap o truoc ngay muon sach! Vui long nhap lai!\n\n";
					continue;
				}
				break;
			}

			ticket[posOfTicket].realReturnDay[posOfBook] = _realReturnDay;
			ticket[posOfTicket].realReturnMonth[posOfBook] = _realReturnMonth;
			ticket[posOfTicket].realReturnYear[posOfBook] = _realReturnYear;

			ticket[posOfTicket].bookStatus[posOfBook] = 4;
			updateBookStatusAndFee(posOfTicket, posOfBook, ticket, book);

			cout << "\nSo tien bi phat do lam mat sach la: " << ticket[posOfTicket].bookFee[posOfBook];
			cout << endl;
			break;
		case 0:
			return;
		default:
			cout << "\nLua chon khong hop le! Vui long thuc hien lai!\n";
			return;
		}
	case 0:
		return;
	default:
		cout << "\nLua chon khong hop le! Vui long thuc hien lai!\n";
		return;
	}
}

void updateBookStatusAndFee(int posOfTicket, int posOfBook, Ticket ticket[], Book book[])
{
	int exDay = ticket[posOfTicket].expectedReturnDay;
	int exMonth = ticket[posOfTicket].expectedReturnMonth;
	int exYear = ticket[posOfTicket].expectedReturnYear;

	int reDay = ticket[posOfTicket].realReturnDay[posOfBook];
	int reMonth = ticket[posOfTicket].realReturnMonth[posOfBook];
	int reYear = ticket[posOfTicket].realReturnYear[posOfBook];

	if (ticket[posOfTicket].bookStatus[posOfBook] == 4)
	{
		int distance = distanceBetweenTwoDates(reDay, reMonth, reYear, exDay, exMonth, exYear);

		ticket[posOfTicket].bookFee[posOfBook] = 5000 * distance + book[posOfBook].bookPrice * 2;
		return;
	}

	if (isDayLater(exDay, exMonth, exYear, reDay, reMonth, reYear))
	{
		ticket[posOfTicket].bookStatus[posOfBook] = 2;
		book[posOfBook].bookQuantity++;
	}
	else
	{
		int distance = distanceBetweenTwoDates(reDay, reMonth, reYear, exDay, exMonth, exYear);

		ticket[posOfTicket].bookStatus[posOfBook] = 3;
		ticket[posOfTicket].bookFee[posOfBook] = 5000 * distance;
		book[posOfBook].bookQuantity++;
	}
}

void displayABorrowTicketByPos(int pos, int totalTickets, int totalBooks, Ticket ticket[], Book book[])
{
	string _borrowDay = to_string(ticket[pos].borrowDay) + '/' + to_string(ticket[pos].borrowMonth) + '/' + to_string(ticket[pos].borrowYear);
	string _expectedReturnDay = to_string(ticket[pos].expectedReturnDay) + '/' + to_string(ticket[pos].expectedReturnMonth) + '/' + to_string(ticket[pos].expectedReturnYear);
	string _realReturnDay, _bookStatus;

	cout << setfill('-');
	cout << setw(130) << "-" << endl;
	cout << setfill(' ');

	cout << setw(5) << left << pos;
	cout << setw(15) << left << ticket[pos].borrowerID;
	cout << setw(15) << left << _borrowDay;
	cout << setw(20) << left << _expectedReturnDay;

	bool flag = 0;
	for (int i = 0; i < totalBooks; i++)
	{
		if (ticket[pos].bookStatus[i] != 0)
		{
			if (flag != 0) cout << setw(55) << " ";
			cout << setw(20) << left << book[i].bookID;

			if (ticket[pos].bookStatus[i] == 1) _bookStatus = "Dang muon";
			else if (ticket[pos].bookStatus[i] == 2) _bookStatus = "Tra sach dung han";
			else if (ticket[pos].bookStatus[i] == 3) _bookStatus = "Tra sach qua han";
			else if (ticket[pos].bookStatus[i] == 4) _bookStatus = "Sach bi mat";

			if (ticket[pos].realReturnDay[i] != 0)
			{
				_realReturnDay = to_string(ticket[pos].realReturnDay[i]) + '/' + to_string(ticket[pos].realReturnMonth[i]) + '/' + to_string(ticket[pos].realReturnYear[i]);
			}
			else _realReturnDay = "";

			cout << setw(25) << left << _bookStatus;
			cout << setw(20) << left << _realReturnDay;
			cout << setw(15) << left << ticket[pos].bookFee[i] << endl;
			flag = 1;
		}
	}
}

void displayAllTickets(int totalTickets, int totalBooks, Ticket ticket[], Book book[])
{
	if (totalTickets == 0)
	{
		cout << "Chua co phieu muon nao duoc lap! Vui long them phieu muon!\n";
		return;
	}

	displayTicketTableTitle();

	for (int i = 0; i < totalTickets; i++)
	{
		displayABorrowTicketByPos(i, totalTickets, totalBooks, ticket, book);
	}
	cout << setfill('-');
	cout << setw(130) << "-" << endl;
	cout << setfill(' ');
}

void displayTicketTableTitle()
{
	cout << setw(5) << left << "STT";
	cout << setw(15) << left << "Ma Doc Gia";
	cout << setw(15) << left << "Ngay muon";
	cout << setw(20) << left << "Ngay tra du kien";
	cout << setw(20) << left << "Ma ISBN cua sach";
	cout << setw(25) << left << "Trang thai sach";
	cout << setw(20) << left << "Ngay tra thuc te";
	cout << setw(15) << left << "So tien phat" << endl;
}

void displayAllBorrowedBooks(int totalTickets, int totalBooks, Ticket ticket[], Book book[])
{
	if (totalTickets == 0)
	{
		cout << "Chua co phieu muon nao duoc lap! Vui long them phieu muon!\n";
		return;
	}

	if (allTicketsOutOfBorrowedBooks(totalTickets, totalBooks, ticket))
	{
		cout << "Hien tai khong co sach nao dang duoc muon! Vui long thuc hien lai sau!\n";
		return;
	}

	cout << "Thong tin cua toan bo sach dang duoc muon: \n\n";

	cout << setw(15) << left << "Ma ISBN";
	cout << setw(15) << left << "Ten sach";
	cout << setw(15) << left << "Tac gia";
	cout << setw(15) << left << "Nha xuat ban";
	cout << setw(15) << left << "Nam xuat ban";
	cout << setw(15) << left << "The loai";
	cout << setw(15) << left << "Gia sach";
	cout << setw(20) << left << "So sach con lai";
	cout << setw(20) << left << "Ma doc gia dang muon" << endl;

	int countBorrowers = 0;
	for (int i = 0; i < totalBooks; i++)
	{
		if (aBookOutOfBorrowers(i, totalTickets, ticket) == 0)
		{
			cout << setfill('-');
			cout << setw(145) << "-" << endl;
			cout << setfill(' ');

			cout << setw(15) << left << book[i].bookID;
			cout << setw(15) << left << book[i].bookName;
			cout << setw(15) << left << book[i].author;
			cout << setw(15) << left << book[i].publisher;
			cout << setw(15) << left << book[i].publishYear;
			cout << setw(15) << left << book[i].category;
			cout << setw(15) << left << book[i].bookPrice;
			cout << setw(20) << left << book[i].bookQuantity;

			int count = 0;
			for (int j = 0; j < totalTickets; j++)
			{
				if (ticket[j].bookStatus[i] == 1)
				{
					if (count != 0)	cout << setw(125) << " ";
					cout << setw(20) << left << ticket[j].borrowerID << endl;
					count++;
					countBorrowers++;
				}
			}
		}
	}

	cout << "\nTong so sach dang duoc muon hien tai la: " << countBorrowers << endl;
}

void displayBorrowerReturnLate
(
	int		totalTickets,
	int		totalReaders,
	int		totalBooks,
	Ticket	ticket[],
	Reader	reader[],
	Book	book[]
)
{
	if (totalTickets == 0)
	{
		cout << "Chua co phieu muon nao duoc lap! Vui long them phieu muon!\n";
		return;
	}

	if (allTicketsNoReturnLate(totalTickets, totalBooks, ticket))
	{
		cout << "Hien tai khong co doc gia nao tra sach tre han! Vui long thuc hien lai sau!\n";
		return;
	}

	cout << "Thong tin cua toan bo doc gia tra sach tre han: \n\n";

	cout << setw(15) << left << "Ma Doc Gia";
	cout << setw(15) << left << "Ho Ten";
	cout << setw(15) << left << "CMND";
	cout << setw(30) << left << "Ma ISBN cua sach tre han";
	cout << setw(15) << left << "So tien phat" << endl;

	for (int posOfReader = 0; posOfReader < totalReaders; posOfReader++)
	{
		bool flag = 0;
		for (int posOfTicket = 0; posOfTicket < totalTickets; posOfTicket++)
		{
			if (reader[posOfReader].readerID == ticket[posOfTicket].borrowerID)
			{
				if (aTicketNoReturnLate(posOfTicket, totalBooks, ticket) == 0)
				{
					if (flag == 0)
					{
						cout << setfill('-');
						cout << setw(90) << "-" << endl;
						cout << setfill(' ');

						cout << setw(15) << left << ticket[posOfTicket].borrowerID;
						cout << setw(15) << left << reader[posOfReader].name;
						cout << setw(15) << left << reader[posOfReader].nationalID;
					}

					int count = 0;
					for (int posOfBook = 0; posOfBook < totalBooks; posOfBook++)
					{
						if (ticket[posOfTicket].bookStatus[posOfBook] == 3)
						{
							if (count != 0 || flag == 1) 	cout << setw(45) << " ";
							cout << setw(30) << left << book[posOfBook].bookID;
							cout << setw(15) << left << ticket[posOfTicket].bookFee[posOfBook] << endl;
							count++;
						}
					}
					flag = 1;
				}
			}

		}
	}
	cout << "\nDa xuat thanh cong danh sach cac doc gia tra sach tre han!\n";
}

bool alreadyBorrowed(int totalTickets, Ticket ticket[], Ticket currentTicket, int posOfBook)
{

	if (currentTicket.bookStatus[posOfBook] == 1) return 1;

	for (int i = 0; i < totalTickets; i++)
	{
		if (ticket[i].borrowerID == currentTicket.borrowerID)
		{
			if (ticket[i].bookStatus[posOfBook] == 1) return 1;
		}
	}

	return 0;
}

bool isDayLater(int d1, int m1, int y1, int d2, int m2, int y2)
{
	if (y1 < y2) return 0;
	if (y1 > y2) return 1;
	if (y1 == y2)
	{
		if (m1 < m2) return 0;
		if (m1 > m2) return 1;
		if (m1 == m2)
		{
			if (d1 < d2) return 0;
			return 1;
		}
	}
}

void tomorow(int& day, int& month, int& year)
{
	if (day == daysOfMonth(month, year))
	{
		if (month == 12)
		{
			day = 1;
			month = 1;
			year++;
		}
		else
		{
			day = 1;
			month++;
		}
	}

	else
	{
		day++;
	}
}

int distanceBetweenTwoDates(int d1, int m1, int y1, int d2, int m2, int y2)
{
	int ans = 0;

	while (d1 != d2 || m1 != m2 || y1 != y2)
	{
		tomorow(d2, m2, y2);
		ans++;
	}

	return ans;
}

bool aTicketOutOfBorrowedBooks(int posOfTicket, int totalBooks, Ticket ticket[])
{
	for (int i = 0; i < totalBooks; i++)
	{
		if (ticket[posOfTicket].bookStatus[i] == 1) return 0;
	}
	return 1;
}

bool allTicketsOutOfBorrowedBooks(int totalTickets, int totalBooks, Ticket ticket[])
{
	for (int i = 0; i < totalTickets; i++)
	{
		if (aTicketOutOfBorrowedBooks(i, totalBooks, ticket) == 0) return 0;
	}
	return 1;
}

bool aTicketNoReturnLate(int posOfTicket, int totalBooks, Ticket ticket[])
{
	for (int i = 0; i < totalBooks; i++)
	{
		if (ticket[posOfTicket].bookStatus[i] == 3) return 0;
	}
	return 1;
}

bool allTicketsNoReturnLate(int totalTickets, int totalBooks, Ticket ticket[])
{
	for (int i = 0; i < totalTickets; i++)
	{
		for (int j = 0; j < totalBooks; j++)
		{
			if (ticket[i].bookStatus[j] == 3) return 0;
		}
	}
	return 1;
}

bool aBookOutOfBorrowers(int posOfBook, int totalTickets, Ticket ticket[])
{
	for (int i = 0; i < totalTickets; i++)
	{
		if (ticket[i].bookStatus[posOfBook] == 1) return 0;
	}
	return 1;
}

int countBorrowersOfABook(int posOfBook, int totalTickets, Ticket ticket[])
{
	int count = 0;
	for (int i = 0; i < totalTickets; i++)
	{
		if (ticket[i].bookStatus[posOfBook]) count++;
	}
	return count;
}