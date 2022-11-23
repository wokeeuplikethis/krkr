#include "book.h"


void Book::getData()
{
	cout << "Данные: \n" << endl 
		<< "Название книги:  " << bookname << endl
		<< "Имя автора:  " << name << endl
		<< "Фамилия автора:  " << lastName << endl 
		<< "Отчество автора:  " << patronymic << endl
		<< "Издательство:  " << publishingoffice << endl 
		<< "Год издания  " << yearOfIssue << endl;
}

string Book::getBookName()
{
	return bookname;

}

string Book::getName()
{
	return name;
}

string Book::getLastName()
{
	return lastName;
}

string Book::getPatronymic()
{
	return patronymic;
}

string Book::getPublishingOffice()
{
	return publishingoffice;
}

int Book::getYear()
{
	return yearOfIssue;
}
//int Book::operator = (const Book & other){
//	if (this != &other) {
//		 = a;
//	}return *this;
//}

