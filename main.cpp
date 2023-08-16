#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cctype>

using namespace std;

enum class MestoProjivania
{
    ozero,
    reka,
    more,
    okean
};
struct DateAnimals
{
    int day;
    int mouth;
    int year;
};
DateAnimals parseDate(string dateString)
{
    string buffer;
    istringstream iss(dateString); // создаем поток из строки

    vector<int> dateVector; // массив со числами
    while (getline(iss, buffer, '.'))
    {                                       // извлекаем строки, разделенные пробелом
        dateVector.push_back(stoi(buffer)); // помещаем в массив число
    }
    return DateAnimals{dateVector[0], dateVector[1], dateVector[2]};
}

struct Animal
{
    string animal;
    string name;
    double speed;
    MestoProjivania mestoObitania;
    double length;
    DateAnimals date;
};

vector<Animal> animals; // контейнер для животных

void addBird(string name, double speed)
{
    Animal bird = {"bird", name, speed, MestoProjivania::more, 0.0, parseDate("00.00.0000")};
    animals.push_back(bird);
}

void addFish(string name, MestoProjivania mestoObitania)
{
    Animal fish = {"fish", name, 0.0, mestoObitania, 0.0, parseDate("00.00.0000")};
    animals.push_back(fish);
}

void addInsects(string name, double length, DateAnimals date)
{
    Animal insect = {"insect", name, length, MestoProjivania::more, 0.0, date};
    animals.push_back(insect);
}

void removeAnimalsForName(const string &name)
{
    bool check = 0;
    for (int i = 0; i < animals.size(); i++)
    {
        if (animals[i].name == name)
        {
            check = true;
            animals.erase(animals.begin() + i);
            cout << "Bird removed successfully!" << endl;
            removeAnimalsForName(name);
            break;
        }
    }
    if (!check)
    {
        cout << endl
             << "Name not found" << endl;
    }
}

void removeAnimalsForRazmer(double razmer)
{
    bool check = 0;
    for (int i = 0; i < animals.size(); i++)
    {
        if (animals[i].length == razmer)
        {
            check = true;
            animals.erase(animals.begin() + i);
            cout << "Insects removed successfully!" << endl;
            removeAnimalsForRazmer(razmer);
            break;
        }
    }
    if (!check)
    {
        cout << endl
             << "Not found" << endl;
    }
}

void removeAnimalsForSpeed(double speed)
{
    bool check = 0;
    for (int i = 0; i < animals.size(); i++)
    {
        if (animals[i].speed == speed)
        {
            check = true;
            animals.erase(animals.begin() + i);
            cout << "Insects removed successfully!" << endl;
            removeAnimalsForSpeed(speed);
            break;
        }
    }
    if (!check)
    {
        cout << endl
             << "Not found" << endl;
    }
}

void removeAnimalsForMesto(MestoProjivania mesto)
{
    bool check = 0;
    for (int i = 0; i < animals.size(); i++)
    {
        if (animals[i].mestoObitania == mesto)
        {
            check = true;
            animals.erase(animals.begin() + i);
            cout << "Insects removed successfully!" << endl;
            removeAnimalsForMesto(mesto);
            break;
        }
    }
    if (!check)
    {
        cout << endl
             << "Not found" << endl;
    }
}

void printAnimals()
{

    cout << "Animals:" << endl;
    for (int i = 0; i < animals.size(); i++)
    {
        cout << i + 1 << ":" << endl;
        cout << "    Name: " << animals[i].name << endl;
        if (animals[i].animal == "bird")
        {
            cout << "    Speed: " << animals[i].speed << endl;
        }

        if (animals[i].animal == "fish")
        {
            string mesto;
            switch (animals[i].mestoObitania)
            {
            case MestoProjivania::ozero:
                mesto = "ozero";
                break;
            case MestoProjivania::reka:
                mesto = "reka";
                break;
            case MestoProjivania::more:
                mesto = "more";
                break;
            case MestoProjivania::okean:
                mesto = "okean";
                break;
            }
            cout << "    Mesto obitania: " << mesto << endl;
        }
        if (animals[i].animal == "insect")
        {
            cout << "    Razmer: " << animals[i].length << endl;
            cout << "    Data obnaruzenia: day: " << animals[i].date.day << " mounth: " << animals[i].date.mouth << " year: " << animals[i].date.year << endl;
        }
    }
    cout << endl;
}

