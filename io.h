#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

enum MENU { keyboardInput = 1, fileInput, quit };
enum SUBMENU { listOfBooksByAuthor = 1, listOfBooksByPublishingOffice, listOfBooksByYearOfIssue, backToTheBeginning };
enum SUBSUBMENU { saveDataOld = 1, notSaveDate };


