#ifndef _POLYNOMIALS_H_
#define _POLYNOMIALS_H_

#include <iostream>
#include <cmath>

class Polynomial{

 public:
  Polynomials(double coeffs[], const int ncoeffs);
  
  //Accessor functions:
  double* getCoeffs();
  double getSingleCoeff(int i);
  int getNcoeffs();
  
  //Functions, operator overloading is done later
  Polynomial add(Polynomial a);
  Polynomial subtract(Polynomial a);
  Polynomial multiply(Polynomial a);
  double evaluate(double x);
  
 private:
  
  const int _ncoeffs;
  double* _coeffs = new double[_ncoeffs];
  
