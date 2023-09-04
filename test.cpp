
#include <gtest/gtest.h>
#include "main.cpp"


using namespace std;

TEST(TestParseDate, Day) {
    string dateString = "12:03:2023";
  
  Date parsedDate = parseDate(dateString);

  Date date = Date{12, 3, 2023};
  
  ASSERT_EQ(parsedDate.day, date.day);
}

TEST(TestParseDate, Mouth) {

    string dateString = "01:08:2023";
  
  Date parsedDate = parseDate(dateString);

  Date date = Date{1, 8, 2023};
  
  ASSERT_EQ(parsedDate.mouth, date.mouth);
}

TEST(TestParseDate, Year) {
    string dateString = "15:07:1991";
  
  Date parsedDate = parseDate(dateString);

  Date date = Date{15, 7, 1991};
  
  ASSERT_EQ(parsedDate.year, date.year);
}



//Тестируем конструкторы классов

TEST(FishConstructorTest, DefaultConstructor) {
    Location location = Location::lake;
    string name = "karas";
  Fish karas = Fish(name, location);
 
ASSERT_TRUE(karas.name == name && karas.location==location);
}

TEST(BirdConstructorTest, DefaultConstructor) {

    double maxSpeed = 12.3;
    string name = "parrot";
    
  Bird parrot = Bird(name, maxSpeed);
 
ASSERT_TRUE(parrot.name == name && parrot.maxSpeed==maxSpeed);
}

TEST(InsectConstructorTest, DefaultConstructor) {

    double size = 5.5;
    string name = "ant";
    Date date = Date{13, 9, 1766};
    
  Insect ant = Insect(name, size, date);
 
ASSERT_TRUE(ant.name == name && ant.size==size && ant.date.day == date.day);
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}


