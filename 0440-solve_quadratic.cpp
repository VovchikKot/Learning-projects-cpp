﻿// solve_quadratic.cpp
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

// Особое значение "бесконечное количество корней".
const int INFINITE_ROOTS = -1;

// Решаем уравнение ax + b = 0.
// Функция возвращает "количество корней".
// Корень записывает по ссылке root.
int solve_linear(double a, double b, double &root)
{
  if (a == 0)
    return b == 0? INFINITE_ROOTS: 0;
  root = -b / a;
  return 1;
}

// Решаем уравнение ax2 + bx + c = 0.
// Функция возвращает "количество корней",
// до двух корней записывает по ссылкам.
int solve_quadratic(double a, double b, double c, double &root1, double &root2)
{
  if (a == 0) // сводится к линейному
    return solve_linear(b, c, root1);
  // a != 0

  const double d = b * b - 4.0 * a * c;
  if (d < 0) // нет корней
    return 0;
  if (d == 0) // один корень
  {
    root1 = -b / (2.0 * a); // обратите внимание на скобки
    return 1;
  }

  // два корня
  const double ds = sqrt(d);
  root1 = (-b - ds) / (2.0 * a);
  root2 = (-b + ds) / (2.0 * a);
  return 2;
}

// Вычислить значение квадратного трёхчлена в точке.
double quadratic(double a, double b, double c, double x)
{
  return (a * x + b) * x + c;
}


int main()
{
  cout << "Solving ax2 + bx + c = 0, enter a, b, c:\n";
  cout.precision(16);
  for (double a, b, c, x1, x2; cin >> a >> b >> c;)
  {
    switch (solve_quadratic(a, b, c, x1, x2))
    {
    case 0:
      cout << "no roots\n";
      break;
    case INFINITE_ROOTS:
      cout << "any number is a root\n";
      break;
    case 1: // один корень, записан в x1
      cout << "x == " << x1 << ", error is " << quadratic(a, b, c, x1) << endl;
      break;
    case 2: // два корня, записаны в x1 и x2
      cout << "x1 == " << x1 << ", error is " << quadratic(a, b, c, x1) << endl;
      cout << "x2 == " << x2 << ", error is " << quadratic(a, b, c, x2) << endl;
      break;
    default:
      cout << "???\n"; // невозможный случай
    }
  }

  return EXIT_SUCCESS;
}