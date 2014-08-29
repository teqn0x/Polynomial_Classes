import java.io.*;
import java.util.List;
import java.util.ArrayList;
import java.lang.Number;


public class GeneralPolynomialTest {
    
    public static void main(String[] args){

	double[] d1 = {1,2,3};
	ArrayList<Double> c1= new ArrayList<Double>();
	for(Double d : d1){
	    c1.add(d);
	}
	
	Polynomial p1 = new Polynomial(c1);
	System.out.println("Printing Polynomial p1:");
	p1.printPolynomial();
	
	double[] d2 = {100,200};
	ArrayList<Double> c2 = new ArrayList<Double>();
	for(Double d : d2){
	    c2.add(d);
	}
	
	Polynomial p2 = new Polynomial(c2);
	System.out.println("Printing Polynomial p2:");
	p2.printPolynomial();
	
	
	Polynomial p3 = p1.add(p2);
	System.out.println("Printing Polynomial p3 = p1.add(p2):");
	p3.printPolynomial();

	System.out.println("p1(1) = " + Double.toString(p1.val(1)));
	System.out.println("p1(-1) = " + Double.toString(p1.val(-1)));
	
	Polynomial p4 = p1.mul(p1);
	System.out.println("Printing Polynomial p4 = p1.mul(p1):");
	p4.printPolynomial();
	
	Polynomial p5 = (p1.mul(p2)).add(p1);
	System.out.println("Printing Polynomial p5 = p1.mul(p2).add(p1):");
	p5.printPolynomial();

	ArrayList<Complex> r1;
	ArrayList<Complex> r2;
	ArrayList<Complex> r3;
	
	r1 = p1.roots();
	System.out.println("Printing the roots for Polynomial p1:");
	for( Complex c : r1 ){
	    System.out.println(c);
	}
	
	r2 = p2.roots();
	System.out.println("Printing the roots for Polynomial p2:");
	for(Complex c: r2){
	    System.out.println(c.toString());
	}

	double[] d6 = {3,2,-1};
	ArrayList<Double> c6 = new ArrayList<Double>();
	for(Double d : d6){
	    c6.add(d);
	}
	Polynomial p6 = new Polynomial(c6);
	System.out.println("Printing Polynomial p6:");
	p6.printPolynomial();
	r3 = p6.roots();
	System.out.println("Printing the roots for Polynomial p6:");
	for(Complex c : r3) {
	    System.out.println(c.toString());
	}

	ArrayList<Complex> r4;
	System.out.println("Trying to get roots for p1*p1 (Should fail)");
	r4 = p4.roots();
    

    }

   

}
     
	    
	    
