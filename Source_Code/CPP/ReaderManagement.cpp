#include "ReaderManagement.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
using namespace std;

void loadReader(int &totalReaders, Reader reader[]) {
	ifstream fileIn("Source_Code\\Data\\Reader.txt");
	
	Reader currentReader;
	fileIn >> totalReaders;
	fileIn.ignore();

	for (int i = 0; i < totalReaders; i++) 
	{
		getline(fileIn, currentReader.readerID);
		getline(fileIn, currentReader.name);
		getline(fileIn, currentReader.nationalID);
		getline(fileIn, currentReader.email);
		getline(fileIn, currentReader.address);
		fileIn >> currentReader.gender;
		fileIn >> currentReader.dayOfBirth;
		fileIn >> currentReader.monthOfBirth;
		fileIn >> currentReader.yearOfBirth;
		fileIn >> currentReader.dayOfStartCard;
		fileIn >> currentReader.monthOfStartCard;
		fileIn >> currentReader.yearOfStartCard;
		fileIn >> currentReader.dayOfEndCard;
		fileIn >> currentReader.monthOfEndCard;
		fileIn >> currentReader.yearOfEndCard;
		fileIn.ignore();
		reader[i] = currentReader;
	}

	fileIn.close();
}

void saveReader(int totalReaders, Reader reader[])
{
	ofstream fp("Source_Code\\Data\\Reader.txt");

	fp << totalReaders << '\n';

	for (int i = 0; i < totalReaders; i++)
	{
		fp << reader[i].readerID << '\n';
		fp << reader[i].name << '\n';
		fp << reader[i].nationalID << '\n';
		fp << reader[i].email << '\n';
		fp << reader[i].address << '\n';
		fp << reader[i].gender << '\n';
		fp << reader[i].dayOfBirth << '\n';
		fp << reader[i].monthOfBirth << '\n';
		fp << reader[i].yearOfBirth << '\n';
		fp << reader[i].dayOfStartCard<< '\n';
		fp << reader[i].monthOfStartCard << '\n';
		fp << reader[i].yearOfStartCard << '\n';
		fp << reader[i].dayOfEndCard << '\n';
		fp << reader[i].monthOfEndCard << '\n';
		fp << reader[i].yearOfEndCard << '\n';
	}

	fp.close();
}

