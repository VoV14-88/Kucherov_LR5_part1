#ifndef _KUCHEROV_MAATHTASK_H_
#define _KUCHEROV_MATHTASK_H_
#include <string>
using namespace std;

// Функция контроля вводимых данных
bool UserInput(const string& input) {
    // Проверка на пустую строку
    if (input.empty()) {
        return false;
    }

    // Проверка на отрицательное число
    if (input[0] == '-') {
        return false;
    }

    // Проверка на наличие нецифровых символов
    for (char c : input) {
        if (!isdigit(c)) {
            return false;
        }
    }

    // Попытка преобразования строки в число
    try {
        int number = stoi(input);
        // Дополнительная проверка на ноль (если нужно)
        if (number == 0) {
            return false;
        }
    }
    catch (...) {
        return false;
    }

    return true;
}

void testUserInput_Empty() {
    // Исходные данные (пустая строка)
    string input = "";
    
    // Ожидаемый результат (функция должна вернуть false)
    bool expected = false;

    // Вызов тестируемой функции
    bool actual = UserInput(input);

    // Проверка соответствия ожидаемого и фактического результатов
    ASSERT_EQUAL(expected, actual);
}
// Тест, проверяющий обработку буквенных символов
void testUserInput_Letter() {
    // Исходные данные (строка с буквой)
    string input = "a";
    
    // Ожидаемый результат (некорректный ввод)
    bool expected = false;

    // Вызов тестируемой функции
    bool actual = UserInput(input);

    // Проверка соответствия результатов
    ASSERT_EQUAL(expected, actual);
}
void testUserInput_DigitLetterValue()
{
    // Исходные данные (строка с цифрой и буквой)
    string input = "5a";
    
    // Ожидаемый результат (некорректный ввод)
    bool expected = false;

    // Вызов тестируемой функции
    bool actual = UserInput(input);

    // Проверка соответствия результатов
    ASSERT_EQUAL(expected, actual);
}
// Тест, проверяющий обработку отрицательных значений
void testUserInput_NegativeValue() 
{
    // Исходные данные (отрицательное число)
    string input = "-5";
    
    // Ожидаемый результат (некорректный ввод - отрицательное значение)
    bool expected = false;

    // Вызов тестируемой функции
    bool actual = UserInput(input);

    // Проверка соответствия ожидаемого и фактического результатов
    ASSERT_EQUAL(expected, actual);
}
// Метод ввода данных
void EnterDigit(int& varLink, const string& label) {
    string raw_input;
    cout << label << " = ";
    getline(cin, raw_input);
    
    while (!UserInput(raw_input)) 
    {
        cout << label << " = ";
        getline(cin, raw_input);
    }
    
    varLink = stoi(raw_input);
}

// Вычисление площади прямоугольника
int CalcRectangleArea(int NumberA, int NumberB)
 {
    return NumberA * NumberB;
}

#endif