#include "CUTE/cute/cute.h"
#include "CUTE/cute/ide_listener.h"
#include "CUTE/cute/cute_runner.h"
// подключение модуля с тестируемыми методами
#include "Kucherov_MathTask.h"

using namespace cute;

void testCalcRectangleArea() {
    // входные значения
    int a = 3;
    int b = 5;
    // ожидаемый результат
    int expected = 15;

    // получение значения с помощью тестируемого метода
    int actual = CalcRectangleArea(a, b);

    // сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expected, actual);
}
void testUserInput_Empty() {
    // исходные данные
    string str = "";
    // ожидаемое значение результата работы функции UserInput
    bool expected = false;

    // получение значения с помощью тестируемого метода
    bool actual = UserInput(str);

    // сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expected, actual);
}

void testUserInput_Letter() {
    // исходные данные
    string str = "a";
    // ожидаемое значение результата работы функции UserInput
    bool expected = false;

    // получение значения с помощью тестируемого метода
    bool actual = UserInput(str);

    // сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expected, actual);
}

void testUserInput_NegativeValue() {
    // исходные данные
    string str = "-5";
    // ожидаемое значение результата работы функции UserInput
    bool expected = false;

    // получение значения с помощью тестируемого метода
    bool actual = UserInput(str);

    // сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expected, actual);
}

int main() {
    // Создаем тестовый набор
    suite s;

    // Добавляем тестовую функцию в набор
    s.push_back(CUTE(testCalcRectangleArea));
    s.push_back(CUTE(testUserInput_Empty));
    s.push_back(CUTE(testUserInput_Letter));
    s.push_back(CUTE(testUserInput_NegativeValue));

    // Создаем listener и runner
    ide_listener<> listener;
    makeRunner(listener)(s, "Test CalcRectangleArea");

    return 0;
}