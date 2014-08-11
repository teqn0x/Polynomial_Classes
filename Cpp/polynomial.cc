#include <iostream>
#include <vector>
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


