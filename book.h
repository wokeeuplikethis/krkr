#pragma once
#include "io.h"

  class Book
	{
	private:
		string bookname, name, lastName, patronymic, publishingoffice;
		int yearOfIssue = 0;
	public:
		//string bookname, name, lastName, patronymic, publishingoffice;
		//int yearOfIssue = 0;
		Book(string BName,
			string nameAuthor,
			string lastnameAuthor,
			string patronymicAuthor,
			string namePublishingOffice,
			int YearOfIssue)
		{   
			bookname = BName;
			name = nameAuthor;
			lastName = lastnameAuthor;
			patronymic = patronymicAuthor;
			publishingoffice = namePublishingOffice;
			yearOfIssue = YearOfIssue;
		}
		
		Book() = default;
		void getData(); 
	

		string getBookName();

		string getName();

		string getLastName();

		string getPatronymic();	

		string getPublishingOffice();
		int getYear();
		
		//int operator = (const Book& other);
  };


