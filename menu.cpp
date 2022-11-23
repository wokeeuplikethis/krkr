#include "io.h"
#include "book.h"
#include <iostream>

ifstream checkFile;
ofstream thirdFile;
ofstream secondFile;
string thirdFileAdress = "";
int choi = 0;
//string secondFileAddress = "";
string secondName = "";
int secondinput = 0;
using namespace std;

bool isNumeric(string const& str) //
{
    auto it = str.begin();   //��������� ��� ������
    while (it != str.end() && isdigit(*it)) { //�������������
        it++;
    }
    return !str.empty() && it == str.end();
}


void filesavemenu(Book array[], int Size)
{
    string inputValue;
    int thirdChoice = 0;
    string secondFileAddress = "";
    do {
        cout << "1 - C�������� � ����" << endl;
        cout << "2 - ���������� ��� ����������" << endl;
        while (true)
        {
         getline(cin, inputValue);
         if (!(isNumeric(inputValue)))
             {
              cout << "������� �� �����...�������� ��� ���!" << endl;
               continue;
             }
         else {
            thirdChoice = stoi(inputValue);
            break;
              }
         }
         switch (thirdChoice) {
         case saveDataOld:         
             while (true) {
                 cout << "�������� �����:" << endl;
                 getline(cin, secondName);
                 try {
                     checkFile.open(secondName);
                     while (checkFile.is_open()) {
                         cout << "���� � ����� ������ ������!" << endl;
                         cout << "1 - ��������� � ���� ����" << endl;
                         cout << "2 � ������ ����� - ������ ����� ��� �����" << endl;
                         while (true)//proverka
                         {
                             getline(cin, inputValue);
                             if (!(isNumeric(inputValue)))
                             {
                                 cout << "������� �� �����...�������� ��� ���!" << endl;
                                 continue;
                             }
                             else
                             {
                                 choi = stoi(inputValue);
                                 break;
                             }
                         }
                         if (choi == 1)
                         {
                             thirdFile.open(secondName);
                             thirdFile << Size << endl;;
                             for (int w = 0; w < Size; w++) {
                                 thirdFile << array[w].getBookName() << endl << array[w].getName() << endl << array[w].getLastName() << endl;
                                 thirdFile << array[w].getPatronymic() << endl << array[w].getPublishingOffice() << endl << array[w].getYear() << endl;
                             }
                             cout << "���� �������" << endl;
                             thirdFile.close();
                         }
                         else {
                             checkFile.close();
                             cout << "�������� ������ �����:" << endl;
                             //cin.get();
                             getline(cin, thirdFileAdress);
                             thirdFile.open(thirdFileAdress);
                             thirdFile << Size << endl;
                             for (int q = 0; q < Size; q++) {
                                 thirdFile << array[q].getBookName() << endl << array[q].getName() << endl << array[q].getLastName() << endl;
                                 thirdFile << array[q].getPatronymic() << endl << array[q].getPublishingOffice() << endl << array[q].getYear() << endl;
                             }
                             cout << "���� �������" << endl;
                             thirdFile.close();
                             break;
                         };
                     }
                 }
                 catch (const exception&)
                 {
                     try
                     {
                         thirdFile.open(secondName);
                         thirdFile << Size << endl;
                         for (int q = 0; q < Size; q++) {
                             thirdFile << array[q].getBookName() << endl << array[q].getName() << endl << array[q].getLastName() << endl;
                             thirdFile << array[q].getPatronymic() << endl << array[q].getPublishingOffice() << endl << array[q].getYear() << endl;
                         }
                         cout << "���� �������" << endl;
                         thirdFile.close();
                     }
                     catch (const exception&)
                     {
                         cout << "������...������� ���������� ����� �����" << endl;
                         continue;
                     }
                     
                 }
             }
            case notSaveDate:
                cout << "�����..." << endl;
                break;
            default:
                cout << "������ ������ � ���� ���!" << endl;
                break;
            }
        } while (thirdFile.is_open()/*thirdChoice != notSaveDate*/);
    }
