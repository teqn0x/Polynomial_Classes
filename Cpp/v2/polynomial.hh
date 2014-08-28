#ifndef _POLYNOMIAL_HH_
#define _POLYNOMIAL_HH_

#include <vector>
#include <complex>

class Polynomial{

public:
  //Constructor, Copy, Destruct.
  Polynomial();
  Polynomial(std::vector<double> _coeffs);
  Polynomial(Polynomial& other);
  ~Polynomial();

  //Accesspr functions:
  std::vector<double> getCoeffs();
  double getSingleCoeff(int i);
  int getOrder();

  std::vector<double> getCoeffs() const;
  double getSingleCoeff(int i) const;
  int getOrder() const;

  //print functions:
  void printPolynomial();
  void printCoeffs();
  void printSingleCoeff(int i);
  void printOrder();

  //addition, multiplication and evaluation
  Polynomial add(const Polynomial& other);
  Polynomial mul(const Polynomial& other);
  double val(double x);

  //Operator overloading
  Polynomial& operator=(const Polynomial& other);
  Polynomial operator+(const Polynomial& other);
  Polynomial operator*(const Polynomial& other);
  double operator[](int i);
  double operator()(double x);
  
  //Special functions:
  std::vector<std::complex<double> > roots();



private:
  std::vector<double> coeffs;
  
};

#endif
