#include "BookManagement.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
using namespace std;

void loadBook(int& totalBooks, Book book[])
{
	ifstream fp("Source_Code\\Data\\Book.txt");

	fp >> totalBooks;

	fp.ignore();

	for (int i = 0; i < totalBooks; i++)
	{
		getline(fp, book[i].bookID);
		getline(fp, book[i].bookName);
		getline(fp, book[i].author);
		getline(fp, book[i].publisher);
		getline(fp, book[i].category);
		fp >> book[i].publishYear;
		fp >> book[i].bookPrice;
		fp >> book[i].bookQuantity;
		fp.ignore();
	}

	fp.close();
}

void saveBook(int totalBooks, Book book[])
{
	ofstream fp ("Source_Code\\Data\\Book.txt");

	fp << totalBooks << '\n';

	for (int i = 0; i < totalBooks; i++)
	{
		fp << book[i].bookID << '\n';
		fp << book[i].bookName << '\n';
		fp << book[i].author << '\n';
		fp << book[i].publisher << '\n';
		fp << book[i].category << '\n';
		fp << book[i].publishYear << '\n';
		fp << book[i].bookPrice << '\n';
		fp << book[i].bookQuantity << '\n';
	}
	fp.close();
}

void addBook(int &totalBooks, Book book[])
{
	Book temp;

	cin.ignore();

	while (true)
	{
		cout << setw(20) << left << "Nhap ma ISBN: ";
		getline(cin, temp.bookID);

		if (temp.bookID.empty())
		{
			cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
			continue;
		}

		if (findPosOfABookByISBN(totalBooks, book, temp.bookID) != -1)
		{
			cout << "\nMa ISBN khong duoc trung voi ma da co! Vui long nhap lai! \n\n ";
			continue;
		}

		break;
	}

	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');

	do
	{
		cout << setw(20) << left << "Nhap ten sach: ";
		getline(cin, temp.bookName);
		if (temp.bookName.empty()) cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
	} while (temp.bookName.empty());

	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');


	while (true)
	{
		cout << setw(20) << left << "Nhap ten tac gia: ";
		getline(cin, temp.author);

		if (temp.author.empty())
		{
			cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
			continue;
		}

		break;
	}


	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');

	while (true)
	{
		cout << setw(20) << left << "Nhap ten NXB: ";
		getline(cin, temp.publisher);

		if (temp.publisher.empty())
		{
			cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
			continue;
		}
		break;
	}

	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');

	while (true)
	{
		cout << setw(20) << left << "Nhap nam xuat ban: ";
		cin >> temp.publishYear;
		if (temp.publishYear < 1)
		{
			cout << "\nDu lieu khong hop le! Vui long nhap lai! \n\n";
			continue;
		}
		break;
	}

	cin.ignore();
	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');

	do
	{
		cout << setw(20) << left << "Nhap the loai: ";
		getline(cin, temp.category);
		if (temp.category.empty()) cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
	} while (temp.category.empty());

	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');

	do
	{
		cout << setw(20) << left << "Nhap gia sach: ";
		cin >> temp.bookPrice;
		if (temp.bookPrice < 1) cout << "\nDu lieu khong hop le! Vui long nhap lai! \n\n";
	} while (temp.bookPrice < 1);

	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');

	do
	{
		cout << setw(20) << left << "Nhap so luong sach: ";
		cin >> temp.bookQuantity;
		if (temp.bookQuantity < 1) cout << "\nDu lieu khong hop le! Vui long nhap lai! \n\n";
	} while (temp.bookQuantity < 1);

	book[totalBooks] = temp;

	totalBooks++;

	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');

	cout << "Thong tin sach da duoc them!\n";
	saveBook(totalBooks, book);
}

