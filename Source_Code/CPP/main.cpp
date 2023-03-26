#include "DisplayMenu.h"
#include "ReaderManagement.h"
#include "BookManagement.h"
#include "TicketManagement.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int main()
{
	
	while (true)
	{
		string email, password;
		cout << setfill('-');
		cout << setw(60) << '-' << endl;
		cout << setfill(' ');

		cout << setw(25) << ' ' << "DANG NHAP" << endl;
		cout << "1. Dang nhap de su dung thu vien\n"
			<< "0. Thoat chuong trinh\n";

		cout << "\nNhap lua chon cua ban: ";
		int choice;
		cin >> choice;

		switch(choice)
		{
		case 1:
			cin.ignore();
			cout << "\nNhap tai khoan: ";
			getline(cin, email);
			cout << "Nhap mat khau: ";
			getline(cin, password);
			if (email.empty())
			{
				cout << "\nEmail khong duoc de trong! Vui long nhap lai!\n";
				system("pause");
				system("cls");
				continue;
			}
			if (password.empty())
			{
				cout << "\nMat khau khong duoc de trong! Vui long nhap lai!\n";
				system("pause");
				system("cls");
				continue;
			}
			if (!(email == "admin" && password == "admin"))
			{
				cout << "\nTai khoan khong hop le! Vui long thuc hien lai!\n";
				system("pause");
				system("cls");
				continue;
			}
			break;
		case 0:
			system("cls");
			cout << setw(22) << ' ' << "BYE BYE BAN NHE!\n";
			system("pause");
			return 0;
		}
		break;
	}

	system("cls");
	
	int		totalReaders = 0;
	Reader	reader[100];

	int		totalBooks = 0;
	Book	book[100];

	int		totalTickets = 0;
	Ticket	ticket[100];

	loadReader(totalReaders, reader);
	loadBook(totalBooks, book);
	loadTicket(totalTickets, ticket);

	while (true)
	{
		cout << setfill('-');
		cout << setw(60) << '-' << endl;
		cout << setfill(' ');

		cout << setw(25) << ' ' << "MAIN MENU" << endl;

		cout << "1. Quan ly doc gia \n"
			<< "2. Quan ly sach \n"
			<< "3. Quan ly muon/tra sach\n"
			<< "4. Cac Thong ke co ban\n"
			<< "0. Ket thuc chuong trinh\n";

		int chosen;
		cout << "\nNhap lua chon cua ban: ";
		cin >> chosen;

		system("cls");

		switch (chosen)
		{
		case 1:
			manageReader(totalReaders, reader);
			break;
		case 2:
			manageBook(totalBooks, book);
			break;
		case 3:
			manageTicket(totalTickets, totalReaders, totalBooks, ticket, reader, book);
			break;
		case 4:
			manageStatics(totalTickets, totalReaders, totalBooks, ticket, reader, book);
			break;
		case 0:
			cout << setw(22) << ' ' << "BYE BYE BAN NHE!\n";
			saveReader(totalReaders, reader);
			system("pause");
			return 0;
		default:
			cout << "Lua chon khong hop le! Vui long nhap lai!\n";
			break;
		}
		system("cls");
	}

	return 0;
}