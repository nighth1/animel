#include <iostream> // Для вывода результатов тестов
#include "main.cpp" // Включаем заголовочный файл с кодом нашей программы

// Функция для проверки результата теста и вывода сообщения
void checkDateParser(bool result, string testName) {
  if (result) {
    std::cout << testName << " - Passed" << std::endl;
  } else {
    std::cout << testName << " - Failed" << std::endl;
  }
}

// Определяем тестовый набор
void runTests() {
  // Проверяем функцию parseDate()
  checkDateParser(parseDate("12.3.2343").day == DateAnimals{12, 3, 2343}.day, "AddTest1");
  checkDateParser(parseDate("4.5.2004").mouth == DateAnimals{4, 5, 2004}.mouth, "AddTest2");
  checkDateParser(parseDate("17.11.2019").year == DateAnimals{17, 11, 2019}.year, "AddTest3");
}

// Запускам тестирование
int main() {
  runTests();
  return 0;
}