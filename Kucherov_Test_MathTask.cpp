#include "CUTE/cute/cute.h"
#include "CUTE/cute/ide_listener.h"
#include "CUTE/cute/cute_runner.h"
// Подключение модуля с тестируемыми методами
#include "Kucherov_MathTask.h"

using namespace cute;

void testCalcRectangleArea() 
{
    // Входные значения
    int a = 3;
    int b = 5;
    
    // Ожидаемый результат
    int expected = 15;

    // Получение значения с помощью тестируемого метода
    int actual = CalcRectangleArea(a, b);

    // Сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expected, actual);
}
int main()
{
        suite testSuite;
    
        // Регистрация тестовых случаев
        testSuite.push_back(CUTE(testCalcRectangleArea));       // Тест вычисления площади
        testSuite.push_back(CUTE(testUserInput_Empty));        // Тест пустого ввода
        testSuite.push_back(CUTE(testUserInput_Letter));       // Тест буквенного ввода
        testSuite.push_back(CUTE(testUserInput_NegativeValue)); // Тест отрицательных значений
        testSuite.push_back(CUTE(testUserInput_DigitLetterValue)); // Тест смешанного ввода
    
        // Настройка системы выполнения тестов
        ide_listener<> resultsListener;
        makeRunner(resultsListener)(testSuite, "Rectangle Module Tests");
    
        return 0;
}