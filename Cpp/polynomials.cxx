#include <iostream>
#include "polynomials.h"

//Constructor:

Polynomial(double coeffs[]){
  _ncoeffs = ncoeffs;
  for(int i = 0; i < _ncoeffs; i++){
    _coeffs[i] = coeffs[i];
  }
}


//Accessor functions:

double* getCoeffs(){
  return _coeffs;
}

double getSingleCoeff(int i){
  if (i < _ncoeffs){
    return _coeffs[i];
  } else {
    return 0.;
  }
}

int getNcoeffs(){
  return _ncoeffs;
}



//Add, Subtract etc.
Polynomial add(Polynomial a){
  const int n1 = a.getNcoeffs();
  const int n2 = this.getNcoeffs();
  double c1[n1] = a.getCoeffs();
  double c2[n2] = this.getCoeffs();
  
  const int N = (n1 < n2) ? n2 : n1;
  
  double newCoeffs[N] = {};
  for(int i = 0; i < n1; i++){
    newCoeffs[i] += c1[i];
  }
  for(int i = 0; i < n2; i++){
    newCoeffs[i] += c2[i];
  }
  
  return Polynomial(newCoeffs, N);
}


Polynomial add(Polynomial a){
  const int n1 = a.getNcoeffs();
  const int n2 = this.getNcoeffs();
  double c1[n1] = a.getCoeffs();
  double c2[n2] = this.getCoeffs();
  
  const int N = (n1 < n2) ? n2 : n1;
  
  double newCoeffs[N] = {};
  for(int i = 0; i < n1; i++){
    newCoeffs[i] -= c1[i];
  }
  for(int i = 0; i < n2; i++){
    newCoeffs[i] += c2[i];
  }
  
  return Polynomial(newCoeffs, N);
}
  
  

Polynomial multiply(Polynomial a){
  const int n1 = a.getNcoeffs();
  const int n2 = this.getNcoeffs();
  double c1[n1] = a.getCoeffs();
  double c2[n2] = this.getCoeffs();
  
  const int N = n1+n2-1
  double newCoeffs[N] = {};

  for(int i = 0; i < n1; i++){
    for(int j = 0; j< n2; j++){
      newCoeffs[i+j] += (c1[i] * c2[j]);
    }
  }
  
  return Polynomial(newCoeffs,N)

}

double evaluate(doulble x){
}

     
