#pragma once
#include "ReaderManagement.h"
#include "BookManagement.h"
#include "TicketManagement.h"

//Ham de hien Menu Doc Gia 
void manageReader(int& totalReaders, Reader reader[]);

//Ham de hien Menu Sach
void manageBook(int& totalBooks, Book book[]);

//Ham de hien Menu Muon/Tra sach
void manageTicket
(
	int& totalTickets,
	int		totalReaders,
	int		totalBooks,
	Ticket	ticket[],
	Reader	reader[],
	Book	book[]
);

//Ham de hien Menu Thong ke
void manageStatics
(
	int		totalTickets,
	int		totalReaders,
	int		totalBooks,
	Ticket	ticket[],
	Reader	reader[],
	Book	book[]
);