void addReader
(
	int&	totalReaders,
	Reader	reader[]
)
{
	Reader temp;

	cin.ignore();

	while (true)
	{
		cout << setw(20) << left << "Nhap ma doc gia: ";
		getline(cin, temp.readerID);
		if (temp.readerID.empty())
		{
			cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
			continue;
		}
		if (findPosOfAReaderByRID(totalReaders, reader, temp.readerID) != -1)
		{
			cout << "\nMa doc gia khong duoc trung voi ma da co! Vui long nhap lai! \n\n ";
			continue;
		}
		break;
	}

	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');

	do
	{
		cout << setw(20) << left << "Nhap ten doc gia: ";
		getline(cin, temp.name);
		if (temp.name.empty()) cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
	} while (temp.name.empty());

	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');


	while (true)
	{
		cout << setw(20) << left << "Nhap so CMND: ";
		getline(cin, temp.nationalID);
		if (temp.nationalID.empty())
		{
			cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
			continue;
		}
		if (findPosOfAReaderByNID(totalReaders, reader, temp.nationalID) != -1)
		{
			cout << "\nCMND khong duoc trung voi CMND da co! Vui long nhap lai! \n\n ";
			continue;
		}
		break;
	}


	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');

	while (true)
	{
		cout << "Nhap ngay sinh: \n"
			<< setw(20) << left << " Nhap ngay: ";
		cin >> temp.dayOfBirth;

		cout << setw(20) << left << " Nhap thang: ";
		cin >> temp.monthOfBirth;

		cout << setw(20) << left << " Nhap nam: ";
		cin >> temp.yearOfBirth;

		if (isValidDate(temp.dayOfBirth, temp.monthOfBirth, temp.yearOfBirth) == 0)
		{
			cout << "\nNgay khong hop le! Vui long nhap lai! \n\n";
			continue;
		}
		break;
	}

	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');

	while (true)
	{
		cout << "Nhap gioi tinh: \n"
			<< setw(20) << left << "1 la Nam, 2 la Nu: ";
		cin >> temp.gender;
		if (temp.gender != 1 && temp.gender != 2)
		{
			cout << "\nNhap khong dung! Vui long nhap lai! \n\n";
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
		cout << setw(20) << left << "Nhap email: ";
		getline(cin, temp.email);
		if (temp.email.empty()) cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
	} while (temp.email.empty());

	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');

	do
	{
		cout << setw(20) << left << "Nhap dia chi nha: ";
		getline(cin, temp.address);
		if (temp.address.empty()) cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
	} while (temp.address.empty());

	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');

	while (true)
	{
		cout << "Nhap ngay lap the: \n"
			<< setw(20) << left << " Nhap ngay: ";
		cin >> temp.dayOfStartCard;

		cout << setw(20) << left << " Nhap thang: ";
		cin >> temp.monthOfStartCard;

		cout << setw(20) << left << " Nhap nam: ";
		cin >> temp.yearOfStartCard;

		if (isValidDate(temp.dayOfStartCard, temp.monthOfStartCard, temp.yearOfStartCard) == 0)
		{
			cout << "\nNgay khong hop le! Vui long nhap lai! \n\n";
			continue;
		}
		break;
	}

	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');

	temp.dayOfEndCard = temp.dayOfStartCard;
	temp.monthOfEndCard = temp.monthOfStartCard;
	temp.yearOfEndCard= temp.yearOfStartCard + 4;

	cout << "Ngay het han the la: " << temp.dayOfEndCard << "/" << temp.monthOfEndCard << "/" << temp.yearOfEndCard << '\n';

	reader[totalReaders] = temp;

	totalReaders++;

	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');

	cout << "Thong tin doc gia da duoc them!\n";
	saveReader(totalReaders, reader);
}

void changeReaderInfo(int totalReaders, Reader reader[]) 
{
	//Neu chua co doc gia nao duoc nhap thong tin thi quay ve menu
	if (totalReaders == 0)
	{
		cout << "Chua co doc gia nao duoc nhap! Vui long them thong tin doc gia tai lua chon 2\n";

		return;
	}

	string currentRID, currentNID;
	int pos, chosen;

	//Hien thi cac lua chon tim kiem
	//Do Ma Doc Gia va CMND la duy nhat nen se su dung de tim kiem
	cout << "Ban muon tim kiem bang gi ?\n"
		<< "1. Tim doc gia bang Ma Doc Gia\n"
		<< "2. Tim doc gia bang CMND\n"
		<< "0. Huy thay doi. Quay ve Menu Doc Gia!\n";

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
			cout << "Nhap Ma Doc Gia: ";
			getline(cin, currentRID);
			if (currentRID.empty()) cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
		} while (currentRID.empty());

		pos = findPosOfAReaderByRID(totalReaders, reader, currentRID);

		if (pos == -1) {
			cout << "\nKhong tim thay thong tin doc gia! Vui long thuc hien lai!\n";

			return;
		}
		break;
	case 2:
		do
		{
			cout << "Nhap CMND: ";
			getline(cin, currentNID);
			if (currentNID.empty()) cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
		} while (currentNID.empty());

		pos = findPosOfAReaderByNID(totalReaders, reader, currentNID);

		if (pos == -1) {
			cout << "\nKhong tim thay thong tin doc gia! Vui long thuc hien lai!\n";

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

		cout << "Day la thong tin doc gia da chon:\n\n";

		displayReaderTableTitle();
		displayAReaderByPos(pos, reader);

		cout << "\nChon thong tin ban muon thay doi: \n"
			<< "1. Ma doc gia\n"
			<< "2. Ho ten\n"
			<< "3. So cmnd\n"
			<< "4. Ngay sinh\n"
			<< "5. Gioi tinh\n"
			<< "6. Email\n"
			<< "7. Dia chi\n"
			<< "8. Ngay lap the\n"
			<< "0. Huy thay doi. Quay ve Menu Doc Gia!\n";


		cout << "\nNhap lua chon cua ban: ";
		cin >> chosen;

		Reader temp;

		cin.ignore();

		cout << setfill('-');
		cout << setw(60) << "-";
		cout << setfill(' ');

		switch (chosen) {
		case 1:
			while (true)
			{
				cout << setw(20) << left << "\nNhap ma doc gia: ";
				getline(cin, temp.readerID);
				if (temp.readerID.empty())
				{
					cout << "\nKhong duoc de trong! Vui long nhap lai! \n";
					continue;
				}
				if (findPosOfAReaderByRID(totalReaders, reader, temp.readerID) != -1)
				{
					cout << "\nMa doc gia khong duoc trung voi ma da co! Vui long nhap lai! \n ";
					continue;
				}
				break;
			}

			reader[pos].readerID = temp.readerID;
			break;

		case 2:
			do
			{
				cout << "\nNhap ten moi: ";
				getline(cin, temp.name);
				if (temp.name.empty()) cout << "\nKhong duoc de trong! Vui long nhap lai! \n";
			} while (temp.name.empty());

			reader[pos].name = temp.name;
			break;

		case 3:
			while (true)
			{
				cout << "\nNhap CMND moi: ";
				getline(cin, temp.nationalID);
				if (temp.nationalID.empty())
				{
					cout << "\nKhong duoc de trong! Vui long nhap lai! \n";
					continue;
				}
				if (findPosOfAReaderByNID(totalReaders, reader, temp.nationalID) != -1)
				{
					cout << "\nCMND khong duoc trung voi CMND da co! Vui long nhap lai! \n ";
					continue;
				}
				break;
			}

			reader[pos].nationalID = temp.nationalID;
			break;

		case 4:
			while (true)
			{
				cout << "\nNhap ngay sinh moi: \n"
					<< setw(20) << left << " Nhap ngay: ";
				cin >> temp.dayOfBirth;

				cout << setw(20) << left << " Nhap thang: ";
				cin >> temp.monthOfBirth;

				cout << setw(20) << left << " Nhap nam: ";
				cin >> temp.yearOfBirth;

				if (isValidDate(temp.dayOfBirth, temp.monthOfBirth, temp.yearOfBirth) == 0)
				{
					cout << "\nNgay khong hop le! Vui long nhap lai! \n";
					continue;
				}
				break;
			}

			reader[pos].dayOfBirth = temp.dayOfBirth;
			reader[pos].monthOfBirth = temp.monthOfBirth;
			reader[pos].yearOfBirth = temp.yearOfBirth;

			break;

		case 5:
			while (true)
			{
				cout << "\nNhap gioi tinh moi: \n"
					<< "1 la Nam, 2 la Nu: ";
				cin >> temp.gender;
				if (temp.gender != 1 && temp.gender != 2)
				{
					cout << "\nNhap khong dung! Vui long nhap lai! \n";
					continue;
				}
				break;
			}

			reader[pos].gender = temp.gender;
			break;

		case 6:
			do
			{
				cout << "\nNhap email moi: ";
				getline(cin, temp.email);
				if (temp.email.empty()) cout << "\nKhong duoc de trong! Vui long nhap lai! \n";
			} while (temp.email.empty());

			reader[pos].email = temp.email;
			break;

		case 7:
			do
			{
				cout << "\nNhap dia chi moi: ";
				getline(cin, temp.address);
				if (temp.address.empty()) cout << "\nKhong duoc de trong! Vui long nhap lai! \n";
			} while (temp.address.empty());

			reader[pos].address = temp.address;
			break;

		case 8:
			while (true)
			{
				cout << "\nNhap ngay lap the moi: \n"
					<< setw(25) << left << " Nhap ngay: ";
				cin >> temp.dayOfStartCard;

				cout << setw(25) << left << " Nhap thang: ";
				cin >> temp.monthOfStartCard;

				cout << setw(25) << left << " Nhap nam: ";
				cin >> temp.yearOfStartCard;

				if (isValidDate(temp.dayOfStartCard, temp.monthOfStartCard, temp.yearOfStartCard) == 0)
				{
					cout << "\nNgay khong hop le! Vui long nhap lai! \n";
					continue;
				}
				break;
			}

			reader[pos].dayOfStartCard = temp.dayOfStartCard;
			reader[pos].monthOfStartCard = temp.monthOfStartCard;
			reader[pos].yearOfStartCard = temp.yearOfStartCard;

			reader[pos].dayOfEndCard = temp.dayOfStartCard;
			reader[pos].monthOfEndCard = temp.monthOfStartCard;
			reader[pos].yearOfEndCard = temp.yearOfStartCard + 4;

			cout << "\nNgay het han the moi la: " << reader[pos].dayOfEndCard << "/" << reader[pos].monthOfEndCard << "/" << reader[pos].yearOfEndCard << '\n';

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

		cout << "Thong tin doc gia da duoc thay doi!\n";

		saveReader(totalReaders, reader);
		system("pause");
		system("cls");
	}
}

void deleteReaderInfo(int &totalReaders, Reader reader[])
{
	//Neu chua co doc gia nao duoc nhap thong tin thi quay ve menu
	if (totalReaders == 0)
	{
		cout << "Chua co doc gia nao duoc nhap! Vui long them thong tin doc gia tai lua chon 2\n";

		return;
	}

	string currentRID, currentNID;
	int pos, chosen;

	//Hien thi cac lua chon tim kiem
	//Do Ma Doc Gia va CMND la duy nhat nen se su dung de tim kiem
	cout << "Ban muon tim kiem bang gi ?\n"
		<< "1. Tim doc gia bang Ma Doc Gia\n"
		<< "2. Tim doc gia bang CMND\n"
		<< "0. Huy thay doi. Quay ve Menu Doc Gia!\n";

	cout << "\nNhap lua chon cua ban: ";
	cin >> chosen;

	cin.ignore();

	cout << setfill('-');
	cout << setw(60) << "-";
	cout << setfill(' ');

	switch (chosen)
	{
	case 1:
		do
		{
			cout << "\nNhap Ma Doc Gia: ";
			getline(cin, currentRID);
			if (currentRID.empty()) cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
		} while (currentRID.empty());

		pos = findPosOfAReaderByRID(totalReaders, reader, currentRID);

		if (pos == -1) {
			cout << "\nKhong tim thay thong tin doc gia! Vui long thuc hien lai!\n";

			return;
		}
		break;
	case 2:
		do
		{
			cout << "\nNhap CMND: ";
			getline(cin, currentNID);
			if (currentNID.empty()) cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
		} while (currentNID.empty());

		pos = findPosOfAReaderByNID(totalReaders, reader, currentNID);

		if (pos == -1) {
			cout << "\nKhong tim thay thong tin doc gia! Vui long thuc hien lai!\n";

			return;
		}
		break;
	case 0:
		cout << '\n';
		return;
	default:
		cout << "\nLua chon khong hop le! Vui long thuc hien lai!\n";

		return;
	}

	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');

	cout << "Thong tin cua doc gia da chon la: \n\n";

	displayReaderTableTitle();
	displayAReaderByPos(pos, reader);

	cout << "\nDay co phai la doc gia ban muon xoa thong tin?\n"
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

		for (int i = pos; i < totalReaders; i++)
		{
			reader[i] = reader[i + 1];
		}

		totalReaders--;

		cout << "Thong tin doc gia nay da duoc xoa!\n";
		saveReader(totalReaders, reader);
		break;
	case 0:
		break;
	default:
		cout << "Lua chon khong hop le! Vui long thuc hien lai!\n";
		break;
	}
	return;
}