void Submenu(Book array[], int Size)
{
    string inputValue;
    int secondChoice = 0;
    string nameAuthor = "";
    string lastNameAuthor = "";
    string patronymicAuthor = "";
    string nameOfPublishingOffice = "";
    Book* resultArray = 0;
    int resultSize = 0;
    int minYearOfIssue = 0;
    do {
        cout << "����� ���� �������." << endl;
        cout << "1 - ������ ����,�� ����� ������. " << endl;
        cout << "2 - ������ ����,�� ������������." << endl;
        cout << "3 - ������ ����,���������� ����� ��������� ����." << endl;
        cout << "4 - ������� � ���������� ����." << endl;
        while (true)
        {
            getline(cin, inputValue);
            if (!(isNumeric(inputValue)))
            {
                cout << "������� �� �����...�������� ��� ���!" << endl;
                continue;
            }
            else
            {
                secondChoice = stoi(inputValue);
                break;
            }
        }
        switch (secondChoice) {
        case listOfBooksByAuthor:
            resultSize = 0;
            cout << "������� ��� ������" << endl;
            getline(cin,nameAuthor);
            cout << "������� ������� ������" << endl;
            getline(cin, lastNameAuthor);
            cout << "������� �������� ������" << endl;
            getline(cin,patronymicAuthor);
            for (int i = 0; i < Size; i++) {
                if (array[i].getName() == nameAuthor and array[i].getLastName() == lastNameAuthor
                    and array[i].getPatronymic() == patronymicAuthor)
                {
                    array[i].getData();
                    resultSize++;
                }
            }
            resultArray = new Book[resultSize];
            for (int i = 0, j = 0; i < Size; i++) { 
                if (array[i].getName() == nameAuthor and array[i].getLastName() == lastNameAuthor
                    and array[i].getPatronymic() == patronymicAuthor) {
                    resultArray[j] = array[i];                   
                    j++;
                }
            }
            filesavemenu(resultArray, resultSize);
            break;
        case listOfBooksByPublishingOffice:
            resultSize = 0;
            cout << "������� �������� ������������" << endl;
            getline(cin,nameOfPublishingOffice);
            for (int i = 0; i < Size; i++) {
                if (array[i].getPublishingOffice() == nameOfPublishingOffice) {
                    array[i].getData();
                    resultSize++;
                }
            }

            resultArray = new Book[resultSize];
            for (int i = 0, j = 0; i < Size; i++) {
                if (array[i].getPublishingOffice() == nameOfPublishingOffice) {
                    resultArray[j] = array[i];
                    j++;
                }
            }
            filesavemenu(resultArray, resultSize);
            break;
        case listOfBooksByYearOfIssue:
            resultSize = 0;
            cout << "������� ��� ����� �������� ���� ������ �����" << endl;
            while (true)
            {
                getline(cin, inputValue);
                if (!(isNumeric(inputValue)))
                {
                    cout << "������� �� �����...�������� ��� ���!" << endl;
                    continue;
                }
                {
                    minYearOfIssue = stoi(inputValue);
                    break;
                }
            }
            for (int i = 0; i < Size; i++) {
                if (array[i].getYear() >= minYearOfIssue) {
                    array[i].getData();
                    resultSize++;
                }
            }
            resultArray = new Book[resultSize];
            for (int i = 0, j = 0; i < Size; i++) {
                if (array[i].getYear() >= minYearOfIssue) {
                    resultArray[j] = array[i];
                    j++;
                }
            }
            filesavemenu(resultArray, resultSize);
        case backToTheBeginning:
            cout << "����������� � ������..." << endl;
            break;
        default:
            cout << "����� � ���� �� ����������!" << endl;
            break;
        }

    } while (secondChoice != backToTheBeginning);
};