#pragma once
#include <iostream>

class Complex
{
protected:

  double Im;
  double Re;

public:

  Complex();
  Complex(double Re, double Im);
  Complex(const Complex& Value);

  double GetIm();
  double GetRe();
  void SetIm(double Im);
  void SetRe(double Re);

  Complex operator + (Complex Value);
  Complex operator - (Complex Value);
  Complex operator * (Complex Value);
  Complex operator / (Complex Value);

  Complex& operator = (const Complex& other);

  bool operator == (Complex Value);

  friend std::ostream& operator << (std::ostream& out, Complex Value);
  friend std::istream& operator >> (std::istream& in, Complex& Value);

  double Mod();
  void TrForm();
  Complex CelStep(int m);
  
}; 
