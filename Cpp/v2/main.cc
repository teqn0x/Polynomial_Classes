#include <iostream>
#include <vector>
#include <complex>
#include "polynomial.hh"

void printRoots(std::vector<std::complex<double> > r);

int main(void){

  std::vector<double> c1 = {1,2,3};
  Polynomial p1(c1);
  std::cout << "p1: ";
  p1.printPolynomial();
  
  std::vector<double> c2 = {100,200};
  Polynomial p2(c2);
  std::cout << "p2: ";
  p2.printPolynomial();

  Polynomial p3;
  p3 = p1.add(p2);
  std::cout << "p1.add(p2): ";
  p3.printPolynomial();
  
  Polynomial p4;
  p4 = p1 + p2;
  std::cout << "p1 + p2: ";
  p4.printPolynomial();
  
  std::cout << "p1(1)  = " << p1(1) << std::endl;
  std::cout << "p1(-1) = " << p1(-1) << std::endl;
  std::cout << "(p1+p2)(10) = " << (p1+p2)(10) << std::endl; //Don't know if this is going to work, otherwise do p4(10)
  
  Polynomial p5;
  p5 = p1.mul(p1);
  std::cout << "p1.mul(p1): ";
  p5.printPolynomial();
  
  Polynomial p6;
  p6 = p1 * p1;
  std::cout << "p1 * p1:  ";
  p6.printPolynomial();

  Polynomial p7;
  p7 = p1 * p2 + p1;
  std::cout << "p1 * p2 + p1: ";
  p7.printPolynomial();

  //The roots part:
  std::vector<std::complex<double> > r1;
  r1 = p1.roots();
  printRoots(r1);
  
  std::vector<std::complex<double> > r2;
  r2 = p2.roots();
  printRoots(r2);
  
  std::vector<double> c8 = {3,2,-1};
  Polynomial p8(c8);
  std::vector<std::complex<double> > r8;
  r8 = p8.roots();
  printRoots(r8);
  
  std::vector<std::complex<double> > r6;
  r6 = p6.roots();
  
  

  
  return 0;
}

void printRoots(std::vector<std::complex<double> > r){
  int n = r.size();
  for(int i = 0; i < n; i++){
    std::cout << "Root " << i+1 << ": " << r[i] << std::endl;
  }
}
