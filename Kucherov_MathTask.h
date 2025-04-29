#ifndef _Kucherov_MATHTASK_H__
#define _Kucherov_MATHTASK_H__

#include <string>
#include <iostream>
using namespace std;

//функция контроля вводимых данных
bool UserInput(string input) {
   //если строка пустая - ввод некорректен
   if (input.empty()) return false;
   //попытаться
   try {
   //преобразование введенного значения в тип
   int number = stoi(input);
   }
   catch (...) //если возникла ошибка в блоке try
   { return false; }
   return true;
}
//метод ввода данных
void EnterDigit(int& varLink, const string& label) 
{
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

//вычисление площади прямоугольника
int CalcRectangleArea(int NumberA, int NumberB) {
    return NumberA * NumberB;
}
#endif