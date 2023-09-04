#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cctype>
#include <list>

using namespace std;




enum class Location
{river, sea, lake, ocean};

struct Date
{  
    int day;
    int mouth;
    int year;
};

Date parseDate(string dateString)
{
    string buffer;
    istringstream iss(dateString); // создаем поток из строки

    vector<int> dateVector; // массив со числами
    while (getline(iss, buffer, ':'))
    {                                       // извлекаем строки, разделенные пробелом
        dateVector.push_back(stoi(buffer)); // помещаем в массив число
    }
    return Date{dateVector[0], dateVector[1], dateVector[2]};
}

class Fish{
    public:
    string name;
Location location;

Fish(string nameFish, Location locationFish)
{
    name =nameFish;
    location = locationFish;
}
};

class Bird{
    public:
    string name;
double maxSpeed;
 Bird(string nameBird, double maxSpeedtBird)
{
    name = nameBird;
    maxSpeed = maxSpeedtBird;
}

};


class Insect
{
    public:
string name;
double size;
Date date;

   Insect(string nameInsect, double sizeInsect, Date dateInsect)
{
    name = nameInsect;
    size = sizeInsect;
    date = dateInsect;
}

};

class Animals
{
     public:
list<Fish> fishes;
list<Bird> birds;
list<Insect> insects;

void printAnimals()
{
    //cout << fishes.size();
    for (auto i = fishes.begin(); i != fishes.end(); ++i) //Итерируем по указателю
    {
        cout << endl << "Name: " << i->name;
        if(i->location == Location::river)
        {
cout << endl << "Location: " << "river" << endl;// << i->name << endl;
        }
        if(i->location == Location::sea)
        {
cout << endl << "Location: " << "sea" << endl;// << i->name << endl;
        }
        if(i->location == Location::lake)
        {
cout << endl << "Location: " << "lake" << endl;// << i->name << endl;
        }
        if(i->location == Location::ocean)
        {
cout  << "Location: " << "ocean" << endl;// << i->name << endl;
        }
}


for (auto i = birds.begin(); i != birds.end(); ++i) {
        cout << endl << "Name: " << i->name;
        cout << endl << "Speed: " << i->maxSpeed;
         
    }

    for (auto i = insects.begin(); i != insects.end(); ++i) {
        cout << endl << "Name: " << i->name;
        cout << endl << "Size: " << i->size;
        cout << endl << "Discovery date: " << i->date.day << "." << i->date.mouth << "." << i->date.year;
    }
}

void removeAnimals(string removeName)
{
    for (auto i = fishes.begin(); i != fishes.end();) {
if(i->name==removeName)
{
 i = fishes.erase(i);
}
else {
        ++i; 
    }     
    }

    for (auto i = birds.begin(); i != birds.end();) {
       if(i->name==removeName)
{
 i = birds.erase(i);
} 
else {
        ++i; 
    }
    }
    for (auto i = insects.begin(); i != insects.end();) {
 if(i->name==removeName)
{
 i = insects.erase(i);
} 
else {
        ++i; 
    }
    }
}



void addAnimal(string animalString)
{
    vector<string> words; // массив со словами
            stringstream ss(animalString);
            string word;
            while (ss >> word)
            {
                words.push_back(word);
            }
             
             if(words.size()==3)
             {

                if (isdigit(words[2][0])) // Является ли символ цифрой (если да преобразовываем строку в тип double)
                {
                    birds.push_back(Bird(words[1], stod(words[2])));
                }
                else
                {
                    if(words[2]=="lake")
{
fishes.push_back(Fish(words[1], Location::lake));
}
if(words[2]=="sea")
{
fishes.push_back(Fish(words[1], Location::sea));
}
if(words[2]=="river")
{
fishes.push_back(Fish(words[1], Location::river));
}
if(words[2]=="ocean")
{
fishes.push_back(Fish(words[1], Location::ocean));
}
                }    
             }  
             if(words.size()==4) //Добавляем насекомое
             { 
insects.push_back(Insect(words[1], stod(words[2]), parseDate(words[3])));
             }
}
};

