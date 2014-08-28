#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#include "polynomial.hh"

Polynomial::Polynomial() { coeffs = {0.}; }

Polynomial::Polynomial(std::vector<double> _coeffs) : coeffs(_coeffs){}

Polynomial::Polynomial(Polynomial& other){
  coeffs = other.getCoeffs();
}

Polynomial::~Polynomial() {}

std::vector<double> Polynomial::getCoeffs(){
  return coeffs;
}

double Polynomial::getSingleCoeff(int i){
  return coeffs[i];
}

int Polynomial::getOrder(){
  return coeffs.size();
}

std::vector<double> Polynomial::getCoeffs() const {
  return const_cast<Polynomial*>(this)->getCoeffs();
}

double Polynomial::getSingleCoeff(int i) const {
  return const_cast<Polynomial*>(this)->getSingleCoeff(i);
}

int Polynomial::getOrder() const {
  return const_cast<Polynomial*>(this)->getOrder();
}

//Print functions:
void Polynomial::printPolynomial(){
  int N = coeffs.size();
  for(int i = 0; i < N; i++){
    if(i == N-1){
      std::cout << coeffs[i];
    }
    else if(i == N-2){
      std::cout << coeffs[i] << "x + ";
    }
    else {
      std::cout << coeffs[i] << "x^" << N-i-1 << " + ";
    }
  }
  std::cout << std::endl;
}

void Polynomial::printCoeffs(){
  int N = coeffs.size();
  std::cout << "Polynomial::Coeffs = [ ";
  for(int i = 0; i < N-1; i++){
    std::cout << coeffs[i] << ", ";
  }
  std::cout << coeffs[N-1] << " ]" << std::endl;
}

void Polynomial::printSingleCoeff(int i){
  if(i < coeffs.size()){
    std::cout << "Coeff[" << i << "] = " << coeffs[i] << std::endl;
  }
  else {
    std::cout << "Out of range!" << std::endl;
  }
}

void Polynomial::printOrder(){
  std::cout << "Polynomial of order " << coeffs.size() << std::endl;
}

//Addition of two polynomial via the function p1.add(p2)
Polynomial Polynomial::add(const Polynomial& other){
  std::vector<double> c1(coeffs);
  std::vector<double> c2 = other.getCoeffs();
  std::vector<double> c3;
  
  
  const int n1 = c1.size();
  const int n2 = c2.size();
  
  if(n1 > n2){
    c3 = c1;
    for(int i = 0; i < n2; i++){
      c3[n1-1-i] += c2[n2-1-i];
    }
  }
  else {
    c3 = c2;
    for(int i = 0; i < n1; i++){
      c3[n2-1-i] += c1[n1-1-i];
    }
  }
  
  Polynomial tmp(c3);
  return tmp;
}

// Multiplication of two polynomial via the function p1.mul(p2) 
Polynomial Polynomial::mul(const Polynomial& other){
  std::vector<double> c1(coeffs);
  std::vector<double> c2 = other.getCoeffs();

  const int n1 = c1.size();
  const int n2 = c2.size();

  std::vector<double> c3(n1+n2-1, 0.0);
  
  for(int i = 0; i < n1; i++){
    for(int j = 0; j < n2; j++){
      c3[i+j] += c1[i]*c2[j];
    }
  }
 
  Polynomial tmp(c3);
  return tmp;
}

double Polynomial::val(double x){
  double val = 0.;
  for(int i=0; i<coeffs.size(); i++){
    val += coeffs[i] * std::pow(x, coeffs.size()-1-i);
  }
  return val;
}

Polynomial& Polynomial::operator=(const Polynomial& other){
  if(coeffs != other.getCoeffs()){
    coeffs = other.getCoeffs();
  }
  return *this;
}

Polynomial Polynomial::operator+(const Polynomial& other){
  Polynomial tmp;
  tmp = this->add(other);
  return tmp;
}

Polynomial Polynomial::operator*(const Polynomial& other){
  Polynomial tmp;
  tmp = this->mul(other);
  return tmp;
}

double Polynomial::operator[](int i){
  return this->getSingleCoeff(i);
}

double Polynomial::operator()(double x){
  return this->val(x);
}

std::vector<std::complex<double> > Polynomial::roots(){
  std::vector<double> cf = this->getCoeffs();
  const int n = cf.size();

  //Roots can be complex, therefore it is best to already start out with a vector of complex numbers
  std::vector<std::complex<double> > roots = {};
  
  if(n == 0){
    std::cerr << "[ERROR] Polynomial is empty, no roots found" << std::endl;
  }
  else if(n == 1){
    std::cerr << "[ERROR] Polynomial is a constant, no roots found" << std::endl;
  }
  else if(n == 2){
    roots.push_back(-1.0 * cf[0] / cf[1]);
  }
  else if(n == 3){
    double a = cf[0];
    double b = cf[1];
    double c = cf[2];
    std::complex<double> D = b*b - 4*a*c; // needs to be a complex in order to work properly with std::sqrt when D < 0
    std::complex<double> xp1 = -1.0 * b / (2*a);
    std::complex<double> xp2 = std::sqrt(D) / (2*a);
    
    roots.push_back(xp1+xp2);
    roots.push_back(xp1-xp2);
  }
  else {
    std::cerr << "[ERROR] Order is to high to solve for roots" << std::endl;
  }
  
  return roots;
}
