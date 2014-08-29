//Test the complex class

import java.lang.Number;

public class TestComplex {
    public static void main(String[] args){
	
	Complex c1 = new Complex(1.0);
	Complex c2 = new Complex(2.5,3.1);
	
	Complex c3 = new Complex(c2);
	
	System.out.println(c1.toString());
	System.out.println(c2.toString());
	System.out.println(c3.toString());
	
	double r = 1;
	double theta = Math.PI / 4.0;
	Complex c4 = Complex.fromPolar(r,theta);
	
	System.out.println(c4.toString());
	
	
	Complex c5 = new Complex(10.1, 123.456);
	System.out.println("c2 = " + c2.toString() + ", c5 = " + c5.toString());
	System.out.println("c2 + c5 = " + (c2.add(c5)).toString());
	System.out.println("c2 - c5 = " + (c2.sub(c5)).toString());
	System.out.println("c2 * c5 = " + (c2.mul(c5)).toString());
	System.out.println("c5 / c2 = " + (c5.div(c2)).toString());
	System.out.println("c2* = " + c2.conj().toString());
	System.out.println("mod(c4) = " + Double.toString(c4.mod()));
	System.out.println("arg(c4) = " + Double.toString(c4.arg()));
	System.out.println("exp(c4) = " + c4.exp().toString());
	
	System.out.println("Complex.toString(new Complex(123,345)) = " + Complex.toString(new Complex(123,456)));
	System.out.println("Complex.toString(3.1, 4.1) = " + Complex.toString(3.1,4.1));
    }
}			   
			  
	
	    
	
