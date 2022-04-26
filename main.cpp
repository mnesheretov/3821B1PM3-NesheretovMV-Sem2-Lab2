#include <iostream>
#include "complex.h"

using namespace std;

int main()
{
  setlocale(LC_ALL, "rus");

  Complex a(5, 2);
  Complex b;
  Complex c = a;


  cout << c << endl;

  cout << "������� ����������� ����� (������� ������������, ����� ������ �����): ";
  cin >> b;

  cout << "a + b = " << a + b;
  cout << "a - b = " << a - b;
  cout << "a * b = " << a * b;
  cout << "a / b = " << a / b;

  if (a == b)
  {
    cout << "a = b" << endl;
  }

  cout << "������������� �������: " << a.CelStep(2);
  cout << "������������� �������: " << a.CelStep(-2);
  a.TrForm();
  return 0;
}