void changeBookInfo(int totalBooks, Book book[])
{
	//Neu chua co sach nao duoc nhap thong tin thi quay ve menu
	if (totalBooks == 0)
	{
		cout << "Chua co sach nao duoc nhap! Vui long them thong tin sach tai lua chon 2\n";

		return;
	}

	string currentISBN;
	int pos, chosen;

	//Hien thi cac lua chon tim kiem
	//Do Ma ISBN la duy nhat nen se su dung de tim kiem	
	cout << "1. Tim sach bang ma ISBN\n"
		<< "0. Huy thay doi. Quay ve Menu Sach!\n";

	cout << "\nNhap lua chon cua ban: ";
	cin >> chosen;

	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');

	cin.ignore();

	switch (chosen)
	{
	case 1:
		do
		{
			cout << "Nhap ma ISBN: ";
			getline(cin, currentISBN);
			if (currentISBN.empty()) cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
		} while (currentISBN.empty());

		pos = findPosOfABookByISBN(totalBooks, book, currentISBN);

		if (pos == -1) {
			cout << "\nKhong tim thay thong tin sach! Vui long thuc hien lai!\n";

			return;
		}
		break;
	case 0:
		return;
	default:
		cout << "Lua chon khong hop le! Vui long thuc hien lai!\n";

		return;
	}

	while(true)
	{
		cout << setfill('-');
		cout << setw(60) << "-" << endl;
		cout << setfill(' ');

		cout << "Day la thong tin sach da chon:\n\n";

		displayBookTableTitle();
		displayABookByPos(pos, book);

		cout << "\nChon thong tin ban muon thay doi: \n"
			<< "1. Ma ISBN\n"
			<< "2. Ten sach\n"
			<< "3. Tac gia\n"
			<< "4. Nha xuat ban\n"
			<< "5. Nam xuat ban\n"
			<< "6. The loai\n"
			<< "7. Gia sach\n"
			<< "8. So quyen sach\n"
			<< "0. Huy thay doi. Quay ve Menu Sach!\n";


		cout << "\nNhap lua chon cua ban: ";
		cin >> chosen;

		Book temp;

		cin.ignore();

		cout << setfill('-');
		cout << setw(60) << "-";
		cout << setfill(' ');

		switch (chosen) {
		case 1:
			while (true)
			{
				cout << setw(20) << left << "\nNhap ma ISBN moi: ";
				getline(cin, temp.bookID);

				if (temp.bookID.empty())
				{
					cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
					continue;
				}

				if (findPosOfABookByISBN(totalBooks, book, temp.bookID) != -1)
				{
					cout << "\nMa ISBN khong duoc trung voi ma da co! Vui long nhap lai! \n\n ";
					continue;
				}

				break;
			}

			book[pos].bookID = temp.bookID;
			break;

		case 2:
			do
			{
				cout << setw(20) << left << "\nNhap ten sach moi: ";
				getline(cin, temp.bookName);
				if (temp.bookName.empty()) cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
			} while (temp.bookName.empty());

			book[pos].bookName = temp.bookName;
			break;

		case 3:
			while (true)
			{
				cout << setw(20) << left << "\nNhap ten tac gia moi: ";
				getline(cin, temp.author);

				if (temp.author.empty())
				{
					cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
					continue;
				}

				break;
			}

			book[pos].author = temp.author;
			break;

		case 4:
			while (true)
			{
				cout << setw(20) << left << "\nNhap ten NXB moi: ";
				getline(cin, temp.publisher);

				if (temp.publisher.empty())
				{
					cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
					continue;
				}
				break;
			}

			book[pos].publisher = temp.publisher;

			break;

		case 5:
			while (true)
			{
				cout << setw(20) << left << "\nNhap nam xuat ban moi: ";
				cin >> temp.publishYear;
				if (temp.publishYear < 1)
				{
					cout << "\nDu lieu khong hop le! Vui long nhap lai! \n\n";
					continue;
				}
				break;
			}

			book[pos].publishYear = temp.publishYear;
			break;

		case 6:
			do
			{
				cout << setw(20) << left << "\nNhap the loai moi: ";
				getline(cin, temp.category);
				if (temp.category.empty()) cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
			} while (temp.category.empty());

			book[pos].category = temp.category;
			break;

		case 7:
			do
			{
				cout << setw(20) << left << "\nNhap gia sach moi: ";
				cin >> temp.bookPrice;
				if (temp.bookPrice < 1) cout << "\nDu lieu khong hop le! Vui long nhap lai! \n\n";
			} while (temp.bookPrice < 1);

			book[pos].bookPrice = temp.bookPrice;
			break;

		case 8:
			do
			{
				cout << setw(20) << left << "\nNhap so luong sach moi: ";
				cin >> temp.bookQuantity;
				if (temp.bookQuantity < 1) cout << "\nDu lieu khong hop le! Vui long nhap lai! \n\n";
			} while (temp.bookQuantity < 1);

			book[pos].bookQuantity = temp.bookQuantity;

			break;

		case 0:
			cout << '\n';
			return;

		default:
			cout << "\nLua chon khong hop le! Vui long thuc hien lai! \n";

			return;
		}

		cout << setfill('-');
		cout << setw(60) << "-" << endl;
		cout << setfill(' ');

		cout << "Thong tin sach da duoc thay doi!\n";
		saveBook(totalBooks, book);
		system("pause");
		system("cls");
	}
}

