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

struct FishNode {
    string name;
Location location;
    FishNode* next;
    FishNode* prev;
};

struct BirdNode {
    string name;
double maxSpeed;
    BirdNode* next;
    BirdNode* prev;
};

struct InsectNode {
    string name;
double size;
Date date;
    InsectNode* next;
    InsectNode* prev;
};

class Animals
{
     public:
FishNode* fishStartPointer = nullptr; 
BirdNode* birdStartPointer = nullptr;
InsectNode* insectStartPointer = nullptr;

void insertFish(FishNode** head, string name, Location location) {
    // Создание нового узла
    FishNode* newNode = new FishNode();
    newNode->name = name;
    newNode->location = location;

    // Если список пустой, делаем новый узел начальным и указываем на самого себя
    if (*head == nullptr) {
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }
     // Иначе, добавляем новый узел в начало списка
    newNode->next = *head;
    newNode->prev = (*head)->prev;
    (*head)->prev->next = newNode;
    (*head)->prev = newNode;
    *head = newNode;
}

void insertBird(BirdNode** head, string name, double maxSpeed) {
    // Создание нового узла
    BirdNode* newNode = new BirdNode();
    newNode->name = name;
    newNode->maxSpeed = maxSpeed;

    // Если список пустой, делаем новый узел начальным и указываем на самого себя
    if (*head == nullptr) {
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }
     // Иначе, добавляем новый узел в начало списка
    newNode->next = *head;
    newNode->prev = (*head)->prev;
    (*head)->prev->next = newNode;
    (*head)->prev = newNode;
    *head = newNode;
}


void insertInsect(InsectNode** head, string name, double maxSize, Date date) {
    // Создание нового узла
    InsectNode* newNode = new InsectNode();
    newNode->name = name;
    newNode->size = maxSize;
    newNode->date = date;

    // Если список пустой, делаем новый узел начальным и указываем на самого себя
    if (*head == nullptr) {
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }
     // Иначе, добавляем новый узел в начало списка
    newNode->next = *head;
    newNode->prev = (*head)->prev;
    (*head)->prev->next = newNode;
    (*head)->prev = newNode;
    *head = newNode;
}

void printAnimals()
{
    cout << endl << "PRINT" << endl;

     if (fishStartPointer != nullptr) {
        FishNode* currentFish = fishStartPointer;
    do {
        cout  << "name: " << currentFish->name;
        if(currentFish->location == Location::river)
        {
cout <<  " Location: " << "river" << endl;
        }
        if(currentFish->location == Location::sea)
        {
cout <<  " Location: " << "sea" << endl;
        }
        if(currentFish->location == Location::lake)
        {
cout <<  " Location: " << "lake" << endl;
        }
        if(currentFish->location == Location::ocean)
        {
cout << " Location: " << "ocean" << endl;
        }
        
        currentFish = currentFish->next;
    } while (currentFish != fishStartPointer);
    cout << endl;
    }

    


     if (birdStartPointer != nullptr) {
         BirdNode* currentBird = birdStartPointer;
    do {
        cout << endl << "name: "  << currentBird->name;
        cout << " speed" << currentBird->maxSpeed; 
        currentBird = currentBird->next;
    } while (currentBird != birdStartPointer);
    cout << endl;

    }

   if (insectStartPointer != nullptr) {
 InsectNode* currentInsect = insectStartPointer;
    do {
        cout << endl << "name: "  << currentInsect->name;
        cout << " size: "  << currentInsect->size; 
        cout  << " date: "  << currentInsect->date.day << "." << currentInsect->date.mouth << "." << currentInsect->date.year; 
        currentInsect = currentInsect->next;
    } while (currentInsect != insectStartPointer);
    cout << endl;
    }

}




bool deleteBird(BirdNode** head, string name) {
    // Если список пустой, ничего не делаем
    if (*head == nullptr) {
        return false;
    }

    BirdNode* current = *head;
    BirdNode* nextNode = nullptr;
    BirdNode* prevNode = nullptr;

    // Если удаляемый элемент находится в начале списка
    if (current->name == name) {
        nextNode = current->next;
        prevNode = current->prev;

        // Если удаляемый элемент является единственным в списке
        if (nextNode == current) {
            *head = nullptr;
        } else {
            nextNode->prev = prevNode;
            prevNode->next = nextNode;
            *head = nextNode;
        }

        delete current;
        return true;
    }

    // Поиск удаляемого элемента
    while (current->next != *head) {
        if (current->name == name) {
            break;
        }
        current = current->next;
    }

    // Если удаляемый элемент найден
    if (current->name == name) {
        nextNode = current->next;
        prevNode = current->prev;

        nextNode->prev = prevNode;
        prevNode->next = nextNode;

        delete current;
         
    }
    return false;
}

bool deleteFish(FishNode** head, string name) {
    // Если список пустой, ничего не делаем
    if (*head == nullptr) {
        return false;
    }

    FishNode* current = *head;
    FishNode* nextNode = nullptr;
    FishNode* prevNode = nullptr;

    // Если удаляемый элемент находится в начале списка
    if (current->name == name) {
        nextNode = current->next;
        prevNode = current->prev;

        // Если удаляемый элемент является единственным в списке
        if (nextNode == current) {
            *head = nullptr;
        } else {
            nextNode->prev = prevNode;
            prevNode->next = nextNode;
            *head = nextNode;
        }

        delete current;
        return true;
    }

    // Поиск удаляемого элемента
    while (current->next != *head) {
        if (current->name == name) {
            break;
        }
        current = current->next;
    }

    // Если удаляемый элемент найден
    if (current->name == name) {
        nextNode = current->next;
        prevNode = current->prev;

        nextNode->prev = prevNode;
        prevNode->next = nextNode;

        delete current;
    }
    return false;
}


bool deleteInsect(InsectNode** head, string name) {
    // Если список пустой, ничего не делаем
    if (*head == nullptr) {
        return false;
    }

    InsectNode* current = *head;
    InsectNode* nextNode = nullptr;
    InsectNode* prevNode = nullptr;

    // Если удаляемый элемент находится в начале списка
    if (current->name == name) {
        nextNode = current->next;
        prevNode = current->prev;

        // Если удаляемый элемент является единственным в списке
        if (nextNode == current) {
            *head = nullptr;
        } else {
            nextNode->prev = prevNode;
            prevNode->next = nextNode;
            *head = nextNode;
        }

        delete current;
        return true;
    }

    // Поиск удаляемого элемента
    while (current->next != *head) {
        if (current->name == name) {
            break;
        }
        current = current->next;
    }

    // Если удаляемый элемент найден
    if (current->name == name) {
        nextNode = current->next;
        prevNode = current->prev;

        nextNode->prev = prevNode;
        prevNode->next = nextNode;

        delete current;
    }
    return false;
}


     




void removeAnimalsToName(string removeName)
{
bool deleteOneBird = deleteBird(&birdStartPointer, removeName);
bool deleteOneFish = deleteFish(&fishStartPointer, removeName);
bool deleteOneInsect = deleteInsect(&insectStartPointer, removeName);


while(deleteOneBird)
{
    deleteOneBird = deleteBird(&birdStartPointer, removeName);
}

while(deleteOneFish)
{
    deleteOneFish = deleteBird(&birdStartPointer, removeName);
}

while(deleteOneInsect)
{
    deleteOneInsect = deleteBird(&birdStartPointer, removeName);
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
                   insertBird(&birdStartPointer, words[1], stod(words[2]));
                }
                else
                {
                    if(words[2]=="lake")
{

    insertFish(&fishStartPointer, words[1], Location::lake);
}
if(words[2]=="sea")
{
insertFish(&fishStartPointer, words[1], Location::sea);
}
if(words[2]=="river")
{
insertFish(&fishStartPointer, words[1], Location::river);
}
if(words[2]=="ocean")
{
insertFish(&fishStartPointer, words[1], Location::ocean);
}
                }    
             }  
             if(words.size()==4) //Добавляем насекомое
             { 
                Date date =  parseDate(words[3]);

                if(date.day>0&&date.day<31&&date.mouth>0&&date.mouth<13&&date.year>0)
                {insertInsect(&insectStartPointer, words[1], stod(words[2]), parseDate(words[3]));}
             }












    
}
};

