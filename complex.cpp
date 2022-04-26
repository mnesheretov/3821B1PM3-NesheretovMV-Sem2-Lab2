#include "complex.h"
#include <vector>
#include <math.h>
#define pi 3.14159

using namespace std;

Complex::Complex()
{
  Re = 0;
  Im = 0;
}

Complex::Complex(double Re, double Im)
{
  this->Im = Im;
  this->Re = Re;
}

Complex::Complex(const Complex& Value)
{
  Im = Value.Im;
  Re = Value.Re;
}

double Complex::GetRe()
{
  return Re;
}

double Complex::GetIm()
{
  return Im;
}

void Complex::SetRe(double Re)
{
  this->Re = Re;
}

void Complex::SetIm(double Im)
{
  this->Im = Im;
}

Complex Complex::operator+(Complex Value)
{
  return Complex(this->Re + Value.Re, this->Im + Value.Im);
}

Complex Complex::operator-(Complex Value)
{
  return Complex(this->Re - Value.Re, this->Im - Value.Im);
}

Complex Complex::operator*(Complex Value)
{
  return Complex((this->Re * Value.Re) - (this->Im * Value.Im), (this->Re * Value.Im) + (this->Im * Value.Re));
}

Complex Complex::operator/(Complex Value)
{
  double _Re = (this->Re * Value.Re + this->Im * Value.Im) / (pow(Value.Re, 2) + pow(Value.Im, 2));
  double _Im = (this->Im * Value.Re - this->Re * Value.Im) / (pow(Value.Re, 2) + pow(Value.Im, 2));
  return Complex(_Re, _Im);
}

Complex& Complex::operator=(const Complex& Value)
{
  Re = Value.Re;
  Im = Value.Im;
  return *this;
}

bool Complex::operator==(Complex Value)
{
  if (this->Re == Value.Re and this->Im == Value.Im)
  {
    return true;
  }
  return false;
}

ostream& operator<<(ostream& out, Complex Value)
{
  out << Value.Re << (Value.Im >= 0 ? " + " : " - ") << abs(Value.Im) << "i" << endl;
  return out;
}

istream& operator>>(istream& in, Complex& Value)
{
  in >> Value.Re;
  in >> Value.Im;
  return in;
}

double Complex::Mod()
{
  return sqrt(pow(this->Re, 2) + pow(this->Im, 2));
}

Complex Complex::CelStep(int m)
{
  double fi = atan2(this->Im, this->Re); 
  return Complex(pow(this->Mod(), m) * cos(m * fi), pow(this->Mod(), m) * sin(m * fi));
}


void Complex::TrForm()
{
  double fi = atan2(this->GetIm(), this->GetRe());
  cout << this->Mod() << "(cos(" << fi << ") + i*sin(" << fi << ")" << endl;
}