void deleteBookInfo(int& totalBooks, Book book[])
{
	//Neu chua co sach nao duoc nhap thong tin thi quay ve menu
	if (totalBooks == 0)
	{
		cout << "Chua co sach nao duoc nhap! Vui long them thong tin sach tai lua chon 2\n";

		return;
	}

	string currentISBN;
	int pos, chosen;

	//Hien thi cac lua chon tim kiem
	//Do Ma ISBN la duy nhat nen se su dung de tim kiem
	cout << "1. Tim sach bang ma ISBN\n"
		<< "0. Huy thay doi. Quay ve Menu Sach!\n";

	cout << "\nNhap lua chon cua ban: ";
	cin >> chosen;

	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');

	cin.ignore();

	switch (chosen)
	{
	case 1:
		do
		{
			cout << "Nhap ma ISBN: ";
			getline(cin, currentISBN);
			if (currentISBN.empty()) cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
		} while (currentISBN.empty());

		pos = findPosOfABookByISBN(totalBooks, book, currentISBN);

		if (pos == -1) {
			cout << "\nKhong tim thay thong tin sach! Vui long thuc hien lai!\n";

			return;
		}
		break;
	case 0:
		return;
	default:
		cout << "Lua chon khong hop le! Vui long thuc hien lai!\n";

		return;
	}

	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');

	cout << "Day la thong tin sach da chon:\n\n";
	displayBookTableTitle();
	displayABookByPos(pos, book);

	cout << "\nDay co phai la sach ban muon xoa thong tin?\n"
		<< "1. Dung roi! Xoa ngay!\n"
		<< "0. Sai roi! Toi muon thuc hien lai!\n";

	cout << "\nNhap lua chon cua ban: ";
	cin >> chosen;

	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');

	switch (chosen)
	{
	case 1:
		for (int i = pos; i < totalBooks; i++)
		{
			book[i] = book[i + 1];
		}

		totalBooks--;

		cout << "Thong tin sach nay da duoc xoa!\n";
		saveBook(totalBooks, book);
		break;
	case 0:
		break;
	default:
		cout << "Lua chon khong hop le! Vui long thuc hien lai!\n";
		break;
	}

	return;
}

void displayAllBooks(int totalBooks, Book book[])
{
	//Neu chua co sach nao duoc nhap thong tin thi quay ve menu
	if (totalBooks == 0)
	{
		cout << "Chua co sach nao duoc nhap! Vui long them thong tin sach!\n";

		return;
	}

	displayBookTableTitle();
	for (int i = 0; i < totalBooks; i++)
	{
		displayABookByPos(i, book);
	}

}

void displayABookByPos(int pos, Book book[])
{
	cout << setw(15) << left << book[pos].bookID;
	cout << setw(25) << left << book[pos].bookName;
	cout << setw(15) << left << book[pos].author;
	cout << setw(15) << left << book[pos].publisher;
	cout << setw(15) << left << book[pos].publishYear;
	cout << setw(15) << left << book[pos].category;
	cout << setw(15) << left << book[pos].bookPrice;
	cout << setw(15) << left << book[pos].bookQuantity << endl;
}

