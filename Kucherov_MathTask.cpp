// Simname_MathTask.cpp > main()
#include <iostream>
#include "Kucherov_MathTask.h"

using namespace std;

int main() {
    int NumberA = 0, NumberB = 0;
    // Ввод переменной A
    EnterDigit(NumberA, "input height A");
    // Ввод переменной B
    EnterDigit(NumberB, "input height B");

    // Вычисление площади прямоугольника
    int RectangleArea = CalcRectangleArea(NumberA, NumberB);
    // Вывод значения площади
    cout << "Area of Rectangle is " << RectangleArea << endl;
    return 0;
}