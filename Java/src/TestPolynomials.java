import java.io.*;
import java.lang.Number;
import java.util.List;
import java.util.ArrayList;


public class TestPolynomials {

    public static void main(String[] args){
	double[] d1 = {1,2,3};
	ArrayList c1 = new ArrayList();
	for(double d : d1){
	    c1.add(new Double(d));
	}

	Polynomial p1 = new Polynomial(c1);
	
	System.out.println("Printing the full list of coefficients using the getCoeffs accessor");
	for(Double c : p1.getCoeffs()){
	    System.out.print(c.toString() + ", ");
	}
	System.out.println();
    
	System.out.println("Getting the 2nd coeff using the getSingleCoeff function: Coeff[1] = " + p1.getSingleCoeff(1).toString());
	System.out.println("Gettign the order using getOrder: Order is " + Integer.toString(p1.getOrder()));

	System.out.println("Now testing the various print functions:");
	System.out.println("printPolynomial results in:");
	p1.printPolynomial();
	System.out.println("printCoeffs results in:");
	p1.printCoeffs();
	System.out.println("printSingleCoeff(1) results in:");
	p1.printSingleCoeff(1);
	System.out.println("printOrder results in:");
	p1.printOrder();
    	
    }

}

	
