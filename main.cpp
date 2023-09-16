#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cctype>
#include <list>
#include "animals.cpp"




using namespace std;


int main()
{

Animals animalsData;

ifstream inputFile("file.txt");

 if (inputFile.is_open()) { // Проверка, удалось ли открыть файл
        string line;

        while (getline(inputFile, line)) { // Чтение строки из файла
if (line.find("ADD") != string::npos)
        {
animalsData.addAnimal(line);
        }
if (line.find("PRINT") != string::npos)
        {
animalsData.printAnimals();
        }
        if (line.find("REM") != string::npos)
        {
            vector<string> words; // массив со словами
            stringstream ss(line);
            string word;
            while (ss >> word)
            {
                words.push_back(word);
            }

animalsData.removeAnimalsToName(words[1]);
        }
        }

        inputFile.close(); // Закрытие файла после чтения
    } else {
        cout << "Не удалось открыть файл." << endl;
        return 1;
    }
    return 0;
}