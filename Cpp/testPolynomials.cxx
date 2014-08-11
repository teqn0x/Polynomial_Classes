#include <iostream>
#include <vector>

#include "polynomial.hh"

template <typename T>
void printVec(std::vector<T> v);

int main(void){

  std::cout << "Making the polynomial 2x^2 + 5x - 3" << std::endl;
  std::vector<double> coeffs= {2,5,-3};
  
  Polynomial *p = new Polynomial(coeffs);
  
  //Using all the print functions:
  std::cout << "using printOrder" << std::endl;
  p->printOrder();
  std::cout << "printing coeffs" << std::endl;
  p->printCoeffs();
  std::cout << "printing coeff [1]" << std::endl;
  p->printSingleCoeff(1);
  std::cout << "And the whole polynomial" << std::endl;
  p->printPolynomial();
  
  std::cout<< "Using the accessor functions" << std::endl;
  std::cout << "Polynomial p of order " << p->getOrder() << " has as 2nd element " << p->getSingleCoeff(1) << std::endl;
  printVec(p->getCoeffs());
 
  //using the copy constructor:
  Polynomial p2(*p);
  std::cout << "Copy of polynomial, calling printvec" << std::endl;
  p2.printPolynomial();

  
  return 0;
}
  

template <typename T>
void printVec(std::vector<T> v){
  std::cout << "Contents of Vector: ";
  for(auto x : v){
    std::cout << x << "  ";
  }
  std::cout << std::endl;
}
