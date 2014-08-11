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

private:
  std::vector<double> coeffs;
};
  
  


#endif