void displayABookByISBN(int totalBooks, Book book[])
{
	//Neu chua co sach nao duoc nhap thong tin thi quay ve menu
	if (totalBooks == 0)
	{
		cout << "Chua co sach nao duoc nhap! Vui long them thong tin sach tai lua chon 2\n";
		return;
	}
	int pos;
	string currentISBN;

	cin.ignore();

	while (true)
	{
		cout << "Nhap ma ISBN: ";
		getline(cin, currentISBN);

		if (currentISBN.empty())
		{
			cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
			continue;
		}
		break;
	}
	pos = findPosOfABookByISBN(totalBooks, book, currentISBN);

	if (pos == -1) {
		cout << "\nKhong tim thay thong tin sach! Vui long thuc hien lai!\n";

		return;
	}

	cout << "\nThong tin cua sach da chon la: \n\n";

	displayBookTableTitle();
	displayABookByPos(pos, book);
	cout << '\n';

}

void displayABookByName(int totalBooks, Book book[])
{
	//Neu chua co sach nao duoc nhap thong tin thi quay ve menu
	if (totalBooks == 0)
	{
		cout << "Chua co sach nao duoc nhap! Vui long them thong tin sach tai lua chon 2\n";
		return;
	}
	int pos;
	string currentBookName;

	cin.ignore();

	do
	{
		cout << "Nhap ten sach: ";
		getline(cin, currentBookName);
		if (currentBookName.empty()) cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
	} while (currentBookName.empty());

	pos = findPosOfABookByName(totalBooks, book, currentBookName);

	if (pos == -1) {
		cout << "\nKhong tim thay thong tin sach! Vui long thuc hien lai!\n";

		return;
	}

	cout << "\nThong tin cua nhung quyen sach co ten " << currentBookName << " la: \n\n";
	displayBookTableTitle();
	for (int i = 0; i < totalBooks; i++)
	{
		if (book[i].bookName == book[pos].bookName)
		{
			displayABookByPos(pos, book);
		}
	}
	cout << endl;
}
void displayBookTableTitle()
{
	cout << setw(15) << left << "Ma ISBN";
	cout << setw(25) << left << "Ten sach";
	cout << setw(15) << left << "Tac gia";
	cout << setw(15) << left << "Nha xuat ban";
	cout << setw(15) << left << "Nam xuat ban";
	cout << setw(15) << left << "The loai";
	cout << setw(15) << left << "Gia sach";
	cout << setw(15) << left << "So sach con lai" << endl;

	cout << setfill('-');
	cout << setw(130) << "-" << '\n';
	cout << setfill(' ');
}

int findPosOfABookByISBN(int totalBooks, Book book[], string currentISBN)
{
	int pos = -1;

	for (int i = 0; i < totalBooks; i++)
	{
		if (book[i].bookID == currentISBN) pos = i;
	}

	return pos;
}

int findPosOfABookByName(int totalBooks, Book book[], string currentBookName)
{
	int pos = -1;

	for (int i = 0; i < totalBooks; i++)
	{
		if (book[i].bookName == currentBookName) pos = i;
	}

	return pos;
}

bool bookAvailable(int totalBooks, Book book[])
{
	for (int i = 0; i < totalBooks; i++)
	{
		if (book[i].bookQuantity != 0) return 1;
	}
	return 0;
}

int countBooks(int totalBooks, Book book[])
{
	int count = 0;
	for (int i = 0; i < totalBooks; i++)
	{
		count = count + book[i].bookQuantity;
	}
	return count;
}

void addCategoryToSet(string categorySet[], int& number, string _category)
{
	for (int i = 0; i < number; i++)
	{
		if (categorySet[i] == _category)
		{
			return;
		}
	}

	categorySet[number] = _category;
	number++;
}

void statisticizeBookByCategory(int totalBooks, Book book[])
{
	string categorySet[100];
	int number = 0;
	for (int i = 0; i < totalBooks; i++)
	{
		addCategoryToSet(categorySet, number, book[i].category);
	}

	cout << setw(15) << left << "The loai";
	cout << setw(15) << left << "So sach con lai" << endl;

	cout << setfill('-');
	cout << setw(30) << "-" << '\n';
	cout << setfill(' ');

	for (int i = 0; i < number; i++)
	{
		cout << setw(15) << left << categorySet[i];
		cout << setw(15) << left << countBooksByCategory(totalBooks, book, categorySet[i]) << endl;
	}
	cout << endl;
}

int countBooksByCategory(int totalBooks, Book book[], string _category)
{
	int count = 0;
	for (int i = 0; i < totalBooks; i++)
	{
		if (book[i].category == _category) count++;
	}
	return count;
}