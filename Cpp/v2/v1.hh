#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

#include <vector>

class Polynomial{

public:
  //Constructors and destructor:
  Polynomial(std::vector<double> _coeffs);
  Polynomial(Polynomial& other);
  ~Polynomial();

  //Accessor functions:
  std::vector<double> getCoeffs();
  double getSingleCoeff(int i);
  int getOrder();
  
  //Print functions:
  void printPolynomial();
  void printCoeffs();
  void printSingleCoeff(int i);
  void printOrder();

  //add, mul and val:
  Polynomial add(const Polynomial& other);
  Polynomial mul(const Polynomial& other);
  double val(double x);
  
  //roots:
  std::vector<double> roots();
  
  //operator overloading
  Polynomial operator+(const Polynomial& other);
  Polynomial operator*(const Polynomial& other);
  double operator[](int i);
  double operator()(double x);


private:
  std::vector<double> coeffs;
};
  
  


#endif