void displayAReaderByPos(int pos, Reader reader[])
{
	string birthDay = to_string(reader[pos].dayOfBirth) + "/" + to_string(reader[pos].monthOfBirth) + "/" + to_string(reader[pos].yearOfBirth);
	string startCard = to_string(reader[pos].dayOfStartCard) + '/' + to_string(reader[pos].monthOfStartCard) + '/' + to_string(reader[pos].yearOfStartCard);
	string endCard = to_string(reader[pos].dayOfEndCard) + '/' + to_string(reader[pos].monthOfEndCard) + '/' + to_string(reader[pos].yearOfEndCard);

	string _gender;
	if (reader[pos].gender == 1) _gender = "Nam";
	if (reader[pos].gender == 2) _gender = "Nu";

	cout << setw(15) << left << reader[pos].readerID;
	cout << setw(15) << left << reader[pos].name;
	cout << setw(15) << left << reader[pos].nationalID;
	cout << setw(15) << left << birthDay;
	cout << setw(15) << left << _gender;
	cout << setw(20) << left << reader[pos].email;
	cout << setw(15) << left << reader[pos].address;
	cout << setw(15) << left << startCard;
	cout << setw(15) << left << endCard << endl;
}

void displayAllReaders(int totalReaders, Reader reader[])
{
	//Neu chua co doc gia nao duoc nhap thong tin thi quay ve menu
	if (totalReaders == 0)
	{
		cout << "Chua co doc gia nao duoc nhap! Vui long them thong tin doc gia tai lua chon 2\n";
		return;
	}
	displayReaderTableTitle();

	for (int i = 0; i < totalReaders; i++)
	{
		displayAReaderByPos(i, reader);
	}
}