int main()
{

    string animal; // название животного
    double d;
    DateAnimals date;
    MestoProjivania mp;

    ifstream inputFile("file.txt");
    string line;

    string command; // буфер для ввода в клавиатуры

    while (getline(inputFile, line)) // обрабатываем команды из файла
    {
        if (line.find("ADD") != string::npos)
        {

            vector<string> words; // массив со словами
            stringstream ss(line);
            string word;

            while (ss >> word)
            {
                words.push_back(word);
            }
            // выборка слов

            animal = words[1]; // название животного

            if (words.size() == 4) // если три значения, то обрабатываем как насекомое
            {

                d = stod(words[2]);
                date = parseDate(words[3]);
                addInsects(animal, d, date);
            }
            else
            {
                if (isdigit(words[2][0])) // Является ли символ цифрой (если да преобразовываем строку в тип double)
                {
                    d = stod(words[2]);
                    addBird(animal, d); // добавляем птицу в контейнер
                }
                else // обрабатывем как рыбу
                {
                    if (words[2] == "more")
                    {
                        mp = MestoProjivania::more;
                    }
                    if (words[2] == "ozero")
                    {
                        mp = MestoProjivania::ozero;
                    }
                    if (words[2] == "reka")
                    {
                        mp = MestoProjivania::reka;
                    }
                    if (words[2] == "okean")
                    {
                        mp = MestoProjivania::okean;
                    }

                    addFish(animal, mp);
                }
            }
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
            removeAnimalsForName(words[1]); // удаляем если имя совпало
        }
        if (line.find("PRINT") != string::npos)
        {
            printAnimals();
        }
    }

    while (true)
    {
        cout << "Enter command: \nADD:   1\nREM:   2 \nPRINT: 3\n";
        cin >> command;

        if (command == "1") // Добавить новую запись
        {
            cout << "Enter command: \nADD Bird:     1\nADD Fish:     2\nADD Insect:   3\n";
            cin >> command;
            if (command == "1")
            {
                cout << "Enter bird name: ";
                cin >> animal;
                cout << "Enter bird speed: ";
                cin >> d;
                addBird(animal, d);
            }
            if (command == "2")
            {
                cout << "Enter fish name: ";
                cin >> animal;
                cout << "Enter fish location: \nozero:    1\nreka:     2\nmore:     3\nokean:    4\n";
                cin >> command;
                if (command == "1")
                {
                    mp = MestoProjivania::ozero;
                }
                if (command == "2")
                {
                    mp = MestoProjivania::reka;
                }
                if (command == "3")
                {
                    mp = MestoProjivania::more;
                }
                if (command == "4")
                {
                    mp = MestoProjivania::okean;
                }
                addFish(animal, mp);
            }
            if (command == "3")
            {
                cout << "Enter insect name: ";
                cin >> animal;
                cout << "Enter insect razmer: ";
                cin >> d;
                cout << "Enter date: dd.mm.yyyy  ";
                cin >> command;
                addInsects(animal, d, parseDate(command));
            }
        }
        if (command == "2") // Удалить запись в контейнере
        {
            cout << "Option to delete: \nname:       1\nrazmer:     2\nspeed:      3\nmesto:      4\n";
            cin >> command;
            if (command == "1")
            {
                cout << "name: ";
                cin >> command;
                removeAnimalsForName(command);
            }
            if (command == "2")
            {
                cout << "razmer: ";
                cin >> command;
                d = stod(command);
                removeAnimalsForRazmer(d);
            }
            if (command == "3")
            {
                cout << "speed: ";
                cin >> command;
                d = stod(command);
                removeAnimalsForSpeed(d);
            }
            if (command == "4")
            {
                cout << "Mesto to delete: \nozero:       1\nreka:     2\nmore:      3\nokean:      4\n";
                cin >> command;

                if (command == "1")
                {

                    removeAnimalsForMesto(MestoProjivania::ozero);
                }
                if (command == "2")
                {
                    removeAnimalsForMesto(MestoProjivania::reka);
                }
                if (command == "3")
                {
                    removeAnimalsForMesto(MestoProjivania::more);
                }
                if (command == "4")
                {
                    removeAnimalsForMesto(MestoProjivania::okean);
                }
            }
        }
        if (command == "3") // Показать контейнеры
        {
            printAnimals();
        }
    }
    return 0;
}
