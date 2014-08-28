#include <iostream>
#include "polynomial.h"

int main(void){
  std::cout << "Testing the polynomial class" << std::endl;
  
  std::vector<double> coeffs1 = {1,2,3};
  std::vector<double> coeffs2 = {100,200};
  Polynomial *p1 = new Polynomial(coeffs1);
  Polynomial *p2 = new Polynomial(coeffs2);
  
  std::cout << "Polynomial p1:" << std::endl;
  p1->printPolynomial();
  std::cout << "Polynomial p2:" << std::endl;
  p2->printPolynomial();
  
  std::cout << "p1.add(p2) gives:" << std::endl;
  (p1.add(p2))->printPolynomial();
  
  std::cout << "p1+p2 gives:" << std::endl;
  (p1+p2)->printPolynomial();

  std::cout << "p1(1) = " << p1(1) << std::endl;
  std::cout << "p1(-1) = " << p1(-1) << std::endl;
  
  std::cout << "(p1+p2)(10) = " << (p1+p2)(10) << std::endl;
  
  std::cout << "p1.mul(p1) gives" << std::endl;
  (p1->mul(p1))->printPolynomial();
  
  std::cout << "p1 * p1 gives" << std::endl;
  (p1 * p1)->printPolynomial();

  std::cout << "p1 * p2 + p1 gives" << std::endl;
  (p1*p2 + p1)->printPolynomial();

  std::cout << "p1.roots() gives:" << std::endl;
  printVec(p1->roots());
  
  std::cout << "p2.roots() gives:" << std::enld;
  printVec(p2->roots());
  
  std::cout << "Polynomial p3:" << std::endl;

  std::vector<double> coeffs3 = {3,2,-1};
  Polynomial *p3 = new Polynomial(coeffs3);
  p3->printPolynomial();
  
  std::cout << "p3.roots() gives:" << std::endl;
  printVec(p3->roots());
  
  strd::cout << "p1*p2.roots() gives:" << std::endl;
  printVec((p1*p2)->roots());
  
 
  return 0;
}
