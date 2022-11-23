#include "io.h"
#include "book.h"
#include "menu.h"
#include <Windows.h>
#include <clocale>

int main() {
    SetConsoleCP(1251);    // устанавливает кодировку вывода на консоль;
    SetConsoleOutputCP(1251);  // устанавливает кодировку ввода из консоли и и`з редактора кода;
    int userChoice = 0;
    int Size = 0;
    string fileAddress = "";
    string inputValue = "";
    string thirdFileAdress = "";
    ofstream thirdFile;
    ifstream file;
    ifstream checkFile;
    file.exceptions(ifstream::badbit | ifstream::failbit);
    thirdFile.exceptions(ifstream::badbit | ifstream::failbit);
    checkFile.exceptions(ifstream::badbit | ifstream::failbit);
    string secondName = "";
    string str = "";
    Book* resultArray = 0;
    int resultSize = 0;
    setlocale(LC_ALL, "Rus");


    cout << "Контрольная работа номер 1. Вариант 4. Бердиев Э.М. 415. \nЗадание: Необходимо разработать класс"
        "для Книг.Доступ к данным реализовать с помощью методов Set,Get,Show." << endl;
    do {
        cout << "Меню." << endl;
        cout << "1 - Заполнение данных" << endl;
        cout << "2 - Файловый ввод" << endl;
        cout << "3 - Выход" << endl;
        while (true)
        {
            getline(cin, inputValue);
            if (!(isNumeric(inputValue)))
            {
                cout << "Введено не число...Попробуй ещё раз!" << endl;
                continue;
            }
            else
            {
                userChoice = stoi(inputValue);
                break;
            }
        }
        if (userChoice == 1)
        {
            while (true)
            {
                cout << "Введите количество книг: " << endl;
                getline(cin, inputValue);
                if (!(isNumeric(inputValue)))
                {
                    cout << "Введено не число...Попробуй ещё раз!" << endl;
                    continue;
                }
                else
                {
                    Size = stoi(inputValue);
                    if (Size < 1)
                    {
                        continue;
                    }
                    break;
                }

            }
        }
        if (userChoice == 2)
        {
            while (true)
            {
                cout << "Введите адрес файла:" << endl << "ENTER : ";
                cin >> fileAddress;
                try {
                    file.open(fileAddress);
                    cout << "файл успешно открыт =)" << endl;
                    file.close();
                    break;
                }
                catch (const exception)
                {
                    cout << "Ошибка" << endl;
                    continue;
                }
            }
            cin.clear();
            cin.ignore();
        }
        Book* array = new Book[Size];
        switch (userChoice) {
        case keyboardInput:

            for (int z = 0; z < Size;z++) {
                string bookname = "", name = "", lastName = "", patronymic = "", publishingoffice = "";
                int yearOfIssue = 0;
                cout << "Введите название "<< z+1 << " книги" << endl;
                getline(cin, bookname);

                cout << "Введите имя автора" << endl;
                getline(cin, name);

                cout << "Введите фамилию автора" << endl;
                getline(cin, lastName);

                cout << "Введите отчество автора" << endl;
                getline(cin, patronymic);

                cout << "Введите название издательства" << endl;
                getline(cin, publishingoffice);

                cout << "Введите год издания книги" << endl;
                while (true)
                {
                    getline(cin, inputValue);
                    if (!(isNumeric(inputValue)))
                    {

                        cout << "Введено не число...Попробуй ещё раз!" << endl;
                        continue;
                    }
                    else
                    {
                        yearOfIssue = stoi(inputValue);
                        break;
                    }

                }
                array[z] = Book(bookname, name, lastName, patronymic, publishingoffice,
                    yearOfIssue);
                //array[w].getData();
            }
            for (int g = 0; g < Size; g++)
            {
                array[g].getData();
            }
            filesavemenu(resultArray,resultSize);
            Submenu(array, Size);
            delete[] array;
            array = nullptr;
            break;
        case fileInput:
            file.open(fileAddress);
            getline(file, inputValue);
            Size = stoi(inputValue);
            array = new Book[Size];
            for (int x = 0; x < Size; x++) {
                string bookname, name, lastName, patronymic, publishingoffice;
                int yearOfIssue;

                //file >> bookname;
                getline(file, bookname);

                //file >> name;
                getline(file, name);

                //file >> lastName;
                getline(file, lastName);

                //file >> patronymic;
                getline(file, patronymic);

                //file >> publishingoffice;
                getline(file, publishingoffice);

                //file >> yearOfIssue;
                getline(file, inputValue);
                yearOfIssue = stoi(inputValue);

                array[x] = Book(bookname, name, lastName, patronymic,
                    publishingoffice, yearOfIssue);

            }
            for (int y = 0; y < Size; y++) {
                array[y].getData();
            }
            filesavemenu(resultArray, resultSize);
            Submenu(array, Size);
            delete[] array;
            array = nullptr;
            file.close();
            break;
        case quit:
            cout << "Завершение работы ;)" << endl;
            break;
            return 0;
        default:
            cout << "Пункт не существует! Введите число > 0" << endl;
            break;
            }
        } while (userChoice != quit);
    }