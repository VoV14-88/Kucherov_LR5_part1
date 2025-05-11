#ifndef _KUCHEROV_MAATHTASK_H_
#define _KUCHEROV_MATHTASK_H_
#include <string>
using namespace std;

// Функция контроля вводимых данных
bool UserInput(string input) 
{
    // Если строка пустая - ввод некорректен
    if (input.empty()) return false;
    
    // Попытаться преобразовать введенное значение в число
    try {
        int number = stoi(input);
    }
    catch (...) { // Если возникла ошибка при преобразовании
        return false;
    }
    
    return true;
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