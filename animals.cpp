#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cctype>
#include <list>
#include "animals.h"

using namespace std;

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


class Animals
{
     public:
  AnimalNode* startPointer = nullptr;



void insertFish(string name, Location location) {
    FishNode* fish = new FishNode;
    fish->name = name;
    fish->location = location;
    fish->next = nullptr;
    fish->prev = nullptr;

    if (startPointer == nullptr) {
        startPointer = fish;
    } else {
        AnimalNode* current = startPointer;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = fish;
        fish->prev = current;
    }
}

void insertBird(string name, double maxSpeed) {
    BirdNode* bird = new BirdNode;
    bird->name = name;
    bird->maxSpeed = maxSpeed;
    bird->next = nullptr;
    bird->prev = nullptr;

    if (startPointer == nullptr) {
        startPointer = bird;
    } else {
        AnimalNode* current = startPointer;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = bird;
        bird->prev = current;
    }
}

void insertInsect(string name, double maxSize, Date date) {
    InsectNode* insect = new InsectNode;
    insect->name = name;
    insect->size = maxSize;
    insect->date = date;
    insect->next = nullptr;
    insect->prev = nullptr;

    if (startPointer == nullptr) {
        startPointer = insect;
    } else {
        AnimalNode* current = startPointer;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = insect;
        insect->prev = current;
    }
}


void printAnimals() {
    cout << endl;
    AnimalNode* current = startPointer;

    while (current != nullptr) {
        cout << endl;
       current->printInfo();
        current = current->next;
    }
    cout << endl;
}

void removeAnimalsToName(string removeName)
{
    if (startPointer == nullptr) {
        return;
    }

    AnimalNode* current = startPointer;
    AnimalNode* nextNode = nullptr;
    AnimalNode* prevNode = nullptr;

    
    


    // Поиск удаляемого элемента
    while (current->next != startPointer) {

        if (current->name == removeName) {
            //Если удаляемый элемент находится в начале списка
if(current==startPointer)
{
    nextNode = current->next;
        prevNode = current->prev;
     if (nextNode == current) {
            startPointer = nullptr;
        } else {
             nextNode->prev = startPointer->prev;
             startPointer = nextNode;
        }
        delete current;
}
else
{
    nextNode = current->next;
            prevNode = current->prev;
            nextNode->prev = prevNode;
            prevNode->next = nextNode;
            delete current; 
}
        } 
        if(current->next == nullptr)
        {
            break;
        }    
        current = current->next; 
    }

    // Удаление последнего элемента списка, если его имя совпадает с искомым
    if (current->name == removeName) {
        nextNode = current->next;
        prevNode = current->prev;
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
        delete current;  
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
                   insertBird(words[1], stod(words[2]));
                }
                else
                {
                    if(words[2]=="lake")
{

    insertFish(words[1], Location::lake);
}
if(words[2]=="sea")
{
insertFish(words[1], Location::sea);
}
if(words[2]=="river")
{
insertFish(words[1], Location::river);
}
if(words[2]=="ocean")
{
insertFish(words[1], Location::ocean);
}
                }    
             }  
             if(words.size()==4) //Добавляем насекомое
             { 
                Date date =  parseDate(words[3]);

                if(date.day>0&&date.day<31&&date.mouth>0&&date.mouth<13&&date.year>0)
                {insertInsect(words[1], stod(words[2]), parseDate(words[3]));
                }
             }   
}
};

