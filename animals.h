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


class AnimalNode {
public:
    string name;
    AnimalNode* next;
    AnimalNode* prev;

     virtual void printInfo() = 0; // Виртуальная функция
};

class FishNode : public AnimalNode {
public:
    Location location;
    void printInfo() override {
        cout << "\nName: " << name;
        if(location==Location::river)
        {cout << "\nLocation: river";}
        if(location==Location::lake)
        {cout << "\nLocation: lake";}
        if(location==Location::sea)
        {cout << "\nLocation: sea";}
        if(location==Location::ocean)
        {cout << "\nLocation: ocean";} 
    }
};

class BirdNode : public AnimalNode {
public:
    double maxSpeed;
     void printInfo() override {
        cout << "\nName: " << name ;
        cout << "\nSpeed: " << maxSpeed ;
    }
};

class InsectNode : public AnimalNode {
public:
    double size;
    Date date;
    void printInfo() override {
        cout << "\nName: " << name;
        cout << "\nSize: " << size;
        cout << "\nDate: " << date.year << "." << date.mouth << "." << date.day;
    }
};