void displayAReaderByNID(int totalReaders, Reader reader[])
{
	//Neu chua co doc gia nao duoc nhap thong tin thi quay ve menu
	if (totalReaders == 0)
	{
		cout << "Chua co doc gia nao duoc nhap! Vui long them thong tin doc gia tai lua chon 2\n";
		return;
	}
	int pos;
	string currentNID;

	cin.ignore();

	do
	{
		cout << "Nhap CMND: ";
		getline(cin, currentNID);
		if (currentNID.empty()) cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
	} while (currentNID.empty());

	pos = findPosOfAReaderByNID(totalReaders, reader, currentNID);

	if (pos == -1) {
		cout << "\nKhong tim thay thong tin doc gia! Vui long thuc hien lai!\n";
		return;
	}

	cout << "\nThong tin cua doc gia da chon la: \n";
	cout << endl;
	displayReaderTableTitle();
	displayAReaderByPos(pos, reader);
	cout << '\n';

}

void displayAReaderByName(int totalReaders, Reader reader[])
{
	//Neu chua co doc gia nao duoc nhap thong tin thi quay ve menu
	if (totalReaders == 0)
	{
		cout << "Chua co doc gia nao duoc nhap! Vui long them thong tin doc gia tai lua chon 2\n";
		return;
	}
	int pos;
	string currentName;

	cin.ignore();

	do
	{
		cout << "Nhap ho ten: ";
		getline(cin, currentName);
		if (currentName.empty()) cout << "\nKhong duoc de trong! Vui long nhap lai! \n\n";
	} while (currentName.empty());

	pos = findPosOfAReaderByName(totalReaders, reader, currentName);

	if (pos == -1) {
		cout << "\nKhong tim thay thong tin doc gia! Vui long thuc hien lai!\n";
		return;
	}

	cout << "\nThong tin cua nhung doc gia co ten " << currentName << " la: \n";

	cout << endl;
	displayReaderTableTitle();

	for (int i = 0; i < totalReaders; i++)
	{
		if (reader[i].name == reader[pos].name)
		{
			displayAReaderByPos(i, reader);
		}
	}
	cout << endl;
}

