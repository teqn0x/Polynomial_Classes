#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#include "polynomial.hh"


//Constructor:
Polynomial::Polynomial(std::vector <double> _coeffs) : coeffs(_coeffs) {
}

Polynomial::Polynomial(Polynomial& other){
  coeffs = other.getCoeffs();
}

Polynomial::~Polynomial() {}

//Accessor functions:
std::vector<double> Polynomial::getCoeffs(){
  return coeffs;
}

double Polynomial::getSingleCoeff(int i){
  return coeffs[i];
}

int Polynomial::getOrder(){
  return coeffs.size();
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
  std::cout << "Coeff[" << i << "] = " << coeffs[i] << std::endl;
}

void Polynomial::printOrder(){
  std::cout << "Polynomial of order " << coeffs.size() << std::endl;
}

Polynomial Polynomial::add(const Polynomial& other){
  std::vector<double> c1 = this->getCoeffs();
  std::vector<double> c2 = other->getCoeffs();
  std::vector<double> c3;
  
  const int n1 = c1.size();
  const int n2 = c2.size();


  if(c1.size() > c2.size()){
    c3 = c1;
    for(int i = 0; i < n2; i++){
      c3[n1-1-i]+=c2[n2-1-i];
    }
  }
  else {
    c3 = c2;
    for(int i = 0; i < n1; i++){
      c3[n2-1-i]+=c2[n1-1-i];
    }
  }
  return Polynomial::Polynomial(c3);
}

Polynomial Polynomial::mul(const Polynomial& other){
  std::vector<double> c1 = this->getCoeffs();
  std::vector<double> c2 = other->getCoeffs();
  const int n1 = c1.size();
  const int n2 = c2.size();
    
  std::vector<double> c3(n1+n2-1, 0.0);
  
  for(int i = 0; i < n1; i++){
    for(int j = 0; j < n2; j++){
      c3[i+j] += c1[i]*c2[j];
    }
  }
  return Polynomial::Polynomial(c3);
}


double Polynomial::val(double x){
  std::vector<double> c = this->getCoeffs();
  const int n = c.size();
  double val = 0.;
  for(int i = 0; i < n; i++){
    val += c[i] * std::pow(x , n-1-i);
  }
  return val;
}


std::vector<double> Polynomial::roots(){
  std::vector<double> c = this->getCoeffs();
  const int n = c.size();
  
  std::vector<double> roots = {};
  if(n == 0){
    std::cerr << "[ERROR] Polynomial is empty, no roots found" << std::endl;
  }
  else if(n == 1){
    std::cerr << "[ERROR] Polynomial is a constant, no roots found" << std::endl;
  }
  else if(n == 2){
    roots.push_back(-1.0 * c[0] / c[1]);
  }
  else if(n == 3){
    double a = c[0];
    double b = c[1];
    double c = c[2];
    double D = b*b - 4*a*c;
    
    double xp1 = -1.0 * b / (2*a);
    if (D < 0){
      double xp2 = std::complex(0, std::sqrt(-1*D) / (2*a));
    }
    else {
      double xp2 = std::sqrt(D) / (2*a);
    }
    
    roots.push_back(xp1+xp2);
    roots.push_back(xp1-xp2);
  }
  else {
    std::cerr << "Order is to high to solve for roots" << std::endl;
  }
  
  return roots;
}

Polynomial Polynomial::operator+(const Polynomial& other){
  return this->Polynomial::add(other);
}

Polynomial Polynomial::operator*(const Polynomial& other){
  return this->Polynomial::mul(other);
}

double Polynomial::operator[](int i){
  return this->Polynomial::getSingleCoeff(i);
}

double Polynomial::operator()(double x){
  return this->Polynomial::val(x);
}

