import java.io.*;
import java.lang.Math;
import java.lang.Number;
import java.util.List;
import java.util.ArrayList;

public class Polynomial {
    
    //Data members, the coefficients:
    private ArrayList<Double> coeffs = new ArrayList<Double>();
    
    //Default constructor:
    Polynomial(){
	coeffs.add(new Double(0.0));
    }
    
    //Constructor with ArrayList as argument:
    Polynomial(ArrayList<Double> coeffs){
	this.coeffs = coeffs;
    }

    //-------------------------------------------------
    // Accessor functions
    //-------------------------------------------------

    public ArrayList<Double> getCoeffs(){
	return coeffs;
    }

    public Double getSingleCoeff(int i){
	return coeffs.get(i);
    }
    
    public int getOrder(){
	return coeffs.size();
    }
    
    //-------------------------------------------------
    //Print functions:
    //-------------------------------------------------

    public void printPolynomial(){
	
	final int N = coeffs.size();
	
	for(int i = 0; i < N; i++) {
	    if(i == N-1){
		System.out.println(coeffs.get(i));
	    }
	    else if(i == N-2) {
		System.out.print(coeffs.get(i).toString() + " x + ");
	    }
	    else {
		System.out.print(coeffs.get(i).toString() + " x^" + Integer.toString(N-i-1) + " + " );
	    }
	}
    }

    public void printCoeffs(){
	
	final int N = coeffs.size();
	
	System.out.print("Coeffs = [ ");
	
	for(int i = 0; i < N-1; i++){
	    System.out.print(coeffs.get(i).toString()+", ");
	}
	System.out.println(coeffs.get(N-1).toString()+"]");

    }

    public void printSingleCoeff(int i){
	System.out.println("Coeff[" + Integer.toString(i) + "] = " + coeffs.get(i).toString());
    }
    
    public void printOrder(){
	System.out.println("Order of the Polynomial is " + Integer.toString(coeffs.size()));
    }

    //Arithmetics
    public Polynomial add(Polynomial other){

	ArrayList<Double> c1 = coeffs;
	ArrayList<Double> c2 = other.getCoeffs();
	ArrayList<Double> c3;
	
	final int n1 = c1.size();
	final int n2 = c2.size();
	
	if (n1 > n2){
	    c3 = new ArrayList<Double>(c1);
	    for(int i = 0; i < n2; i++){
		Double val = c3.get(n1-1-i) + c2.get(n2-i-1);
		c3.set(n1-1-i, val);
	    }
	}
	
	else {
	    c3 = new ArrayList<Double>(c2);
	    for(int i = 0; i < n1; i++){
		Double val = c3.get(n2-1-i) + c1.get(n1-i-1);
		c3.set(n2-1-i,val);
	    }
		
	}
	
	return new Polynomial(c3);
    }
	
    public Polynomial mul(Polynomial other){
	ArrayList<Double> c1 = coeffs;
	ArrayList<Double> c2 = other.getCoeffs();
	final int n1 = c1.size();
	final int n2 = c2.size();

	ArrayList<Double> c3 = new ArrayList<Double>(n1+n2-1);
	
	for(int i = 0; i < n1+n2-1; i++){
	    c3.add(new Double(0.0));
	}
	
	for(int i = 0; i < n1; i++){
	    for(int j = 0; j < n2; j++){
		Double val = c3.get(i+j) + c1.get(i) * c2.get(j);
		c3.set(i+j,val);
	    }
	}

	return new Polynomial(c3);
    }

    public double val(double x){
	double val = 0;
	final int n = coeffs.size();
	for(int i = 0; i < n; i++){
	    val += coeffs.get(i) * Math.pow(x, n-1-i);
	}
	
	return val;
    }

    
    //Special operations:
    public ArrayList<Complex> roots(){
	ArrayList<Double> c1 = coeffs;
	final int n = c1.size();
	ArrayList<Complex> r = new ArrayList<Complex>();
	
	if(n == 0){
	    System.out.println("[ERROR] Polynomial is empty, no roots found");
	}
	else if(n == 1){
	    System.out.println("[ERROR] Polynomial is a constant, no roots found");
	}
	if(n == 2){
	    r.add(new Complex(-1.0 * c1.get(0) / c1.get(1)));
	}
	else if(n == 3){
	    Double a = c1.get(0);
	    Double b = c1.get(1);
	    Double c = c1.get(2);
	    Double D = b*b - 4*a*c;
	    
	    Double xp1 = -1.0 * b / (2*a);
	    Double xp2;
	    
	    if(D < 0){
		xp2 = Math.sqrt(-1*D) / (2*a);
		r.add(new Complex(xp1,xp2));
		r.add(new Complex(xp1,-1*xp2));
	    }
	    else {
		xp2 = Math.sqrt(D) / (2*a);
		r.add(new Complex(xp1+xp2));
		r.add(new Complex(xp1-xp2));
	    }
	}
	else {
	    System.out.println("[ERROR] Order is to high to solve for roots"); // not entirely true... 
	}
	
	
	return r;
    }



}