void displayReaderTableTitle()
{
	cout << setw(15) << left << "Ma Doc Gia";
	cout << setw(15) << left << "Ho Ten";
	cout << setw(15) << left << "CMND";
	cout << setw(15) << left << "Ngay sinh";
	cout << setw(15) << left << "Gioi tinh";
	cout << setw(20) << left << "Email";
	cout << setw(15) << left << "Dia chi";
	cout << setw(15) << left << "Ngay lap the";
	cout << setw(15) << left << "Ngay het han the" << endl;

	cout << setfill('-');
	cout << setw(140) << "-" << endl;
	cout << setfill(' ');
}

void statisticizeReadersByGender(int totalReaders, Reader reader[])
{
	cout << setw(15) << left << "Gioi tinh";
	cout << setw(15) << left << "So luong doc gia" << endl;

	cout << setfill('-');
	cout << setw(30) << "-" << endl;
	cout << setfill(' ');

	cout << setw(15) << left << "Nam";
	cout << setw(15) << left << countReadersByGender(totalReaders, reader, 1) << endl;

	cout << setw(15) << left << "Nu";
	cout << setw(15) << left << countReadersByGender(totalReaders, reader, 2) << endl;

	cout << endl;
}

int countReadersByGender(int totalReaders, Reader reader[], int _gender)
{
	int count = 0;
	for (int i = 0; i < totalReaders; i++)
	{
		if (reader[i].gender == _gender)
		{
			count++;
		}
	}
	return count;
}

int findPosOfAReaderByRID(
	int totalReaders,
	Reader reader[],
	string currentRID
) {
	int pos = -1;
	for (int i = 0; i < totalReaders; i++)
		if (reader[i].readerID == currentRID)
			pos = i;
	return pos;
}

int findPosOfAReaderByNID(
	int totalReaders,
	Reader reader[],
	string currentNID
) {
	int pos = -1;
	for (int i = 0; i < totalReaders; i++)
		if (reader[i].nationalID == currentNID)
			pos = i;
	return pos;
}

int findPosOfAReaderByName(
	int totalReaders,
	Reader reader[],
	string currentName
) {
	int pos = -1;
	for (int i = 0; i < totalReaders; i++)
		if (reader[i].name == currentName)
			pos = i;
	return pos;
}

bool isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int daysOfMonth(int month, int year)
{
	int days;

	switch (month)
	{
	case 1:	case 3:	case 5:	case 7:	case 8:	case 10: case 12:
		days = 31;
		break;

	case 4:	case 6:	case 9:	case 11:
		days = 30;
		break;

	case 2:
		if (isLeapYear(year))	days = 29;
		else days = 28;
		break;
	}

	return days;
}

bool isValidDate(int day, int month, int year)
{

	if (year < 0)   return 0;

	if (month < 1 || month > 12)    return 0;

	if (day < 1 || day > daysOfMonth(month, year))   return 0;

	return 1;
}